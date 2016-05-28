//
//  main.cpp
//  test
//
//  Created by Jasper Wang on 16/5/22.
//  Copyright © 2016年 Jasper. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace::std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


string reverseString(string s){
    string temp;
    for (int i = 0; i < s.length(); i++){
        temp = s[i] + temp;
    }
    return temp;
}

// move zeros to the end of the list
void movingZeros(vector<int>& arr){
    int j = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i]){
            arr[j++] = arr[i];
        }
    }
    for (; j < arr.size(); j++) {
        arr[j] = 0;
    }
}


// given only that node
void deleteNode(ListNode* node) {
    if (node == NULL) return;
    if (node->next == NULL) {
        node = NULL;
        return;
    }
    node->next = node->next->next;
    node->val = node->next->val;
}


// invert tree
TreeNode* invertTree(TreeNode* root) {
    if (root == NULL) return NULL;
    TreeNode* temp = invertTree(root->right);
    root->right = invertTree(root->left);
    root->left = temp;
    return root;
}

// 8. String to Integer (atoi)
int myAtoi(string str) {
    if (!str.length()) return 0;
    int i = 0, sign = 1;
    while (i + 1 < str.size() && isspace(str[i])) ++i;
    int res = 0;
    if (str[i] == '-' || str[i] == '+') sign = 44 - str[i++];
    while (i < str.size()) {
        if (isdigit(str[i])) res = 10 * res + str[i++] - '0';
        else return res * sign;
        if (res > INT_MAX) return sign == -1 ? INT_MIN : INT_MAX;
    }
    return res * sign;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    // cout << myAtoi("-364") << endl;
    //    std::cout << reverseString("Hello, World!\n");
    return 0;
}