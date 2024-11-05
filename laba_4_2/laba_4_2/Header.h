#pragma once
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <math.h>





void Input_one_digit(int* ptr)
{

	char c[100];
	short isnt_correct = 0;

	do {
		isnt_correct = 0;
		fgets(c, sizeof(c), stdin);

		if (c[0] < '0' || c[0] > '9') {
			if (c[0] != '-') {
				isnt_correct = 1;
			}
		}

		for (int i = 1; c[i] != '\n'; i++)
		{
			if (c[i] < '0' || c[i] > '9') {
				isnt_correct = 1;
				break;
			}
		}

		if (!isnt_correct)
		{
			if (sscanf_s(c, "%d", ptr) == 1)
			{
				return;
			}
			else { printf("Введите одно число! - "); }
		}
		else { printf("Введите корректное значение! : "); }

	} while (isnt_correct);

	return;
}

void Input_one_digit_in_string(char* ptr)
{

	char c[33];
	short isnt_correct = 0;

	do {

		isnt_correct = 0;
		fgets(c, sizeof(c), stdin);

		if (c[0] < '0' || c[0] > '9') {
			if (c[0] != '-') {
				isnt_correct = 1;
			}
		}

		for (int i = 1; c[i] != '\n'; i++)
		{
			if (c[i] < '0' || c[i] > '9') {
				isnt_correct = 1;
				break;
			}
		}

		if (!isnt_correct)
		{
			for (int i = 0; c[i - 1] != '\n'; i++)
			{
				ptr[i] = c[i];
			}
		}
		else { printf("Введите корректное значение! : "); while (getchar() != '\n') {} }

	} while (isnt_correct);

	return;
}

void Input_matrix(int matrix[100][100], int n, int m)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int j, kol = 0, isnt_correct = 0, d = 0;
	for (int i = 0; i < n; i++)
	{
		do
		{

			j = -1;
			kol = isnt_correct = 0;

			char c[3000], temp[10];

			for (int k = 0; k < 10; k++) { temp[k] = ' '; d = 0; }

			if (!fgets(c, sizeof(c), stdin)) {
				printf("Ошибка при вводе строки.\n");
				isnt_correct = 1;
				continue;
			}

			while (c[++j] != '\n')
			{

				if (c[j] > '9' || c[j] < '0')
				{
					if ((c[j] == '-'))
					{
						if (d == 0)
						{
							temp[d++] = c[j];
						}
						else
						{
							printf("Вы допустили ошибку при вводе строки матрицы!!! Даю вам еще один шанс) \n");
							isnt_correct = 1;
							break;
						}
					}
					else if (c[j] != ' ')
					{

						printf("Вы допустили ошибку при вводе строки матрицы!!! Даю вам еще один шанс) \n");
						isnt_correct = 1;
						break;
					}
					else
					{

						sscanf_s(temp, "%d", &matrix[i][kol]);

						kol++;

						for (int k = 0; k < 10; k++) { temp[k] = ' '; d = 0; }
					}
				}
				else
				{
					temp[d++] = c[j];
				}
			}
			
			if(!isnt_correct)
			if (c[j] > '9' || c[j] < '0')
			{
				if (c[j] != '\n')
				{

					printf("Вы допустили ошибку при вводе строки матрицы!!! Даю вам еще один шанс) \n");
					isnt_correct = 1;
					break;
				}
				else
				{

					sscanf_s(temp, "%d", &matrix[i][kol]);

					kol++;

					for (int k = 0; k < 10; k++) { temp[k] = ' '; d = 0; }
				}
			}
		} while (isnt_correct);
	}
}

void Generate_matrix(int matrix[100][100], int n, int m)
{
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{

		int znak = 0;


		for (int j = 0; j < m; j++)
		{
			znak = rand() % 3;

			znak = znak == 0 ? -1 : 1;

			(matrix[i][j]) = (rand() % 50) * znak;
		}
	}
}

void Print_matrix(int matrix[100][100], int n, int m)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", matrix[i][j]);
			//printf("%d ", i * (*m) + j);
		}
		printf("\n");
	}
}

void Input_one_double(double* ptr)
{

	char c[100];
	short isnt_correct = 0;

	do {
		isnt_correct = 0;
		fgets(c, sizeof(c), stdin);

		if (c[0] < '0' || c[0] > '9') {
			if (c[0] != '-') {
				isnt_correct = 1;
				break;
			}
		}

		int has_point = 0;

		for (int i = 1; c[i] != '\n'; i++)
		{
			if (c[i] < '0' || c[i] > '9')
			{
				if (c[i] == '.') { has_point++; }
				else
				{
					isnt_correct = 1;
					break;
				}

			}

		}

		if (!isnt_correct && has_point < 2)
		{
			if (sscanf_s(c, "%lf", ptr) == 1)
			{
				return;
			}
			else { printf("Введите одно число! : "); }
		}
		else { printf("Введите корректное значение! : "); }

	} while (isnt_correct);

	return;
}

void Input_double_array_by_hand(double* ptr, int* size)
{
	int b = 0;
	for (int i = 0; i < *size; i++)
	{
		printf("Введите элемент %d : ", i + 1);
		Input_one_double(&ptr[i]);
	}
	return;
}

void Input_double_array_rand(double* ptr, int* size)
{
	int znak = 0;

	srand(time(NULL));

	for (int i = 0; i < *size; i++)
	{
		znak = rand() % 3;

		znak = znak == 0 ? -1 : 1;

		ptr[i] = (double)((rand() % 50) * znak);
	}
	return;
}

void Input_int_array_by_hand(int* ptr, int* size)
{
	int b = 0;
	for (int i = 0; i < *size; i++)
	{
		printf("Введите элемент %d : ", i + 1);
		Input_one_digit(&ptr[i]);
	}
	return;
}

void Input_int_array_rand(int* ptr, int* size)
{
	int znak = 0;


	DWORD milliseconds = GetTickCount();

	srand(milliseconds);

	for (int i = 0; i < *size; i++)
	{


		znak = rand() % 3;

		znak = znak == 0 ? -1 : 1;

		ptr[i] = ((rand() % 50) * znak);
	}
	return;
}
