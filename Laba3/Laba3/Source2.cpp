//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//#include <string.h>
//
//typedef struct node {
//    char inf[256];  // информация
//    struct node* next; // ссылка на следующий элемент 
//} node;
//
//// Функции добавления элемента, просмотра стека
//void push(node** top), review(node** top), pop(node** top);
//
//node* get_struct(void) {
//    node* p = NULL;
//    char s[256];
//
//    if ((p = (node*)malloc(sizeof(node))) == NULL)  // выделяем память под новый элемент стека
//    {
//        printf("Ошибка при распределении памяти\n");
//        exit(1);
//    }
//
//    printf("Введите название объекта: \n");   // вводим данные
//    scanf("%s", s);
//    if (*s == 0)
//    {
//        printf("Запись не была произведена\n");
//        return NULL;
//    }
//    strcpy(p->inf, s);
//    p->next = NULL;
//    return p;    // возвращаем указатель на созданный элемент
//}
//
///* Добавление элемента в стек */
//void push(node** top) {
//    node* p = NULL;
//    p = get_struct();
//    if (p != NULL) {
//        p->next = *top;
//        *top = p;
//    }
//}
//
///* Просмотр содержимого стека */
//void review(node** top) {
//    node* struc = *top;
//    if (*top == NULL)
//    {
//        printf("Стек пуст\n");
//    }
//    while (struc != NULL)
//    {
//        printf("Имя - %s, \n", struc->inf);
//        struc = struc->next;
//    }
//}
//
///* Поиск элемента по содержимому. */
//node* find(node** top, char* name) {
//	node* struc = *top;
//	int k = 0;
//	if (*top == NULL)
//	{
//		printf("Список пуст\n");
//	}
//	while (struc)
//	{
//		if (strstr(struc->inf, name) != NULL) {
//			printf("%s ", struc->inf);
//			k++;
//		}
//		struc = struc->next;
//	}
//	if (k == 0) {
//		printf("Ни одного подходящего элемеента не найдено.");
//	}
//	printf("\n");
//	return NULL;
//}
//
///* Удаление элемента из стека */
//void pop(node** top) {
//    if (*top == NULL) {
//        printf("Стек пуст\n");
//        return;
//    }
//    node* temp = *top;
//    *top = (*top)->next;
//    free(temp);
//}
//
//void main() {
//    node* top = NULL; // указатель на верхний элемент стека
//    int choice;
//    char name[256];
//    setlocale(LC_ALL, "RUS");
//    do {
//        printf("1. Добавить элемент\n");
//        printf("2. Удалить элемент\n");
//        printf("3. Найти элемент\n");
//        printf("4. Просмотреть стек\n");
//        printf("5. Выход\n");
//        printf("Выберите действие: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            push(&top);
//            break;
//        case 2:
//            pop(&top);
//            printf("Верхний элемент удалён!\n");
//            break;
//        case 3:
//            printf("Введите название объекта для поиска: ");
//            scanf("%s", &name);
//            find(&top, name);
//            break;
//        case 4:
//            system("cls");
//            review(&top);
//            break;
//        case 5:
//            system("cls");
//            printf("До свидания!\n");
//            break;
//        default:
//            system("cls");
//            printf("Некоректный выбор!");
//            break;
//        }
//    } while (choice != 5);
//}