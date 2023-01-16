#include <iostream>

using namespace std;

#define maxSize 20
typedef int keyType;

typedef struct{
    keyType key;
} recordType;

typedef struct {
    recordType r[maxSize+1];
    int length;
} sqList;

/*
 * 插入排序
 */

// 直接插入排序
void insertSotr(sqList& l){
    int i, j;
    for(i = 2; i <= l.length; i++){
        if(l.r[i].key < l.r[i-1].key){
            l.r[0] = l.r[i]; // 赋值到哨兵位置
            // 前面的值全部往后面移动
            for(j = i-1; l.r[0].key < l.r[j].key; --j){
                l.r[j+1] = l.r[j];
            }
            // 插入正确位置
            l.r[j+1] = l.r[0];
        }
    }
}

// 折半插入排序
void binaryInsertSort(sqList& l){
    for (int i = 2; i < l.length; ++i) {
        l.r[0] = l.r[i];
        int low = 1, high = i-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(l.r[0].key < l.r[mid].key) high = mid - 1;
            else low = mid + 1;
        }
        // high+1 为 此元素应该插入的位置
        for (int j = i; j >= high+1; --j) l.r[j+1] = l.r[j];
        l.r[high+1] = l.r[0];
    }
}

// 希尔排序
// dk为步长
void shellInsert(sqList& l, int dk){
    int i, j;
    for (i = dk+1; i <= l.length; ++i) {
        if(l.r[i].key < l.r[i-dk].key){
            l.r[0] = l.r[i];
            for (j = i-dk; j>0 && l.r[0].key < l.r[j].key; j = j-dk) {
                l.r[j+dk] = l.r[j];
            }
            l.r[j+dk] = l.r[0];
        }
    }
}


void shellSort(sqList& l, int dlta[], int t){
    for (int i = 0; i < t; ++i) {
        shellInsert(l, dlta[i]);
    }
}


/*
 * 交换排序
 */

// 冒泡排序
void bubbleSort(sqList& l){
    for (int i = 1; i <= l.length-1; ++i) {
        for (int j = 1; j <= l.length-i; ++j) {
            if(l.r[j].key > l.r[j+1].key){ // 发生逆序
                // 交换
                recordType temp = l.r[j];
                l.r[j] = l.r[j+1];
                l.r[j+1] = temp;
            }
        }
    }
}

//快速排序
int partition(sqList& l, int low, int high){
    l.r[0] = l.r[low];
    int pivot = l.r[low].key;
    // 找出中心点
    while(low < high){
        while(low < high && l.r[high].key >= pivot) --high;
        l.r[low] = l.r[high];
        while(low < high && l.r[low].key <= pivot) ++low;
        l.r[high] = l.r[low];
    }
    // 中心点赋值为pivot值
    l.r[low] = l.r[0];
    return low;
}

void quickSort(sqList& l, int low, int high){
    if(low < high){
        int pivotLoc = partition(l, low, high);
        quickSort(l, low, pivotLoc-1);
        quickSort(l, pivotLoc+1, high);
    }
}

/*
 * 选择排序
 */
void selectSort(sqList& l){
    for (int i = 1; i < l.length; ++i) {
        int k = i;
        // 寻找大值的插入位置
        for (int j = i+1; j <= l.length; ++j) {
            if(l.r[j].key < l.r[k].key) k = j;
        }
        // 交换值
        if(k != i) {
            recordType temp = l.r[k];
            l.r[k] = l.r[i];
            l.r[i] = temp;
        }
    }
}






int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
