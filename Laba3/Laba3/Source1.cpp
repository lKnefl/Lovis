//#define _crt_secure_no_warnings
//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//#include <string.h>
//
//typedef struct node {
//	char inf[256];  // ����������
//	struct node* next; // ������ �� ��������� ������� 
//} node;
//
//// ������� ���������� ��������, ��������� ������
//void spstore(void), review(void), del(char* name);
//
//node* find(char* name); // ������� ���������� ��������
//node* get_struct(void); // ������� �������� ��������
//
//node* get_struct(void) {
//	node* p = null;
//	char s[256];
//
//	if ((p = (node*)malloc(sizeof(node))) == null)  // �������� ������ ��� ����� ������� ������
//	{
//		printf("������ ��� ������������� ������\n");
//		exit(1);
//	}
//
//	printf("������� �������� �������: \n");   // ������ ������
//	scanf("%s", s);
//	if (*s == 0)
//	{
//		printf("������ �� ���� �����������\n");
//		return null;
//	}
//	strcpy(p->inf, s);
//	p->next = null;
//	return p;		// ���������� ��������� �� ��������� �������
//}
//
//* ���������������� ���������� � ������ �������� (� �����)*/
//void spstore(node** head, node** last) {
//	node* p = null;
//	p = get_struct();
//	if (*head == null && p != null)	// ���� ������ ���, �� ������������� ������ ������
//	{
//		*head = p;
//		*last = p;
//	}
//	else if (*head != null && p != null) // ������ ��� ����, �� ��������� � �����
//	{
//		(*last)->next = p;
//		*last = p;
//	}
//}
//
//* �������� ����������� ������. */
//void review(node** head) {
//	node* struc = *head;
//	if (*head == null)
//	{
//		printf("������ ����\n");
//	}
//	while (struc != null)
//	{
//		printf("��� - %s, \n", struc->inf);
//		struc = struc->next;
//	}
//}
//
//* ����� �������� �� �����������. */
//node* find(node** head, char* name) {
//	node* struc = *head;
//	int k = 0;
//	if (head == null)
//	{
//		printf("������ ����\n");
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
//		printf("�� ������ ����������� ��������� �� �������.");
//	}
//	printf("\n");
//	return null;
//}
//
//// �������� �������� �� ������ �������
//void dequeue(node** head) {
//	if (*head == null) {
//		printf("������� �����\n");
//		return;
//	}
//	node* temp = *head;
//	*head = (*head)->next;
//	free(temp);
//}
//
//void main() {
//	node* head = null, *last = null, *result = null; // ��������� �� ������ � ��������� �������� ������
//	int choice;
//	char name[256];
//	setlocale(lc_all, "rus");
//	do {
//		printf("1. �������� �������\n");
//		printf("2. ������� �������\n");
//		printf("3. ����� �������\n");
//		printf("4. ����������� ������\n");
//		printf("5. �����\n");
//		printf("�������� ��������: ");
//		scanf("%d", &choice);
//		switch (choice) {
//		case 1:
//			spstore(&head, &last);
//			break;
//		case 2:
//			dequeue(&head);
//          printf("������ ������� �����!\n");
//			break;
//		case 3:
//			printf("������� �������� ������� ��� ������: ");
//			scanf("%s", &name);
//			find(&head, name);
//			break;
//		case 4:
//			system("cls");
//			review(&head);
//			break;
//		case 5:
//			system("cls");
//			printf("�� ��������!\n");
//			break;
//		default:
//			system("cls");
//			printf("����������� �����!");
//			break;
//		}
//	} while (choice != 5);
//}