#include "CircularQueue.h"

int main(void)
{
	int i;
	CircularQueue* Queue;

	CQ_CreateQueue(&Queue, 10);

	CQ_EnQueue(Queue, 1);
	CQ_EnQueue(Queue, 2);
	CQ_EnQueue(Queue, 3);
	CQ_EnQueue(Queue, 4);

	for (i = 0; i < 3; i++)
	{
		printf("DeQueue : %d, ", CQ_DeQueue(Queue));
		printf("Front : %d, Rear : %d\n", Queue->Front, Queue->Rear);
	}
	
	i = 100;
	while (CQ_IsFull(Queue) == 0)
	{
		CQ_EnQueue(Queue, i++);
	}

	printf("Capacity : %d, Size : %d\n\n", Queue->Capacity, CQ_GetSize(Queue));

	while (CQ_IsEmpty(Queue) == 0)
	{
		printf("DeQueue : %d, ", CQ_DeQueue(Queue));
		printf("Front : %d, Rear : %d\n", Queue->Front, Queue->Rear);
	}

	CQ_DestroyQueue(Queue);

	return 0;
}