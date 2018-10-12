#define _CRT_SECURE_NO_WARNINGS
#include "BiSortTree.h"

Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree *p) {
	//���ڵ�ָ��T
	//ָ��fָ��T��˫�ף���ʼΪNULL
	//ָ��pָ������Ԫ�ؽڵ�
	if (!T) {//���Ҳ��ɹ���pָ����һ�����ʵĽڵ�
		(*p) = f;
		return 0;
	}
	else if (EQ(key, T->data)) {//���ҳɹ���pָ��ǰ�ڵ�
		(*p) = T;
		return 1;
	}
	else if (LT(key, T->data)) {//���������м�������
		return SearchBST(T->lchild, key, T, p);
	}
	else//���������м�������
		return SearchBST(T->rchild, key, T, p);
}
Status InserBST(BiTree *T, elemtType e) {
	BiTree p;
	BiTNode *s = NULL;
	if (!SearchBST(*T, e, NULL, &p)) {//δ���ҳɹ�������
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
	else return 0;//Ԫ���Ѵ��ڣ����ٲ���
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
	else {//���������������Ϊ��
		q = (*p);//
		s = (*p)->lchild;
		while (s->rchild) {//qָ��ǰ���ڵ��˫�׽ڵ㣬sָ��ǰ���ڵ�
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;//��ǰ���ڵ����Ҫɾ���Ľڵ�
		if (q != *p)//���ǰ���ڵ��˫�׽ڵ㲻��Ҫɾ���Ľڵ� 
			q->rchild = s->lchild;//ǰ���ڵ��˫�׽����Һ���ָ��ǰ���ڵ�����ӣ���ǰ���ڵ�ȥ����
		else q->lchild = s->lchild;//Ҫɾ���Ľڵ����Ӿ�����ǰ���ڵ㣬������Ϊǰ���ڵ������
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



