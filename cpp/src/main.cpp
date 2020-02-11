//
// Created by ajz34 on 2020/2/9.
//

#include "e0001_e0100/e0011_contain_most_water.h"

#include <iostream>
using namespace std;

int main() {
    vector<int> v{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    cout << Solution().maxArea(v) << endl;
    vector<int> t{ 10,9,8,7,6,5,4,3,2,1 };
    cout << Solution().maxArea(t) << endl;
}