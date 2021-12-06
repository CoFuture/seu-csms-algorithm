//
// Created by 小柠宝 on 2021/12/5.
//

//题目 堆排序
//注意点：二叉树如果根结点序号为1，则节点n的左子节点序号为2n，右子节点序号为2n+1
//二叉树如果根结点序号为1，则节点n的左子节点序号为2n+1，右子节点序号为2n+2

#include <iostream>
#include <string>

using namespace std;

long long getNum(string str, int start, int end);


int main() {
    int num_samples;
    int array_length;
    int a[1000] = {0};

    cin >> num_samples;
    for (int i = 0; i < num_samples; ++i) {

        int len_str, num_mul;
        string str;

        // best[i][j] 表示前i个数字中插入j个乘号的最大乘积
        long long best[41][7] = {0};
        // num[i][j] 表示string 从i到j转化为数字的值
        long long num[41][41] = {0};

        cin >> len_str >> num_mul >> str;

        // 初始化num
        for (int j = 0; j < len_str; ++j) {
            for (int k = j; k < len_str; ++k) {
                num[j][k] = getNum(str, j, k);
            }
        }

        //初始化best数组部分结果
        for (int j = 0; j < len_str; ++j) {
            // 插入0个乘号，即数字本身
            best[j][0] = num[0][j];
        }

        //动态规划



        cout << endl;
    }
    return 0;
}


//输出从start～end的字符串的数字
long long getNum(string str, int start, int end){
    long long result = 0;
    for (int i = start; i <= end; ++i) {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}