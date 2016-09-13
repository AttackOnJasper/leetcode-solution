//
//  MediumQuestions.cpp
//  leetcode
//
//  Created by Jasper Wang on 16/9/5.
//  Copyright © 2016年 Jasper. All rights reserved.
//

#include "header.hpp"

using namespace std;

// MARK: 122. Best Time to Buy and Sell Stock II

int maxProfit2(vector<int>& prices) {
    if (!prices.size()) return 0;
    int res = 0;
    for(int i = 0;i < prices.size()-1;i++){
        if (prices[i+1] > prices[i]){
            res += prices[i+1] - prices[i];
        }
    }
    return res;
}

// MARK: 167. Two Sum II - Input array is sorted

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


// MARK: 238. Product Of Array Except Self
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(),0);
    res[0] = 1;
    for(int i = 1; i < nums.size();i++){
        res[i] = res[i-1] * nums[i-1];
    }
    int right = 1;
    for(int i = nums.size()-1; i >= 0; i--){
        res[i] *= right;
        right *= nums[i];
    }
    return res;
}

// MARK: 268. Missing Number
int missingNumber(vector<int>& nums) {
    vector<int> temp(nums.size()+1, 1);
    for(int num:nums){
        temp[num]--;
    }
    for(int i = 0; i < temp.size(); i++){
        if (temp[i]) return i;
    }
    return 0;
}


// MARK: 343. Integer Break
int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (n % 3 == 1) return pow(3,(n/3)-1)*4;
    if (n % 3 == 2) return pow(3,n/3)*2;
    return pow(3,n/3);
}

// MARK: 357 Count Numbers with Unique Digits
int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;
    int res = 10;
    int digits = 9;
    int availableNumber = 9;
    while (n-- > 1 && availableNumber > 0) {
        digits = digits * availableNumber;
        res += digits;
        availableNumber--;
    }
    return res;
}

// MARK: 384. Shuffle an Array
vector<int> v1;
vector<int> v2;

/** Resets the array to its original configuration and return it. */
vector<int> reset() {
    return v1;
}

/** Returns a random shuffling of the array. */
vector<int> shuffle() {
    random_shuffle(v2.begin(),v2.end());
    return v2;
}

// MARK: 392. Is Subsequence
bool isSubsequence(string s, string t) {
    if (s == "") return true;
    int i = 0;
    for(int j = 0; j < t.length(); j++){
        if (t[j] == s[i]){
            i++;
            if (i == s.length()) return true;
        }
    }
    return false;
}