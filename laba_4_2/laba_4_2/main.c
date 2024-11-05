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

	if (num == -1) { printf("\nСтолбца, полностью состоящего из нулевых элементов не существут(((\n\n"); return; }
	else if (num > n) { printf("\nНомер столбца, полностью состоящего из нулей, превышает кол-во строк в матрице((( Равен он кстати %d\n\n", num + 1); return; }
	else { printf("\nНомер столбца, полностью состоящего из нулей = %d\n\n", num + 1);}

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

		printf("Пожалуйста, введите количество строк в массиве : ");
		Input_one_digit(&n);
		while (n < 1 || n > 100) { printf("АШЫБПКА, ПЛИЗ, ИНСЕРТ ВАЛУЕ БЕТВИН 1 ЭНД ВАН ХАНГРЕД :");  Input_one_digit(&n); }


		printf("Пожалуйста, введите количество столбцов в массиве : ");
		Input_one_digit(&m);
		while (m < 1 || m > 100) { printf("АШЫБПКА, ПЛИЗ, ИНСЕРТ ВАЛУЕ БЕТВИН 1 ЭНД ВАН ХАНГРЕД :"); Input_one_digit(&m); }


		printf("\nВыберите режим заполнения матрицы\n(1 - Ручной ввод, 2 - рандомнапя генерация) : ");
		Input_one_digit(&r);
		while (r < 1 || r > 2) { printf("АШЫБПКА, ПЛИЗ, ИНСЕРТ ВАЛУЕ (1 ОР ТУ) :"); Input_one_digit(&r); }


		if (r == 1)
		{
			printf("\nВведите свою матрицу : \n\n");

			Input_matrix(&matrix, n, m);

		}
		else
		{
			Generate_matrix(&matrix, n, m);

			printf("\nВот случайно сгенерирования матрица : \n\n");


			Print_matrix(matrix, n, m);

			printf("\n\n");
		}

		calculate(&matrix, n, m);

		printf("Вот преобразованная матрица :\n\n");

		Print_matrix(matrix, n, m);

		printf("\n\nЖелаете продолжить? (1 - да, 2 - нет) : ");

		Input_one_digit(&r);
		while (r < 1 || r > 2) { printf("АШЫБПКА, ПЛИЗ, ИНСЕРТ ВАЛУЕ (1 ОР 2) :"); Input_one_digit(&r); }

	} while (!(r - 1));


}

int main()
{
	solution();
	return 0;
}