#include "Header.h"

int find_sum(int matrix[100][100], int n, int m)
{

	int f_sum = 0, t_sum = 0;
	for (int i = 0; i < m; i++)
	{
		t_sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (matrix[j][i] > -1) { t_sum += matrix[j][i]; }
			else { t_sum = 0; break; }
		}

		f_sum += t_sum;
	}

	return f_sum;
}

int find_min(int matrix[100][100], int n, int m)
{
	int mn = 1e9, k = m-1;

	for (int d = 1 - n; d < n; d++) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int j = n - 1 - i + d;
			if (j >= 0 && j < n) {
				sum += abs(matrix[i][j]);
			}
		}
		if (sum < mn) {
			mn = sum;
		}
	}

	return mn;
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
		while(m < 1 || m > 100){ printf("�������, ����, ������ ����� ������ 1 ��� ��� ������� :"); Input_one_digit(&m); }
		

		printf("\n�������� ����� ���������� �������\n(1 - ������ ����, 2 - ���������� ���������) : ");
		Input_one_digit(&r);
		while(r < 1 || r > 2){ printf("�������, ����, ������ ����� (1 �� ��) :"); Input_one_digit(&r); }
		

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

		int sum_1 = find_sum(matrix, n, m);

		printf("\nC���� ��������� � ��� ��������, ������� �� �������� ������������� ��������� = %d\n\n", sum_1);

		int d_min = find_min(matrix, n, m);

		printf("������� ����� ���� ������� ��������� ����������, ������������ �������� ��������� ������� = %d\n\n", d_min);

		printf("������� ����������? (1 - ��, 2 - ���) : ");

		Input_one_digit(&r);
		while (r < 1 || r > 2) { printf("�������, ����, ������ ����� (1 �� 2) :"); Input_one_digit(&r); }

	} while (!(r-1));


}

int main()
{
	solution();
	return 0;
}