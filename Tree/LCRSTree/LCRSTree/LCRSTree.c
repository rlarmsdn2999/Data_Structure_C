#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(ElementType NewData)
{
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	NewNode->Data = NewData;
}

void LCRS_DestroyNode(LCRSNode* Node)
{
	free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root)
{
	if (Root->RightSibling != NULL)
		LCRS_DestroyTree(Root->RightSibling);
	if (Root->LeftChild != NULL)
		LCRS_DestroyTree(Root->LeftChild);

	Root->LeftChild = NULL;
	Root->RightSibling = NULL;

	LCRS_DestroyNode(Root);
}

void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child)
{
	if (Parent->LeftChild == NULL)
	{
		Parent->LeftChild = Child;
	}
	else
	{
		LCRSNode* TempNode = Parent->LeftChild;
		while (TempNode->RightSibling != NULL)
			TempNode = TempNode->RightSibling;

		TempNode->RightSibling = Child;
	}
}

void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
	int i = 0;
	for (i = 0; i < Depth; i++)
		printf(" ");
	
	printf("%c\n", Node->Data);

	if (Node->LeftChild != NULL)
		LCRS_PrintTree(Node->LeftChild, Depth + 1);
	if (Node->RightSibling != NULL)
		LCRS_PrintTree(Node->RightSibling, Depth);
}

// Ư���������
void LCRS_PrintNodesAtLevel(LCRSNode* Root, int level) {//��Ʈ /����  
	int depth = 0;
	LCRSNode* tempChild = Root;
	LCRSNode* tempParent = Root;
	while (depth <= level)// ������ �����Ҷ����� �ݺ�  
	{
		if (depth == level)// ���� �ش� ������ ��尡 �����Ѵٸ�  
		{
			while (tempChild != NULL)
			{
				printf("%c ", tempChild->Data);
				// �����͸� ����ϰ� ���� ���� �̵�
				tempChild = tempChild->RightSibling;
			}
			if (tempParent->RightSibling != NULL)
				// �θ� ����� ���� ��尡 �����Ѵٸ�
			{
				tempParent = tempParent->RightSibling;
				// �� ����� �ڽ� ���鵵 ���
				tempChild = tempParent->LeftChild;
			}
			else// �θ� ����� ���� ��尡 �������� ������ ����
				break;
		}
		else// ���̿� ������ ���� ������
		{
			tempParent = tempChild;// �θ��带 �����ϰ�           		
			tempChild = tempChild->LeftChild;// �Ѵܰ� ��������.           
			depth++;
		}
	}
	printf("\n");
}