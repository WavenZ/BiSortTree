#pragma once

#include <stdio.h>
#include <stdlib.h>
#ifndef Status
	#define Status int
#endif

typedef char elemtType;

typedef struct BiTNode {
	elemtType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

Status CreateBiTree(BiTree *T);
Status DestroyBiTree(BiTree *T);
Status PreOderTraverse(BiTree T, int(*visit)(elemtType e));
Status InOderTraverse(BiTree T, int(*visit)(elemtType e));
Status PostOderTraverse(BiTree T, int(*visit)(elemtType e));