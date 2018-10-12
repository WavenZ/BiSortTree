#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"
#include "BasicFunctions.h"

typedef int KeyType;

Status SearchBST(BiTree T, KeyType key, BiTree f, BiTree *p);
Status InserBST(BiTree *T, elemtType e);
Status DeleteBST(BiTree *T, KeyType key);
Status Delete(BiTree *p);
