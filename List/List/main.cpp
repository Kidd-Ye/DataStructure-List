//
//  main.cpp
//  List
//
//  Created by kidd on 2018/9/7.
//  Copyright © 2018年 Kidd. All rights reserved.
//

#include <iostream>
#define LIST_INIT_SIZE 100
#define LISTINCERTMENT 10 // 线性表存储空间的分配增量(当存储空间不够时要用到)

typedef int ElemType;
typedef struct {
    ElemType *elem;       //存储空间的基地址
    int length;      //当前线性表的长度
    int listsize;    //当前分配的存储容量
}SqList;

int InitList(SqList &L){
    //开辟一个存储空间，并把这块存储空间的基地址赋值给elem
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) {
        return -1; // 空间分配失败
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return 0;
}

int LocateElem(SqList L, ElemType X){
    // 这里函数参数SqList L中的L不是&L, 是因为查询操作不需要实际改变顺序表的元素，只需要找到位置，所以不需要传入L的地址
    int pos = -1;
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == X) {
            pos = i;
        }
    }
    return pos;
}

int ListInsert(SqList &L, int i, ElemType E){
    if (i < 1 || i > L.length+1) {
        return -1;
    }
    ElemType *q, *p;
    q = &(L.elem[i-1]);
    for (p = &(L.elem[L.length-1]); p >= q; --p) {
        *(p+1) = *p;
    }
    *q = E;
    L.length +=1;
    return 0;
}

int ListDelete(SqList &L, int pos){
    if (pos < 1 || pos > L.length) {
        return -1;
    }
    ElemType *q, *p;
    p = &(L.elem[pos-1]); //p为被删除元素的位置
    q = L.elem + L.length-1; // q指向表尾最后一个元素
    for (++p ; p <= q; ++p) {
        *(p-1) = *p;
    }
    L.length -=1;
    return 0;
}
void PrintList(SqList list){
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.elem[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    SqList list;
    InitList(list);
    int n = 5;
    for (int i = 0; i < n; i++) {
        ListInsert(list, i+1, i+1);
    }
    printf("初始化的顺序表\n");
    PrintList(list);
    
    ListDelete(list, 1);
    printf("删除第一个元素后的顺序表\n");
    PrintList(list);
    
    ListInsert(list, 3, 88);
    printf("将88插入第三个位置后的顺序表\n");
    PrintList(list);
    
    return 0;
}
