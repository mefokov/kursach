
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <locale>
#include <conio.h> 
#include <malloc.h>


int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	printf("Приложение для поиска изолированных вершин в графе.\n");
	printf("Если хотите ввести матрицу вручную, нажмите 1, если хотите сгенерировать рандомно, нажмите 2: ");
	int size;
	int menu;
	scanf("%d", &menu); // переменная для выбора заполенения массива
	printf("Введите размерность матрицы: ");
	scanf("%d", &size); // размерность массива
	int **G;
	G = (int**)malloc(size * sizeof(int*)); //выделение памяти для массива
	for (int i = 0; i < size; i++)
	{
		G[i] = (int*)malloc(size * sizeof(int));
	}
	float n; // переменная кол-во вершин
	float ver; // переменная вероятности появления нуля

	if (menu == 2) {
		printf("Введите вероятность появление 0: ");
		scanf("%f", &ver);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j <= i; j++) {
				G[i][j] = rand() % 2;
				n = ((float)rand()) / RAND_MAX;
				if (n < ver)
				{
					G[i][j] = 0;
				}
				G[j][i] = G[i][j]; //главная диагональ 
				G[i][i] = 0;
			}
		}
	}
	else
	{
		printf("Вводите матрицу.\n");
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j <size; j++) {
				scanf("%d", &G[i][j]);
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			printf("%3d", G[i][j]);

		}
		printf("\n");
	}

	int num = 0;
	printf("Изолированные вершины: ");
	for (int i = 0; i < size; i++)
	{
		int kol = 0; //переменная для проверки изолированной вершины
		for (int j = 0; j < size; j++)
		{

			if (G[i][j] == 1) kol++;
		}
		if (kol == 0) {
			printf("%d ", i);
			num++; // счетчик изолированных вершин
		}
	}
	printf("\n");
	printf("Количество изолированных вершин: %d", num);

	for (int i = 0; i < size; i++)
		free(G[i]);
	free(G);
	getchar();
	}
