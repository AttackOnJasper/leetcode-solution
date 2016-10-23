//
//  main.cpp
//  test
//
//  Created by Jasper Wang on 16/5/22.
//  Copyright © 2016年 Jasper. All rights reserved.
//

#include "header.hpp"

using namespace::std;


// MARK: 344 Reverse string
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

// MARK: 8. String to Integer (atoi)
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

// MARK: 11. Contains most water
int maxArea(vector<int>& height) {
    int curMax = 0;
    int length = (int)height.size() - 1;
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

// MARK: 15. 3Sum
vector<vector<int> > threeSum(vector<int> &num) {
    
    vector<vector<int> > res;
    
    std::sort(num.begin(), num.end());
    
    for (int i = 0; i < num.size(); i++) {
        
        int target = -num[i];
        int front = i + 1;
        int back = (int)num.size() - 1;
        
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

// MARK: 18. 4Sum
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++){
        for (int j = i + 1; j < nums.size(); j++) {
            int start = j+1;
            int end = (int)nums.size() - 1;
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

// MARK: 21. Merge 2 sorted lists
ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    if (l1->val <= l2->val) {
        l1->next = mergeTwoLists1(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists1(l1, l2->next);
        return l2;
    }
}

ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode* res = new ListNode(0);
    ListNode* cur = res;
    while (l1 && l2) {
        if (l1->val < l2->val){
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1) {
        cur->next = l1;
    } else {
        cur->next = l2;
    }
    return res->next;
}

// MARK: 22. Generate Parenthesis
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

// MARK: 24 Swap nodes in pairs
ListNode* swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *temp1 = swapPairs(head->next->next);
    ListNode *temp2 = head;
    head = head->next;
    head->next = temp2;
    temp2->next = temp1;
    return head;
}

// MARK: 38 Count and Say
string countAndSay(int n) {
    if (n == 0) return NULL;
    if (n == 1) return "1";
    string s = countAndSay(n-1);
    int count = 1;
    string res = "";
    for(int i = 0; i < s.length(); i++){
        if(i+1 < s.length() && s[i] == s[i+1]){
            count++;
        } else {
            res += to_string(count)+s[i];
            count = 1;
        }
    }
    return res;
}

// MARK: 66 Plus one
vector<int> plusOne(vector<int>& digits) {
    if (!digits.size()) return digits;
    if (digits.back() != 9){
        digits.back()++;
        return digits;
    }
    int index = digits.size()-1;
    while (digits[index] == 9 && index != 0) {
        digits[index] = 0;
        index--;
    }
    if (index){
        digits[index]++;
    } else {
        if (digits.front() == 9){
            digits.front() = 1;
            digits.push_back(0);
        } else {
            digits.front()++;
        }
    }
    return digits;
}

// MARK: 88 Merge sorted array
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i,j = 0;
    vector<int> temp;
    while(i < m && j < n){
        if (nums1[i] < nums2[j]){
            temp.push_back(nums1[i]);
            i++;
        } else {
            temp.push_back(nums2[j]);
            j++;
        }
    }
    if (i == m){
        for(; j < n; j++){
            temp.push_back(nums2[j]);
        }
    } else {
        for(; i < m; i++){
            temp.push_back(nums1[i]);
        }
    }
    nums1 = vector<int>(temp);
}


// MARK: 102 Binary Tree Level Order Traversal
void levelOrderHelper(TreeNode* root, vector<vector<int>> &list, int level){
    if (!root) return;
    if (list.empty() || level > (list.size() - 1)) list.push_back(vector<int>());
    list[level].push_back(root->val);
    levelOrderHelper(root->left, list, level+1);
    levelOrderHelper(root->right, list, level+1);
}
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> list;
    levelOrderHelper(root, list, 0);
    return list;
}

// MARK: 107
void levelOrderBottomHelper(TreeNode* root, vector<vector<int> > &v, int h){
    if (root == NULL) return;
    if (v.empty() || h > (v.size() - 1)) {
        v.push_back(vector<int>());
    }
    v[h].push_back(root->val);
    levelOrderBottomHelper(root->left, v, h+1);
    levelOrderBottomHelper(root->right, v, h+1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    levelOrderBottomHelper(root, res, 0);
    reverse(res.begin(), res.end());
    return res;
}

// MARK: 110. Balanced Binary Tree
int height(TreeNode* root){
    if (!root) return 0;
    int left = height(root->left);
    int right = height(root->right);
    if (left==-1 || right==-1 || left>right+1 || right>left+1) return -1;
    return max(left,right)+1;
}
bool isBalanced(TreeNode* root) {
    return height(root) != -1;
}

// MARK: 111. Minimum Depth of Binary Tree
int minDepth(TreeNode* root) {
    if (!root) return 0;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    return (left == 0 || right == 0)? max(left,right)+1 : min(left, right)+1;
}

// MARK: 112
bool hasPathSum(TreeNode* root, int sum) {
    if (!root || (!root->left && !root->right)) return root && root->val == sum;
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}

// MARK: 121 Buy and Sell
int maxProfit(vector<int> &prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;
        for(int i = 0; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);
        }
        return maxPro;
}


// MARK: 125. Palindrome
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

// MARK: 141. Linked list cycle
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

// MARK: 157. Read N Characters Given Read4
//int read4(char *buf);
///**
// * @param buf Destination buffer
// * @param n   Maximum number of characters to read
// * @return    The number of characters read
// */
//int read(char *buf, int n) {
//    int res = 0;
//    for(int i = 0; i < n/4; ++i){
//        int temp = read4(buf);
//        res += temp;
//        buf += temp;
//    }
//    res+= min(read4(buf),n%4);
//    return res;
//}

// MARK: 165. Compare Version Numbers
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

// MARK: 168. Excel sheet column title
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

// MARK: 170 Two Sum Data Structure
class TwoSum {
    unordered_map<int,int> map;
public:
    void add(int number) {
        map[number]++;
    }
    
    bool find(int value) {
        for (unordered_map<int,int>::iterator it = map.begin(); it != map.end(); it++) {
            int i = it->first;
            int j = value - i;
            if ((i == j && it->second > 1) || (i != j && map.find(j) != map.end())) {
                return true;
            }
        }
        return false;
    }
};

// MARK: 171 Excel column to number
int titleToNumber(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        res = res * 26 + s[i] - 'A' + 1;
    }
    return res;
}

// MARK: 189. Rotate Array
void rotate(vector<int>& nums, int k) {
    if(k%nums.size())
    {
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k%nums.size());
        reverse(nums.begin()+k%nums.size(),nums.end());
    }
}


// MARK: 198 House Robber
int rob(vector<int>& nums) {
    if (!nums.size()) return 0;
    vector<int> res(nums.size(), 0);
    res[0] = nums[0];
    res[1] = nums[0] > nums[1]? nums[0]: nums[1];
    for(int i = 2; i < nums.size(); i++){
        res[i] = max(res[i-1], res[i-2]+nums[i]);
    }
    return res[nums.size()-1];
}

// MARK: 206 reverse linked list
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *temp = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

// MARK: 225 Implement Stack using Queues
//
//queue<int> q;
//// Push element x onto stack.
//void push(int x) {
//    queue<int> temp;
//    while(!q.empty()){
//        temp.push(q.front());
//        q.pop();
//    }
//    q.push(x);
//    while(!temp.empty()){
//        q.push(temp.front());
//        temp.pop();
//    }
//}
//
//// Removes the element on top of the stack.
//void pop() {
//    q.pop();
//}
//
//// Get the top element.
//int top() {
//    return q.front();
//}
//
//// Return whether the stack is empty.
//bool empty() {
//    return q.empty();
//}

// MARK: 232 Implement Queue by Stack
stack<int> s;

// Push element x to the back of queue.
void push(int x) {
    stack<int> temp;
    while (!s.empty()){
        temp.push(s.top());
        s.pop();
    }
    s.push(x);
    while (!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
}

// Removes the element from in front of queue.
void pop(void) {
    s.pop();
}

// Get the front element.
int peek(void) {
    return s.top();
}

// Return whether the queue is empty.
bool empty(void) {
    return s.empty();
}


// MARK: 234. Palindrome Linked List
bool isPalindrome(ListNode* head) {
    if(!head || !head->next) return true;
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reverseList(slow->next);
    slow=slow->next;
    while(slow!=NULL){
        if(head->val!=slow->val)
            return false;
        head=head->next;
        slow=slow->next;
    }
    return true;
}
//ListNode* reverseList(ListNode* head) {
//    ListNode* pre=NULL;
//    ListNode* next=NULL;
//    while(head!=NULL){
//        next=head->next;
//        head->next=pre;
//        pre=head;
//        head=next;
//    }
//    return pre;
//}


// MARK: 243. Shortest Word Distance
// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list
int shortestDistance(vector<string>& words, string word1, string word2) {
    int n = (int)words.size(), idx1 = -1, idx2 = -1, dist = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (words[i] == word1) idx1 = i;
        else if (words[i] == word2) idx2 = i;
        if (idx1 != -1 && idx2 != -1)
            dist = min(dist, abs(idx1 - idx2));
    }
    return dist;
}

// MARK: 246. Strobogrammatic Number (looks the same when rotated 180 degrees)
bool isStrobogrammatic(string num) {
    for(int i = 0, j = (int)num.length()-1; i < num.length(); i++, j--){
        if((num[i] == '0' || num[i] == '8' || num[i] == '1') && num[i] == num[j]) continue;
        if(num[i] == '6' && num[j] == '9') continue;
        if (num[i] == '9' && num[j] == '6') continue;
        return false;
    }
    return true;
}

// MARK: 249. Group Shifted Strings
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string> > mp;
        for (string  s : strings)
            mp[shift(s)].push_back(s);
        vector<vector<string> > groups;
        for (auto m : mp) {
            vector<string> group = m.second;
            sort(group.begin(), group.end());
            groups.push_back(group);
        }
        return groups;
    }
private:
    string shift(string& s) {
        string t;
        int n = (int)s.length();
        for (int i = 1; i < n; i++) {
            int diff = s[i] - s[i - 1];
            if (diff < 0) diff += 26;
            t += diff + ',';
        }
        return t;
    }
};

// MARK: 252 Meeting Rooms
// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){ return a.start < b.start; });
    int currend=INT_MIN;
    for(int i = 0; i < intervals.size(); ++i) {
        if(intervals[i].start < currend)  return false;
        currend = intervals[i].end;
    }
    return true;
}

// MARK: 257. Binary Tree Paths
void binaryTreePathsHelper(TreeNode* root, string curString, vector<string> &v){
    if (!root) return;
    if (!root->left && !root->right) v.push_back(curString+to_string(root->val));
    binaryTreePathsHelper(root->left, curString+to_string(root->val)+"->", v);
    binaryTreePathsHelper(root->right, curString+to_string(root->val)+"->", v);
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    binaryTreePathsHelper(root, "", res);
    return res;
}

// MARK: 266 Palindrome Permutation
// Given a string, determine if a permutation of the string could form a palindrome
bool canPermutePalindrome(string s) {
    bitset<26> bs;
    for (auto ch : s)
        bs[ch - 'a'].flip();
    return (bs.count() <= 1);
}


// MARK: 270. Closest Binary Search Tree Value
// Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
int closestValue(TreeNode* root, double target) {
    int closest = root->val;
    while (root) {
        if (abs(closest - target) >= abs(root->val - target))
            closest = root->val;
        root = target < root->val ? root->left : root->right;
    }
    return closest;
}

// MARK: 276. Paint Fence
int numWays(int n, int k) {
    if(n == 0) return 0;
    if(n == 1) return k;
    // choose one color to paint the first and choose the other to paint the second
    int diffColorCounts = k*(k-1);
    // use the same color as the second previous one
    int sameColorCounts = k;
    for(int i=2; i<n; i++) {
        int temp = diffColorCounts;
        diffColorCounts = (diffColorCounts + sameColorCounts) * (k-1);
        sameColorCounts = temp;
    }
    return diffColorCounts + sameColorCounts;
}


// MARK: 288. Unique Word Abbreviation
class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string& d : dictionary) {
            int n = (int)d.length();
            string abbr = d[0] + to_string(n) + d[n - 1];
            mp[abbr].insert(d);
        }
    }
    
    bool isUnique(string word) {
        int n = (int)word.length();
        string abbr = word[0] + to_string(n) + word[n - 1];
        return mp[abbr].count(word) == mp[abbr].size();
    }
private:
    unordered_map<string, unordered_set<string>> mp;
};

// MARK: 293 Flip Game
vector<string> generatePossibleNextMoves(string s) {
    vector<string> res;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == s[i-1] && s[i] == '+'){
            string temp = s;
            temp[i] = '-';
            temp[i-1] = '-';
            res.push_back(temp);
        }
    }
    return res;
}

// MARK: 339 Nested List Weight Sum
 class NestedInteger {
       public:
         // Return true if this NestedInteger holds a single integer, rather than a nested list.
         bool isInteger() const;
    
         // Return the single integer that this NestedInteger holds, if it holds a single integer
        // The result is undefined if this NestedInteger holds a nested list
         int getInteger() const;
    
         // Return the nested list that this NestedInteger holds, if it holds a nested list
         // The result is undefined if this NestedInteger holds a single integer
         const vector<NestedInteger> &getList() const;
};

//int depthSumHelper(vector<NestedInteger>& nestedList, int level){
//    int sum = 0;
//    for(int i = 0; i < nestedList.size(); i++){
//        if (nestedList[i].isInteger()){
//            sum += nestedList[i].getInteger()*level;
//        } else {
//            sum += depthSumHelper(nestedList[i].getList(), level+1);
//        }
//    }
//    return sum;
//}
//
//int depthSum(vector<NestedInteger>& nestedList) {
//    return depthSumHelper(nestedList, 1);
//}



// MARK: 342 is power of 4
bool isPowerOfFour(int num) {
    return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    // num & num - 1 : 100000 compare to 0111111 (could be power of 2s)
    // (num - 1) % 3 prove by induction
}

// MARK: 345

bool isVowel(char c){
   return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
string reverseVowels(string s) {
    int front = 0, behind = (int)s.length() - 1;
    while (front < behind)
    {
        if (!isVowel(s[front]))
        {
            front++;
        }
        else if (!isVowel(s[behind]))
        {
            behind--;
        }
        else
        {
            char c = s[front];
            s[front] = s[behind];
            s[behind] = c;
            front++;
            behind--;
        }
    }
    
    return s;
}

// MARK: 346. Moving Average from Data Stream
class MovingAverage {
    queue<int> Q;
    int subSum = 0;
    int size;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        if (Q.size() == size) {
            subSum -= Q.front();
            Q.pop();
        }
        Q.push(val);
        subSum += val;
        return (double)subSum / Q.size();
    }
    
};

// MARK: 359. Logger Rate Limiter
map<string, int> ok;

bool shouldPrintMessage(int timestamp, string message) {
    if (timestamp < ok[message])
        return false;
    ok[message] = timestamp + 10;
    return true;
}


// MARK: 371 Sum of Two Ints
int getSum(int a, int b) {
    int sum = 0;
    while (b != 0) {
        sum = a ^ b;
        b = (a & b) << 1;
        a = sum;
    }
    return a;
}

// MARK: 383. ransom note
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

// 396 Rotate function
int maxRotateFunction(vector<int>& A) {
    int sumOfNums = 0;
    int res = 0;
    int cur = 0;
    for(int i = 0; i<A.size();i++){
        res += i * A[i];
        sumOfNums += A[i];
    }
    cur = res;
    for(int i = (int)A.size()-1; i >= 0; i--){
        cur += sumOfNums - A[i]*A.size();
        if (cur > res) res = cur;
    }
    return res;
}

// MARK: 397. Integer Replacement
int integerReplacement(int n) {
    if (n == INT_MAX) return 32;
    int res = 0;
    while(n!=1){
        if (n%2 == 0) n/=2;
        else if (n== 3){
            res += 2;
            return res;
        }
        else if ((n+1)%4 == 0) n += 1;
        else n -= 1;
        res++;
    }
    return res;
}


// MARK: 404. Sum of Left Leaves
int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    if (root->left && !root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}



// MARK: 408. Valid Word Abbreviation
bool validWordAbbreviation(string word, string abbr) {
    int i = 0, j = 0;
    while (i < word.size() && j < abbr.size()) {
        if (isdigit(abbr[j])) {
            if (abbr[j] == '0') return false;
            int val = 0;
            while (j < abbr.size() && isdigit(abbr[j]))
                val = val * 10 + abbr[j++] - '0';
            i += val;
        }
        else if (word[i++] != abbr[j++]) return false;
    }
    return i == word.size() && j == abbr.size();
}

// MARK: 412. Fizz Buzz
vector<string> fizzBuzz(int n) {
    vector<string> res;
    for(int i = 1; i <= n; i++){
        if (i%3 == 0){
            if (i%5 == 0){
                res.push_back("FizzBuzz");
            } else {
                res.push_back("Fizz");
            }
        } else if (i%5 == 0){
            res.push_back("Buzz");
        } else {
            res.push_back(to_string(i));
        }
    }
    return res;
}

// MARK: 422. Valid Word Square
/*
 Given a sequence of words, check whether it forms a valid word square.
 
 A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
 
 */
bool validWordSquare(vector<string>& words) {
    for(int i = 0; i < words.size(); ++i) {
        for(int j = 0; j < words[i].length(); ++j){
            if(j >= words.size() || words[j].length() <= i || words[j][i] != words[i][j])
                return false;
        }
    }
    return true;
}

// test
int main(int argc, const char * argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(1);
    vector<int> n = {12,9,3,8,5,11};
    vector<int> m = {7,24,3,8,5,11};
    vector<int> A = {4,3,2,6};
    vector<vector <int>> r = fourSum(A,0);
    return 0;
}