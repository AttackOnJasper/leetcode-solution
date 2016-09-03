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
#include <unordered_map>

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

// 11. Contains most water
int maxArea(vector<int>& height) {
    int curMax = 0;
    int length = height.size() - 1;
    int i = 0;
    int j = length;
    while (j > i) {
        if (height[i] > height[j]) {
            curMax = height[j]*length > curMax? height[j]*length : curMax;
            j--;
        } else {
            curMax = height[i]*length > curMax? height[i]*length : curMax;
            i++;
        }
        length--;
    }
    return curMax;
}

// 15. 3Sum
vector<vector<int> > threeSum(vector<int> &num) {
    
    vector<vector<int> > res;
    
    std::sort(num.begin(), num.end());
    
    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;
        
        while (front < back) {
            
            int sum = num[front] + num[back];
            
            // Finding answer which start from number num[i]
            if (sum < target)  front++;
            
            else if (sum > target)  back--;
            
            else {
                vector<int> triplet(3, 0);
                triplet[0] = num[i];
                triplet[1] = num[front];
                triplet[2] = num[back];
                res.push_back(triplet);
                
                // Processing duplicates of Number 2
                // Rolling the front pointer to the next different number forwards
                while (front < back && num[front] == triplet[1]) front++;
                
                // Processing duplicates of Number 3
                // Rolling the back pointer to the next different number backwards
                while (front < back && num[back] == triplet[2]) back--;
            }
            
        }
        
        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i]) i++;
        
    }
    
    return res;
    
}

// 18. 4Sum
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++){
        for (int j = i + 1; j < nums.size(); j++) {
            int start = j+1;
            int end = nums.size() - 1;
            int curTarget = target - nums[i] - nums[j];
            while (end > start) {
                if (nums[end] + nums[start] > curTarget) end--;
                else if (nums[end] + nums[start] < curTarget) start++;
                else {
                    vector <int> newRow = {nums[i], nums[j], nums[start], nums[end]};
                    result.push_back(newRow);
                    start++;
                    end--;
                }
            }
        }
    }
    sort( result.begin(), result.end() );
    result.erase( unique( result.begin(), result.end() ), result.end() );
    return result;
    
}


// 22. Generate Parenthesis
void helper(vector<string> &cur, string curString, int left, int right){
    if (right == 0){
        cur.push_back(curString);
    }
    if (left > 0){
        helper(cur, curString + '(', left-1, right);
    }
    if (right > left){
        helper(cur, curString + ')', left, right-1);
    }
    
}
vector<string> generateParenthesis(int n) {
    vector<string> res;
    if (!n) return res;
    helper(res, "", n, n);
    return res;
}

// 125. Palindrome
bool isPalindrome(string s) {
    string temp = "";
    for(int i = 0; i < s.length(); i++){
        if (('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z') || (48 <= s[i] && s[i] <= 57) ){
            temp += s[i];
        }
    }
    for (int i = 0; i < temp.length()/2; i++){
        char back = temp[temp.length()-i-1];
        if (temp[i] != back){
            if (!(('A' <= back && back <= 'Z') && back + 32 == temp[i]) && !(('a' <= back && back <= 'z') && back - 32 == temp[i])) return false;
        }
    }
    return true;
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

// 171
int titleToNumber(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        res = res * 26 + s[i] - 'A' + 1;
    }
    return res;
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

int checkCommon(vector<int>& n, vector<int>& m){
    bool checker = false;
    int curNode = 0;
    int i = (int)(n.size() - m.size());
    int j = 0;
    while (i != n.size() || j != m.size()) {
        if (n[i] == m[j]){
            if (!checker) {
                curNode = n[i];
                checker = true;
            }
        } else {
            checker = false;
        }
        i++;
        j++;                                                                                          
    }
    return curNode;
}


// 371 Sum of Two Ints
int getSum(int a, int b) {
    int sum = 0;
    while (b != 0) {
        sum = a ^ b;
        b = (a & b) << 1;
        a = sum;
    }
    return a;
}

// 383.
bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> map;
    for(auto c : magazine){
        map[c]++;
    }
    for(auto c : ransomNote){
        if (map[c] != 0){
            map[c]--;
        } else {
            return false;
        }
    }
    return true;
}

// test
int main(int argc, const char * argv[]) {
    vector<int> n = {12,9,3,8,5,11};
    vector<int> m = {7,24,3,8,5,11};
    vector<int> A = {1,0,-1,0,2,-2};
    vector<vector <int>> r = fourSum(A,0);
    cout << getSum(17,29) << endl;
    return 0;
}