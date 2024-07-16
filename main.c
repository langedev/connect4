#include "connect4.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  struct Board *my_board = make_board(6, 7);
  int drop_spot = 0;
  do {
    print_board(my_board);
    printf("Where to drop? ");
    scanf("%d",&drop_spot);
  } while (!drop_tile(my_board, drop_spot-1));
  print_board(my_board);
  printf("Congratulations!");
  return EXIT_SUCCESS;
}
