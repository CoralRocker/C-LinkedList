#include <stdio.h>
#include "LinkedList.h"

void printLL(int_LL *start)
{
	for(int i = 0; i < linkedListSize(start);i++)
		printf("Link %d: %d\n", i, getLink(start, i));
}

int main()
{
	printf("init linkeded list to 500\n");
	int_LL *l = initLinkedList(500);
	printf("LL: %d\n", getLink(l, 0));

	printf("Push back linked list 20\n");
	pushBackLinkedList(l, 20);
	printLL(l);

	printf("Insert linked list to 1 23\n");
	insertLinkedList(l, 1, 23);
	printLL(l);

	printf("Linked List Size: %d\n", linkedListSize(l));

	printf("Get link 0: %d\n", getLink(l, 0));

	printf("Delete link 1\n");
	deleteLink(l, 1);
	printLL(l);

	printf("Set link 0 to 234\n");
	setLink(l, 0, 234);
	printLL(l);

	freeLinkedList(l);
}
