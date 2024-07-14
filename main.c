#include "connect4.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  struct Board *my_board = make_board(6, 7);
  print_board(my_board);
  return EXIT_SUCCESS;
}
