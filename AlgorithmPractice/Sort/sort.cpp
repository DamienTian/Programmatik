#include "sort.h"
// #include "../helper.h"

Sort::Sort(){};
Sort::~Sort(){};

// 冒泡排序：多次对比相邻两数并调换
//  Time: O(n^2)    Space: O(1)
vector<int> Sort::bubbleSort(vector<int> v){
    vector<int> result = v;
    int n = result.size();
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - 1 - i; ++j){
            if(result[j] > result[j+1])
                swap(result[j], result[j+1]);
        }
    }

    return result;
}

// 选择排序：将数组分成两部分，前半部分有序，后半部分无序。
//           将后半部分的最小值加入前半部分。
//  Time: O(n^2)    Space: O(1)
vector<int> Sort::selectionSort(vector<int> v){
    vector<int> result = v;
    int n = result.size();

    int minIndex;   // 最小数的index
    
    for(int i = 0; i < n - 1; ++i){
        minIndex = i;
        // NOTE: j 为有序集与无序集之间的分界点
        for(int j = i + 1; j < n; ++j){
            if(result[minIndex] > result[j])
                minIndex = j;   // 更新最小数 index
        }

        swap(result[i], result[minIndex]);
    }

    return result;
}

// 插入排序: 假设第一位是排序的，往后搜索后面的数。前面的数若大则调换
//  Time: O(n^2)    Space: O(1)
vector<int> Sort::insertionSort(vector<int> v){
    vector<int> result = v;
    int n = result.size();

    for(int i = 1; i < n; ++i){
        int currentIndex = i;
        while(currentIndex > 0 && result[currentIndex] < result[currentIndex - 1]){
            swap(result[currentIndex], result[currentIndex-1]);
            --currentIndex;
        }
    }

    return result;
}

// 归并排序：将数组分割成两个两个的小数组，逐渐排序融合
//  Time: O(nlogn)  Space: O(n)
vector<int> merge(vector<int> left, vector<int> right){
    vector<int> result;

    while(left.size() > 0 && right.size() > 0){
        if(left[0] > right[0]){
            result.push_back(right[0]);
            right.erase(right.begin());
        }
        else{
            result.push_back(left[0]);
            left.erase(left.begin());
        }
    }

    // 插入剩余值
    while(left.size() > 0){
        result.push_back(left[0]);
        left.erase(left.begin());
    }

    while(right.size() > 0){
        result.push_back(right[0]);
        right.erase(right.begin());
    }

    return result;
}

vector<int> Sort::mergeSort(vector<int> v){
    int n = v.size();
    if(n < 2)   return v;

    int mid = n / 2;
    vector<int> left(v.begin(), v.begin() + mid);
    vector<int> right(v.begin() + mid, v.end());
    return merge(mergeSort(left), mergeSort(right));
}

// 快速排序：将数组基于 pivot 排列后分区，在左右分开进行排列
//  ref: https://www.youtube.com/watch?v=PgBzjlCcFvc
int partation(vector<int> &v, int l, int r){
    int pivot = v[r];   // 使用最右侧数字作为旋转点
    int lastSmallerIndex = l - 1; // 最后一个小于 pivot 的 index

    // 循环处理 pivot 之前的数字，将左右小于 pivot 放在 lastSmallerIndex 之前
    for(int i = l; i <= r - 1; ++i){
        if(v[i] <= pivot){
            ++lastSmallerIndex;
            swap(v[i], v[lastSmallerIndex]);
        }
    }

    // 将 pivot 放在正确的位置（与第一个的大于 pivot 的值交换）
    swap(v[r], v[lastSmallerIndex + 1]);
    return lastSmallerIndex + 1;
}

vector<int> Sort::quickSort(vector<int> &v, int l, int r){
    int partitionIndex; // 分割点（pivot）

    if(l < r){
        partitionIndex = partation(v, l, r);
        // 分开再次排序（左部是小于 pivot 的值，右侧是大于的）
        quickSort(v, l, partitionIndex - 1);
        quickSort(v, partitionIndex + 1, r);
    }

    return v;
}

// 堆排序 (目前仍有问题)

int len; // 因为声明的多个函数都需要数据长度，所以把len设置成为全局变量
void buildMaxHeap(vector<int> v, int len);
void heapify(vector<int>& v, int i);

// 构建 Maxheap
void buildMaxHeap(vector<int> v){
    len = v.size();
    // Q：为什么 i 等于 len / 2
    // A：因为 heap 的树状结构，在 len / 2 之后全部是叶子节点
    for(int i = len / 2 - 1; i >= 0; --i){
        heapify(v, i);
    }
}

// 将 array 堆化，调整 Maxheap
void heapify(vector<int>& v, int i){
    // 左右子节点位置
    int left = 2 * i + 1, right = 2 * i + 2;
    // 目前值最大的节点位置
    int largest = i;
    
    // 找出当前堆的最大值
    if(left < len && v[left] > v[largest]){
        largest = left;
    }
    if(right < len && v[right] > v[largest]){
        largest = right;
    }
        
    // 若堆的最大值位置改变，则继续堆化
    if(largest != i){
        swap(v[i], v[largest]);
        heapify(v, largest);
    }
}

vector<int> Sort::heapSort(vector<int> v){
    vector<int> result = v;
    buildMaxHeap(result);

    // 生成 MaxHeap 后，将顶端与末尾置换，再进行堆化
    for(int i = result.size() - 1; i > 0; --i){
        swap(result[0], result[i]);
        --len;
        heapify(result, 0);
    }

    return result;
}
