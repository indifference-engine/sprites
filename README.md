# Sprites

C library to draw sprites.

## Usage

### Project Level

Your application's build pipeline will need to be configured to compile each C
file in the [src](./src) directory and recompile every C file should any H files
change.  Then, include each H file in the same directory to make its
corresponding function available.

### Assumptions

- The compilation environment supports C99.
- The sprite being sampled from:
  - Has its origin in the top left corner.
  - Is row-major.
  - Is planar (not interleaved).
  - Has a red plane.
  - Has a green plane.
  - Has a blue plane.
  - Has an opacity plane (where required).
  - Uses 32-bit floats for all planes.
  - Describes absolute transparency as an opacity of 0.
  - Describes absolute opacity as an opacity of 1.
  - Does not pre-multiply any plane by the opacity plane.
- The viewport being rendered to:
  - Has its origin in the top left corner.
  - Is row-major.
  - Is planar (not interleaved).
  - Has a red plane.
  - Has a green plane.
  - Has a blue plane.
  - Has an opacity plane.
  - Uses 32-bit floats for all planes.
  - Describes absolute transparency as an opacity of 0.
  - Describes absolute opacity as an opacity of 1.
  - Does not pre-multiply any plane by the opacity plane.
- No float arguments:
  - Are NaN.
  - Are infinity.
  - Are negative infinity.
  - Cannot be cast to `int` without undefined behavior (for example, very large
    values).

### Blend Modes

| Blend Mode | Color                                           | Opacity                          |
| ---------- | ----------------------------------------------- | -------------------------------- |
| Opaque     | Overwritten.                                    | Overwritten with 1.              |
| Cutout     | Overwritten or unchanged.                       | Overwritten with 1 or unchanged. |
| Additive   | Summed ("linear dodge").                        | Unchanged.                       |
| Blended    | Mixed using opacity.                            | Mixed with opacity.              |

### Functions

| Name              | Type         | Blend Mode |
| ----------------- | ------------ | ---------- |
| `opaque_sprite`   | Draw         | Opaque     |
| `cutout_sprite`   | Draw         | Cutout     |
| `additive_sprite` | Draw         | Additive   |
| `blended_sprite`  | Draw         | Blended    |

## Tests

Execute `make` to run the test suite.

### Dependencies

- Make.
- MinGW-GCC for Windows, Clang for all other platforms.
- Bash.
