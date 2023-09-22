//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <locale.h>
//
//int main() {
//
//	setvbuf(stdin, NULL, _IONBF, 0);
//	setvbuf(stdout, NULL, _IONBF, 0);
//	setlocale(LC_ALL, "RUS");
//	clock_t start, end; // объявляем переменные для определения времени выполнения
//	int** arr = 0;
//	int** brr = 0;
//	int** crr = 0;
//	int i = 0, j = 0, r, rows, cols, p;
//	int elem_c;
//	double time_spent = 0.0;
//
//	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
//	for (p = 0; p < 7; p++) {
//		printf("Введите размер  массива для %d итерации:\n", p);
//		printf("Введите размерномть массива: ");
//		scanf("%d", &rows);
//		arr = (int**)malloc(rows * sizeof(int*));
//		brr = (int**)malloc(rows * sizeof(int*));
//		crr = (int**)malloc(rows * sizeof(int*));
//		if (arr == NULL) {
//			printf("Не удалось выделить память!\n");
//			return (0);
//		}
//		for (i = 0; i < rows; i++) {
//			arr[i] = (int*)malloc(rows * sizeof(int));
//		}if (brr == NULL) {
//			printf("Не удалось выделить память!\n");
//			return (0);
//		}
//		for (i = 0; i < rows; i++) {
//			brr[i] = (int*)malloc(rows * sizeof(int));
//		}if (crr == NULL) {
//			printf("Не удалось выделить память!\n");
//			return (0);
//		}
//		for (i = 0; i < rows; i++) {
//			crr[i] = (int*)malloc(rows * sizeof(int));
//		}
//		i = 0; j = 0;
//		for (i = 0; i < rows; i++)
//		{
//			for (j = 0; j < rows; j++)
//			{
//				arr[i][j] = rand() % 100; // заполняем массив случайными числами
//			}
//		}
//		i = 0; j = 0;
//		for (i = 0; i < rows; i++)
//		{
//			for (j = 0; j < rows; j++)
//			{
//				brr[i][j] = rand() % 100; // заполняем массив случайными числами
//			}
//		}
//		start = clock();
//		for (i = 0; i < rows; i++)
//		{
//			for (j = 0; j < rows; j++)
//			{
//				elem_c = 0;
//				for (r = 0; r < rows; r++)
//				{
//					elem_c = elem_c + arr[i][r] * brr[r][j];
//					crr[i][j] = elem_c;
//				}
//			}
//		}
//		end = clock();
//		time_spent = (double)(end - start) / CLOCKS_PER_SEC;
//		printf("%f\n", time_spent);
//	}
//	return (0);
//}
