/*
	@brief:¶þ²æÅÅÐòÊ÷
	@author:WavenZ
	@time:2018/10/12
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "BiSortTree.h"
#include "BiTree.h"

int visit(elemtType e) {
	printf("%d ", e);
}

int main(int argc, char *argv[]) {
	
	BiTree T = NULL;
	int data;
	freopen("data.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (scanf("%d", &data) != -1) {
		InserBST(&T, (elemtType)data);
	}
	InOderTraverse(T, visit);
	printf("\n");
	DeleteBST(&T, 53);
	InOderTraverse(T, visit);
	fclose(stdin);
	fclose(stdout);
	system("pause");
	return 1;
}