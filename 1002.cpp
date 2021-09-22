//
// Created by 小柠宝 on 2021/9/18.
//

//题目：找第二小数字

#include "iostream"
using namespace std;

int getSecSmallNumber(const int* array, int array_length);

int main(){
    int num_samples;
    int array_length = 0;
    int array[1001];
    int secSmallNum = 0;

    cin >> num_samples;
    for (int i = 0; i < num_samples; ++i) {
        cin >> array_length;
        for (int j = 0; j < array_length; ++j) {
            cin >> array[j];
        }

        secSmallNum = getSecSmallNumber(array, array_length);
        cout << secSmallNum << endl;
    }
    return 0;
}

int getSecSmallNumber(const int* array, int array_length){
    if (array_length < 2){
        cout << "array length error" << endl;
        return -1;
    }

    int firstSmallNum;
    int secSmallNum;

    //比较前两个数字
    if (array[0] < array[1]){
        firstSmallNum = array[0];
        secSmallNum = array[1];
    } else {
        firstSmallNum = array[1];
        secSmallNum = array[0];
    }

    for (int i = 2; i < array_length; ++i) {
        if (array[i] < secSmallNum){
            if (array[i] < firstSmallNum){
                // 小于first
                secSmallNum = firstSmallNum;
                firstSmallNum = array[i];
            } else {
                // 小于sec 但是 >= first
                secSmallNum = array[i];
            }
        }
    }

    return secSmallNum;
}

//todo 提高思考：在无序序列中寻找第k大数字