//Linked List based BFS
//Using Linked List based Queue

/*
	Reference : Introduction to Data Structure Using C, Orange Media, author : 윤성우
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_N 101

/***** type define *******/
typedef int Data;

typedef struct _node
{
	Data data;
	struct _node * next;
}Node;

typedef struct _lQueue
{
	Node * front;
	Node * rear;
}LQueue;

typedef struct _linkedList
{
	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	int(*comp)(Data d1, Data d2);
}LinkedList;

typedef LQueue Queue;
typedef LinkedList List;

/***** type define *******/

/***Global Variables***/
int visited[MAX_N];
List adjList[MAX_N];
/***********************/

/*******Function Define***/
void QueueInit(Queue * pq);
int QIsEmpty(Queue *pq);

void Enqueue(Queue * pq, Data data); // enqueue ¿¬»ê ´ã´ç È½¼ö
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);


void ListInit(List * plist);
void LInsert(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data *pdata);

Data LRemove(List * plist);
int Lcount(List * plist);

void SetSortRule(List * plist, int(*comp)(Data d1, Data d2));
/*******Function Define***/

int main(void)
{
	int n, start, target;
	int m;
	int v, u, i,j;
	
	//Queue Initiation
	Queue q;
	QueueInit(&q);
		
	scanf("%d", &n);
	scanf("%d %d", &start, &target);
	scanf("%d", &m);
	
	//node Init
	for(i=0; i<MAX_N; i++)
		ListInit(&adjList[i]);

	
	for(i=0; i<m; i++)
	{
		scanf("%d %d", &v, &u);
		LInsert(&adjList[v], u);
		LInsert(&adjList[u], v);
		//adj[v][u] = 1;
		//adj[u][v] = 1;
	}

	//Insert Data
	Enqueue(&q, start);
	visited[start] = 1;
	
	//Pop Queue
	while (!QIsEmpty(&q))
	{
		int p = Dequeue(&q);
		//printf("p : %d\n", p);
		
		if(p==target)
		{
			printf("%d\n", visited[p]-1);
			return 0;
		}
		
		int nextData;
		if(LFirst(&adjList[p], &nextData))
		{
			//printf("nextData : %d\n", nextData);
			
			if(!visited[nextData])
			{
				//printf("i : %d\n", i);
				Enqueue(&q, nextData);
				visited[nextData] = visited[p]+1;
			}
			
			while(LNext(&adjList[p], &nextData))
			{				
				if(!visited[nextData])
				{
					//printf("i : %d\n", i);
					Enqueue(&q, nextData);
					visited[nextData] = visited[p]+1;
				}
				
			}
		}
		
	}
	
	printf("-1\n");

	return 0;
}

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	
	newNode->next = plist->head->next;
	plist->head->next = newNode;
	
	(plist->numOfData)++;
}

void SInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	Node * pred = plist->head;
	newNode->data = data;

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numOfData)++;
}

void LInsert(List *plist, Data data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List * plist, Data * pdata)
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;

}

void SetSortRule(List * plist, int(*comp)(Data d1, Data d2))
{
	plist->comp = comp;
}
 
void QueueInit(Queue *pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue *pq)
{
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data Dequeue(Queue * pq)
{
	Node * delNode;
	Data retData;

	if (QIsEmpty(pq))
	{
		//printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	return retData;
}

Data QPeek(Queue *pq)
{
	if (QIsEmpty(pq))
	{
		//printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->front->data;
}
