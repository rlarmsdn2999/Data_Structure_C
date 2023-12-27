#include "LinkedQueue.h"

int main(void)
{
	Node* Popped;
	LinkedQueue* Queue;

	LQ_CreateQueue(&Queue);

	LQ_EnQueue(Queue, LQ_CreateNode("abc"));
	LQ_EnQueue(Queue, LQ_CreateNode("def"));
	LQ_EnQueue(Queue, LQ_CreateNode("ghi"));
	LQ_EnQueue(Queue, LQ_CreateNode("jkl"));

	printf("Queue Size : %d\n", Queue->Count);

	while (LQ_IsEmpty(Queue) == 0)
	{
		Popped = LQ_DeQueue(Queue);
		
		printf("DeQueue : %s\n", Popped->Data);

		LQ_DestroyNode(Popped);
	}

	LQ_CreateQueue(Queue);

	return 0;
}