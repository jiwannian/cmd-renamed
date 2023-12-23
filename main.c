
#include <stdio.h>
#include "opena.h"
#include <windows.h>

int main()
{
	LinkList OL = (LNode*)malloc(sizeof(LNode));
	int i = 0;
	OL->next = NULL;
	opena(OL);
	return 0;
}