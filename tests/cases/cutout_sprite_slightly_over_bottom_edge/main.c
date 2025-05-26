#include "../../../src/cutout_sprite.h"
#include "../../helpers/main.h"

int main(int argc, char **argv)
{
  (void)(argc);
  (void)(argv);

  float *const sprite_opacities = read_file("inputs/sprite/opacities.data", 10, 8);
  float *const sprite_reds = read_file("inputs/sprite/reds.data", 10, 8);
  float *const sprite_greens = read_file("inputs/sprite/greens.data", 10, 8);
  float *const sprite_blues = read_file("inputs/sprite/blues.data", 10, 8);

  float *const viewport_opacities = read_file("inputs/viewport/opacities.data", 192, 256);
  float *const viewport_reds = read_file("inputs/viewport/reds.data", 192, 256);
  float *const viewport_greens = read_file("inputs/viewport/greens.data", 192, 256);
  float *const viewport_blues = read_file("inputs/viewport/blues.data", 192, 256);

  cutout_sprite(
      10, 8, sprite_opacities, sprite_reds, sprite_greens, sprite_blues,
      0.8f, 0.7f, 0.9f, 0.6f, 183, 120,
      192, 256, viewport_opacities, viewport_reds, viewport_greens, viewport_blues);

  write_file(sprite_opacities, "outputs/actual/sprite/opacities.data", 10, 8);
  write_file(sprite_reds, "outputs/actual/sprite/reds.data", 10, 8);
  write_file(sprite_greens, "outputs/actual/sprite/greens.data", 10, 8);
  write_file(sprite_blues, "outputs/actual/sprite/blues.data", 10, 8);

  write_file(viewport_opacities, "outputs/actual/viewport/opacities.data", 192, 256);
  write_file(viewport_reds, "outputs/actual/viewport/reds.data", 192, 256);
  write_file(viewport_greens, "outputs/actual/viewport/greens.data", 192, 256);
  write_file(viewport_blues, "outputs/actual/viewport/blues.data", 192, 256);

  return 0;
}
