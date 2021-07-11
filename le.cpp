/*

207. Course Schedule
Mediu
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] 
indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

topological sort

*/

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
#include <stack>
#include <climit>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, unordered_set<int>> g;
        for (auto p : prerequisites)
        {
            g[p[1]].insert(p[0]);
        }

        return TopoSort(g);
    }

    bool TopoSort(unordered_map<int, unordered_set<int>> &g)
    {
        unordered_set<int> visited;
        unordered_set<int> rec;

        for (auto &e : g)
        {
            if (!dfs(g, visited, rec, e.first))
            {
                return false;
            }
        }
        return true;
    }

    bool dfs(unordered_map<int, unordered_set<int>> &g, unordered_set<int> &visited,
             unordered_set<int> &rec, int v)
    {
        if (rec.count(v))
            return false;
        if (visited.count(v))
            return true;

        visited.insert(v);
        rec.insert(v);

        for (auto &e : g[v])
        {
            if (!dfs(g, visited, rec, e))
            {
                return false;
            }
        }

        rec.remove(v);
        return true;
    }
};

int main()
{
    Solution s = Solution();

    return 0;
}