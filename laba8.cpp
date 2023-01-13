#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <queue>

using namespace std;

int** G;
int* vis;
int ver;

void BFS(int v, int n)
{
    queue<int> q; // объявление
    q.push(v); // добавления в очередь вершину
    vis[v] = 1;
    while (!q.empty())
    {
        v = q.front();
        printf(" %d", v);
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (G[v][i] == 1 && vis[i] == 0)
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    int n;
    n = 0;
    int k = 0;

    setlocale(LC_ALL, "RUS");

    printf("Введите размерность матрицы: ");
    scanf_s("%d", &n);

    srand(time(NULL));

    G = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++)
    {
        G[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            G[i][j] = rand() % 2;
            if (i == j)
            {
                G[i][j] = 0;
            }
            G[j][i] = G[i][j];
        }
    }

    printf("\nМатрица смежности:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    vis = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    printf("Введите вершину, с которой нужно начинать обход графа в ширину (0..4): ");
    scanf_s("%d", &ver);

    printf("\nРезультат:  ");

    BFS(ver, n);

    getchar();
    getchar();
}
