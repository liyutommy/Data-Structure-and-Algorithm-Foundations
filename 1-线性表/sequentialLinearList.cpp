#include <iostream>

# define MAXSIZE 10
using namespace std;

using ElementType = int;


/*
 * 顺序线性表
 */
struct SqList{
    ElementType* elem; // 表头
    int length; // 长度
};

// 线性表的初始化
bool InitList(SqList& L){
    L.elem = new ElementType[MAXSIZE];
    // 存储分配失败
    if(!L.elem){
        cerr<<"error"<<endl;
        return false;
    }
    L.length = 0;
    return true;
}


bool InitList(SqList& L, ElementType arr[], int len){
    L.elem = new ElementType[MAXSIZE];
    // 存储分配失败
    if(!L.elem){
        cerr<<"error"<<endl;
        return false;
    }
    L.length = 0;
    // 导入数据
    for (int i = 0; i < len; ++i) {
        L.elem[L.length] = arr[i];
        L.length++;
    }
    return true;
}

//线性表的销毁
void DestroyList(SqList& L){
    if(L.elem) delete L.elem;
}

//线性表的清空
void ClearList(SqList& L){
    L.length = 0;
}

//线性表的长度
int GetLength(SqList L){
    return L.length;
}

//判断是否为空表
bool IsEmpty(SqList& L){
    if(L.length == 0) return true;
    else return false;
}

//线性表的取值
bool GetElem(SqList L, int index, ElementType& e){
    if(index < 1 || index > L.length){
        cerr<<"error"<<endl;
        return false;
    }
    // 第i-1个单元存储着第i个数据
    e = L.elem[index-1];
    return true;
}

//线性表的查找
int LocateElem(SqList L, ElementType e){
    for(int i = 0; i < L.length; i++){
        if(L.elem[i] == e) return i+1; // 返回序号，而不是索引
    }
    return 0;
}

//线性表的插入
bool InsertList(SqList& L, int index, ElementType e){
    // index不合法或者存储空间满了
    if(index < 1 || index > L.length || L.length == MAXSIZE){
        cerr<<"error"<<endl;
        return false;
    }
    // 插入位置以及之后的元素都往后移
    for(int j = L.length-1; j >= index-1; j--){
        L.elem[j+1] = L.elem[j];
    }
    L.elem[index-1] = e; //将新元素e放入第i个位置
    L.length++;  //长度加1
    return true;
}

//线性表的删除
bool DeleteList(SqList& L, int index){
    if(index < 1 || index > L.length){
        cerr<<"error"<<endl;
        return false;
    }
    // 被删除元素之后的元素前移
    for (int j = index; j <= L.length; j++) {
        L.elem[j-1] = L.elem[j];
    }
    L.length--;
    return true;
}

//打印线性表
void PrintList(SqList L){
    cout << "The element of list: ";
    for (int i = 0; i < L.length; ++i) {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}

int main() {

    SqList L;
    ElementType a[] = {4, 3, 2, 1};
    int length = sizeof(a) / sizeof(a[0]);
    //初始化数组中的数据
    InitList(L, a, length);
    PrintList(L);
    //得到线性表长度
    cout << "The size of list: " << GetLength(L) << endl;
    //判断是否为空表
    cout << "Is an empty list? " << IsEmpty(L) << endl;
    //线性表的取值
    ElementType e;
    cout << "Get element successfully? " << GetElem(L, 3, e) << endl;
    cout << "The value of e: " << e << endl;
    cout << "Get element successfully? " << GetElem(L, 5, e) << endl;
    cout << "The value of e: " << e << endl;
    //线性表的查找
    cout <<  "The index of element: " << LocateElem(L, e) << endl;
    //线性表的插入
    e = 6;
    cout << "Insert successfully? " <<InsertList(L, 2, e) << endl;
    PrintList(L);
    //线性表的删除
    DeleteList(L, 1);
    PrintList(L);
    //线性表的清空
    ClearList(L);
    cout << "The size of list: " << GetLength(L) << endl;
    //线性表的销毁
    DestroyList(L);

    return 0;
}
