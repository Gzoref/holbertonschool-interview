#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stdio.h>
#include <stdlib.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void _print_grid(int grid[3][3]);
int is_stable(int grid1[3][3]);
void topple(int grid1[3][3], int grid2[3][3]);

#endif /* _SANDPILES_H_ */
