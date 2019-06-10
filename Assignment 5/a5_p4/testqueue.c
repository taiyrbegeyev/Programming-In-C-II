/*
JTSK-320112
testqueue.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

/**
 * @file testqueue.c
 */

#include <stdio.h>

#include "queue.h"

int main() 
{
	Queue line;
	Item temp;
	char ch;
	
	initialize_queue(&line);
	
	while (((ch = getchar()) != EOF) && (ch != 'q'))
	{
		switch (ch)	{
			case 'a':
				printf("add int: ");
				scanf("%d", &temp);
				enqueue(temp, &line);
				break;
			case 'd':
				dequeue(&temp, &line);
				printf("Removing %d from queue\n", temp);
				break;
			default:
				printf("%d items in queue\n", queue_item_count(&line));
				puts("Type a to add, d to delete, q to quit:");
		}
	}	
	empty_queue(&line);
	puts("Bye.");
	return 0;
}
