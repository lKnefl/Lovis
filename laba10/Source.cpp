#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <queue>

typedef struct Node {
    int inf;
    struct Node* next;
}Node;

void addSp(Node** arr_sp, int** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (arr[i][j] != 0) {
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

// ��������� ��� �������� �������� �����
typedef struct GraphSettings {
    int weighted;  // 1, ���� ���� ����������, ����� 0
    int directed;  // 1, ���� ���� ���������������, ����� 0
} GraphSettings;

GraphSettings arguments(int argc, char* argv[]) {
    GraphSettings settings = { 0, 0 };  // �������������� ��������� ����������� �� ���������

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-w") == 0) {
            settings.weighted = 1;
        }
        else if (strcmp(argv[i], "-d") == 0) {
            settings.directed = 1;
        }
    }

    return settings;
}

void crossQue(int** arr, int* arr_visited, int rows, int rows1) {
    std::queue<int> q;  // ������ �������
    arr_visited[rows1 - 1] = 0;
    q.push(rows1);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < rows; i++) {
            arr[current - 1][i] = (arr[current - 1][i] < 0) ? -arr[current - 1][i] : arr[current - 1][i];
            if (arr[current - 1][i] > 0 && arr_visited[i] == -1) {
                printf("%d ", arr[current - 1][i]);
                arr_visited[i] = arr_visited[current - 1] + arr[current - 1][i];
                q.push(i + 1);
            }
        }
    }
   printf("\n");
}

void main(int argc, char* argv[]) {

    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    GraphSettings graphSettings = arguments(argc, argv);
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

    // ������������ ��������� �������� ��� ������� ���������
    for (i = 0; i < rows; i++) {
        for (j = i; j < rows; j++) {
            if (i == j) {
                arr[i][j] = 0; // �� ������� ��������� ����
            }
            else {
                if (graphSettings.weighted == 1 && graphSettings.directed == 1) {
                    arr[i][j] = (-10) + rand() % 21; // ��������� �������� �� -10 �� 10
                    arr[j][i] = arr[i][j];
                }
                if (graphSettings.weighted == 0 && graphSettings.directed == 1) {
                    arr[i][j] = (-1) + rand() % 3;
                    arr[j][i] = arr[i][j];
                }
                if (graphSettings.weighted == 1 && graphSettings.directed == 0) {
                    arr[i][j] = rand() % 10;
                    arr[j][i] = arr[i][j];
                }
                if (graphSettings.weighted == 0 && graphSettings.directed == 0) {
                    arr[i][j] = rand() % 2;
                    arr[j][i] = arr[i][j];
                }
            }
        }
    }

    // �������� ������� ��������� �� �����
    printf("������� ��������� ��� �����:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            printf("%-4d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("������ ��������� ��� �����:\n");
    addSp(arr_sp, arr, rows);
    printSp(arr_sp, rows);
    int* eccentricities = (int*)malloc(rows * sizeof(int));
    int* eccentricities_min = (int*)malloc(rows * sizeof(int));
    int choice, radius, start, max_distance, min_distance, minima = 10, diameter = 0, rows1 = 0;
    do {
        printf("1. ����������� ������\n");
        printf("2. ����� ���������� �����\n");
        printf("3. ���������� ������� � ��������, ����� ����������� � ������������ ������\n");
        printf("4. �����\n");
        printf("�������� ��������: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("������� ��������� ��� �����:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%-4d ", arr[i][j]);
                }
                printf("\n");
            }

            printSp(arr_sp, rows);
            break;
        case 2:
            arr_visited = (int*)malloc(rows * sizeof(int));
            for (i = 0; i < rows; i++) {
                arr_visited[i] = -1;  // �������������� ��� ������� ��� ������������
            }
            printf("������� ������� � ������� ������ ������ �����: ");
            scanf("%d", &rows1);
            if (rows1 < 1 || rows1 > rows) {
                printf("������������ ����� �������!\n");
                break;
            }
            printf("���������� �� ������� %d: \n", rows1);
            crossQue(arr, arr_visited, rows, rows1);
            for (i = 0; i < rows; i++) {
                printf("�� ������� %d: %d\n", i + 1, arr_visited[i]);
            }
            break;
        case 3:
            arr_visited = (int*)malloc(rows * sizeof(int));
            for (int start = 0; start < rows; start++) {
                // �������������� ������� ���������� ������
                for (i = 0; i < rows; i++) {
                    arr_visited[i] = -1;
                }
                crossQue(arr, arr_visited, rows, start + 1);
                // ������� �������������� ��� ������� �������
                max_distance = 0;
                for (i = 0; i < rows; i++) {
                    if (arr_visited[i] > max_distance) {
                        max_distance = arr_visited[i];
                    }
                }
                eccentricities[start] = max_distance;

                min_distance = 10;
                for (i = 0; i < rows; i++) {
                    if (arr_visited[i] < min_distance && arr_visited[i] != 0) {
                        min_distance = arr_visited[i];
                    }
                }
                eccentricities_min[start] = min_distance;
            }
            for (i = 0; i < rows; i++) {
                if (eccentricities[i] > diameter) {
                    diameter = eccentricities[i];
                }
            }
            printf("��������������� ������:\n");
            for (i = 0; i < rows; i++) {
                printf("%d ", eccentricities[i]);
            }
            printf("\n");
            printf("����������� ���������� ������:\n");
            for (i = 0; i < rows; i++) {
                printf("%d ", eccentricities_min[i]);
            }
            for (i = 0; i < rows; i++) {
                    minima = (minima > eccentricities_min[i]) ? eccentricities_min[i] : minima;
            }
            printf("\n");
            printf("����������� ����������: %d", minima);
            printf("\n");
            radius = diameter;
            for (i = 0; i < rows; i++) {
                if (eccentricities[i] < radius) {
                    radius = eccentricities[i];
                }
            }
            // ����� ������� � ��������
            printf("������ �����: %d\n", radius);
            printf("������� �����: %d\n", diameter);
            // ����� ����������� � ������������ ������
            printf("����������� �������: ");
            for (i = 0; i < rows; i++) {
                if (eccentricities[i] == radius) {
                    printf("%d ", i + 1);
                }
            }
            printf("\n");
            printf("������������ �������: ");
            for (i = 0; i < rows; i++) {
                if (eccentricities[i] == diameter) {
                    printf("%d ", i + 1);
                }
            }
            printf("\n");
            break;
        case 4:
            system("cls");
            printf("�� ��������!\n");
            break;
        default:
            printf("������������ �����!\n");
            break;
        }
    } while (choice != 4);

    // ������������ ������
    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}