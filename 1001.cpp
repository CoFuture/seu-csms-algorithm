//
// Created by Ningbao on 2021/10/30.
//

//题目：统计字符个数
#include <iostream>
using namespace std;

int main(){
    int n;
    char input[110];
    int count = 0;
    cin >> n;
    //获取n那一层的输入
    cin.getline(input, 10);

    for (int i = 0; i < n; ++i) {
        cin.getline(input, 100);
        for (int j = 0; input[j] != '\0'; ++j) {
            if (input[j] >= '0' && input[j] <= '9'){
                count++;
            }
        }
        cout << count << endl;
        count = 0;
    }
    return 0;
}