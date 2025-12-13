#include <stdio.h>
#include <stdlib.h>

void print_arr(int n, int a[]) {
	putchar('[');
	for (int i = 0; i < n-1; i++)
		printf("%d, ", a[i]);
	printf("%d]\n", a[n-1]);
}

int* spiralOrder(int** matrix, int m, int* n) {
    int *arr = malloc(m * (*n) * sizeof(int));
    int rowFirst = 0, colFirst = -1, rowLast = m, colLast = *n;
    register int i = 0, j = 0;
    int size = 0;

    while (size < m * *n) {
        while (j < colLast)
            arr[size++] = matrix[i][j++];
        ++i; j = --colLast;
        while (i < rowLast)
            arr[size++] = matrix[i++][j];
        --j; i = --rowLast;
        while (j > colFirst)
            arr[size++] = matrix[i][j--];
        --i; j = ++colFirst;
        while (i > rowFirst)
            arr[size++] = matrix[i--][j];
        ++j; i = ++rowFirst;
    }
    return arr;
}

int main(void)
{
	int m = 3, n = 4;
	int **matrix = (int **) malloc(m * sizeof(int *));
	for (int i = 0; i < m; i++) {
		matrix[i] = (int *) malloc(n * sizeof(int));
	}
	for (int i = 0; i < m * n; i++) {
		matrix[i / n][i % n] = i + 1;
	}

	int *a = spiralOrder(matrix, m, &n);
	printf("The array after performing the operation is: "); print_arr(m * n, a);
	free(a);
	for (int i = 0; i < m; i++)
		free(matrix[i]);
	free(matrix);
	return 0;
}
