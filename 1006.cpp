//
// Created by 小柠宝 on 2021/12/5.
//

//题目 堆排序
//注意点：二叉树如果根结点序号为1，则节点n的左子节点序号为2n，右子节点序号为2n+1
//二叉树如果根结点序号为1，则节点n的左子节点序号为2n+1，右子节点序号为2n+2

#include<iostream>

using namespace std;

void swap(int &num1, int &num2);

void heapAdjust(int array[], int low, int knots_total);

void createMinHeap(int array[], int knots_total);


int main() {
    int num_samples;
    int array_length;
    int a[1000] = {0};

    cin >> num_samples;
    for (int i = 0; i < num_samples; ++i) {
        cin >> array_length;
        for (int j = 0; j < array_length; ++j) {
            cin >> a[j];
        }

        createMinHeap(a, array_length);

        for (int j = 0; j < array_length; ++j) {
            cout << a[j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void swap(int &num1, int &num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void createMinHeap(int array[], int knots_total) {
    for (int j = (knots_total - 1) / 2; j >= 0; j--) {//将无序的a[1]-a[n]数据建成一个小顶堆,其中j为二叉树的最后一个非叶子结点
        heapAdjust(array, j, knots_total);
    }
}

// 进行子树的调整
// low为要调整的节点序号，knots_total为节点总数
void heapAdjust(int array[], int low, int knots_total) {
    int i = low;
    int j = low * 2 + 1;
    //对所有子节点进行调整
    while (j < knots_total) {
        // 获取两个子节点的中的最小值
        if (j + 1 < knots_total && array[j + 1] < array[j]) {
            j = j + 1;
        }

        // 节点与子节点比较
        if (array[j] < array[i]) {
            // 交换i和j的值
            swap(array[i], array[j]);
            i = j;
            j = j * 2 + 1;
        } else {
            // 孩子中权值均比欲调整结点i大，调整结束
            break;
        }
    }
}
