#include "connect4.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  struct Board *my_board = make_board(6, 7);
  while (1) {
    print_board(my_board);
    int drop_spot = 0;
    printf("Where to drop? ");
    scanf("%d",&drop_spot);
    drop_tile(my_board, drop_spot-1);
  }
  return EXIT_SUCCESS;
}
