#include <iostream>

using namespace std;

#define maxInt 32767 //极大值
#define vexNum 100 //最大节点数
typedef char vertexType; //节点类型
typedef int arcType; //边的类型

/*
 * 邻接矩阵实现图
 */

typedef struct {
    vertexType vexs[vexNum];
    arcType arcs[vexNum][vexNum];
    int currentVexNum; // 当前节点数
    int currentArcNum; // 当前边数
} Graph;

int locateVex(Graph g, vertexType v){
    for (int i = 0; i < g.currentVexNum; ++i) {
        if(g.vexs[i] == v) return i;
    }
    return -1;
}

//创建无向网
void createGraph(Graph& g){
    //输入总节点数和总边数
    cout << "Enter total number of vertices and edges: ";
    cin >> g.currentVexNum >> g.currentArcNum;

    // 输入节点的名称(char类型)
    for (int i = 0; i < g.currentVexNum; ++i) {
        cin >> g.vexs[i];
    }

    // 所有的路径初始化为无穷大
    for (int i = 0; i < g.currentVexNum; ++i) {
        for (int j = 0; j < g.currentVexNum; ++j) {
            g.arcs[i][j] = maxInt;
        }
    }

    // 所有的边赋值权重
    for (int i = 0; i < g.currentArcNum; ++i) {
        char v1, v2;
        int weight;
        cout << "Enter vertex 1, vertex 2, and weight: ";
        cin >> v1 >> v2 >> weight;
        // 获取到节点1和节点2的index
        int vertex1Index = locateVex(g, v1);
        int vertex2Index = locateVex(g, v2);
        g.arcs[vertex1Index][vertex2Index] = weight;
        g.arcs[vertex2Index][vertex1Index] = weight;
    }
}

// 深度遍历 DFS
void dfs(Graph g, int vertexIndex, bool visited[]){
    cout << "vertex: " << vertexIndex;
    visited[vertexIndex] = true;
    for (int i = 0; i < g.currentVexNum; ++i) {
        // 存在一条路径，并且没有被访问过
        if((g.arcs[vertexIndex][i] != 0) && !visited[i]){
            dfs(g, i, visited);
        }
    }
}

// 广度遍历 bfs
/*
void bfs(Graph g, int vertexIndex, bool visited[]){
    cout << "vertex: " << vertexIndex;
    visited[vertexIndex] = true;
    initQueue(q);
    enqueue(q, vertexIndex);
    while(!isEmpty(q)){
        // u为出队的节点
        deQueue(q, u);
        // w为尚未访问的邻接节点
        for(w = firstAjdVex(g, u); w >= 0; w = nextAjdVex(g, u, w)){
            if(!visited[w]){
                cout << w ;
                visited[w] = true;
                enqueue(q, w);
            }
        }

    }
}
 */

/*
 * 邻接表实现图
 */

#define nodeNum 100
// 边的结构
typedef struct arcNode{
    int adjVex; //该边所指向的顶点位置
    int weight;
    struct arcNode* nextarc;
};

//节点的结构
typedef struct vertex{
    vertexType data;
    arcNode* firstArc; // 保存邻接表
} vertex, adjList[nodeNum];

//图的结构
typedef struct{
    adjList vertices; // 邻接表
    int vertexNum; // 图的当前节点
    int arcNum; // 图的边
} ALGraph;

//创建无向图
void createGraph(ALGraph& g){
    //输入图的节点个数和边的条数
    cout << "Enter total number of vertices and edges: ";
    cin >> g.vertexNum >> g.arcNum;
    //给节点赋值信息
    for (int i = 0; i < g.vertexNum; ++i) {
        cin >> g.vertices[i].data;
        g.vertices[i].firstArc = nullptr;
    }
    //给每个节点的边赋值
    for (int i = 0; i <g.arcNum; ++i) {
        char v1, v2;
        cin >> v1 >> v2;
        int i = locateVex(g, v1);
        int j = locateVex(g, v2);
        //构造节点
        arcNode* p = new arcNode;
        p->adjVex = j;
        //头插法
        p->nextarc = g.vertices[i].firstArc;
        g.vertices[i].firstArc = p;

        //构造节点
        arcNode* q = new arcNode;
        q->adjVex = i;
        //头插法
        p->nextarc = g.vertices[j].firstArc;
        g.vertices[j].firstArc = q;
    }
}



int main() {
    Graph g;
    bool visited[g.currentVexNum];

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
