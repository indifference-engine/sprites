#include "opaque_sprite.h"

void opaque_sprite(
    const int sprite_rows,
    const int sprite_columns,
    const float *const sprite_reds,
    const float *const sprite_greens,
    const float *const sprite_blues,
    const float red,
    const float green,
    const float blue,
    const int row,
    const int column,
    const int viewport_rows,
    const int viewport_columns,
    float *const viewport_opacities,
    float *const viewport_reds,
    float *const viewport_greens,
    float *const viewport_blues)
{
  const int skipped_top_rows = row < 0 ? -row : 0;
  const int skipped_bottom_rows = row + sprite_rows > viewport_rows ? row + sprite_rows - viewport_rows : 0;
  const int visible_rows = sprite_rows - skipped_top_rows - skipped_bottom_rows;

  if (visible_rows <= 0)
  {
    return;
  }

  const int skipped_left_columns = column < 0 ? -column : 0;
  const int skipped_right_columns = column + sprite_columns > viewport_columns ? column + sprite_columns - viewport_columns : 0;
  const int visible_columns = sprite_columns - skipped_left_columns - skipped_right_columns;

  if (visible_columns <= 0)
  {
    return;
  }

  int sprite_index = skipped_top_rows * sprite_columns + skipped_left_columns;
  const int sprite_skip = sprite_columns - visible_columns;
  int viewport_index = (row > 0 ? row * viewport_columns : 0) + (column > 0 ? column : 0);
  const int viewport_skip = viewport_columns - visible_columns;

  for (int row = 0; row < visible_rows; row++)
  {
    for (int column = 0; column < visible_columns; column++)
    {
      viewport_opacities[viewport_index] = 1.0f;
      viewport_reds[viewport_index] = sprite_reds[sprite_index] * red;
      viewport_greens[viewport_index] = sprite_greens[sprite_index] * green;
      viewport_blues[viewport_index] = sprite_blues[sprite_index] * blue;

      sprite_index++;
      viewport_index++;
    }

    sprite_index += sprite_skip;
    viewport_index += viewport_skip;
  }
}
