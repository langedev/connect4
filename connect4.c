#include "connect4.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct Board *make_board(size_t height, size_t width) 
{
  struct Board *new_board = malloc(sizeof(*new_board));
  if (!new_board)
    return NULL;
  new_board->tilemap = calloc(height*width, sizeof(*(new_board->tilemap)));
  if (!new_board->tilemap)
    goto out_tilemap;
  new_board->tile_heights = calloc(width, sizeof(*(new_board->tile_heights)));
  if (!new_board->tile_heights)
    goto out_tile_heights;
  
  new_board->height = height;
  new_board->width = width;
  new_board->next_player = RED;

  return new_board;

out_tile_heights:
  free(new_board->tilemap);
out_tilemap:
  free(new_board);
  return NULL;
}

int drop_tile(struct Board *board, size_t drop_pos) {
  return 0;
}

void print_board(struct Board *board) {
  for (int j = 0; j < board->height; j++) {
    for (int i = 0; i < board->width; i++) {
      printf("%d", IDX(i, j, board));
    }
    printf("\n");
  }

}
