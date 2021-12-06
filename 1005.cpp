//
// Created by 小柠宝 on 2021/12/5.
//

//题目 输出快速排序第二层的结果
#include<iostream>
using namespace std;

int partition(int array[], int low, int high);
void quickSort(int array[], int low, int high, int depth);


int num_samples;
int array_length;
int a[1000] = {0};
int result[1000] = {0};

int main(){
    cin >> num_samples;
    for (int i = 0; i < num_samples; ++i) {
        cin >> array_length;
        for (int j = 0; j < array_length; ++j) {
            cin >> a[j];
        }

        quickSort(a, 0, array_length-1, 1);

        for (int j = 0; j < array_length; ++j) {
            cout << result[j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// 进行一次划分排序
int partition(int array[], int low, int high){
    // 选取第一个数组值为基准pivot
    int pivot = array[low];
    while (low < high){
        // 从右往左
        while (low < high && a[high] >= pivot){
            --high;
        }
        array[low] = array[high];
        // 从左往右
        while (low < high && a[low] <= pivot){
            ++low;
        }
        array[high] = array[low];
    }
    array[low] = pivot;
    return low;
}

void quickSort(int array[], int low, int high, int depth){
    if(low < high){
        int pivot_index = partition(array, low, high);
        if (depth == 1){
            result[pivot_index] = array[pivot_index];
        }
        if (depth == 2){
            for (int i = low; i <= high; ++i) {
                result[i] = array[i];
            }
        }

        quickSort(array, low, pivot_index - 1, depth+1);
        quickSort(array, pivot_index+1, high, depth+1);
    }
}