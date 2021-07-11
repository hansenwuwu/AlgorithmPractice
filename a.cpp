#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <utility>

#include "graph.h"

using namespace std;

void printVec(vector<int> &vec)
{
    for (auto &e : vec)
    {
        cout << e << endl;
    }
    cout << endl;
}
void printVec(vector<vector<int>> &vec)
{
    for (auto &ee : vec)
    {
        for (auto &e : ee)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    cout << endl;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        vector<int> res;
        dfs(root, voyage, 0, voyage.size() - 1, res);
    }

    void dfs(TreeNode *node, vector<int> &voyage, int i, int j, vector<int> &res)
    {
        if (node == NULL)
            return;

        if (node->val != voyage[i])
        {
            res.push_back(-1);
            return;
        }
    }
};

int main()
{
    Solution s = Solution();

    vector<vector<int>> edges = {{1, 2}, {2, 4}, {1, 3}, {2, 3}, {2, 1}};
    vector<int> queries = {2, 3};

    // printf("%d\n", s.countPairs(edges, queries));
    // cout << s.minDistance("sea", "eat") << endl;
    // cout << s.minDistance("leetcode", "etco") << endl;
    return 0;
}