#include <iostream>
#include <vector>

using namespace std;

#define maxSize 100
typedef int keyType;

struct elemType{
    keyType key;
};

struct ssTable{
    elemType* r; // 表基地址
    int length; // 表长
};

/*
 * 顺序查找
 */

// 第一个位置为空
int searchSeq(ssTable t, keyType k){
    for (int i = t.length; i >=1 ; --i) {
        if(t.r[i].key == k) return i;
    }
    return 0;
}

// 另一种形式
int otherSearchSeq(ssTable t, keyType k){
    for (int i = t.length; t.r[i].key != k; --i) {
        if(i <= 0) break;
    }

    return (i > 0)? i : 0;
}

// 另一种形式
int anotherSearchSeq(ssTable t, keyType k){
    for (int i = t.length; t.r[i].key != k && i > 0; --i);
    return (i > 0)? i : 0;
}

// 改进版
int advancedSearchSeq(ssTable t, keyType k){
    //把要查找的值存在第一个位置
    t.r[0].key = k;
    int i;
    for (i = t.length; t.r[i].key != k; --i);
    return i; // i = 0的话，就不存在查找的值
}

// 二分查找
int binarySearch(ssTable t, keyType k){
    int low = 1;
    int high = t.length;
    while(low <= high){
        int mid = (low + high) / 2;
        if(t.r[mid].key == k) return mid;
        if(k < t.r[mid].key){
            high = mid - 1;
        }
        if(k > t.r[mid].key)){
            low = mid + 1;
        }
    }
    return -1;
}

// 二分查找 递归版
int recursiveBinarySearch(ssTable t, keyType k, int low, int high){
    // 递归的终止条件
    if(low > high){
        return -1;
    }
    int mid = (low + high) / 2;
    if(t.r[mid].key == k) return mid;
    if(k < t.r[mid].key){
        return recursiveBinarySearch(t, k, low, mid-1);
    }
    if(k > t.r[mid].key)){
        return recursiveBinarySearch(t, k, mid+1, high);
    }
}


/*
 * 二叉树的查找算法
 */
typedef struct bstNode{
    elemType data;
    struct bstNode* leftChild;
    struct bstNode* rightChild;
} bstNode, *bstTree;


bstTree searchBST(bstTree t, keyType k){
    // 如果为空，返回空指针
    if(!t || k == t->data.key) return t;
    // 否则去左子树查找
    else if(k < t->data.key) return searchBST(t->leftChild, k);
    // 否则去右子树查找
    else return searchBST(t->rightChild, k);
}

// 二叉树的插入
void insertBST(bstTree& t, keyType k){
    //空树
    if(t == nullptr){
        t = new bstNode;
        t->data = k;
    }

    if(k == t->data.key){
        return;
    } else if(k < t->data.key){
        insertBST(t->leftChild, k);
    } else{
        insertBST(t->rightChild, k);
    }
}

// 二叉树的生成
void createBST(bstTree& t){
    vector<elemType> vec;
    elemType input;
    while(cin >> input.key){
        vec.push_back(input);
    }
    //调用插入算法
    for (vector<elemType>::iterator it = vec.begin();  it != vec.end(); ++it) {
        insertBST(t, *it);
    }
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
