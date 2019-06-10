/*
JTSK-320112
queue.c
Taiyr Begeyev
t.begeyev@jacobs-university.de
*/

/**
 * @file queue.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static void copy_to_node(Item item, Node *pn);
static void copy_to_item(Node *pn, Item *pi);

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
	if (!queue_is_full(pq))
	{
		printf("Putting %d into queue\n", item);
		// create a new node
		Node *newNode = (Node*) malloc(sizeof(Node));
		if (newNode == NULL) {
			printf("Error allocating memory\n");
			exit(1);
		}

		// copy item to the node
		copy_to_node(item, newNode);
		//set next pointer to the NULL
		newNode->next = NULL;

		if(queue_is_empty(pq))
			// set front node if queue is empty
			pq->front = newNode;
		else 
			// set current rear node's next pointer to new node
			(pq->rear)->next = newNode;

		// change the rear
		pq->rear = newNode; 
		pq->items++;

		return 0;
	}
	else {
		printf("Queue is full\n");
		return -1;
	}
}

int dequeue(Item *pitem, Queue *pq)
{
	if(!queue_is_empty(pq)) {
		Node *newNode = (Node*) malloc(sizeof(Node));
		if (newNode == NULL) {
			printf("Error allocating memory\n");
			exit(1);
		} 

		// copy item to a new variable
		copy_to_item(pq->front, pitem);

		newNode = pq->front;
		// reset front pointer to the next time in the queue
		pq->front = newNode->next;
		free(newNode);

		pq->items--;
		if(queue_is_empty(pq))
			initialize_queue(pq); 

		return 0;		
	}
	else {
		printf("Nothing to delete\n");
		return -1;
	}
}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}

static void copy_to_node(Item item, Node *pn)
{
	pn->item = item;
}

static void copy_to_item(Node *pn, Item *pi)
{
	*pi = pn->item;
}
