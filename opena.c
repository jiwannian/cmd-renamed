#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "opena.h"
#include <windows.h>
#include <assert.h>
#include <string.h>

void huanc()
{
	system("cls");
	for (int j = 0; j < 2; j++)
	{
		printf("���Եȣ�\n");
		for (int i = 0; i < 10; i++)
		{
			printf("-");
			Sleep(150);
		}
		system("cls");
	}
}
void save(LinkList L)
{
	FILE* fp = fopen("data_1.dat", "w");
	LinkList temp = L->next;
	while (temp) 
	{
		fputs(temp->key, fp);
		fputs(temp->lvj, fp);
		temp = temp->next;
	}
	fclose(fp);
}

void load(LinkList L)
{
	FILE* fp = fopen("data_1.dat", "w+");
	if (fp != NULL)
	{
		char ch = fgetc(fp);
		if (L->next == NULL && ch != EOF)
		{
			while (ch != EOF)
			{
				LinkList temp = (LNode*)malloc(sizeof(LNode));
				if (!temp)
					assert(temp);
				temp->key[0] = ch;
				fgets(&(temp->key[1]), (int)temp->key[0], fp);
				temp->lvj[0] = fgetc(fp);
				fgets(&(temp->lvj[1]), (int)temp->lvj[0], fp);
				ch = fgetc(fp);

				temp->next = L->next;
				L->next = temp;
			}
		}
		fclose(fp);
	}
}
void Increa(LinkList L)
{
	getchar();
	system("cls");
	char st[100] = { 0 };
	LinkList temp = (LNode*)malloc(sizeof(LNode));
	if (!temp)
		assert(temp);
	printf("new name:>");
	gets(temp->key);
	if (temp->key[0] == '#')
		return;
	strcpy(st, temp->key);
	temp->key[0] = strlen(temp->key) + 1;
	strcpy(&(temp->key[1]), st);
	for (int i = 0; i < 100; i++)
		st[i] = 0;

	printf("cmd:>");
	gets(temp->lvj);
	if (temp->lvj[0] == '#')
		return;
	strcpy(st, temp->lvj);
	temp->lvj[0] = strlen(temp->lvj) + 1;
	strcpy(&(temp->lvj[1]), st);

	temp->next = L->next;
	L->next = temp;
}
void Delet(LinkList L)
{
	getchar();
	char ch[100] = { 0 };
	printf("�������ɾ��������:�����뾮���Է��أ�>:");
	gets(ch);
	LinkList temp = L->next;
	LinkList p = L;
	while (temp)
	{
		if (temp && strcmp(&(temp->key[1]), ch) == 0)
		{
			p->next = p->next->next;
			printf("ɾ���ɹ�������\n");
			printf("�س��Լ���������\n");
			getchar();
			break;
		}
		p = temp;
		temp = temp->next;
	}

}
void Visit(LinkList L)
{
	LinkList temp = L->next;
	int i = 1;
	printf("���п�ݷ�ʽ���£�\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	while (temp)
	{
		printf("--------------------------\n");
		printf("NO.%d\n", i++);
		printf(" name: %s\n", &(temp->key[1]));
		printf(" luj : %s\n", &(temp->lvj[1]));
		temp = temp->next;
	}
	printf("--------------------------\n");
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("�س��Լ���������\n");
	getchar();
	getchar();
}
void Xg(LinkList L)
{
	LinkList temp = L->next;
	int n = 0;
	char str1[100] = { 0 };
	char str2[100] = { 0 };
	Visit(L);
	printf("��ѡ��NO:>");
	scanf("%d", &n);
	if ((char)n == '#')
		return;
	for (int i = 1; i < n; i++)
		temp = temp->next;
	printf("--------------------------\n");
	printf("NO.%d\n", n);
	printf(" name: %s\n", &(temp->key[1]));
	printf(" luj : %s\n", &(temp->lvj[1]));
	printf("--------------------------\n");
	printf("new name�����뾮�ţ����޸Ĵ��:>");

	getchar();
	gets(&str1[1]);
	str1[0] = strlen(&str1[1]) + 2;
	if (str1[1] != '#')
		strcpy(temp->key, str1);

	printf("cmd�����뾮�ţ����޸Ĵ��:>");
	gets(&str2[1]);
	str2[0] = strlen(&str2[1]) + 2;
	if (str2[1] != '#')
		strcpy(temp->lvj, str2);
}
void MENU(LinkList L)
{
	int t = 0;
	
	do {
		system("cls");
		printf("���ã�\n");
		printf("----------------\n");
		printf("---1.���cmd---\n");
		printf("---2.ɾ��cmd---\n");
		printf("---3.����cmd---\n");
		printf("---4.�޸�cmd---\n");
		printf("---0.�˳�����---\n");
		printf("��ѡ��:>");
		scanf("%d", &t);
		switch (t)
		{
		case 1:
			Increa(L);
			system("cls");
			break;
		case 2:
			Delet(L);
			save(L);
			system("cls");
			break;
		case 3:
			Visit(L);
			system("cls");
			break;
		case 4:
			Xg(L);
			system("cls");
			break;
		case 0:
			system("cls");
			save(L);
			return;
		default:
			printf("\n�Ƿ����룡����\n");
			break;
		}
	} while (t);
}
void opena(LinkList L)
{
	load(L);
	printf("����'#'�������ý��棡����\n");
	printf("�ڴ˽���ֱ���������������cmd�������\n");
	LinkList temp = L->next;
	char a[101] = { 0 };
	a[0] = 1;
	while (a[0])
	{
		gets(a);
		switch (a[0])
		{
		case '#':
			MENU(L);
			temp = L->next;
			getchar();
			system("cls");
			break;
		default:
			while (temp)
			{
				if (temp && strcmp(&(temp->key[1]), a) == 0)
				{
					system(&(temp->lvj[1]));
					system("cls");
					for (int i = 1; i < 100; i++)
						a[i] = 0;
				}
				temp = temp->next;
			}
		}
		temp = L->next;
	}
	return;
}

