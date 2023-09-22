/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>


void main() {
    int rows, cols, choice, i, j, choice2;
    int* arr = 0;
    int min, max, index, sum;
    SetConsoleCP(1251);//Установка языка
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    do {
        printf("\tМеню\n");
        printf("1. Просмотреть массив\n");
        printf("2. Найти максимальное и минимальное значение эелемента массива\n");
        printf("3. Посчитать сумму элментов массива в строке или столбце\n");
        printf("4. Создать новый массив\n");
        printf("5. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            if (arr == NULL) {
                printf("Сначала создайте массив!\n");
                break;
            }
            for (i = 0; i < rows; i++) {  // цикл по строкам
                for (j = 0; j < cols; j++) { // цикл по столбцам
                    printf("%5d ", *(arr + i * cols + j)); // вывод элементов массива
                }
                printf("\n");
            }
            break;
        case 2:
            if (arr == NULL) {
                printf("Сначала создайте массив!\n");
                break;
            }
            min = *(arr + 0 * cols + 0);
            max = *(arr + 0 * cols + 0);
            for (i = 0; i < rows; i++) { // цикл по строкам
                for (j = 0; j < cols; j++) { // цикл по столбцам
                    if (*(arr + i * cols + j) < min) {
                        min = *(arr + i * cols + j);
                    }
                    if (*(arr + i * cols + j) > max) {
                        max = *(arr + i * cols + j);
                    }
                }
            }
            printf("Минимальное число: %d\n", min);
            printf("Максимальное число: %d\n", max);
            break;
        case 3:
            if (arr == NULL) {
                printf("Сначала создайте массив!\n");
                break;
            }
            do {
                printf("\n\tМеню\n");
                printf("1. Посчитать сумму в столбце\n");
                printf("2. Посчитать сумму в строке\n");
                printf("3. Вернуться\n");
                printf("Выберите действие: ");
                scanf("%d", &choice2);
                switch (choice2) {
                case 1:
                    sum = 0;
                    printf("Выберите номер стобца: ");
                    scanf("%d", &index);
                    for (i = 0; i < rows; i++) {
                        sum += *(arr + i * cols + index - 1);
                    }
                    printf("\nСумма равна: %d", sum);
                    break;
                case 2: 
                    sum = 0;
                    printf("Выберите номер строки: ");
                    scanf("%d", &index);
                    for (j = 0; j < cols; j++) {
                        sum += *(arr + (index - 1) * cols + j);
                    }
                    printf("\nСумма равна: %d", sum);
                    break;
                case 3: 
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("Некорректный выбор!\n");
                    break;
                }
            } while (choice2 != 3);
            break;
        case 4:
            printf("Введите количество строк: ");
            scanf("%d", &rows);
            printf("Введите количество столбцов: ");
            scanf("%d", &cols);
            arr = (int*)malloc(rows * cols * sizeof(int));
            if (arr == NULL) {
                printf("Не удалось выделить память!\n");
                break;
            }
            for (i = 0; i < rows; i++)  { // цикл по строкам
                for (j = 0; j < cols; j++)  { // цикл по столбцам
                    *(arr + i * cols + j) = rand () % 100;
                }
            }
            printf("Массив создан!\n");
            break;
        case 5:
            system("cls");
            printf("До свидания!\n");
            break;
        default:
            system("cls");
            printf("Некорректный выбор!\n");
            break;
        }
    } while (choice != 5);
}*/