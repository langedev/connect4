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
  if (drop_pos >= board->width)
    return -1;

  size_t tower_height = board->height-board->tile_heights[drop_pos]-1;

  if (tower_height < 0)
    return -1;
  
  IDX(drop_pos, tower_height, board) = board->next_player;

  board->tile_heights[drop_pos]++;
  board->next_player *= -1;

  // Check if player won in separate function

  return 0;
}

void print_board(struct Board *board) {
  for (int j = 0; j < board->height; j++) {
    printf("|");
    for (int i = 0; i < board->width; i++) {
      switch (IDX(i,j,board)) {
      case BLACK:
        printf("\033[90m");
        break;
      case RED:
        printf("\033[31m");
        break;
      case EMPTY:
        printf("\033[36m");
      }
      printf("O");
    }
    printf("\033[0m|\n");
  }
  printf("\n");
}
