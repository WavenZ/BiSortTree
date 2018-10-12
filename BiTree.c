#define _CRT_SECURE_NO_WARNINGS
#include "BiTree.h"

Status CreateBiTree(BiTree *T) {
	char ch;
	scanf("%c", &ch);
	if (ch == ' ') 
		*T = NULL;
	else {
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
	return 1;
}
Status DestroyBiTree(BiTree *T) {
	if (*T) {
		if((*T)->lchild)
			DestroyBiTree(&(*T)->lchild);
		if((*T)->rchild)
			DestroyBiTree(&(*T)->rchild);
		DestroyBiTree(*T);
		*T = NULL;
	}
}
Status PreOderTraverse(BiTree T,int(*visit)(elemtType e)) {
	if (T) {
		visit(T->data);
		PreOderTraverse(T->lchild, visit);
		PreOderTraverse(T->rchild, visit);
		return 1;
	}
	else return 0;
}
Status InOderTraverse(BiTree T, int(*visit)(elemtType e)) {
	if (T) {
		InOderTraverse(T->lchild, visit);
		visit(T->data);
		InOderTraverse(T->rchild, visit); 
		return 1;
	}
	else return 0;
}
Status PostOderTraverse(BiTree T, int(*visit)(elemtType e)) {
	if (T) {
		PostOderTraverse(T->lchild, visit);
		PostOderTraverse(T->rchild, visit);
		visit(T->data);
		return 1;
	}
	else return 0;
}

