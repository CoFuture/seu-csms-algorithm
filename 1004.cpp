//
// Created by Ningbao on 2021/10/30.
//

// 题目：归并排序 输出递归过程中自顶自下第三层的排序结果
#include <iostream>

using namespace std;

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
    }
    return 0;
}
