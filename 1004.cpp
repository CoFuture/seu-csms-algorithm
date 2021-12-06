//
// Created by 小柠宝 on 2021/12/4.
//

//题目 输出归并排序第三层的结果
#include<iostream>
using namespace std;

void mergesort(int *a, int start, int end);
void merge(int a[], int start, int mid, int end);

int threshold;
int array_length;

int main() {
    int num_samples;
    int array[1000];

    cin >> num_samples;
    for (int i = 0; i < num_samples; ++i) {
        cin >> array_length;
        for (int j = 0; j < array_length; ++j) {
            cin >> array[j];
        }

        threshold = array_length / 2;
        //数组初始化完成
        mergesort(array, 0, array_length - 1);
    }
    return 0;
}

// 归并排序
void mergesort(int *a, int start, int end) {
    // 数组长度为1 返回
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    mergesort(a, start, mid);
    mergesort(a, mid + 1, end);

    if (end - start == threshold || end - start == threshold - 1) {
        // 输出
        for (int i = start; i <= end; ++i) {
            if(i == array_length - 1)
                cout << a[i] << endl;
            else
                cout << a[i] << " ";
        }
    }

    merge(a, start, mid, end);
}


// 归并函数
void merge(int *a, int start, int mid, int end) {
    int result[array_length];
    int k = 0;

    //两个游标
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end) {
        if (a[i] < a[j]) {
            result[k++] = a[i++];
        } else {
            result[k++] = a[j++];
        }
    }

    // 将剩下的一段合并进去
    if (i == mid + 1) {
        while (j <= end)
            result[k++] = a[j++];
    }

    if (j == end + 1) {
        while (i <= mid)
            result[k++] = a[i++];
    }

    for (j = 0, i = start; j < k; i++, j++) {
        a[i] = result[j];
    }
}

