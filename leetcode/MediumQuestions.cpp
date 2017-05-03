//
//  MediumQuestions.cpp
//  leetcode
//
//  Created by Jasper Wang on 16/9/5.
//  Copyright © 2016年 Jasper. All rights reserved.
//

#include "header.hpp"

using namespace std;


// Pre-order, in-order, post-order traversal using loop
void traversal(TreeNode* root){
    stack<TreeNode *> temp;
    while (root || !temp.empty()){
        while (root){
            // pre order: cout << root << endl;
            temp.push(root);
            root = root->left;	// post order: root = root->right;
        }
        root = temp.top();
        temp.pop();
        // in-order & post-order: out << root << endl;
        root = root->right;		// post order: root = root->left;
    }
}

// MARK: 12. Int to Roman
string intToRoman(int num) {
    string M[] = {"", "M", "MM", "MMM"};
    string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}

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

// MARK: 144. Binary Tree Preorder Traversal
vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return vector<int>();
    stack<TreeNode*> s;
    s.push(root);
    vector<int> res;
    while(!s.empty()){
        TreeNode* temp = s.top();
        res.push_back(temp->val);
        s.pop();
        if(temp->right) s.push(temp->right);
        if(temp->left) s.push(temp->left);
    }
    return res;
}

// MARK: 163. Missing Ranges
string missingRangeHelper(int l, int u){
    if (l == u){
        return to_string(l);
    }
    return (to_string(l) + "->" + to_string(u));
}

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    int n = (int)nums.size();
    vector<string> res;
    if (n < 1) {
        res.push_back(missingRangeHelper(lower, upper));
        return res;
    }
    
    if (nums[0] > lower){
        res.push_back(missingRangeHelper(lower, nums[0] - 1));
    }
    for (int i = 1; i < n; ++i){
        if (nums[i] > nums[i - 1] + 1){
            res.push_back(missingRangeHelper(nums[i-1] + 1, nums[i] - 1));
        }
    }
    if (nums[n-1] < upper){
        res.push_back(missingRangeHelper(nums[n-1] + 1, upper));
    }
    
    return res;
}




// MARK: 167. Two Sum II - Input array is sorted

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = (int)numbers.size()-1;
    while(j > i){
        int temp = numbers[j]+numbers[i];
        if (temp == target) break;
        if (temp > target) j--;
        else i++;
    }
    return {i+1,j+1};
}

// MARK: 200 Number of Islands
void DFS(vector<vector<char>> &grid, int x, int y)
{
    grid[x][y] = '0';
    if(x > 0 && grid[x - 1][y] == '1')
        DFS(grid, x - 1, y);
    if(x < grid.size() - 1 && grid[x + 1][y] == '1')
        DFS(grid, x + 1, y);
    if(y > 0 && grid[x][y - 1] == '1')
        DFS(grid, x, y - 1);
    if(y < grid[0].size() - 1 && grid[x][y + 1] == '1')
        DFS(grid, x, y + 1);
}

int numIslands(vector<vector<char>> &grid)
{
    if(grid.size() == 0 || grid[0].size() == 0) return 0;
    
    int res = 0;
    for(int i = 0; i < grid.size(); ++ i)
        for(int j = 0; j < grid[0].size(); ++ j)
            if(grid[i][j] == '1')
            {
                ++ res;
                DFS(grid, i, j);
            }
    return res;
}

// MARK: 228. Summary Ranges
// For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    int i = 0;
    while(i < nums.size()){
        int level = i+1;
        int curr = nums[i];
        while(level < nums.size() && (nums[level] - curr) == 1){
            curr = nums[level];
            level++;
        }
        if (level == i+1) {
            res.push_back(to_string(curr));
        }
        else {
            res.push_back(to_string(nums[i])+"->"+to_string(curr));
        }
        i = level;
    }
    return res;
}

// MARK: 238. Product Of Array Except Self
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res(nums.size(),0);
    res[0] = 1;
    for(int i = 1; i < nums.size();i++){
        res[i] = res[i-1] * nums[i-1];
    }
    int right = 1;
    for(int i = (int)nums.size()-1; i >= 0; i--){
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

// MARK: 279. Perfect Squares
int numSquares(int n) {
    vector<int> dp {0};
    while(dp.size() <= n){
        int m = (int)dp.size(), temp = INT_MAX;
        for(int i = 1; i*i <= m; i++){
            temp = min(temp, dp[m-i*i]+1);
        }
        dp.push_back(temp);
    }
    return dp[n];
}

// MARK: 280 Wiggle Sort
void wiggleSort(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++)
        if (((i & 1) && nums[i] < nums[i - 1]) || (!(i & 1) && nums[i] > nums[i - 1]))
            swap(nums[i], nums[i - 1]);
}

// MARK: 319. Bulb Switcher
int bulbSwitch(int n) {
    return sqrt(n);
}

// MARK: 337. House Robber III
int tryRob(TreeNode* root, int& l, int& r){
    if(!root) return 0;
    int ll = 0, lr = 0, rl = 0, rr = 0;
    l = tryRob(root->left, ll, lr);
    r = tryRob(root->right, ll, lr);
    
    return max(root->val + ll + lr + rl + rr, l + r); // dynamic programming
}

int rob(TreeNode* root){
    int l,r;
    return tryRob(root, l, r);
}

// MARK: 338. Counting Bits
vector<int> countBits(int num) {
    // Count of 1's in i:
    // Odd:  i = (i-1) | 1, previous count + 1
    // Even: i = i/2 << 1, same count as i/2
    vector<int> v(num+1);
    for (uint i = 0; i <= num; i++) {
        if (i & 1) v[i] = v[i-1] + 1;
        else v[i] = v [i / 2];
    }
    return v;
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

// MARK: 366 Find leaves of binary tree
// Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
int findLeavesHelper(TreeNode* root, vector<vector<int>>& vec){
    if(!root) return 0;
    int level = max(findLeavesHelper(root->left, vec), findLeavesHelper(root->right, vec))+1;
    if(level > (int)vec.size()) vec.push_back(vector<int>());
    vec[level-1].push_back(root->val);
    return level;
}

vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> res;
    findLeavesHelper(root, res);
    return res;
}

// MARK: 370. Range Addition


// MARK: 377. Combination Sum IV
int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1,0);
    dp[0]=1;
    for(int i=1;i<=target;i++){
        for(int j=0;j<nums.size();j++){
            if(i>=nums[j]){
                dp[i]+=dp[i-nums[j]];
            }
        }
    }
    return dp[target];
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


// MARK: 419. Battleships in a Board
int countBattleships(vector<vector<char>>& board) {
    int res = 0;
    for(int i = 0; i < (int)board.size(); i++){
        for(int j = 0; j < (int)board[i].size();j++){
            char temp = board[i][j];
            if (temp == 'X'){
                if ((i && board[i-1][j] == temp)||(j && board[i][j-1] == temp)){}
                else res++;
            }
        }
    }
    return res;
}
