#include "DoubleLinkedList.h"

//노드 생성
Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->prevNode = NULL;
	NewNode->nextNode = NULL;

	return NewNode;
}

//노드 소멸
void DLL_DestroyNode(Node* Node)
{
	free(Node);
}

//노드 추가
void DLL_AppendNode(Node** Head, Node* NewNode)
{
	// 헤드 노드가 NULL이라면 새로운 노드가 Head
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// 테일을 찾아 NewNode를 연결한다.
		Node* Tail = (*Head);
		while (Tail->nextNode != NULL)
		{
			Tail = Tail->nextNode;
		}

		Tail->nextNode = NewNode;
		NewNode->prevNode = Tail; // 기존의 테일을 새 테일의 PrevNode가 가르킨다.
	}
}

//노드 삽입
void DLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->nextNode = Current->nextNode;
	NewNode->prevNode = Current;

	if (Current->nextNode != NULL)
	{
		Current->nextNode->prevNode = NewNode;
	}
	Current->nextNode = NewNode;
}

//노드 제거
void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->nextNode;
		if ((*Head) == Remove)
		{
			(*Head)->prevNode = NULL;
		}
		Remove->prevNode = NULL;
		Remove->nextNode = NULL;
	}
	else
	{
		Node* Temp = Remove;
		
		if (Remove->prevNode != NULL)
			Remove->prevNode->nextNode = Temp->nextNode;

		if (Remove->nextNode != NULL)
			Remove->nextNode->prevNode = Temp->prevNode;

		Remove->prevNode = NULL;
		Remove->nextNode = NULL;
	}
}

//노드 탐색
Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->nextNode;
	}

	return Current;
}

//노드 수 세기
int DLL_GetNodeCount(Node* Head)
{
	unsigned int Count = 0;
	Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->nextNode;
		Count++;
	}

	return Count;
}