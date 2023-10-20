#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>

typedef struct Node {
    int inf;
    struct Node* next;
}Node;

void addSp(Node** arr_sp, int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (arr[i][j] == 1) {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->inf = j + 1;
                newNode->next = arr_sp[i];
                arr_sp[i] = newNode;
            }
        }
    }
}

void printSp(Node** arr_sp, int rows) {
    for (int i = 0; i < rows; i++) {
        printf("������� %d ������ �: ", i + 1);
        Node* current = arr_sp[i];
        while (current != NULL) {
            printf("%d ", current->inf);
            current = current->next;
        }
        printf("\n");
    }
}

void cross(int** arr, int rows1, int* arr_visited, int rows) {
    arr_visited[rows1] = 1; // �������� ������� ������� ��� ����������
    printf("%d ", rows1 + 1);
    for (int i = 0; i < rows; i++) {
        if (arr[rows1][i] == 1 && arr_visited[i] != 1) {
            cross(arr, i, arr_visited, rows);
        }
    }
}

void crossSp(Node** arr_sp, int rows1, int* arr_visited) {
    arr_visited[rows1] = 1; // �������� ������� ������� ��� ����������
    printf("%d ", rows1 + 1);
    Node* current = arr_sp[rows1];
    while (current != NULL) {
        int temp = current->inf;
        if (!arr_visited[--temp]) {
            crossSp(arr_sp, temp, arr_visited);
        }
        current = current->next;
    }
}

void crossStack(int** arr, int* arr_visited, int rows1, int rows) {
    int* stack = (int*)malloc(rows * sizeof(int)); // ����
    int top = -1; // ������� �����
    stack[++top] = rows1; // �������� ��������� ������� � ����

    while (top != -1) {
        int temp = stack[top--]; // ��������� ������� �� �����

        if (arr_visited[temp] != 1) {
            arr_visited[temp] = 1; // �������� ������� ��� ����������
            printf("%d ", temp + 1); // ������� �������

            for (int i = rows - 1; i >= 0; i--) {
                if (arr[temp][i] == 1 && arr_visited[i] != 1) {
                    stack[++top] = i; // �������� ������� ������������ ������� � ����
                }
            }
        }
    }
}

void main() {

    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int** arr = 0; // ������� ���������
    int* arr_visited = 0; // ������� ���������� ������
    int i, j, rows;
    printf("������� ���������� ������ �����: ");
    scanf("%d", &rows);
    Node** arr_sp = NULL;
    // ��������� ������ ��� ������� ������� ���������
    arr_sp = (Node**)malloc(rows * sizeof(Node*));
    if (arr_sp == NULL) {
        printf("�� ������� �������� ������!\n");
        return;
    }
    for (i = 0; i < rows; i++) {
        arr_sp[i] = NULL;
    }

    arr = (int**)malloc(rows * sizeof(int*));
    if (arr == NULL) {
        printf("�� ������� �������� ������!\n");
        return;
    }
    for (i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(rows * sizeof(int));
    }

    arr_visited = (int*)malloc(rows * sizeof(int));
    for (i = 0; i < rows; i++) {
        arr_visited[i] = 0;  // �������������� ��� ������� ��� ������������
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

    // �������� ������� ��������� �� �����
    printf("������� ��������� ��� �����:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            printf("%-2d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("������ ��������� ��� �����:\n");
    addSp(arr_sp, arr, rows);
    printSp(arr_sp, rows);

    int choice, rows1 = 0;
    do {
        printf("1. ����������� ������\n");
        printf("2. ����� ����� � �������\n");
        printf("3. ����� ����� � �������  � �������� �������\n");
        printf("4. ����� ����� � ������� � ������� �����\n");
        printf("5. �����\n");
        printf("�������� ��������: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("������� ��������� ��� �����:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%-2d ", arr[i][j]);
                }
                printf("\n");
            }
            printSp(arr_sp, rows);
            break;
        case 2:
            arr_visited = (int*)malloc(rows * sizeof(int));
			for (i = 0; i < rows; i++) {
				arr_visited[i] = 0;  // �������������� ��� ������� ��� ������������
			}
            printf("������� ������� � ������� ������ ������ �����: ");
            scanf("%d", &rows1);
            if (rows1 < 1 || rows1 > rows) {
                printf("������������ ����� �������!\n");
                break;
            }
            printf("��������� ������ ����� � �������: ");
            cross(arr, rows1 - 1, arr_visited, rows);
            printf("\n");
			free(arr_visited);
            break;
        case 3:   
			arr_visited = (int*)malloc(rows * sizeof(int));
            for (i = 0; i < rows; i++) {
               arr_visited[i] = 0;
            }
            printf("������� ������� � ������� ������ ������ �����: ");
            scanf("%d", &rows1);
            if (rows1 < 1 || rows1 > rows) {
                printf("������������ ����� �������!\n");
                break;
            }
            printf("��������� ������ ����� � �������: ");
			memset(arr_visited, 0, sizeof(int) * rows);
            crossSp(arr_sp, rows1 - 1, arr_visited);
            printf("\n");
			free(arr_visited);
            break;
        case 4:
			arr_visited = (int*)malloc(rows * sizeof(int));
            for (i = 0; i < rows; i++) {
                arr_visited[i] = 0;
            }
            printf("������� ������� � ������� ������ ������ �����: ");
            scanf("%d", &rows1);
            if (rows1 < 1 || rows1 > rows) {
                printf("������������ ����� �������!\n");
                break;
            }
            printf("��������� ������ ����� � �������: ");
            crossStack(arr, arr_visited, rows1 - 1, rows);
            printf("\n");
			free(arr_visited);
            break;
        case 5:
            system("cls");
            printf("�� ��������!\n");
            break;
        default:
            printf("������������ �����!\n");
            break;
        }
    } while (choice != 5);

    // ������������ ������
    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}
