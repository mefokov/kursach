
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
	printf("���������� ��� ������ ������������� ������ � �����.\n");
	printf("���� ������ ������ ������� �������, ������� 1, ���� ������ ������������� ��������, ������� 2: ");
	int size;
	int menu;
	scanf("%d", &menu); // ���������� ��� ������ ����������� �������
	printf("������� ����������� �������: ");
	scanf("%d", &size); // ����������� �������
	int **G;
	G = (int**)malloc(size * sizeof(int*)); //��������� ������ ��� �������
	for (int i = 0; i < size; i++)
	{
		G[i] = (int*)malloc(size * sizeof(int));
	}
	float n; // ���������� ���-�� ������
	float ver; // ���������� ����������� ��������� ����

	if (menu == 2) {
		printf("������� ����������� ��������� 0: ");
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
				G[j][i] = G[i][j]; //������� ��������� 
				G[i][i] = 0;
			}
		}
	}
	else
	{
		printf("������� �������.\n");
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
	printf("������������� �������: ");
	for (int i = 0; i < size; i++)
	{
		int kol = 0; //���������� ��� �������� ������������� �������
		for (int j = 0; j < size; j++)
		{

			if (G[i][j] == 1) kol++;
		}
		if (kol == 0) {
			printf("%d ", i);
			num++; // ������� ������������� ������
		}
	}
	printf("\n");
	printf("���������� ������������� ������: %d", num);

	for (int i = 0; i < size; i++)
		free(G[i]);
	free(G);
	getchar();
	}
