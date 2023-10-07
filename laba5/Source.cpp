#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void main() {

    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int** arr = 0; // ������� ���������
    int** incidenceMatrix = 0; // ������� �������������
    int i, j, rows, k, unit = 0;
    printf("������� ���������� ������ �����: ");
    scanf("%d", &rows);
    arr = (int**)malloc(rows * sizeof(int*));
    if (arr == NULL) {
        printf("�� ������� �������� ������!\n");
        return;
    }
    for (i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(rows * sizeof(int));
    }
    // ������������ ��������� �������� ��� ������� ���������
    for (i = 0; i < rows; i++) {
        for (j = i; j < rows; j++) {
            if (i == j) {
                arr[i][j] = 0; // �� ������� ��������� ����
            }
            else {
                arr[i][j] = rand() % 2; // ��������� �������� 0 ��� 1
                arr[j][i] = arr[i][j]; // ����������� ��������� �������� ��� ������������������ �����
            }
        }
    }

    printf("������� ���������:\n");
    // �������� ������� ��������� �� �����
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            printf("%-2d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("������ ����� �����: %d\n", rows);

    int  edgeCount = 0;
    for (j = 0; j < rows; j++) {
        for (i = j + 1; i < rows; i++) {
            if (arr[i][j] == 1) {
                edgeCount++;
            }
        }
    }

    int* rArr = 0;
    rArr = (int*)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            if (arr[i][j] == 0) {
                unit = unit;
            }
            else {
                unit++;
            }
        }
        rArr[i] = unit;
        //printf("%d\n", rArr[i]);
        unit = 0;
    }
    for (i = 0; i < rows; i++) {
        if (rArr[i] == 1) {
            printf("%d ������� - ��������\n", i + 1);
        }
        else if (rArr[i] == rows - 1) {
            printf("%d ������� - ������������\n", i + 1);
        }
        else if (rArr[i] == 0) {
            printf("%d ������� - �������������\n", i + 1);
        }
    }

    unit = edgeCount;
    incidenceMatrix = (int**)malloc(rows * sizeof(int*));
    if (incidenceMatrix == NULL) {
        printf("�� ������� �������� ������!\n");
        return;
    }
    for (i = 0; i < rows; i++) {
        incidenceMatrix[i] = (int*)malloc(edgeCount * sizeof(int));
    }

    // ���������� ������� ������������� �� ������ ������� ���������
    edgeCount = 0;
    for (i = 0; i < rows; i++) {
        for (j = i + 1; j < rows; j++) {
            if (arr[i][j] == 1) {
                for (k = 0; k < rows; k++) {
                    if (k == i || k == j) {
                        incidenceMatrix[k][edgeCount] = 1;
                    }
                    else {
                        incidenceMatrix[k][edgeCount] = 0;
                    }
                }
                edgeCount++;
            }
        }
    }
    


    // ����� ������� ������������� �� �����
    printf("������� �������������:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < edgeCount; j++) {
            printf("%-2d ", incidenceMatrix[i][j]);
        }
        printf("\n");
    }

    int* resultArr;
    int p = 0;
    resultArr = (int*)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++) {
        for (j = 0; j < unit; j++) {
            if (incidenceMatrix[i][j] == 0) {
                p = p;
            }
            else {
                p++;
            }
        }
        resultArr[i] = p;
        //   printf("%d\n", resultArr[i]);
        p = 0;
    }
    printf("������ ����� �����: %d\n", rows);
    p = 0;
    for (i = 0; i < rows; i++) {
        if (resultArr[i] == 1) {
            printf("%d ������� - ��������\n", i + 1);
        }
        else if (resultArr[i] == rows - 1) {
            printf("%d ������� - ������������\n", i + 1);
        }
        else if (resultArr[i] == 0) {
            printf("%d ������� - �������������\n", i + 1);
        }
    }
    // ������������ ������
    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    for (i = 0; i < rows; i++) {
        free(incidenceMatrix[i]);
    }
    free(incidenceMatrix);
}