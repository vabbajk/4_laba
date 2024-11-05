#include "Header.h"

void calculate(int matrix[100][100], int n, int m)
{

	int mn = 1e9;

	for(int i = n/2; i<n; i++)
	{
		for (int j = 0; j < m / 2; j++)
		{
			if (matrix[i][j] % 2 == 0 && matrix[i][j] < mn) { mn = matrix[i][j]; }
		}
	}
	

	printf("����������� ������� 3-�� �������� ����� %d", mn);
}


void solution()
{
	int matrix[100][100], i, j, k, size, n = 0, m = 0, r = 0;

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	do
	{

		n = m = r = 0;

		printf("����������, ������� ���������� ����� � ������� : ");
		Input_one_digit(&n);
		while (n < 1 || n > 100) { printf("�������, ����, ������ ����� ������ 1 ��� ��� ������� :");  Input_one_digit(&n); }


		printf("����������, ������� ���������� �������� � ������� : ");
		Input_one_digit(&m);
		while (m < 1 || m > 100) { printf("�������, ����, ������ ����� ������ 1 ��� ��� ������� :"); Input_one_digit(&m); }


		printf("\n�������� ����� ���������� �������\n(1 - ������ ����, 2 - ���������� ���������) : ");
		Input_one_digit(&r);
		while (r < 1 || r > 2) { printf("�������, ����, ������ ����� (1 �� ��) :"); Input_one_digit(&r); }


		if (r == 1)
		{
			printf("\n������� ���� ������� : \n\n");

			Input_matrix(&matrix, n, m);

		}
		else
		{
			Generate_matrix(&matrix, n, m);

			printf("\n��� �������� �������������� ������� : \n\n");


			Print_matrix(matrix, n, m);

			printf("\n\n");
		}

		calculate(&matrix, n, m);

		printf("\n\n������� ����������? (1 - ��, 2 - ���) : ");

		Input_one_digit(&r);
		while (r < 1 || r > 2) { printf("�������, ����, ������ ����� (1 �� 2) :"); Input_one_digit(&r); }

	} while (!(r - 1));


}

int main()
{
	solution();
	return 0;
}