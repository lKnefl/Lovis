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
    SetConsoleCP(1251);//��������� �����
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    do {
        printf("\t����\n");
        printf("1. ����������� ������\n");
        printf("2. ����� ������������ � ����������� �������� ��������� �������\n");
        printf("3. ��������� ����� �������� ������� � ������ ��� �������\n");
        printf("4. ������� ����� ������\n");
        printf("5. �����\n");
        printf("�������� ��������: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            if (arr == NULL) {
                printf("������� �������� ������!\n");
                break;
            }
            for (i = 0; i < rows; i++) {  // ���� �� �������
                for (j = 0; j < cols; j++) { // ���� �� ��������
                    printf("%5d ", *(arr + i * cols + j)); // ����� ��������� �������
                }
                printf("\n");
            }
            break;
        case 2:
            if (arr == NULL) {
                printf("������� �������� ������!\n");
                break;
            }
            min = *(arr + 0 * cols + 0);
            max = *(arr + 0 * cols + 0);
            for (i = 0; i < rows; i++) { // ���� �� �������
                for (j = 0; j < cols; j++) { // ���� �� ��������
                    if (*(arr + i * cols + j) < min) {
                        min = *(arr + i * cols + j);
                    }
                    if (*(arr + i * cols + j) > max) {
                        max = *(arr + i * cols + j);
                    }
                }
            }
            printf("����������� �����: %d\n", min);
            printf("������������ �����: %d\n", max);
            break;
        case 3:
            if (arr == NULL) {
                printf("������� �������� ������!\n");
                break;
            }
            do {
                printf("\n\t����\n");
                printf("1. ��������� ����� � �������\n");
                printf("2. ��������� ����� � ������\n");
                printf("3. ���������\n");
                printf("�������� ��������: ");
                scanf("%d", &choice2);
                switch (choice2) {
                case 1:
                    sum = 0;
                    printf("�������� ����� ������: ");
                    scanf("%d", &index);
                    for (i = 0; i < rows; i++) {
                        sum += *(arr + i * cols + index - 1);
                    }
                    printf("\n����� �����: %d", sum);
                    break;
                case 2: 
                    sum = 0;
                    printf("�������� ����� ������: ");
                    scanf("%d", &index);
                    for (j = 0; j < cols; j++) {
                        sum += *(arr + (index - 1) * cols + j);
                    }
                    printf("\n����� �����: %d", sum);
                    break;
                case 3: 
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("������������ �����!\n");
                    break;
                }
            } while (choice2 != 3);
            break;
        case 4:
            printf("������� ���������� �����: ");
            scanf("%d", &rows);
            printf("������� ���������� ��������: ");
            scanf("%d", &cols);
            arr = (int*)malloc(rows * cols * sizeof(int));
            if (arr == NULL) {
                printf("�� ������� �������� ������!\n");
                break;
            }
            for (i = 0; i < rows; i++)  { // ���� �� �������
                for (j = 0; j < cols; j++)  { // ���� �� ��������
                    *(arr + i * cols + j) = rand () % 100;
                }
            }
            printf("������ ������!\n");
            break;
        case 5:
            system("cls");
            printf("�� ��������!\n");
            break;
        default:
            system("cls");
            printf("������������ �����!\n");
            break;
        }
    } while (choice != 5);
}*/