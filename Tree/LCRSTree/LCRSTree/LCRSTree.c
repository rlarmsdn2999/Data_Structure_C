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

// 특정레벨출력
void LCRS_PrintNodesAtLevel(LCRSNode* Root, int level) {//루트 /깊이  
	int depth = 0;
	LCRSNode* tempChild = Root;
	LCRSNode* tempParent = Root;
	while (depth <= level)// 레벨에 도달할때까지 반복  
	{
		if (depth == level)// 만약 해당 레벨의 노드가 존재한다면  
		{
			while (tempChild != NULL)
			{
				printf("%c ", tempChild->Data);
				// 데이터를 출력하고 형제 노드로 이동
				tempChild = tempChild->RightSibling;
			}
			if (tempParent->RightSibling != NULL)
				// 부모 노드의 형제 노드가 존재한다면
			{
				tempParent = tempParent->RightSibling;
				// 그 노드의 자식 노드들도 출력
				tempChild = tempParent->LeftChild;
			}
			else// 부모 노드의 형제 노드가 존재하지 않으면 종료
				break;
		}
		else// 깊이와 레벨이 맞지 않으면
		{
			tempParent = tempChild;// 부모노드를 저장하고           		
			tempChild = tempChild->LeftChild;// 한단계 내려간다.           
			depth++;
		}
	}
	printf("\n");
}