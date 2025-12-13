#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int min(int a, int b) {
    return ((a < b)?(a):(b));
}

int _minPathSumHelper(int **grid, uint8_t i, uint8_t j, uint8_t m, uint8_t n) {
    if (i == m - 1 && j == n - 1)
        return grid[i][j];
    else if (i == m - 1) {
        int sum_row = 0;
        for (int k = j; k < n; k++)
            sum_row += grid[i][k];
        return sum_row;
    } else if (j == n - 1) {
        int sum_col = 0;
        for (int k = i; k < m; k++)
            sum_col += grid[k][j];
        return sum_col;
    } else {
        int down = _minPathSumHelper(grid, i + 1, j, m, n);
        int right = _minPathSumHelper(grid, i, j + 1, m, n);
        return grid[i][j] + min(down, right);
    }
}

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int cost = 0;
    cost += _minPathSumHelper(grid, 0, 0, gridSize, *gridColSize);
    return cost;
}

int main(void) {
	int m = 2;
	int n = 3;
	int **mat;
	mat = malloc(m * sizeof(int *));
	if (!mat) {
		perror("Cannot allocate memory");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < m; i++) {
		mat[i] = malloc(n * sizeof(int));
		if (!mat[i]) {
			perror("Cannot allocate memory");
			exit(EXIT_FAILURE);
		}
	}

	for (int i = 0; i < m * n; i++) {
		mat[i / n][i % n] = i + 1;
	}

	printf("minPathSum = %d\n", minPathSum(mat, m, &n));
	return 0;
}
