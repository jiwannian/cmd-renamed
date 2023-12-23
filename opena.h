#pragma once
#ifndef _OPENA_H_
#define _OPENA_H_
#define NUB 100;
typedef struct LNode
{
	char key[101];
	char lvj[101];
	struct LNode* next;
}LNode,*LinkList;

typedef struct Save_Node
{
	char Elem[100];
	int nub;
}Save_Node;

//void save(LinkList L);
//void load(LinkList L);
//void Increa(LinkList L);
//void Delet(LinkList L);
//void Visit(LinkList L);
//void Xg(LinkList L);
//void MENU(LinkList L);

void opena(LinkList L);

#endif