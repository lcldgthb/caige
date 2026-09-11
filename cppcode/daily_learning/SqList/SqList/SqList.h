#pragma once
#define LISTINITSIZE 100 
#define LISTINCREMENT 10 

typedef int ElemType;

typedef struct {
    ElemType* elem;
    int length;
}SqList;

void InitSqList(SqList& l)//³õÊ¼»¯
{
    ElemType* tmp = l.elem;
    delete[] tmp;
    l.elem = nullptr;
    l.length = 0;
}
//Ïú»Ù
void DestroySqList(SqList& l)
{
    ElemType* tmp = l.elem;
    delete[] tmp;
    l.elem = nullptr;
    l.length = 0;
}
//ÅÐ¿Õ
int IsSqListEmpty(SqList& l)
{
    return l.length == 0;
}
int IsSqListFull(SqList& l);
int SqListLength(SqList& l);
ElemType GetSqListElement(SqList& l, int i);
int SqListLocation(SqList& l, ElemType x);
int SqListPrior(SqList& l, ElemType x);
int SqListNext(SqList& l, ElemType x);
void InsertSqList(SqList& l, int i, ElemType x);
void DeleteSqList(SqList& l, int i);
void SortSqList(SqList& l);
void PrintSqList(SqList& l);
