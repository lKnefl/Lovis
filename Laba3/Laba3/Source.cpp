#define _crt_secure_no_warnings
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct node {
    int data;
    int priority;
    struct node* next;
} node;

node* createnode(int data, int priority) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("�� ������� �������� ������!\n");
        return NULL;
    }
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;
    return newnode;
}

void enqueue(node** head, int data, int priority) {
    node* newnode = createnode(data, priority);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    if (priority < (*head)->priority) {
        newnode->next = *head;
        *head = newnode;
        return;
    }
    node* current = *head;
    while (current->next != NULL && current->next->priority <= priority) {
        current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
}

int dequeue(node** head) {
    if (*head == NULL) {
        printf("������ ����!\n");
        return -1;
    }
    node* temp = *head;
    int data = temp->data;
    *head = (*head)->next;
    free(temp);
    return data;
}

void main() {
    node* head = NULL;
    int choice, priority, data;
    setlocale(LC_ALL, "rus");
    do {
        printf("1. ������ ����� ������� �������\n");
        printf("2. ������� ������������ ������� �� �������\n");
        printf("3. ������� ������ �� �����\n");
        printf("4. �����\n");
        printf("�������� ��������: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("������� ���������� � ������� ������: ");
            scanf("%d", &data);
            printf("������� ���������: ");
            scanf("%d", &priority);
            enqueue(&head, data, priority);
            break;
        case 2: 
            data = dequeue(&head);
            printf("�������: %d", data);
            printf("\n������������ ������� �����!\n");
            break;
        case 3:
            while (head != NULL) {
                data = dequeue(&head);
                printf("%d ", data);
            }
            printf("\n");
            break;
        case 4: 
            system("cls");
            printf("�� ��������!\n");
            break;
        default:
            system("cls");
            printf("����������� �����!\n");
            break;
        }
    } while (choice != 4);
}