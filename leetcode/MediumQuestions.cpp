//
//  MediumQuestions.cpp
//  leetcode
//
//  Created by Jasper Wang on 16/9/5.
//  Copyright © 2016年 Jasper. All rights reserved.
//

#include "header.hpp"

using namespace std;

// 167. Two Sum II - Input array is sorted

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size()-1;
    while(j > i){
        int temp = numbers[j]+numbers[i];
        if (temp == target) break;
        if (temp > target) j--;
        else i++;
    }
    return {i+1,j+1};
}
