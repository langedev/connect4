#ifndef CONNECT4_H_
#define CONNECT4_H_

#include <stddef.h>

enum Tile {
  BLACK = -1,
  EMPTY = 0,
  RED = 1,
};

struct Board {
  size_t height;
  size_t width;
  size_t *tile_heights;
  enum Tile *tilemap;
  enum Tile next_player;
};

#define IDX(i, j, board) (board->tilemap[j*(board->width) + i])

// Returns a board struct with height and width based on parameters
struct Board *make_board(size_t height, size_t width);

void free_board(struct Board *board);

// Drops a tile, returns 0 if successful, -1 if error, and 1 if the move won
int drop_tile(struct Board *board, size_t drop_pos);

// Prints the supplied board
void print_board(struct Board *board);

#endif // !CONNECT4_H_
