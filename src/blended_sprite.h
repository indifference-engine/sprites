#ifndef BLENDED_SPRITE_H

#define BLENDED_SPRITE_H

/**
 * Draws a sprite with blended transparency.
 * @param sprite_rows The height of the sprite in rows.  Behavior is undefined
 *                    if less than 1.
 * @param sprite_columns The width of the sprite in columns.  Behavior is
 *                       undefined if less than 1.
 * @param sprite_opacities The opacity of each pixel within the sprite, row
 *                         major, starting from the top left corner, where 0 is
 *                         fully transparent and 1 is fully opaque.  Behavior
 *                         for values outside this range is undefined.  Behavior
 *                         is undefined if NaN, infinity or negative infinity.
 * @param sprite_reds The intensity of the red channel of each pixel within the
 *                    sprite, row-major, starting from the top left corner.
 *                    Behavior is undefined if any are NaN, infinity, negative
 *                    infinity or unable to be cast to int.
 * @param sprite_greens The intensity of the green channel of each pixel within
 *                      the sprite, row-major, starting from the top left
 *                      corner.  Behavior is undefined if any are NaN, infinity,
 *                      negative infinity or unable to be cast to int.
 * @param sprite_blues The intensity of the blue channel of each pixel within
 *                     the sprite, row-major, starting from the top left corner.
 *                     Behavior is undefined if any are NaN, infinity,  negative
 *                     infinity or unable to be cast to int.
 * @param opacity The opacity of the sprite, where 0 is fully transparent and 1
 *                is fully opaque.  Behavior for values outside this range is
 *                undefined.  Behavior is undefined if NaN, infinity or negative
 *                infinity.
 * @param red The intensity of the red channel of the sprite.  Behavior is
 *            undefined if NaN, infinity, negative infinity or unable to be cast
 *            to int.
 * @param green The intensity of the green channel of the sprite.  Behavior is
 *              undefined if NaN, infinity, negative infinity or unable to be
 *              cast to int.
 * @param blue The intensity of the blue channel of the sprite.  Behavior is
 *             undefined if NaN, infinity, negative infinity or unable to be
 *             cast to int.
 * @param row The number of rows between the top of the viewport and the sprite.
 * @param column The number of columns between the left of the viewport and the
 *               sprite.
 * @param viewport_rows The height of the viewport, in rows.  Behavior is
 *                      undefined if less than 1.
 * @param viewport_columns The width of the viewport, in columns.  Behavior is
 *                         undefined if less than 1.
 * @param viewport_opacities The opacity of each pixel within the viewport,
 *                           row-major, starting from the top left corner, where
 *                           0 is fully transparent and 1 is fully opaque.
 *                           Behavior is undefined for values outside this
 *                           range, NaN, infinity or positive infinity.
 * @param viewport_reds The intensity of the red channel of each pixel within
 *                      the viewport, row-major, starting from the top left
 *                      corner.  Behavior is undefined if any are NaN, infinity,
 *                      negative infinity or unable to be cast to int.
 * @param viewport_greens The intensity of the red channel of each pixel within
 *                        the viewport, row-major, starting from the top left
 *                        corner.  Behavior is undefined if any are NaN,
 *                        infinity, negative infinity or unable to be cast to
 *                        int.
 * @param viewport_blues The intensity of the blue channel of each pixel within
 *                       the viewport, row-major, starting from the top left
 *                       corner.  Behavior is undefined if any are NaN,
 *                       infinity, negative infinity or unable to be cast to
 *                       int.
 */
void blended_sprite(
    const int sprite_rows,
    const int sprite_columns,
    const float *const sprite_opacities,
    const float *const sprite_reds,
    const float *const sprite_greens,
    const float *const sprite_blues,
    const float opacity,
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
    float *const viewport_blues);

#endif
