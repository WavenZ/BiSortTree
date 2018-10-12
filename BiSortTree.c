#define _CRT_SECURE_NO_WARNINGS
#include "BiSortTree.h"

Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree *p) {
	//根节点指针T
	//指针f指向T的双亲，初始为NULL
	//指针p指向数据元素节点
	if (!T) {//查找不成功，p指向上一个访问的节点
		(*p) = f;
		return 0;
	}
	else if (EQ(key, T->data)) {//查找成功，p指向当前节点
		(*p) = T;
		return 1;
	}
	else if (LT(key, T->data)) {//在左子树中继续查找
		return SearchBST(T->lchild, key, T, p);
	}
	else//在右子树中继续查找
		return SearchBST(T->rchild, key, T, p);
}
Status InserBST(BiTree *T, elemtType e) {
	BiTree p;
	BiTNode *s = NULL;
	if (!SearchBST(*T, e, NULL, &p)) {//未查找成功，插入
		s=(BiTree)malloc(sizeof(BiTNode));
		s->data = e;
		s->lchild = NULL;
		s->rchild = NULL;
		if (!p) 
			*T = s;
		else if (LT(e, p->data))
			p->lchild=s;
		else p->rchild = s;
		return 1;
	}
	else return 0;//元素已存在，不再插入
}
Status Delete(BiTree *p) {
	BiTNode *q,*s;
	if (!(*p)->lchild) {
		q = (*p);
		*p = (*p)->rchild;
		free(q);
	}
	else if (!(*p)->rchild) {
		q = (*p);
		*p = (*p)->lchild;
		free(q);
	}
	else {//如果左右子树都不为空
		q = (*p);//
		s = (*p)->lchild;
		while (s->rchild) {//q指向前驱节点的双亲节点，s指向前驱节点
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;//用前驱节点代替要删除的节点
		if (q != *p)//如果前驱节点的双亲节点不是要删除的节点 
			q->rchild = s->lchild;//前驱节点的双亲结点的右孩子指向前驱节点的左孩子（把前驱节点去掉）
		else q->lchild = s->lchild;//要删除的节点左孩子就是其前驱节点，则左孩子为前驱节点的左孩子
		free(s);
	}
	return 1;
}
Status DeleteBST(BiTree *T, KeyType key) {
	if (!T) return 0;
	else {
		if (EQ(key, (*T)->data)) 
			return Delete(T);
		else if (LT(key, (*T)->data)) 
			return DeleteBST(&(*T)->lchild,key);
		else 
			return DeleteBST(&(*T)->rchild, key);
	}
}



