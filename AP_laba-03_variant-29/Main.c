#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct addr
{
	char name[30];
	double rating;
} addr_list;

addr_list student[MAX];


void enter(void);
void delete(void);
void list(void);
int menu_select(void);
int find_free(void);
void quick_struct(addr_list items[], int count);
void qs_struct(addr_list items[], int left, int right);
void TwoMax(addr_list items[]);



int main(void)
{
	system("chcp 1251");
	system("color F0");
	char choice;
	int count = 0;
	int left = 0;
	for (;;) {
		choice = menu_select();
		switch (choice)
		{
		case 1: enter();
			count++;
			printf("%d", count);
			break;
		case 2: delete();
			break;
		case 3: list();
			break;
		case 4: qs_struct(student, left, count);
			break;
		case 5: TwoMax(student);
			break;
		case 6: system("cls");
			break;
		case 0: exit(0);
		}
	}
	return 0;
}
//

int menu_select(void)
{
	char s[80];
	int c;
	printf("--Меню--\n");
	printf("1. Додати запис\n");
	printf("2. Видалити запис\n");
	printf("3. Вивести всі записи\n");
	printf("4. Відсортувати \n");
	printf("5. вивести 2 максимальні\n");;
	printf("6. Очистити екран\n");
	printf("0. Завершити роботу з програмою\n\n");
	do {
		printf("\n Введіть номер потрібного пункту: ");
		gets(s);
		c = atoi(s);
	} while (c < -1 || c>8);
	return c;
}
//
void enter(void)
{

	int slot;
	char s[80];

	slot = find_free();
	if (slot == -1) {
		printf("\n Список заповнений");
		return;
	}

	printf("Введіть ім'я: ");
	gets(student[slot].name);

	printf("Введіть бал: ");
	gets(s);
	student[slot].rating = strtoul(s, '\0', 10);

}
int find_free(void)
{
	register int t;
	for (t = 0; student[t].name[0] && t < MAX; ++t);
	if (t == MAX) return -1;
	return t;
}
void delete(void) {
	register int slot;
	char s[80];

	printf("Введіть номер запису: ");
	gets(s);
	slot = atoi(s);
	if (slot >= 0 && slot < MAX)
		student[slot].name[0] = '\0';
}

void TwoMax(addr_list items[])
{
	register int i;
	int first = 0;
	int first_i = 0;
	int second = 0;
	int second_i = 0;
	for (i = 0; i < MAX; i++)
	{
		if (first < student[i].rating)
		{
			first = student[i].rating;
			first_i = i;
		}
	}
	for (i = 0; i < MAX; i++)
	{
		if ((second < student[i].rating) && (student[i].rating < first))
		{
			second = student[i].rating;
			second_i = i;
		}
	}
	puts("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");
	printf("Ім'я %s\n", student[first_i].name);
	printf("Рейтинговий бал %lf\n", student[first_i].rating);
	puts("---------------------------------------------------");
	printf("Ім'я %s\n", student[second_i].name);
	printf("Рейтинговий бал %lf\n", student[second_i].rating);
	puts("+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+");

}

void quick_struct(addr_list items[], int count)
{
	qs_struct(items, 0, count - 1);
}

void qs_struct(addr_list items[], int left, int right)
{
	register int i, j;
	char* x;
	struct addr temp;
	i = left; j = right + 1;

	x = items[(left + right) / 2].name;
	do {
		while ((strcmp(student[i].name, x) < 0) && (i < right)) i++;
		while ((strcmp(student[j].name, x) > 0) && (j > left)) j--;
		if (i <= j) {
			temp = items[i];
			items[i] = items[j];
			items[j] = temp;
			i++; j--;
		}
	} while (i <= j);
	if (left < j) qs_struct(items, left, j);
	if (i < right) qs_struct(items, i, right);
}

void list(void) {
	register int t;
	for (t = 0; t < MAX; ++t) {
		if (student[t].name[0]) {
			if (t == 0)
				printf("---|Початок потоку данх|---\n");
			printf("Ім'я %s\n", student[t].name);
			printf("Рейтинговий бал %lf\n", student[t].rating);
			printf("\n");
		}
	}
	printf("---|Кінець потоку данх|---\n");
	printf("\n\n");
}