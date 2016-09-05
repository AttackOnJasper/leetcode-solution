//
//  header.hpp
//  leetcode
//
//  Created by Jasper Wang on 16/9/5.
//  Copyright © 2016年 Jasper. All rights reserved.
//

#ifndef MediumQuestions_hpp
#define MediumQuestions_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <stack>
#include <queue>

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


#endif /* MediumQuestions_hpp */
