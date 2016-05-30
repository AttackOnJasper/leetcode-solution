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
#include <sstream>

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

// 141. Linked list cycle
bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return false;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        
        if (fast == slow) return true;
    }
    return false;
}

// 165. Compare Version Numbers
int compareVersion(string version1, string version2) {
    char dot;
    istringstream ss1(version1), ss2(version2);
    while (ss1 || ss2) {
        int v1 = 0, v2 = 0;
        if (ss1) ss1 >> v1 >> dot;
        if (ss2) ss2 >> v2 >> dot;
        if (v1 != v2) {
            return v1 < v2 ? -1 : 1;
        }
    }
    return 0;
}

// 168. Excel sheet column title
// 27 -> AA
// 28 -> AB
string convertToTitle(int n) {
    string result;
    while (n) {
        result.push_back('A' + (n - 1) % 26);
        n = (n - 1) / 26;
    }
    reverse(result.begin(), result.end());
    return result;
}

// 189. Rotate Array
void rotate(vector<int>& nums, int k) {
    if(k%nums.size())
    {
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k%nums.size());
        reverse(nums.begin()+k%nums.size(),nums.end());
    }
}

// 287. First Bad Version
bool isBadVersion(int version);

int helper(int first, int last) {
    if (first == last - 1) return (isBadVersion(first))? first : last;
    if (isBadVersion(first+(last-first)/2)){
        return helper(first, first+(last-first)/2);
    } else return helper(first+(last-first)/2, last);
}

int firstBadVersion(int n) {
    return helper(0, n);
}

// test
int main(int argc, const char * argv[]) {
    return 0;
}