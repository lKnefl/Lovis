#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

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
        Node* current = arr_sp[i];
        printf("������� %d ������ �: ", i + 1);
        while (current != NULL) {
            printf("%d ", current->inf);
            current = current->next;
        }
        printf("\n");
    }
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void mergeRows(int** arr, int* rows, int rows1, int rows2, Node** arr_sp) {
    // ��������
    if (rows1 >= *rows || rows2 >= *rows || rows1 < 0 || rows2 < 0) {
        printf("������: ������������ ������ ������!\n");
        return;
    }

    // ������������� ������� ����� ���������� �� ������ � ���� �� ��������
    for (int i = 0; i < *rows; i++) {
        arr[i][rows1] = arr[i][rows1] || arr[i][rows2];
    }
    for (int i = 0; i < *rows; i++) {
        arr[rows1][i] = arr[rows1][i] || arr[rows2][i];
    }

    // �������� ������� ������ �� rows2 �� ���� ������� �����
    for (int i = 0; i < *rows - 1; i++) {
        for (int j = rows2; j < *rows - 1; j++) {
            arr[i][j] = arr[i][j + 1];
        }
    }

    for (int i = rows2; i < *rows - 1; i++) {
        for (int j = 0; j < *rows - 1; j++) {
            arr[i][j] = arr[i + 1][j];
        }
    }

    // ��������� ���������� ������ �� 1
    (*rows)--;
    for (int i = 0; i < *rows+1; i++) {
        freeList(arr_sp[i]);
        arr_sp[i] = NULL;
    }
    addSp(arr_sp, arr, *rows);
}

void contractEdge(int** arr, int* rows, int rows1, int rows2, Node** arr_sp) {
    // ���������� �����
    if (rows1 >= *rows || rows2 >= *rows || rows1 < 0 || rows2 < 0) {
        printf("������: ������������ ������ ������!\n");
        return;
    }
    if (arr[rows1][rows2] == 0) {
        printf("����� ��������� ������ ���� �����!\n");
        return;
    }
    // ������������� ������� ����� ���������� �� ������ � ���� �� ��������
    for (int i = 0; i < *rows; i++) {
        arr[i][rows1] = arr[i][rows1] || arr[i][rows2];
    }
    for (int i = 0; i < *rows; i++) {
        arr[rows1][i] = arr[rows1][i] || arr[rows2][i];
    }
    arr[rows1][rows1] = 0;
    // �������� ������� ������ �� vertex2 �� ���� ������� �����
    for (int i = 0; i < *rows - 1; i++) {
        for (int j = rows2; j < *rows - 1; j++) {
            arr[i][j] = arr[i][j + 1];
        }
    }

    for (int i = rows2; i < *rows - 1; i++) {
        for (int j = 0; j < *rows; j++) {
            arr[i][j] = arr[i + 1][j];
        }
    }
    // ��������� ���������� ������ �� 1
    (*rows)--;
    for (int i = 0; i < *rows + 1; i++) {
        freeList(arr_sp[i]);
        arr_sp[i] = NULL;
    }
    addSp(arr_sp, arr, *rows);
}

void deleteRows(int** arr, int* rows, int rows1, Node** arr_sp) {
    // ����������� �������
    int new_rows = *rows + 1;
    int** arr_split = (int**)malloc(new_rows * sizeof(int*));
    for (int i = 0; i < new_rows; i++) {
        arr_split[i] = (int*)malloc(new_rows * sizeof(int));

        for (int j = 0; j < new_rows; j++) {
            if (i < *rows && j < *rows) {
                arr_split[i][j] = arr[i][j];  // �������� ����� �������� �������
            }
            else if (i == *rows && j < *rows) {
                arr_split[i][j] = arr[rows1][j];  // ����� ������� ��������� �� �������� ��������� ��������� �������
            }
            else if (i < *rows && j == *rows) {
                arr_split[i][j] = arr[i][rows1];  // ������� ������� ��������� � ����� ��������
            }
            else {
                arr_split[i][j] = 0;  // ����� ������� �� ������� � ���������� ���������
            }
        }
    }

    (*rows)++;
    arr = (int**)malloc(*rows * sizeof(int*));
    for (int i = 0; i < *rows; i++) {
        arr[i] = (int*)malloc(*rows * sizeof(int));
    }
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *rows; j++) {
            arr[i][j] = arr_split[i][j];
        }
    }

    printf("��������� ����������� �������:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *rows; j++) {
            printf("%-2d ", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < *rows - 1; i++) {
        freeList(arr_sp[i]);
        arr_sp[i] = NULL;
    }
    arr_sp = (Node**)malloc((*rows) * sizeof(Node*));
    if (arr_sp == NULL) {
        printf("�� ������� �������� ������!\n");
        return;
    }
    for (int i = 0; i < *rows; i++) {
        arr_sp[i] = NULL;
    }
    addSp(arr_sp, arr, *rows);
    printSp(arr_sp, *rows);
}

void combineArr(int** arr, int** arr_2, int rows, int rows_2) { // ����������� ������
    int max_rows = (rows > rows_2) ? rows : rows_2;  // ������������ ������ ��� ������������� �������
    int** arr_union = (int**)malloc(max_rows * sizeof(int*));
    for (int i = 0; i < max_rows; i++) {
        arr_union[i] = (int*)malloc(max_rows * sizeof(int));
        for (int j = 0; j < max_rows; j++) {
            int val_1 = (i < rows && j < rows) ? arr[i][j] : 0;  // �������� �� arr, ���� ������� � �������� �������� �������
            int val_2 = (i < rows_2 && j < rows_2) ? arr_2[i][j] : 0;  // �������� �� arr_2, ���� ������� � �������� �������� �������
            arr_union[i][j] = val_1 || val_2;  // ���������� ��� ��������
        }
    }

    printf("��������� ����������� ������:\n");
    for (int i = 0; i < max_rows; i++) {
        for (int j = 0; j < max_rows; j++) {
            printf("%-2d ", arr_union[i][j]);
        }
        printf("\n");
    }
}

void crossArr(int** arr, int** arr_2, int rows, int rows_2) { // ����������� ������
    int max_rows = (rows > rows_2) ? rows : rows_2;
    int** arr_intersect = (int**)malloc(max_rows * sizeof(int*));
    for (int i = 0; i < max_rows; i++) {
        arr_intersect[i] = (int*)malloc(max_rows * sizeof(int));

        for (int j = 0; j < max_rows; j++) {
            int val_1 = (i < rows && j < rows) ? arr[i][j] : 0;
            int val_2 = (i < rows_2 && j < rows_2) ? arr_2[i][j] : 0;
            arr_intersect[i][j] = val_1 && val_2;
        }
    }
    printf("��������� ����������� ������:\n");
    for (int i = 0; i < max_rows; i++) {
        for (int j = 0; j < max_rows; j++) {
            printf("%-2d ", arr_intersect[i][j]);
        }
        printf("\n");
    }
}

void sumArr(int** arr, int** arr_2, int rows, int rows_2) { // ��������� �����
    int max_rows = (rows > rows_2) ? rows : rows_2;
    int** arr_ring_sum = (int**)malloc(max_rows * sizeof(int*));
    for (int i = 0; i < max_rows; i++) {
        arr_ring_sum[i] = (int*)malloc(max_rows * sizeof(int));

        for (int j = 0; j < max_rows; j++) {
            if (i < rows && i < rows_2 && j < rows && j < rows_2) {
                if (i==j || (arr[i][j] == 1 && arr_2[i][j] == 1)) {
                    arr_ring_sum[i][j] = 0;
                }
                else {
                    int val_1 = (i < rows&& j < rows) ? arr[i][j] : 0;
                    int val_2 = (i < rows_2&& j < rows_2) ? arr_2[i][j] : 0;
                    arr_ring_sum[i][j] = val_1 || val_2;
                }
            }
            else {
                arr_ring_sum[i][j] = 0;
            }
        }
    }
    printf("��������� ��������� ����� ������:\n");
    for (int i = 0; i < max_rows; i++) {
        for (int j = 0; j < max_rows; j++) {
            printf("%-2d ", arr_ring_sum[i][j]);
        }
        printf("\n");
    }
}

void decartArr(int** arr, int** arr_2, int rows, int rows_2) { // ��������� ������������
    int decart_rows = rows * rows_2;
    int decart_cols = rows * rows_2;

    int** arr_decart = (int**)malloc(decart_rows * sizeof(int*)); // �������������� ���� G
    for (int i = 0; i < decart_rows; i++) {
        arr_decart[i] = (int*)malloc(decart_cols * sizeof(int));
        for (int j = 0; j < decart_rows; j++) {
            arr_decart[i][j] = 0;
        }
    }  
	int u = 0, v = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows_2; j++) {
            for (int k = 0; k < rows; k++) {
                for (int l = 0; l < rows_2; l++) {
                    u = i * rows_2 + j;
                    v = k * rows_2 + l;
                    if (j == l) {
                        arr_decart[u][v] = arr[i][k]; // ������� ����� � G, ���� ���� ���� � G1 � G2
                    }
					if (i == k) {
						arr_decart[u][v] = arr_2[j][l];
					}
					if (i != k && j != l) {
						arr_decart[u][v] = 0;
					}
                }
            }
        }
    }

    // ����� ���������� �� �����
    printf("��������� ����������� ������������ ������:\n");
    for (int i = 0; i < decart_rows; i++) {
        for (int j = 0; j < decart_cols; j++) {
            printf("%-2d ", arr_decart[i][j]);
        }
        printf("\n");
    }
}

void main() {

    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int** arr = 0; // ������� ���������
    int** arr_2 = 0; // ������� ��������� 2
    int i, j, rows, rows_2, k, unit = 0;
    printf("������� ���������� ������ �����: ");
    scanf("%d", &rows);
    printf("������� ���������� ������ �����: ");
    scanf("%d", &rows_2);
    Node** arr_sp = NULL;
    Node** arr_sp_2 = NULL;
    // ��������� ������ ��� ������� ������� ���������
    arr_sp = (Node**)malloc(rows * sizeof(Node*));
    if (arr_sp == NULL) {
        printf("�� ������� �������� ������!\n");
        return;
    }
    for (i = 0; i < rows; i++) {
        arr_sp[i] = NULL;
    }
    arr_sp_2 = (Node**)malloc(rows_2 * sizeof(Node*));
    if (arr_sp_2 == NULL) {
        printf("�� ������� �������� ������!\n");
        return;
    }
    for (i = 0; i < rows_2; i++) {
        arr_sp_2[i] = NULL;
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
                arr[i][j] = rand() % 2; // ��������� �������� 0 ��� 1
                arr[j][i] = arr[i][j]; // ����������� ��������� �������� ��� ������������������ �����
            }
        }
    }

    // �������� ������� ��������� �� �����
    printf("������� ��������� ��� ����� �1:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            printf("%-2d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("������ ��������� ��� ����� �1:\n");
    addSp(arr_sp, arr, rows);
    printSp(arr_sp, rows);

    arr_2 = (int**)malloc(rows_2 * sizeof(int*));
    if (arr_2 == NULL) {
        printf("�� ������� �������� ������!\n");
        return;
    }
    for (i = 0; i < rows_2; i++) {
        arr_2[i] = (int*)malloc(rows_2 * sizeof(int));
    }

    // ������������ ��������� �������� ��� ������� ��������� 2
    for (i = 0; i < rows_2; i++) {
        for (j = i; j < rows_2; j++) {
            if (i == j) {
                arr_2[i][j] = 0; // �� ������� ��������� ����
            }
            else {
                arr_2[i][j] = rand() % 2; // ��������� �������� 0 ��� 1
                arr_2[j][i] = arr_2[i][j]; // ����������� ��������� �������� ��� ������������������ �����
            }
        }
    }

    printf("������� ��������� ��� ����� �2:\n");
    // �������� ������� ��������� �� �����
    for (i = 0; i < rows_2; i++) {
        for (j = 0; j < rows_2; j++) {
            printf("%-2d ", arr_2[i][j]);
        }
        printf("\n");
    }
    printf("������ ��������� ��� ����� �2:\n");
    addSp(arr_sp_2, arr_2, rows_2);
    printSp(arr_sp_2, rows_2);

    int choice, rows1, rows2, what;
    do {
        printf("1. ������������ �������\n");
        printf("2. ������� �����\n");
        printf("3. ��������� �������\n");
        printf("4. ���������� �����\n");
        printf("5. ��������� �������� ����������� ������\n");
        printf("6. ����� ��������� �����\n");
        printf("7. ����� ��������� ������������\n");
        printf("8. ����������� �������\n");
        printf("9. �����\n");
        printf("�������� ��������: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("�������� � ����� ������� ������ ��� ������� (1 ��� 2): ");
            scanf("%d", &what);
            if (what == 1) {
                printf("������� 1 �������, ������� ������ ������������: ");
                scanf("%d", &rows1);
                printf("������� 2 �������, ������� ������ ������������: ");
                scanf("%d", &rows2);
                mergeRows(arr, &rows, rows1 - 1, rows2 - 1, arr_sp);
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < rows; j++) {
                        printf("%-2d ", arr[i][j]);
                    }
                    printf("\n");
                }
                printSp(arr_sp, rows);
            }
            else if (what == 2) {
                printf("������� 1 �������, ������� ������ ������������: ");
                scanf("%d", &rows1);
                printf("������� 2 �������, ������� ������ ������������: ");
                scanf("%d", &rows2);
                mergeRows(arr_2, &rows_2, rows1 - 1, rows2 - 1, arr_sp_2);
                for (i = 0; i < rows_2; i++) {
                    for (j = 0; j < rows_2; j++) {
                        printf("%-2d ", arr_2[i][j]);
                    }
                    printf("\n");
                }
                printSp(arr_sp_2, rows_2);
            }
            else {
                printf("������������ �����!\n");
                break;
            }
            break;
        case 2:
            printf("�������� � ����� ������� ������ ��� ������� (1 ��� 2): ");
            scanf("%d", &what);
            if (what == 1) {
                printf("������� 1 �������, ����� �������� ����� ������� �����: ");
                scanf("%d", &rows1);
                printf("������� 2 �������, ����� �������� ����� ������� �����: ");
                scanf("%d", &rows2);
                contractEdge(arr, &rows, rows1 - 1, rows2 - 1, arr_sp);
                for (i = 0; i < rows; i++) {
                    for (j = 0; j < rows; j++) {
                        printf("%-2d ", arr[i][j]);
                    }
                    printf("\n");
                }
                printSp(arr_sp, rows);
            }
            else if (what == 2) {
                printf("������� 1 �������, ����� �������� ����� ������� �����: ");
                scanf("%d", &rows1);
                printf("������� 2 �������, ����� �������� ����� ������� �����: ");
                scanf("%d", &rows2);
                contractEdge(arr_2, &rows_2, rows1 - 1, rows2 - 1, arr_sp_2);
                for (i = 0; i < rows_2; i++) {
                    for (j = 0; j < rows_2; j++) {
                        printf("%-2d ", arr_2[i][j]);
                    }
                    printf("\n");
                }
                printSp(arr_sp_2, rows_2);
            }
            else {
                printf("������������ �����!\n");
                break;
            }
            break;
        case 3:
            printf("�������� � ����� ������� ������ ��� ������� (1 ��� 2): ");
            scanf("%d", &what);
            if (what == 1) {
                printf("������� �������, ������� ������ ���������: ");
                scanf("%d", &rows1);
                deleteRows(arr, &rows, rows1 - 1, arr_sp);
            }
            else if (what == 2) {
                printf("������� �������, ������� ������ ���������: ");
                scanf("%d", &rows1);
                deleteRows(arr_2, &rows_2, rows1 - 1, arr_sp_2);
            }
            else {
                printf("������������ �����!\n");
                break;
            }
            break;
        case 4:
            combineArr(arr, arr_2, rows, rows_2);
            break;
        case 5:
            crossArr(arr, arr_2, rows, rows_2);
            break;
        case 6:
            sumArr(arr, arr_2, rows, rows_2);
            break;
        case 7:
            decartArr(arr, arr_2, rows, rows_2);
            break;
        case 8:
            printf("������� ��������� ��� ����� �1:\n");
            for (i = 0; i < rows; i++) {
                for (j = 0; j < rows; j++) {
                    printf("%-2d ", arr[i][j]);
                }
                printf("\n");
            }
            printSp(arr_sp, rows);
            printf("������� ��������� ��� ����� �2:\n");
            // �������� ������� ��������� �� �����
            for (i = 0; i < rows_2; i++) {
                for (j = 0; j < rows_2; j++) {
                    printf("%-2d ", arr_2[i][j]);
                }
                printf("\n");
            }
            printSp(arr_sp_2, rows_2);
            break;
        case 9:
            system("cls");
            printf("�� ��������!\n");
            break;
        default:
            printf("������������ �����!\n");
            break;
        }
    } while (choice != 9);
}