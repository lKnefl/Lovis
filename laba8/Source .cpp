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

// Определение структуры для очереди
typedef struct Queue {
    Node* front; // первый элемент
    Node* rear; // последний
} Queue;

// Функция для создания очереди
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Ошибка выделения памяти для очереди!\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Функция для добавления элемента в очередь
void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти для нового элемента!\n");
        exit(1);
    }
    newNode->inf = value;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Функция для извлечения элемента из очереди
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Очередь пуста!\n");
        exit(1);
    }

    Node* temp = queue->front;
    int value = temp->inf;
    queue->front = temp->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return value;
}

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
        printf("Вершина %d смежна с: ", i + 1);
        Node* current = arr_sp[i];
        while (current != NULL) {
            printf("%d ", current->inf);
            current = current->next;
        }
        printf("\n");
    }
}

void crossSp(Node** arr_sp, int* arr_visited, int rows1) {

    Queue* queue = createQueue();
    arr_visited[rows1 - 1] = 1; // Отмечаем текущую вершину как посещенную
    enqueue(queue, rows1);

    printf("Результат обхода графа в ширину: ");

    while (queue->front != NULL) {
        int currentRows = dequeue(queue);
        printf("%d ", currentRows);

        Node* current = arr_sp[currentRows - 1];
        while (current != NULL) {
            int temp = current->inf;
            if (!arr_visited[temp - 1]) {
                arr_visited[temp - 1] = 1;
                enqueue(queue, temp);
            }
            current = current->next;
        }
    }

    free(arr_visited);
    free(queue);
}

void cross(int** arr, int* arr_visited, int rows, int rows1) {
    Queue* queue = createQueue();
    arr_visited[rows1 - 1] = 1;
    enqueue(queue, rows1);
    printf("Результат обхода графа в ширину: ");
    while (queue->front != NULL) {
        int current = dequeue(queue);
        printf("%d ", current);
        for (int i = 0; i < rows; i++) {
            if (arr[current - 1][i] == 1 && !arr_visited[i]) {
                arr_visited[i] = 1;
                enqueue(queue, i + 1);
            }
        }
    }
    free(arr_visited);
    free(queue);
}

void crossQue(int** arr, int* arr_visited, int rows, int rows1) {
    std::queue<int> q;  // пустая очередь
    arr_visited[rows1 - 1] = 1;
    q.push(rows1);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        printf("%d ", current);
        for (int i = 0; i < rows; i++) {
            if (arr[current - 1][i] == 1 && !arr_visited[i]) {
                arr_visited[i] = 1;
                q.push(i + 1);
            }
        }
    }
}

void crossSpQue(Node** arr_sp, int* arr_visited, int rows1) {
    std::queue<int> q;
    arr_visited[rows1 - 1] = 1;
    q.push(rows1);
    printf("Результат обхода графа в ширину: ");
    while (!q.empty()) {
        int currentRows = q.front();
        q.pop();
        printf("%d ", currentRows);
        Node* current = arr_sp[currentRows - 1];
        while (current != NULL) {
            int temp = current->inf;
            if (!arr_visited[temp - 1]) {
                arr_visited[temp - 1] = 1;
                q.push(temp);
            }
            current = current->next;
        }
    }
}

void main() {

    setlocale(LC_ALL, "RUS");
    srand(time(NULL));
    int** arr = 0; // матрица смежности
    int* arr_visited = 0; // матрица посещённых вершин
    clock_t start, end; // объявляем переменные для определения времени выполнения
    double time_spent = 0.0;
    int i, j, rows;
    printf("Введите количество вершин графа: ");
    scanf("%d", &rows);
    Node** arr_sp = NULL;
    // Выделение памяти для массива списков смежности
    arr_sp = (Node**)malloc(rows * sizeof(Node*));
    if (arr_sp == NULL) {
        printf("Не удалось выделить память!\n");
        return;
    }
    for (i = 0; i < rows; i++) {
        arr_sp[i] = NULL;
    }

    arr = (int**)malloc(rows * sizeof(int*));
    if (arr == NULL) {
        printf("Не удалось выделить память!\n");
        return;
    }
    for (i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(rows * sizeof(int));
    }

    arr_visited = (int*)malloc(rows * sizeof(int));
    for (i = 0; i < rows; i++) {
        arr_visited[i] = 0;  // Инициализируем все вершины как непосещенные
    }

    // генерировать случайные значения для матрицы смежности
    for (i = 0; i < rows; i++) {
        for (j = i; j < rows; j++) {
            if (i == j) {
                arr[i][j] = 0; // на главной диагонали нули
            }
            else {
                arr[i][j] = rand() % 2; // случайные значения 0 или 1
                arr[j][i] = arr[i][j]; // симметрично заполнять значения для неориентированного графа
            }
        }
    }

    // выводить матрицу смежности на экран
    printf("Матрица смежности для графа:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < rows; j++) {
            printf("%-2d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("Списки смежности для графа:\n");
    addSp(arr_sp, arr, rows);
    printSp(arr_sp, rows);

    int choice, rows1 = 0;
    do {
        printf("1. Просмотреть массив\n");
        printf("2. Обход графа в ширину с помощью списков\n");
        printf("3. Обход графа в ширину с помощью queue\n");
        printf("4. Обход графа в ширину с помощью queue и списков\n");
        printf("5. Обход графа в ширину\n");
        printf("6. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Матрица смежности для графа:\n");
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
                arr_visited[i] = 0;  // Инициализируем все вершины как непосещенные
            }
            printf("Введите вершину с которой хотите начать обход: ");
            scanf("%d", &rows1);
            if (rows1 < 1 || rows1 > rows) {
                printf("Некорректный номер вершины!\n");
                break;
            }
            start = clock();
            crossSp(arr_sp, arr_visited, rows1);
            end = clock();
            printf("\n");
            time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("%f\n", time_spent);
            break;
        case 3:
            arr_visited = (int*)malloc(rows * sizeof(int));
            for (i = 0; i < rows; i++) {
                arr_visited[i] = 0;  // Инициализируем все вершины как непосещенные
            }
            printf("Введите вершину с которой хотите начать обход: ");
            scanf("%d", &rows1);
            if (rows1 < 1 || rows1 > rows) {
                printf("Некорректный номер вершины!\n");
                break;
            }
            printf("Результат обхода графа в ширину: ");
            start = clock();
            crossQue(arr, arr_visited, rows, rows1);
            end = clock();
            printf("\n");
            time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("%f\n", time_spent);
            break;
        case 4:
            arr_visited = (int*)malloc(rows * sizeof(int));
            for (i = 0; i < rows; i++) {
                arr_visited[i] = 0;  // Инициализируем все вершины как непосещенные
            }
            printf("Введите вершину с которой хотите начать обход: ");
            scanf("%d", &rows1);
            if (rows1 < 1 || rows1 > rows) {
                printf("Некорректный номер вершины!\n");
                break;
            }
            start = clock();
            crossSpQue(arr_sp, arr_visited, rows1);
            end = clock();
            printf("\n");
            time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("%f\n", time_spent);
            break;
        case 5:
            arr_visited = (int*)malloc(rows * sizeof(int));
            for (i = 0; i < rows; i++) {
                arr_visited[i] = 0;  // Инициализируем все вершины как непосещенные
            }
            printf("Введите вершину с которой хотите начать обход: ");
            scanf("%d", &rows1);
            if (rows1 < 1 || rows1 > rows) {
                printf("Некорректный номер вершины!\n");
                break;
            }
            start = clock();
            cross(arr, arr_visited, rows, rows1);
            end = clock();
            printf("\n");
            time_spent = (double)(end - start) / CLOCKS_PER_SEC;
            printf("%f\n", time_spent);
            break;
        case 6:
            system("cls");
            printf("До свидания!\n");
            break;
        default:
            printf("Некорректный выбор!\n");
            break;
        }
    } while (choice != 6);

    // Освобождение памяти
    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}
