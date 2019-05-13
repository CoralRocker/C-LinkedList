#pragma once
#include <stdlib.h>

typedef struct int_LL {
	struct int_LL *nxt;
	int val;
}int_LL;

/* Initialize a linked list pointer with a given value. The list is initialized with malloc,
 * so the list will eventually have to be freed before the end of the program is reached. The
 * pointer for the next link is set to NULL, which the list always takes to mean that said 
 * link is the end of the list.
 */
int_LL *initLinkedList(int val)
{
	int_LL *ll = (int_LL*)malloc(sizeof(int_LL));
	ll->nxt = NULL;
	ll->val = val;
	return ll;
}

/* Frees every link in the list sequentially. This method assumes that the only methods used
 * to instatiate the list were the ones provided here, or malloc. 
 */
void freeLinkedList(int_LL* start)
{
	int_LL *t = start;
	while(t->nxt)
	{
		start = t->nxt;
		free(t);
		t=start;
	}
}

/* Adds an element to the back of the list.
 */
void pushBackLinkedList(int_LL *start, int val)
{
	int_LL *t = start;
	while(t->nxt != NULL)
		t = t->nxt;
	int_LL *nxt = initLinkedList(val);
	t->nxt = nxt;
}

/* Adds a link to the list at a certain index, pushing back the rest on the links.
 */
int insertLinkedList(int_LL *start, int index, int val)
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
	return insert;
}


/* Returns the amount of links in the list.
 */
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

/* Returns the value stored at a specific index in the list.
 */
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

/* Removes a link from the list, and relinks the proceeding and preceeding links to each 
 * other to preserve continuity.
 */
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

/* Sets the value of a specific link to given value.
 */
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

/* Gets the first value in the list. Basically useless, but whatever.
 */
int frontLink(int_LL *start)
{
	return start->val;
}

/* Deletes the last link in the list.
 */
void popBackLink(int_LL *start)
{
	int_LL *t = start, *t2;
	while(t->nxt)
	{
		t2 = t;
		t = t->nxt;
	}
	t2->nxt = NULL;
	free(t);
}

/* Returns the last link in the list.
 */
int backLink(int_LL *start)
{
	int_LL *t = start;
	while(t->nxt)
		t=t->nxt;
	return t->val;
}

/* Returns the pointer to the link at the given index. If the index is greater than the size of the
 * list, returns a pointer to the last link in the list. If the index is less than 0, returns a
 * pointer to the first element, which is essentialy the pointer already passed to the method by the
 * "start" parameter.
 */ 
int_LL* linkPointer(int_LL *start, int index)
{
	int_LL *t = start;
	for(int i = 0; i < index && t->nxt; i++)
	{
		t =  t->nxt;
	}
	return t;
}

/* Swaps the contents of two links at separate (or equal indexes.
 */
void swapLink(int_LL *start, int index1, int index2)
{
	int_LL *t1 = linkPointer(start, index1),
	       *t2 = linkPointer(start, index2);
	int n1 = t1->val,
	    n2 = t2->val;
	t1->val = n2;
	t2->val = n1;
}
