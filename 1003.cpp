//
// Created by Ningbao on 2021/10/30.
//

// 题目：冒泡排序 输出一次冒泡时候的结果
#include <iostream>
using namespace std;

void oneBubbleSort(int *array, int length);

int main() {
    int n;
    int a[1000];
    int num_count = 0;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num_count;
        for (int j = 0; j < num_count; ++j) {
            cin >> a[j];
        }

        //排序
        oneBubbleSort(a, num_count);

        //输出
        for (int j = 0; j < num_count; ++j) {
            if (j != num_count - 1) {
                cout << a[j] << " ";
            } else {
                cout << a[j] << endl;
            }
        }
    }

    return 0;
}


void oneBubbleSort(int *array, int length) {
    int temp;
    for (int i = 0; i < length - 1; ++i) {
        if (array[i] > array[i + 1]) {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
    }
}
