/*对一个二维数组，写一个函数，计算数组的总和，某一列的总和，某一行的总和*/
#include <stdio.h>
#define ROWS 3
#define COLS 4
int sum(int ar[][COLS], int cols);

int main(void) {
  int ar[3][4] = {{23, 12, 65, 21}, {55, 21, 27, 35}, {25, 41, 34, 12}};
  printf("%d", sum(ar, COLS));
}

int sum(int ar[][COLS], int cols) {
  int i, j;
  int rowSUM = 0;
  for (i = 0; i < ROWS; i++) {
    rowSUM += ar[i][0];
  }
}