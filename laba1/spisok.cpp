/*#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>

// Определение структуры для хранения информации о студентах
typedef struct {
    char name[10];
    char surname[10];
    char faculty[10];
    int id;
} struc;

// Определение структуры для узла списка
typedef struct Node {
    struc A;
    struct Node* next;
} Node;

// Функция для создания нового узла списка
Node* create(struc x) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->A = x;
    t->next = NULL;
    return t;
}

// Функция для добавления нового узла в конец списка
void back(Node** p, struc x) {
    Node* NEWe = create(x);
    Node* tpm = *p;
    while (tpm->next != NULL) {
        tpm = tpm->next;
    }
    tpm->next = NEWe;
}

// Функция для вывода списка студентов
void prin(Node* p) {
    int i = 1;
    printf("+---------------------------------------------------------+\n"
        "|   |               |     информация     |                |\n"
        "| № |      имя      |----------+---------|     фамилия    |\n"
        "|   |               |    id    |факультет|                |\n"
        "+---+---------------+----------+---------+----------------+\n");
    while (p != NULL) {
        printf("| %-2d| %-14s| %-9d| %-8s| %-15s|\n", i, p->A.name, p->A.id, p->A.faculty, p->A.surname);
        printf("+---------------------------------------------------------+\n");
        p = p->next;
        i++;
    }
    getch();
}

void main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int A = 1, i = 1;
    Node* p = 0;
    struc x;
    Node* head = 0;

    while (A != 0) {
        printf("Студент №%d\n", i);
        printf("Введите имя %d-го студента: ", i);
        scanf("%s", &x.name);
        if (x.name[0] == '*') break;
        printf("Введите номер зачётной книжки для %d-го студента: ", i);
        scanf("%d", &x.id);
        printf("Введите факультет для %d-го студента: ", i);
        scanf("%s", &x.faculty);
        printf("Введите фамилию %d-го студента: ", i);
        scanf("%s", &x.surname);
        printf("\n");
        if (A == 1) {
            p = create(x);
            head = p;
            A += 1;
        }
        else {
            back(&p, x);
        }
        i++;
    }
    prin(p);
}*/