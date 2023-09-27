//#define _crt_secure_no_warnings
//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//#include <string.h>
//
//typedef struct node {
//	char inf[256];  // информация
//	struct node* next; // ссылка на следующий элемент 
//} node;
//
//// функции добавления элемента, просмотра списка
//void spstore(void), review(void), del(char* name);
//
//node* find(char* name); // функция нахождения элемента
//node* get_struct(void); // функция создания элемента
//
//node* get_struct(void) {
//	node* p = null;
//	char s[256];
//
//	if ((p = (node*)malloc(sizeof(node))) == null)  // выделяем память под новый элемент списка
//	{
//		printf("ошибка при распределении памяти\n");
//		exit(1);
//	}
//
//	printf("введите название объекта: \n");   // вводим данные
//	scanf("%s", s);
//	if (*s == 0)
//	{
//		printf("запись не была произведена\n");
//		return null;
//	}
//	strcpy(p->inf, s);
//	p->next = null;
//	return p;		// возвращаем указатель на созданный элемент
//}
//
//* последовательное добавление в список элемента (в конец)*/
//void spstore(node** head, node** last) {
//	node* p = null;
//	p = get_struct();
//	if (*head == null && p != null)	// если списка нет, то устанавливаем голову списка
//	{
//		*head = p;
//		*last = p;
//	}
//	else if (*head != null && p != null) // список уже есть, то вставляем в конец
//	{
//		(*last)->next = p;
//		*last = p;
//	}
//}
//
//* просмотр содержимого списка. */
//void review(node** head) {
//	node* struc = *head;
//	if (*head == null)
//	{
//		printf("список пуст\n");
//	}
//	while (struc != null)
//	{
//		printf("имя - %s, \n", struc->inf);
//		struc = struc->next;
//	}
//}
//
//* поиск элемента по содержимому. */
//node* find(node** head, char* name) {
//	node* struc = *head;
//	int k = 0;
//	if (head == null)
//	{
//		printf("список пуст\n");
//	}
//	while (struc)
//	{
//		if (strstr(struc->inf, name) != null) {
//			printf("%s ", struc->inf);
//			k++;
//		}
//		struc = struc->next;
//	}
//	if (k == 0) {
//		printf("ни одного подходящего элемеента не найдено.");
//	}
//	printf("\n");
//	return null;
//}
//
//// удаление элемента из начала очереди
//void dequeue(node** head) {
//	if (*head == null) {
//		printf("очередь пуста\n");
//		return;
//	}
//	node* temp = *head;
//	*head = (*head)->next;
//	free(temp);
//}
//
//void main() {
//	node* head = null, *last = null, *result = null; // указатели на первый и последний элементы списка
//	int choice;
//	char name[256];
//	setlocale(lc_all, "rus");
//	do {
//		printf("1. добавить элемент\n");
//		printf("2. удалить элемент\n");
//		printf("3. найти элемент\n");
//		printf("4. просмотреть список\n");
//		printf("5. выход\n");
//		printf("выберите действие: ");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			spstore(&head, &last);
//			break;
//		case 2:
//			dequeue(&head);
//          printf("первый элемент удалён!\n");
//			break;
//		case 3:
//			printf("введите название объекта для поиска: ");
//			scanf("%s", &name);
//			find(&head, name);
//			break;
//		case 4:
//			system("cls");
//			review(&head);
//			break;
//		case 5:
//			system("cls");
//			printf("до свидание!\n");
//			break;
//		default:
//			system("cls");
//			printf("некоректный выбор!");
//			break;
//		}
//	} while (choice != 5);
//}