#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Структура для узла бинарного дерева
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
int p = 0;
// Функция для создания нового узла
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Функция для вставки нового узла в дерево
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    else { // Если элемент уже существует в дереве, ничего не делаем (е сли не закоментировать этот else, то повторов будет всего 1 - что логично)
        printf("Нельзя добавить уже существующий элемент!\n");
        free(createNode(data));
        return root;
    }
    return root;
}

// Функция для поиска элемента в дереве
Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    else if (data < root->data) {
		p++;
        return search(root->left, data);
    }
    else {
		p++;
        return search(root->right, data);
    }
}

// Функция для печати элементов дерева в порядке возрастания
void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

void print_tree(Node* root, int l)
{

    if (root == NULL)
    {
        return;
    }

    print_tree(root->right, l + 1);
    for (int i = 0; i < l; i++)
    {
        printf("\t");
    }

    printf("%d\n", root->data);
    print_tree(root->left, l + 1);
}

int countOccurrences(Node* root, int data) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == data) {
        return 1 + countOccurrences(root->left, data) + countOccurrences(root->right, data);
    }
    else if (data < root->data) {
        return countOccurrences(root->left, data);
    }
    else {
        return countOccurrences(root->right, data);
    }
}

void main() {
    setlocale(LC_ALL, "RUS");
    Node* root = NULL;
    Node* searchResult = NULL;
    int choice, data, searchData, occurrences = 0;
    do {
        printf("1. Ввести новый элемент в дерево\n");
        printf("2. Просмтореть дерево\n");
        printf("3. Найти элемент\n");
        printf("4. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: // Вставка элементов в дерево
            printf("Введите число: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("Элементы дерева в порядке возрастания: ");
            printInOrder(root);
            printf("\n\n");
            print_tree(root, 0);
            break;
        case 3: // Поиск элемента в дереве
            printf("Введите число которое хотите найти: ");
            scanf("%d", &searchData);
            searchResult = search(root, searchData);
            if (searchResult != NULL) {
                printf("%d найден в дереве\n", searchData);
            }
            else {
                printf("%d не найден в дереве\n", searchData);
            }
            occurrences = countOccurrences(root, searchData);
            printf("Число %d встречается %d раз(а) в дереве\n", searchData, occurrences);
			printf("Искомый элемент находится на %d уровне\n", p);
			p=0;
            break;
        case 4:
            system("cls");
            printf("До свиания!\n");
            break;
        default:
            system("cls");
            printf("Некоректный выбор!\n");
            break;
        }
    } while (choice != 4);  
}