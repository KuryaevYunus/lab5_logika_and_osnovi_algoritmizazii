#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    srand(time(NULL));
    int N;
    int s = 0;
    printf("Количество вершин: ");
    scanf("%d", &N);
    int CountOfVertex = N;
    int *d = new int[N];
    int **Arr = new int *[N];

    for (int i = 0; i < N; i++) {
        Arr[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < CountOfVertex; j++) {
            if (i == j) {
                Arr[i][j] = 0;
            } else if (i != j) {
                Arr[i][j] = rand() % 3;
                Arr[j][i] = Arr[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < CountOfVertex; j++) {
            if (Arr[i][j] != 0) {
                s = s + 1;
            }
            printf("%d ", Arr[i][j]);
        }
        d[i] = s;
        s = 0;
        printf("\n");
    }
    printf("\n");

    for (int i = 0; i < N; i++) {
        if (d[i] == 0) {
            printf("Изолированная вершина: %d\n", i + 1);
        }
        if (d[i] == 1) {
            printf("Концевая вершина: %d\n", i + 1);
        }
        if (d[i] == N - 1) {
            printf("Доминирующая вершина: %d\n", i + 1);
        }
    }

    int kol;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < CountOfVertex; j++) {
            if (Arr[i][j] != 0) {
                kol++;
            }
        }
    }
    printf("Степень графа: %d", kol);

}