#include <iostream>
#define MAXSIZE 100

using namespace std;

// 顺序栈
// top指针在最后一个元素后面一个位置
// 空栈：base == top
// 栈满：top-base == stackSize

typedef int ElemType;

typedef struct {
  ElemType *base;
  ElemType *top;
  int stackSize;
  int length;
} sqStack;

// 创建栈
bool InitStack(sqStack &s) {
  s.base = new ElemType[MAXSIZE];
  if (!s.base) {
    cerr << "cannot generate stack" << endl;
    return false;
  }
  s.top = s.base;
  s.stackSize = MAXSIZE;
  s.length = 0;
  return true;
}

// 判断是否为空
bool isEmpty(sqStack s) { return s.length == 0; }

// 求栈的元素个数
int getLength(sqStack s) { return s.length; }

// 清空栈
bool clearStack(sqStack &s) {
  if (s.base) {
    s.top = s.base;
    s.length = 0;
    return true;
  }
  return false;
}

// 销毁栈
bool destoryStack(sqStack &s) {
  if (s.base) {
    delete[] s.base;
    s.length = 0;
    s.stackSize = 0;
    s.base = s.top = nullptr;
    return true;
  }
  return false;
}

bool pushStack(sqStack &s, ElemType e) {
  if (s.length == s.stackSize) {
    cerr << "full of stack" << endl;
    return false;
  }
  *s.top = e;
  s.top++; // 上移一个位置
  s.length++;
  return true;
}

// 创建栈
bool createStack(sqStack &s, int n) {
  for (int i = 0; i < n; ++i) {
    ElemType input;
    cout << "Enter the element: ";
    cin >> input;
    if (!pushStack(s, input)) {
      cerr << "full of stack" << endl;
      return false;
    }
  }
  return true;
}

// 弹出栈
bool popStack(sqStack &s, ElemType &e) {
  if (isEmpty(s)) {
    cerr << "empty stack" << endl;
    return false;
  }
  s.top--;
  e = *s.top;
  s.length--;
  return true;
}

// 压入栈
void printStack(sqStack s) {
  cout << "The elements of stack: ";
  for (int i = 0; i < s.length; ++i) {
    cout << s.base[i] << " ";
  }
  cout << endl;
}

/*
 * 链式栈
 */
typedef struct stackNode {
  ElemType data;
  stackNode *next;
} *linkStack;

void initStack(linkStack &s) {
  // 创建头结点
  s = new stackNode;
  s->data = 0;
  s->next = nullptr;
}

// 压栈 （头插法）
bool push(linkStack &s, ElemType e) {
  // 插入元素
  stackNode *node = new stackNode;
  node->data = e;
  node->next = s;
  s = node;
  return true;
}

// 创建栈
void createStack(linkStack &s, int n) {
  ElemType input;
  for (int i = 0; i < n; ++i) {
    cin >> input;
    push(s, input);
  }
}

bool pop(linkStack &s, ElemType &e) {
  if (s == nullptr) {
    cerr << "empty stack" << endl;
    return false;
  }
  // 删除元素
  e = s->data;         // 存储数据
  stackNode *node = s; // 存储地址为了后续删除
  s = s->next;
  delete node;
  return true;
}

int getLength(linkStack s) {
  if (s == nullptr) {
    return -1;
  }
  int len = 0;
  while (s) {
    len++;
    s = s->next;
  }
  return len;
}

// s直接指向栈顶
ElemType getTop(linkStack s) {
  if (s != nullptr) {
    return s->data;
  }
  return -1;
}

bool isEmpty(linkStack s) { return s == nullptr; }

bool clearStack(linkStack &s) {
  if (!s) {
    cerr << "empty stack" << endl;
    return false;
  }
  stackNode *p = s;
  while (p) {
    stackNode *q = p;
    p = p->next;
    delete q;
  }
  return true;
}

void printStack(linkStack s) {
  cout << "The elements of stack: ";
  while (s) {
    cout << s->data;
  }
  cout << endl;
}

int main() {
  // 顺序栈
  sqStack s;
  InitStack(s);
  cout << "Is the stack empty? " << isEmpty(s) << endl;
  cout << "The length of stack: " << getLength(s) << endl;
  createStack(s, 5);
  cout << "The length of stack: " << getLength(s) << endl;
  printStack(s);
  // 弹出元素
  ElemType e;
  popStack(s, e);
  cout << "The element popped out: " << e << endl;
  printStack(s);

  // 链式栈
  linkStack stack;
  initStack(stack);

  return 0;
}
