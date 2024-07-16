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

void free_board(struct Board *board)
{
  free(board->tile_heights);
  free(board->tilemap);
  free(board);
}

int check_for_win_horizontal(struct Board *board, size_t pos_i, size_t pos_j)
{
  enum Tile current_player = board->next_player * -1;
  char in_a_row = 1;
  // Right
  size_t npos_i = pos_i + 1;
  while (npos_i < board->width && IDX(npos_i, pos_j, board) == current_player) {
    in_a_row++;
    npos_i++;
    if (in_a_row >= 4)
      return 1;
  }
  // Left
  npos_i = pos_i - 1;
  while (npos_i < board->width && IDX(npos_i, pos_j, board) == current_player) {
    in_a_row++;
    npos_i--;
    if (in_a_row >= 4)
      return 1;
  }
  return 0;
}

int check_for_win_vertical(struct Board *board, size_t pos_i, size_t pos_j)
{
  enum Tile current_player = board->next_player * -1;
  char in_a_row = 1;
  // Down
  size_t npos_j = pos_j + 1;
  while (npos_j < board->height && \
      IDX(pos_i, npos_j, board) == current_player) {
    in_a_row++;
    npos_j++;
    if (in_a_row >= 4)
      return 1;
  }
  return 0;
}

int check_for_win_lr_diagonal(struct Board *board, size_t pos_i, size_t pos_j)
{
  enum Tile current_player = board->next_player * -1;
  char in_a_row = 1;
  // Down-right
  size_t npos_i = pos_i + 1;
  size_t npos_j = pos_j + 1;
  while (npos_i < board->width && npos_j < board->height &&
      IDX(npos_i, npos_j, board) == current_player) {
    in_a_row++;
    npos_i++;
    npos_j++;
    if (in_a_row >= 4)
      return 1;
  }
  // Up-left
  npos_i = pos_i - 1;
  npos_j = pos_j - 1;
  while (npos_i < board->width && npos_j < board->height &&
      IDX(npos_i, npos_j, board) == current_player) {
    in_a_row++;
    npos_i--;
    npos_j--;
    if (in_a_row >= 4)
      return 1;
  }

  return 0;
}

int check_for_win_rl_diagonal(struct Board *board, size_t pos_i, size_t pos_j)
{
  enum Tile current_player = board->next_player * -1;
  char in_a_row = 1;
  // Down-left
  size_t npos_i = pos_i - 1;
  size_t npos_j = pos_j + 1;
  while (npos_i < board->width && npos_j < board->height &&
      IDX(npos_i, npos_j, board) == current_player) {
    in_a_row++;
    npos_i--;
    npos_j++;
    if (in_a_row >= 4)
      return 1;
  }
  // Up-right
  npos_i = pos_i + 1;
  npos_j = pos_j - 1;
  while (npos_i < board->width && npos_j < board->height &&
      IDX(npos_i, npos_j, board) == current_player) {
    in_a_row++;
    npos_i++;
    npos_j--;
    if (in_a_row >= 4)
      return 1;
  }

  return 0;
}

int check_for_win(struct Board *board, size_t pos_i, size_t pos_j)
{
  if (check_for_win_horizontal(board, pos_i, pos_j))
      return 1;
  if (check_for_win_vertical(board, pos_i, pos_j))
      return 1;
  if (check_for_win_lr_diagonal(board, pos_i, pos_j))
      return 1;
  if (check_for_win_rl_diagonal(board, pos_i, pos_j))
      return 1;
  return 0;
}

int drop_tile(struct Board *board, size_t drop_pos)
{
  if (drop_pos >= board->width)
    return -1;

  size_t tower_height = board->height-board->tile_heights[drop_pos]-1;

  if (tower_height > board->height)
    return -1;

  IDX(drop_pos, tower_height, board) = board->next_player;

  board->tile_heights[drop_pos]++;
  board->next_player *= -1;

  return check_for_win(board, drop_pos, tower_height);
}

void print_board(struct Board *board)
{
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
