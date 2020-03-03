#include "FloodFill.h"

int map[][];
//uint8_t walls; //no good way to represent a nibble
long walls[]; // 1d array of rows; ints are too small, so long is used instead
private static int[] cellMasks = new int[16];           // Wall arrangements
private static long[] posMasks = new long[16];          // Masks for position of cell in long

FloodFill::FloodFill()
{
  map[][]=
  {
    {16, 15, 14, 13, 12, 11, 10, 9, 8, 8, 9, 10, 11, 12, 13, 14, 15, 16},
    {15, 14, 13, 12, 11, 10, 9,  8, 7, 7, 8, 9,  10, 11, 12, 13, 14, 15},
    {14, 13, 12, 11, 10, 9,  8,  7, 6, 6, 7, 8,  9,  10, 11, 12, 13, 14},
    {13, 12, 11, 10, 9,  8,  7,  6, 5, 5, 6, 7,  8,  9,  10, 11, 12, 13},
    {12, 11, 10, 9,  8,  7,  6,  5, 4, 4, 5, 6,  7,  8,  9,  10, 11, 12},
    {11, 10, 9,  8,  7,  6,  5,  4, 3, 3, 4, 5,  6,  7,  8,  9,  10, 11},
    {10, 9,  8,  7,  6,  5,  4,  3, 2, 2, 3, 4,  5,  6,  7,  8,  9,  10},
    {9,  8,  7,  6,  5,  4,  3,  2, 1, 1, 2, 3,  4,  5,  6,  7,  8,  9},
    {8,  7,  6,  5,  4,  3,  2,  1, 0, 0, 1, 2,  3,  4,  5,  6,  7,  8},
    {8,  7,  6,  5,  4,  3,  2,  1, 0, 0, 1, 2,  3,  4,  5,  6,  7,  8},
    {9,  8,  7,  6,  5,  4,  3,  2, 1, 1, 2, 3,  4,  5,  6,  7,  8,  9},
    {10, 9,  8,  7,  6,  5,  4,  3, 2, 2, 3, 4,  5,  6,  7,  8,  9,  10},
    {11, 10, 9,  8,  7,  6,  5,  4, 3, 3, 4, 5,  6,  7,  8,  9,  10, 11},
    {12, 11, 10, 9,  8,  7,  6,  5, 4, 4, 5, 6,  7,  8,  9,  10, 11, 12},
    {13, 12, 11, 10, 9,  8,  7,  6, 5, 5, 6, 7,  8,  9,  10, 11, 12, 13},
    {14, 13, 12, 11, 10, 9,  8,  7, 6, 6, 7, 8,  9,  10, 11, 12, 13, 14},
    {15, 14, 13, 12, 11, 10, 9,  8, 7, 7, 8, 9,  10, 11, 12, 13, 14, 15},
    {16, 15, 14, 13, 12, 11, 10, 9, 8, 8, 9, 10, 11, 12, 13, 14, 15, 16}
  }

  //walls[]=//0b;
}

uint8_t FloodFill::detectwall(int x, int y)
{
  return {false, false, false, false};
}

void update(int x, int y, uint8_t walls)
{
  //uhhhhhh
}

// 0bNESW
// 0 = wall, 1 = open space
void initializewalls() {
  // First row
  walls[0] = 0b0110;                                  // First cell in first row
  for(int i = 1; i < 15; i++) {                       // Cells 1-14 in first row
      walls[0] = (walls[0] << 4) | 0b0111;
  }
  walls[0] = (walls[0] << 4) | 0b0011;                // Last cell in first row

  // Rows 1 - 14
  for(int i = 1; i < 15; i++) {
      walls[i] = 0b1110;                              // First cell in row i
      for(int j = 1; j < 15; j++) {                   // Cells 1 - 14 in row i
          walls[i] = (walls[i] << 4) | 0b1111;
      }
      walls[i] = (walls[i] << 4) | 0b1011;            // Last cell in row i
  }

  // Last row
  walls[15] = 0b1100;                                 // First cell in last row
  for(int i = 1; i < 15; i++) {                       // Cells 1-14 in last row
      walls[15] = (walls[15] << 4) | 0b1101;
  }
  walls[15] = (walls[15] << 4) | 0b1001;              // Last cell in last row
}

void initializeMasks() {
  cellMasks[0]  = 0b0000; // All walls
  cellMasks[1]  = 0b0001; // W
  cellMasks[2]  = 0b0010; // E
  cellMasks[3]  = 0b0011; // EW
  cellMasks[4]  = 0b0100; // S
  cellMasks[5]  = 0b0101; // SW
  cellMasks[6]  = 0b0110; // ES
  cellMasks[7]  = 0b0111; // ESW
  cellMasks[8]  = 0b1000; // N
  cellMasks[9]  = 0b1001; // NW
  cellMasks[10] = 0b1010; // NE
  cellMasks[11] = 0b1011; // NEW
  cellMasks[12] = 0b1100; // NS
  cellMasks[13] = 0b1101; // NSW
  cellMasks[14] = 0b1110; // NSE
  cellMasks[15] = 0b1111; // NSEW - all open

  for(int i = 0; i < 16; i++) {
      posMasks[i] = ~(0b1111 << (4*i));
  }
}

void updateWall(int row, int col, int maskID) {
  walls[row] = walls[row] & posMasks[maskID] | cellMasks[maskID] << ((15-col)*4);
  // AND row with posMask (0 out values at cell location)
  // OR changed row with cellMask (new value of cell)
}

