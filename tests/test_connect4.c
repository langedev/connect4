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

void test_ul_diagonal_win(void)
{
  struct Board *board = make_board(4,4);
  /* X    9
   * OX   87
   * OOX  465
   * OXOX 0123
   */
  int positions[] = {0, 1, 2, 3, 0, 2, 1, 1, 0};
  drop_series(board, positions, 9);
  int output = drop_tile(board, 0);
  assert(output == 1 && "Upper Left Diagonal Win");
  free_board(board);
}

void test_ur_diagonal_win(void)
{
  struct Board *board = make_board(4,4);
  /*    X    9
   *   XO   78
   *  XOO  564
   * XOXO 3210
   */
  int positions[] = {3, 2, 1, 0, 3, 1, 2, 2, 3};
  drop_series(board, positions, 9);
  int output = drop_tile(board, 3);
  assert(output == 1 && "Upper Right Diagonal Win");
  free_board(board);
}


void test_lr_diagonal_win(void)
{
  struct Board *board = make_board(4,4);
  /* X    7
   * OX   69
   * OOX  485
   * OXOX 0123
   */
  int positions[] = {0, 1, 2, 3, 0, 2, 0, 0, 1};
  drop_series(board, positions, 9);
  int output = drop_tile(board, 1);
  assert(output == 1 && "Left-Right Middle Diagonal Win");
  free_board(board);
}

void test_rl_diagonal_win(void)
{
  struct Board *board = make_board(4,4);
  /*    X    7
   *   XO   96
   *  XOO  584
   * XOXO 3210
   */
  int positions[] = {3, 2, 1, 0, 3, 1, 3, 3, 2};
  drop_series(board, positions, 9);
  int output = drop_tile(board, 2);
  assert(output == 1 && "Right-Left Middle Diagonal Win");
  free_board(board);
}

void test_br_diagonal_win(void)
{
  struct Board *board = make_board(4,4);
  /* XO   38
   * OXO  27A
   * XXX  159
   * OOOX 046B
   */
  int positions[] = {0, 0, 0, 0, 1, 1, 2, 1, 1, 2, 2};
  drop_series(board, positions, 11);
  int output = drop_tile(board, 3);
  assert(output == 1 && "Bottom-Right Diagonal Win");
  free_board(board);
}

void test_bl_diagonal_win(void)
{
  struct Board *board = make_board(4,4);
  /*   OX   83
   *  OXO  A72
   *  XOO  951
   * XOXO B640
   */
  int positions[] = {3, 3, 3, 3, 2, 2, 3, 2, 2, 1, 1};
  drop_series(board, positions, 11);
  int output = drop_tile(board, 0);
  assert(output == 1 && "Bottom-left Diagonal Win");
  free_board(board);
}

int main(int argc, char *argv[])
{
  test_vertical_win();
  test_left_horizontal_win();
  test_right_horizontal_win();
  test_middle_horizontal_win();
  test_ul_diagonal_win();
  test_bl_diagonal_win();
  test_rl_diagonal_win();
  test_ur_diagonal_win();
  test_br_diagonal_win();
  test_lr_diagonal_win();

  return EXIT_SUCCESS;
}
