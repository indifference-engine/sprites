ifeq ($(OS),Windows_NT)
	CC = x86_64-w64-mingw32-gcc
else
	CC = clang
endif

CFLAGS = -Wall -Wextra -Werror -std=c99 -nostdlib -ffreestanding -O3 -pedantic -ffp-contract=off

# Unfortunately, I have found that make quite often selects the wrong shell
# (e.g. PowerShell), so commands like "find" won't work unless we explicitly
# specify bash.  You also can't use a variable for this (e.g. $(SHELL)) as make
# inexplicably tries to read something from the PATH and fails.  So hardcoding a
# reference to bash seems to be the only way to get a working build.
C_FILES = $(sort $(shell bash -c "find src -type f -iname ""*.c""") $(shell bash -c "find tests/helpers -type f -iname ""*.c"""))
H_FILES = $(sort $(shell bash -c "find src -type f -iname ""*.h""") $(shell bash -c "find tests/helpers -type f -iname ""*.h"""))
O_FILES = $(sort $(patsubst %.c,obj/%.o,$(C_FILES)))
TOTAL_REBUILD_FILES = makefile $(H_FILES)
EXPECTED_OUTPUTS = $(sort $(foreach S,$(shell bash -c "find tests/cases -mindepth 5 -maxdepth 5 -type f -iname ""*.data"""),$(if $(findstring /expected/,$S),$S)))

test: $(patsubst %.data,%.hex,$(addprefix tests/pass_markers/,$(subst /expected/,/actual/,$(EXPECTED_OUTPUTS))))

dist/%: tests/cases/%/main.c $(O_FILES)
	mkdir -p $(dir $@)
	$(CC) $(CLAGS) -flto $^ -o $@
	mkdir -p tests/cases/$*/outputs/actual/viewport tests/cases/$*/outputs/actual/sprite
	cd tests/cases/$* && ../../../$@

obj/%.o: %.c $(TOTAL_REBUILD_FILES)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

tests/cases/%/outputs/actual/viewport/opacities.data: dist/%;
tests/cases/%/outputs/actual/viewport/reds.data: dist/%;
tests/cases/%/outputs/actual/viewport/greens.data: dist/%;
tests/cases/%/outputs/actual/viewport/blues.data: dist/%;
tests/cases/%/outputs/actual/viewport/depths.data: dist/%;
tests/cases/%/outputs/actual/sprite/opacities.data: dist/%;
tests/cases/%/outputs/actual/sprite/reds.data: dist/%;
tests/cases/%/outputs/actual/sprite/greens.data: dist/%;
tests/cases/%/outputs/actual/sprite/blues.data: dist/%;

tests/cases/%.hex: tests/cases/%.data
	xxd $< > $@

tests/pass_markers/%: % $(patsubst %.data,%.hex,$(EXPECTED_OUTPUTS))
	diff $* $(subst /actual/,/expected/,$*)

clean:
	rm -rf obj dist $(patsubst %, tests/cases/%/outputs/actual, $(TESTS)) tests/pass_markers
