#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

void shell(int* items, int count)
{

    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;

    i = left; j = right;

    // выбор компаранда 
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}

void voz(int* arr, int size) {
    arr[0] = rand() % 100;
    for (int i = 1; i < size; i++) {
        arr[i] = arr[i - 1] + rand() % 100;
    }
}

void yb(int* arr, int size) {
    arr[size - 1] = rand() % 100;
    for (int i = size - 2; i >= 0; i--) {
        arr[i] = arr[i + 1] + rand() % 100;
    }
}

void vozyb(int* arr, int size_2, int size) {
    arr[0] = rand() % 100;
    size_2 = size / 2;
    for (int i = 1; i < size_2; i++) {
        arr[i] = arr[i - 1] + rand() % 100;
    }
    arr[size - 1] = rand() % 100;
    for (int i = size - 2; i >= size_2; i--) {
        arr[i] = arr[i + 1] + rand() % 100;
    }
}

void ran(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

int comp(const void* x, const void* y) {
    return (*(int*)x - *(int*)y);
}

void main() {
	setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int size, i, choice, size_2;
    clock_t start, end;
    double time_spent_1 = 0.0, time_spent_2 = 0.0, time_spent_3 = 0.0, time_spent_4 = 0.0, time_spent_5 = 0.0,
        time_spent_6 = 0.0, time_spent_7 = 0.0, time_spent_8 = 0.0, time_spent_9 = 0.0, time_spent_10 = 0.0,
        time_spent_11 = 0.0, time_spent_12 = 0.0;
    int* arr = 0;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Не удалось выделить память!\n");
        return;
    }
    size_2 = size / 2;

    yb(arr, size);
    start = clock();
    qs(arr, 0, size - 1);
    end = clock();
    time_spent_1 = (double)(end - start) / CLOCKS_PER_SEC;
    yb(arr, size);
    start = clock();
    shell(arr, size);
    end = clock();
    time_spent_2 = (double)(end - start) / CLOCKS_PER_SEC;
    yb(arr, size);
    start = clock();
    qsort(arr, size, sizeof(int), comp);
    end = clock();
    time_spent_3 = (double)(end - start) / CLOCKS_PER_SEC;

    voz(arr, size);
    start = clock();
    qs(arr, 0, size - 1);
    end = clock();
    time_spent_4 = (double)(end - start) / CLOCKS_PER_SEC;
    voz(arr, size);
    start = clock();
    shell(arr, size);
    end = clock();
    time_spent_5 = (double)(end - start) / CLOCKS_PER_SEC;
    voz(arr, size);
    start = clock();
    qsort(arr, size, sizeof(int), comp);
    end = clock();
    time_spent_6 = (double)(end - start) / CLOCKS_PER_SEC;

    vozyb(arr, size_2, size);
    start = clock();
    qs(arr, 0, size - 1);
    end = clock();
    time_spent_7 = (double)(end - start) / CLOCKS_PER_SEC;
    vozyb(arr, size_2, size);
    start = clock();
    shell(arr, size);
    end = clock();
    time_spent_8 = (double)(end - start) / CLOCKS_PER_SEC;
    vozyb(arr, size_2, size);
    start = clock();
    qsort(arr, size, sizeof(int), comp);
    end = clock();
    time_spent_9 = (double)(end - start) / CLOCKS_PER_SEC;

    ran(arr, size);
    start = clock();
    qs(arr, 0, size - 1);
    end = clock();
    time_spent_10 = (double)(end - start) / CLOCKS_PER_SEC;
    ran(arr, size);
    start = clock();
    shell(arr, size);
    end = clock();
    time_spent_11 = (double)(end - start) / CLOCKS_PER_SEC;
    ran(arr, size);
    start = clock();
    qsort(arr, size, sizeof(int), comp);
    end = clock();
    time_spent_12 = (double)(end - start) / CLOCKS_PER_SEC;

    printf("+---------------------------------------------------------+\n"
        "|   |               |                    |                |\n"
        "|   |      qs       |        shell       |      qsort     |\n"
        "|   |               |                    |                |\n"
        "+---+---------------+----------+---------+----------------+\n");
        printf("| \\ | %-14f|      %-16f| %-13f|\n", time_spent_1, time_spent_2, time_spent_3);
        printf("+---------------------------------------------------------+\n");
        printf("| / | %-14f|      %-16f| %-13f|\n", time_spent_4, time_spent_5, time_spent_6);
        printf("+---------------------------------------------------------+\n");
        printf("| /\\| %-14f|      %-16f| %-13f|\n", time_spent_7, time_spent_8, time_spent_9);
        printf("+---------------------------------------------------------+\n");
        printf("| . | %-14f|      %-16f| %-13f|\n", time_spent_10, time_spent_11, time_spent_12);
        printf("+---------------------------------------------------------+\n");
        char n_file[50];
        FILE* file;
        printf("Введите имя файла для загрузки данных в него: ");
        scanf("%s", n_file);
        if (sizeof(n_file) > 50) {
            printf("Имя файла превышает доступное значение (49)!\n");
            return;
        }
        if ((file = fopen(n_file, "w")) == NULL)
        {
            printf("\nНевозможно открыть для записи файл: %s\n", n_file);
            _getch();
            return;
        }
        fprintf(file, "+---------------------------------------------------------+\n"
            "|   |               |                    |                |\n"
            "|   |      qs       |        shell       |      qsort     |\n"
            "|   |               |                    |                |\n"
            "+---+---------------+----------+---------+----------------+\n");
        fprintf(file, "| \\ | %-14f|      %-16f| %-13f|\n", time_spent_1, time_spent_2, time_spent_3);
        fprintf(file, "+---------------------------------------------------------+\n");
        fprintf(file, "| / | %-14f|      %-16f| %-13f|\n", time_spent_4, time_spent_5, time_spent_6);
        fprintf(file, "+---------------------------------------------------------+\n");
        fprintf(file, "| /\\| %-14f|      %-16f| %-13f|\n", time_spent_7, time_spent_8, time_spent_9);
        fprintf(file, "+---------------------------------------------------------+\n");
        fprintf(file, "| . | %-14f|      %-16f| %-13f|\n", time_spent_10, time_spent_11, time_spent_12);
        fprintf(file, "+---------------------------------------------------------+\n");
        fclose(file);
        printf("Данные успешно записаны!\n");

}