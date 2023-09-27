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
        printf("не удалось выделить память!\n");
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
        printf("список пуст!\n");
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
        printf("1. ввести новый элемент очереди\n");
        printf("2. удалить приоритетный элемент из очереди\n");
        printf("3. вывести список на экран\n");
        printf("4. выход\n");
        printf("выберите действие: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("введите информацию в элемент списка: ");
            scanf("%d", &data);
            printf("введите приоритет: ");
            scanf("%d", &priority);
            enqueue(&head, data, priority);
            break;
        case 2: 
            data = dequeue(&head);
            printf("элемент: %d", data);
            printf("\nприоритетный элемент удалён!\n");
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
            printf("до свидания!\n");
            break;
        default:
            system("cls");
            printf("некоректный выбор!\n");
            break;
        }
    } while (choice != 4);
}