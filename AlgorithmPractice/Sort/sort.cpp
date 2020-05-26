#include "sort.h"

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

    // 将 pivot 放在正确的位置（与最靠前的大于 pivot 交换）
    swap(v[r], v[lastSmallerIndex + 1]);
    return lastSmallerIndex + 1;
}

vector<int> Sort::quickSort(vector<int> &v, int l, int r){
    int partitionIndex; // 分割点（pivot）

    if(l < r){
        partitionIndex = partation(v, l, r);
        quickSort(v, l, partitionIndex - 1);
        quickSort(v, partitionIndex + 1, r);
    }

    return v;
}

