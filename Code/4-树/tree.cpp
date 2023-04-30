#include <iostream>
#include <vector>

using namespace std;

typedef int ElementType;

typedef struct BiNode{
    ElementType data;
    struct BiNode* leftChild;
    struct BiNode* rightCHild;
} BiNode, *BiTree;

/*
 * 遍历算法
 */
// 递归实现
//前序遍历 - 根左右
bool preorderTraverse(BiTree t){
    if(t == nullptr) return true;
    cout << t->data << endl;
    preorderTraverse(t->leftChild);
    preorderTraverse(t->rightCHild);
    return true;
}

//中序遍历 - 左根右
bool inorderTraverse(BiTree t){
    if(t == nullptr) return true;
    preorderTraverse(t->leftChild);
    cout << t->data << endl;
    preorderTraverse(t->rightCHild);
    return true;
}

//后序遍历 - 左右根
bool postorderTraverse(BiTree t){
    if(t == nullptr) return true;
    preorderTraverse(t->leftChild);
    preorderTraverse(t->rightCHild);
    cout << t->data << endl;
    return true;
}

//非递归实现
//中序遍历
/*
bool inOrderTraverse(BiTree t){
    BiTree node = t;
    BiTree q;
    Stack s;
    while(node || !isEmpty(s)){
        if(node){
            push(s, node);
            node = node->leftChild;
        } else{
            pop(s, q);
            cout << q->data << endl;
            node = node->rightCHild;
        }
    }
}
 */

//层序遍历
/*
void levelorderTraverse(BiTree t){
    BiTree node;
    Queue q;
    enQueue(q, t);
    while(!isEmpty(q)){
        deQueue(q, node);
        cout << node->data << endl;
        if(node->leftChild != nullptr) enQueue(q, node->leftChild);
        if(node->rightCHild != nullptr) enQueue(q, node->rightCHild);
    }
}
 */

// 二叉树的建立 （先序遍历）
// 一层一层下去赋值结点
bool createTree(BiTree& t){
    ElementType input;
    cout << "Enter data: ";
    cin >> input;
    if(input == -1) return false;
    t = new BiNode;
    t->data = input;
    //创建左子树
    createTree(t->leftChild);
    //创建右子树
    createTree(t->rightCHild);
    return true;
}

// 二叉树的复制
// 一层一层下去复制
bool copyTree(BiTree t, BiTree& newT){
    if(t == nullptr){
        newT = nullptr;
        return false;
    }
    newT = new BiNode;
    newT->data = t->data;
    copyTree(t->leftChild, newT->leftChild);
    copyTree(t->rightCHild, newT->rightCHild);
    return true;
}

// 求二叉树的深度
int getDepth(BiTree t){
    if(t == nullptr) return 0;
    int l = getDepth(t->leftChild);
    int r = getDepth(t->rightCHild);
    return (l > r)? l : r;
}

// 求节点数
int getNodeNum(BiTree t){
    if(t == nullptr) return 0;
    // 1 为根节点
    return getNodeNum(t->leftChild) + getNodeNum(t->rightCHild) + 1;
}

// 求叶子数
int getLeafNum(BiTree t){
    // 空树返回0
    if(t == nullptr) return 0;
    // 叶子节点数返回1
    if(t->leftChild == nullptr && t->rightCHild == nullptr) return 1;
    return getLeafNum(t->leftChild) + getLeafNum(t->rightCHild);
}

/*
 * 哈夫曼树
 */
typedef struct{
    int weight;
    int parent;
    int leftChild;
    int rightChild;
}htNode, *huffmanTree;

// 初始化树
void initTree(huffmanTree& t, int n){
    t = new htNode[2*n];
    for (int i = 1; i < 2*n; ++i) {
        t[i].parent = t[i].leftChild = t[i].rightChild = 0;
    }
    for (int i = 0; i <= n; ++i) {
        cin >> t[i].weight;
    }
}

// 构造哈夫曼树
void createHuffmanTree(huffmanTree& t, int length){
    //第一步：初始化哈夫曼树
    initTree(t, length);
    //第二步：找出当前森林中最小的两棵树，创建新树，并让原来的两个树作为新树的孩子
    for (int i = length+1; i < 2*length; ++i) {
        int s1 = 0, s2 = 0;
        select(t, i-1, s1, s2); //关键
        t[i].leftChild = s1;
        t[i].rightChild = s2;
        t[s1].parent = i;
        t[s2].parent = i;
        t[i].weight = t[s1].weight + t[s2].weight;
    }
}

void select(huffmanTree& t, int n, int& s1, int& s2){
    vector<int> vec;
    for (int i = 1; i <= n; ++i) {
        if(t[i].parent == 0){
            vec.push_back(i);
        }
    }
    //找出最小的一个
    auto flag1 = vec.begin();
    for (auto it = vec.begin()+1; it != vec.end(); ++it) {
        if(t[*it].weight < t[*flag1].weight){
            flag1 = it;
        }
    }
    s1 = *flag1; // 最小的元素下标

    auto flag2 = vec.begin();
    for (auto it = vec.begin()+1; it != vec.end(); ++it) {
        if(t[*it].weight < t[*flag2].weight){
            flag2 = it;
        }
    }
    s2 = *flag2; // 第二小的元素下标
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
