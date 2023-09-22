#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

struct student {
	char name[20], surname[20], faculty[10], id[10];
} chel[3];
void main() {
	SetConsoleCP(1251);//Установка языка
	SetConsoleOutputCP(1251);
	int i;
	for (i = 0; i < 3; i++) {
		printf("Введите имя студента %d: ", i + 1);
		scanf("%s", chel[i].name);
		printf("Введите фамилию студента %d: ", i + 1);
		scanf("%s", chel[i].surname);
		printf("Введите название факультета студента %d: ", i + 1);
		scanf("%s", chel[i].faculty);
		printf("Введите номер зачётной книжки студента %d: ", i + 1);
		scanf("%s", chel[i].id);
	}
	char search[50];
	printf("\nЧтобы найти студента введите имя, фамилию или номер контакта (можно ввести несколько букв или цифр): ");
	scanf("%s", search);
	printf("Результаты поиска:\n");

	for (i = 0; i < 3; i++) {
		if (strstr(chel[i].name, search) != NULL || strstr(chel[i].surname, search) != NULL || strstr(chel[i].faculty, search) || strstr(chel[i].id, search)) {
			printf("%d. %s %s %s %s\n", i + 1, chel[i].name, chel[i].surname, chel[i].faculty, chel[i].id);
		}
	}
}
