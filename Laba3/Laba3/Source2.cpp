//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//#include <string.h>
//
//typedef struct node {
//    char inf[256];  // ����������
//    struct node* next; // ������ �� ��������� ������� 
//} node;
//
//// ������� ���������� ��������, ��������� �����
//void push(node** top), review(node** top), pop(node** top);
//
//node* get_struct(void) {
//    node* p = NULL;
//    char s[256];
//
//    if ((p = (node*)malloc(sizeof(node))) == NULL)  // �������� ������ ��� ����� ������� �����
//    {
//        printf("������ ��� ������������� ������\n");
//        exit(1);
//    }
//
//    printf("������� �������� �������: \n");   // ������ ������
//    scanf("%s", s);
//    if (*s == 0)
//    {
//        printf("������ �� ���� �����������\n");
//        return NULL;
//    }
//    strcpy(p->inf, s);
//    p->next = NULL;
//    return p;    // ���������� ��������� �� ��������� �������
//}
//
///* ���������� �������� � ���� */
//void push(node** top) {
//    node* p = NULL;
//    p = get_struct();
//    if (p != NULL) {
//        p->next = *top;
//        *top = p;
//    }
//}
//
///* �������� ����������� ����� */
//void review(node** top) {
//    node* struc = *top;
//    if (*top == NULL)
//    {
//        printf("���� ����\n");
//    }
//    while (struc != NULL)
//    {
//        printf("��� - %s, \n", struc->inf);
//        struc = struc->next;
//    }
//}
//
///* ����� �������� �� �����������. */
//node* find(node** top, char* name) {
//	node* struc = *top;
//	int k = 0;
//	if (*top == NULL)
//	{
//		printf("������ ����\n");
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
//		printf("�� ������ ����������� ��������� �� �������.");
//	}
//	printf("\n");
//	return NULL;
//}
//
///* �������� �������� �� ����� */
//void pop(node** top) {
//    if (*top == NULL) {
//        printf("���� ����\n");
//        return;
//    }
//    node* temp = *top;
//    *top = (*top)->next;
//    free(temp);
//}
//
//void main() {
//    node* top = NULL; // ��������� �� ������� ������� �����
//    int choice;
//    char name[256];
//    setlocale(LC_ALL, "RUS");
//    do {
//        printf("1. �������� �������\n");
//        printf("2. ������� �������\n");
//        printf("3. ����� �������\n");
//        printf("4. ����������� ����\n");
//        printf("5. �����\n");
//        printf("�������� ��������: ");
//        scanf("%d", &choice);
//
//        switch (choice) {
//        case 1:
//            push(&top);
//            break;
//        case 2:
//            pop(&top);
//            printf("������� ������� �����!\n");
//            break;
//        case 3:
//            printf("������� �������� ������� ��� ������: ");
//            scanf("%s", &name);
//            find(&top, name);
//            break;
//        case 4:
//            system("cls");
//            review(&top);
//            break;
//        case 5:
//            system("cls");
//            printf("�� ��������!\n");
//            break;
//        default:
//            system("cls");
//            printf("����������� �����!");
//            break;
//        }
//    } while (choice != 5);
//}