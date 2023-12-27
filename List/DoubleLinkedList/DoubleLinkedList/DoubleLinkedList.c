#include "DoubleLinkedList.h"

//��� ����
Node* DLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->prevNode = NULL;
	NewNode->nextNode = NULL;

	return NewNode;
}

//��� �Ҹ�
void DLL_DestroyNode(Node* Node)
{
	free(Node);
}

//��� �߰�
void DLL_AppendNode(Node** Head, Node* NewNode)
{
	// ��� ��尡 NULL�̶�� ���ο� ��尡 Head
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		// ������ ã�� NewNode�� �����Ѵ�.
		Node* Tail = (*Head);
		while (Tail->nextNode != NULL)
		{
			Tail = Tail->nextNode;
		}

		Tail->nextNode = NewNode;
		NewNode->prevNode = Tail; // ������ ������ �� ������ PrevNode�� ����Ų��.
	}
}

//��� ����
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

//��� ����
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

//��� Ž��
Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->nextNode;
	}

	return Current;
}

//��� �� ����
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