#include "connect4.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void drop_series(struct Board *board, int *positions, size_t psize) {
  for(int i = 0; i < psize; i++) {
    drop_tile(board, positions[i]);
  }
}

void test_vertical_win(void)
{
  struct Board *board = make_board(4,4);
  int positions[] = {0, 3, 0, 3, 0, 3};
  drop_series(board, positions, 6);
  int output = drop_tile(board, 0);
  assert(output == 1 && "Vertical Win");
  free_board(board);
}

void test_left_horizontal_win(void)
{
  struct Board *board = make_board(4,4);
  int positions[] = {0, 0, 1, 1, 2, 2};
  drop_series(board, positions, 6);
  int output = drop_tile(board, 3);
  assert(output == 1 && "Left Horizontal Win");
  free_board(board);
}

void test_right_horizontal_win(void)
{
  struct Board *board = make_board(4,4);
  int positions[] = {3, 3, 2, 2, 1, 1};
  drop_series(board, positions, 6);
  int output = drop_tile(board, 0);
  assert(output == 1 && "Right Horizontal Win");
  free_board(board);
}

void test_middle_horizontal_win(void)
{
  struct Board *board = make_board(4,4);
  int positions[] = {3, 3, 2, 2, 0, 0};
  drop_series(board, positions, 6);
  int output = drop_tile(board, 1);
  assert(output == 1 && "Middle Horizontal Win");
  free_board(board);
}

int main(int argc, char *argv[])
{
  test_vertical_win();
  test_left_horizontal_win();
  test_right_horizontal_win();
  test_middle_horizontal_win();

  return EXIT_SUCCESS;
}
