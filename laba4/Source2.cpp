#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// ��������� ��� ���� ��������� ������
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
int p = 0;
// ������� ��� �������� ������ ����
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ������� ��� ������� ������ ���� � ������
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
    else { // ���� ������� ��� ���������� � ������, ������ �� ������ (� ��� �� ��������������� ���� else, �� �������� ����� ����� 1 - ��� �������)
        printf("������ �������� ��� ������������ �������!\n");
        free(createNode(data));
        return root;
    }
    return root;
}

// ������� ��� ������ �������� � ������
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

// ������� ��� ������ ��������� ������ � ������� �����������
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
        printf("1. ������ ����� ������� � ������\n");
        printf("2. ����������� ������\n");
        printf("3. ����� �������\n");
        printf("4. �����\n");
        printf("�������� ��������: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1: // ������� ��������� � ������
            printf("������� �����: ");
            scanf("%d", &data);
            root = insert(root, data);
            break;
        case 2:
            printf("�������� ������ � ������� �����������: ");
            printInOrder(root);
            printf("\n\n");
            print_tree(root, 0);
            break;
        case 3: // ����� �������� � ������
            printf("������� ����� ������� ������ �����: ");
            scanf("%d", &searchData);
            searchResult = search(root, searchData);
            if (searchResult != NULL) {
                printf("%d ������ � ������\n", searchData);
            }
            else {
                printf("%d �� ������ � ������\n", searchData);
            }
            occurrences = countOccurrences(root, searchData);
            printf("����� %d ����������� %d ���(�) � ������\n", searchData, occurrences);
			printf("������� ������� ��������� �� %d ������\n", p);
			p=0;
            break;
        case 4:
            system("cls");
            printf("�� �������!\n");
            break;
        default:
            system("cls");
            printf("����������� �����!\n");
            break;
        }
    } while (choice != 4);  
}