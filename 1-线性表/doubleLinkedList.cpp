#include <iostream>

using namespace std;

/*
 * 双向链表
 */
using ElementType = int;

struct DLnode{
    ElementType data;
    DLnode* prev;
    DLnode* next;
};

typedef DLnode *DLinkList; // *Lnode = LinkList

//链表的初始化
bool InitList(DLinkList& L){
    L = new DLnode;
    L->prev = nullptr;
    L->next = nullptr;
    return true;
}

//头插法建立双向链表（L后面的永远是新的节点）
void CreateListHead(DLinkList& L, int n){
    L = new DLnode;
    L->prev = nullptr;
    L->next = nullptr;
    for(int i = n; i > 0; i--){
        DLnode* node = new DLnode;
        cout << "Enter element: ";
        cin  >> node->data;
        //链接结点（关键是一直用L去链接的）
        node->next = L->next;
        node->prev = L;
        //排除掉插入第一个结点的时候，L->next是空指针
        if(L->next) L->next->prev = node;
        L->next = node;
    }
}

//尾插法建立双向链表
void CreateListTail(DLinkList& L, int n){
    L = new DLnode;
    L->prev = nullptr;
    L->next = nullptr;
    DLnode* tail = L;
    for(int i = 0; i < n; i++){
        DLnode* node = new DLnode;
        cout << "Enter element: ";
        cin  >> node->data;
        //链接结点
        node->next = tail->next;
        node->prev = tail;
        tail->next = node;
        //尾指针指向新的节点(关键)
        tail = node;
    }
}

//链表插入（头插入，不需要考虑空指针）
bool InsertList(DLinkList& L, int i, ElementType e){
    DLnode*  p = L;
    int j = 0;
    // p为插入节点前一个节点
    while(p && j < i-1){
        p = p->next;
        j++;
    }
    //i大于表长或者i小于1的时候（不包括i等于1的情况）
    if(!p || j > i-1){
        cerr << "The value of i is invalid" << endl;
        return false;
    }
    //创建新的节点
    DLnode* node = new DLnode;
    node->data = e;
    //链接结点
    node->next = p->next;
    node->prev = p;
    p->next->prev = node;
    p->next = node;
    return true;
}

//链表删除
bool DeleteNode(DLinkList & L, int i, ElementType& e){
    DLnode* p = L;
    int j = 0;
    // p为删除节点前一个节点
    while(p && j < i-1){
        p = p->next;
        j++;
    }
    //i大于表长或者i小于1的时候（不包括i等于1的情况）
    if(!p || j > i-1){
        cerr << "The value of i is invalid" << endl;
        return false;
    }
    //保存删除结点的指针和值
    DLnode* q = p->next;
    e = q->data;
    //链接结点
    p->next = q->next;
    //排除删除节点为最后一个节点的情况
    if(p->next) p->next->prev = p;
    delete q;
    return true;
}



//打印线性表
void PrintList(DLinkList L){
    cout << "The elements of LinkedList: ";
    DLnode* p = L->next;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}



int main(){
    //初始化数组中的数据
    DLinkList L;
    CreateListTail(L, 5);
    PrintList(L);
    //插入数据
    InsertList(L, 1, 8);
    PrintList(L);
    //删除数据
    ElementType e;
    DeleteNode(L, 6, e);
    PrintList(L);
    cout << "删除的数据值：" << e << endl;

    return 0;
}
