#include <iostream>

using namespace std;

/*
 * 循环链表
 */
using ElementType = int;

struct CLnode{
    ElementType data;
    CLnode* next;
};

typedef CLnode *circularLinkList; // *Lnode = LinkList

//链表的初始化
bool InitList(circularLinkList& L){
    L = new CLnode;
    L->next = L;
    return true;
}





int main(){
    //初始化数组中的数据
    LinkList L;
    CreateListHead(L, 5);
    PrintList(L);
    //判断是否为空表
    cout << "Is it an empty list? ";
    cout << IsEmpty(L) << endl;
    //取值
    ElementType e;
    GetElem(L, 2, e);
    cout << "The value of element: " << e << endl;
    //求表长
    cout << "The length of list: " << GetLength(L) << endl;
    //按值查找
    cout << "The index of the element: " << LocateElemIndex(L, 5) << endl;
    //插入元素
    InsertList(L, 5, 20);
    PrintList(L);
    //删除元素
    DeleteNode(L, 4, e);
    cout << "The value of removed element: " << e << endl;
    //清空链表
    ClearList(L);
    PrintList(L);
    //销毁链表
    DestroyList(L);
    PrintList(L);
    return 0;
}
