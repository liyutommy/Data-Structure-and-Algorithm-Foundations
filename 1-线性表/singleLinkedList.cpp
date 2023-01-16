#include <iostream>

using namespace std;

/*
 * 单向链表
 */
using ElementType = int;

struct Lnode{
    ElementType data;
    Lnode* next;
};

typedef Lnode *LinkList; // *Lnode = LinkList

//链表的初始化
bool InitList(LinkList& L){
    L = new Lnode;
    L->next = nullptr;
    return true;
}

//头插法建立单链表
void CreateListHead(LinkList& L, int n){
    L = new Lnode;
    L->next = nullptr;
    for(int i = n; i > 0; i--){
        Lnode* p = new Lnode;
        cout << "Enter element: ";
        cin  >> p->data;
        p->next = L->next;
        L->next = p;
    }
}

//尾插法建立单链表
void CreateListTail(LinkList& L, int n){
    L = new Lnode;
    L->next = nullptr;
    Lnode* tail = L;
    for (int i = 0; i < n; ++i) {
        Lnode* p = new Lnode;
        cout << "Enter element: ";
        cin >> p->data;
        p->next = nullptr;
        //链接新节点
        tail->next = p;
        tail = p;
    }
}

//判断链表是否为空表(头结点和头指针仍然在)
bool IsEmpty(LinkList L){
    return L->next == nullptr;
}

//销毁链表(从头结点开始释放)
bool DestroyList(LinkList& L){
    Lnode* p;
    //按顺序删除每个结点
    while(L){
        p = L->next;
        delete L;
        L = p;
    }
    return true;
}

//清空链表(头结点和头指针仍然在)
bool ClearList(LinkList& L){
    Lnode* p;
    Lnode* q;
    p = L->next;
    while(p){
        q = p->next;
        delete p;
        p = q;
    }
    //设置首原节点为空指针
    L->next = nullptr;
    return true;
}

//求表长
int GetLength(LinkList L){
    Lnode*  p = L->next;
    int length = 0;
    while(p){
        length++;
        p = p->next;
    }
    return length;
}

//取链表中第i个元素的值
bool GetElem(LinkList L, int i, ElementType& e){
    if(i < 1 || i > GetLength(L)){
        cerr << "out of range" << endl;
        return false;
    }
    Lnode*  p = L->next;
    int j = 1;
    while(p && j < i){
        p = p->next;
        j++;
    }
    if(!p || j > i){
        cerr << "out of range" << endl;
        return false;
    }
    e = p->data;
    return true;
}

//按值查找
//返回地址(找到返回L中值为e的地址，否则返回null)
LinkList LocateElemAddress(LinkList L, ElementType e){
    Lnode*  p = L->next;
    while(p && p->data != e){
        p = p->next;
    }
    return p;
}

//返回位置序号（从1开始数）
int LocateElemIndex(LinkList L, ElementType e){
    Lnode*  p = L->next;
    int j = 1;
    while(p && p->data != e){
        p = p->next;
        j++;
    }
    if(p) return j;
    else return 0;
}

//链表插入
bool InsertList(LinkList& L, int i, ElementType e){
    Lnode*  p = L;
    int j = 0;
    while(p && j < i-1){
        p = p->next;
        j++;
    }
    //i大于表长或者i小于1的时候（不包括i等于1的情况）
    if(!p || j > i-1){
        cerr << "The value of i is invalid" << endl;
        return false;
    }
    //创建结点
    auto node = new Lnode;
    node->data = e;
    //链接结点
    node->next = p->next;
    p->next = node;
    return true;
}

//链表删除
bool DeleteNode(LinkList& L, int i, ElementType& e){
    Lnode* p = L;
    int j = 0;
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
    LinkList q = p->next;
    e = q->data;
    //链接结点
    p->next = q->next;
    delete q;
    return true;
}

//打印线性表
void PrintList(LinkList L){
    cout << "The elements of LinkedList: ";
    Lnode* p = L->next;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
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
