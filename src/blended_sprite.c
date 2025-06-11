#include "blended_sprite.h"

void blended_sprite(const int sprite_rows, const int sprite_columns,
                    const float *const sprite_opacities,
                    const float *const sprite_reds,
                    const float *const sprite_greens,
                    const float *const sprite_blues, const float opacity,
                    const float red, const float green, const float blue,
                    const int row, const int column, const int viewport_rows,
                    const int viewport_columns, float *const viewport_opacities,
                    float *const viewport_reds, float *const viewport_greens,
                    float *const viewport_blues) {
  const int skipped_top_rows = row < 0 ? -row : 0;
  const int skipped_bottom_rows =
      row + sprite_rows > viewport_rows ? row + sprite_rows - viewport_rows : 0;
  const int visible_rows = sprite_rows - skipped_top_rows - skipped_bottom_rows;

  if (visible_rows <= 0) {
    return;
  }

  const int skipped_left_columns = column < 0 ? -column : 0;
  const int skipped_right_columns =
      column + sprite_columns > viewport_columns
          ? column + sprite_columns - viewport_columns
          : 0;
  const int visible_columns =
      sprite_columns - skipped_left_columns - skipped_right_columns;

  if (visible_columns <= 0) {
    return;
  }

  int sprite_index = skipped_top_rows * sprite_columns + skipped_left_columns;
  const int sprite_skip = sprite_columns - visible_columns;
  int viewport_index =
      (row > 0 ? row * viewport_columns : 0) + (column > 0 ? column : 0);
  const int viewport_skip = viewport_columns - visible_columns;

  for (int row = 0; row < visible_rows; row++) {
    for (int column = 0; column < visible_columns; column++) {
      const float source_opacity = sprite_opacities[sprite_index] * opacity;
      const float inverse_source_opacity = 1.0f - source_opacity;
      const float destination_opacity = viewport_opacities[viewport_index];

      const float final_opacity =
          1.0f - inverse_source_opacity * (1.0f - destination_opacity);

      if (final_opacity > 0.0f) {
        viewport_opacities[viewport_index] = final_opacity;

        const float inverse_opacity = 1.0f / final_opacity;
        const float source_coefficient = source_opacity * inverse_opacity;
        const float destination_coefficient =
            destination_opacity * inverse_source_opacity * inverse_opacity;

        const float source_red = red * sprite_reds[sprite_index];
        const float destination_red = viewport_reds[viewport_index];

        viewport_reds[viewport_index] =
            (source_red * source_coefficient +
             destination_red * destination_coefficient);

        const float source_green = green * sprite_greens[sprite_index];
        const float destination_green = viewport_greens[viewport_index];

        viewport_greens[viewport_index] =
            (source_green * source_coefficient +
             destination_green * destination_coefficient);

        const float source_blue = blue * sprite_blues[sprite_index];
        const float destination_blue = viewport_blues[viewport_index];

        viewport_blues[viewport_index] =
            (source_blue * source_coefficient +
             destination_blue * destination_coefficient);
      }

      sprite_index++;
      viewport_index++;
    }

    sprite_index += sprite_skip;
    viewport_index += viewport_skip;
  }
}
