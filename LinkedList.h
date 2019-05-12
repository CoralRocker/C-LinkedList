#pragma once
#include <stdlib.h>

typedef struct int_LL {
	struct int_LL *nxt;
	int val;
}int_LL;

int_LL *initLinkedList(int val)
{
	int_LL *ll = (int_LL*)malloc(sizeof(int_LL));
	ll->nxt = NULL;
	ll->val = val;
	return ll;
}

void freeLinkedList(int_LL* start)
{
	int_LL *t = start;
	while(t->nxt != NULL)
	{
		start = t->nxt;
		free(t);
		t=start;
	}
}

void pushBackLinkedList(int_LL *start, int val)
{
	int_LL *t = start;
	while(t->nxt != NULL)
		t = t->nxt;
	int_LL *nxt = initLinkedList(val);
	t->nxt = nxt;
}

void insertLinkedList(int_LL *start, int index, int val)
{
	int_LL *t = start;
	for(int i = 0; i < index - 1; i++)
	{
		if(t->nxt != NULL)
			t = t->nxt;
		else
			break;
	}
	int_LL *nxt = t->nxt;
	int_LL *insert = initLinkedList(val);
	t->nxt = insert;
	insert->nxt = nxt;
}

int linkedListSize(int_LL *start)
{
	if(start == NULL)
		return 0;
	int_LL *t = start;
	int count = 1;
	while(t->nxt != NULL)
	{
		t = t->nxt;
		count++;
	}
	return count;
}

int getLink(int_LL *start, int index)
{
	int_LL *t = start;
	for(int i = 0; i < index; i++)
	{
		if(t->nxt == NULL)
			break;
		t = t->nxt;
	}
	return t->val;
}

void deleteLink(int_LL *start, int index)
{
	int_LL *t = start, *t2;
	for(int i = 0; i < index - 1; i++)
	{
		if(t == NULL)
			return;
		t=t->nxt;
	}
	t2 = t;
	t = t->nxt;
	t2->nxt = t->nxt;
	free(t);
}

void setLink(int_LL *start, int index, int val)
{
	int_LL *t = start;
	for(int i = 0; i < index; i++)
	{
		t = t->nxt;
		if(t == NULL)
			return;
	}
	t->val = val;
}
