#include <iostream>
#define MAXSIZE 6

using namespace std;

typedef int ElemType;

/*
 * 队列
 * 队空：front == rear
 * 队满：（rear+1）% MAXSIZE == front
 */

struct sqQueue {
  ElemType *base;
  int front;
  int rear;
};

// 初始化
bool initQueue(sqQueue &q) {
  q.base = new ElemType[MAXSIZE];
  q.front = 0;
  q.rear = 0;
  return true;
}

bool isEmpty(sqQueue q) { return q.front == q.rear; }

// 少用一个元素空间
bool isFull(sqQueue q) { return (q.rear + 1) % MAXSIZE == q.front; }

// 入队 后移rear指针
bool enqueue(sqQueue &q, ElemType e) {
  if (isFull(q)) {
    cerr << "full of queue" << endl;
    return false;
  }
  q.base[q.rear] = e;
  q.rear = (q.rear + 1) % MAXSIZE;
  return true;
}

// 出队 后移front指针
bool dequeue(sqQueue &q, ElemType &e) {
  if (isEmpty(q)) {
    cerr << "The queue is empty" << endl;
    return false;
  }
  e = q.base[q.front];
  q.front = (q.front + 1) % MAXSIZE;
  return true;
}

// + MAXSIZE 保证为正数
int getLength(sqQueue q) { return ((q.rear - q.front + MAXSIZE) % MAXSIZE); }

// 求队头
ElemType getHead(sqQueue q) {
  if (!isEmpty(q)) {
    return q.base[q.front];
  }
  return -1;
}

// 批量进队
void createQueue(sqQueue &q, int n) {
  ElemType input;
  for (int i = 0; i < n; ++i) {
    cout << "Enter Element: ";
    cin >> input;
    cout << q.front << " " << q.rear << endl;
    enqueue(q, input);
  }
}

void printQueue(sqQueue q) {
  cout << "queue: " << endl;
  for (int i = q.front; i != q.rear; i = (i + 1) % MAXSIZE) {
    cout << q.base[i] << " ";
  }
  cout << endl;
}

/*
 * 链式队列
 */
struct Qnode {
  ElemType data;
  Qnode *next;
};

struct linkQueue {
  Qnode *front;
  Qnode *rear;
};

void initQueue(linkQueue &q) {
  q.front = new Qnode;
  q.rear = q.front;
  q.front->data = 0;
  q.front->next = nullptr;
}

bool insertQueue(linkQueue &q, ElemType e) {
  Qnode *node = new Qnode;
  if (!node) {
    cout << "cannot generate node" << endl;
    return false;
  }
  node->data = e;
  node->next = nullptr;
  q.rear->next = node;
  q.rear = node;
  return true;
}

bool popQueue(linkQueue &q, ElemType &e) {
  if (q.front == q.rear) {
    cout << "empty queue" << endl;
    return false;
  }
  Qnode *node = q.front->next;
  e = node->data;
  q.front->next = node->next;
  delete node;
  return true;
}

bool getHead(linkQueue &q, ElemType &e) {
  if (q.front == q.rear) {
    cout << "empty queue" << endl;
    return false;
  }
  e = q.front->next->data;
  return true;
}

void printQueue(linkQueue q) {
  Qnode *temp = q.front->next;
  while (temp) {
    cout << temp->data << endl;
    temp = temp->next;
  }
}

bool destroyQueue(linkQueue &q) {
  while (q.front) {
    Qnode *temp = q.front->next;
    delete q.front;
    q.front = temp;
  }
  return true;
}
int main() {
  // 存5个元素要预留6个元素位置
  // 顺序存储
  sqQueue q;
  initQueue(q);
  createQueue(q, 5);
  printQueue(q);
  cout << "The head element: " << getHead(q) << endl;
  cout << "The length of queue: " << getLength(q) << endl;

  // 链式存储
  linkQueue lq;
  initQueue(lq);
}
