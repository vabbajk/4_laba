#include "Header.h"

void calculate(int matrix[100][100], int n, int m)
{

	int kol = -1, num = -1;
	for (int i = 0; i < m; i++)
	{
		kol = 0;
		for (int j = 0; j < n; j++)
		{
			if (matrix[j][i] == 0) { kol++; }
			else { break; }
		}

		if (kol == n) { num = i; break; }
	}

	if (num == -1) { printf("\n�������, ��������� ���������� �� ������� ��������� �� ���������(((\n\n"); return; }
	else if (num > n) { printf("\n����� �������, ��������� ���������� �� �����, ��������� ���-�� ����� � �������((( ����� �� ������ %d\n\n", num + 1); return; }
	else { printf("\n����� �������, ��������� ���������� �� ����� = %d\n\n", num + 1);}

	for(int i = 0; i<m; i++)
	{
		matrix[num][i] = matrix[num][i] * -1;
	}

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

		printf("��� ��������������� ������� :\n\n");

		Print_matrix(matrix, n, m);

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