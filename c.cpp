#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printVec(vector<int> &v)
{
    for (auto &e : v)
        cout << e << " ";
}

void insert(int target, int a, int b, ListNode *node)
{
    while (node)
    {
        if (node->val == a || node->val == b)
        {
            ListNode *next = node->next;
            ListNode *newNode = new ListNode(target);
            node->next = newNode;
            newNode->next = next;
            return;
        }
        node = node->next;
    }
}

void insertNotMid(int target, int mid, int other, ListNode *node)
{
    ListNode *newNode = new ListNode(target);

    bool isAfter = false;

    while (true)
    {
        if (node->next->val == mid && !isAfter)
        {
            ListNode *temp = node->next;
            node->next = newNode;
            newNode->next = temp;
            return;
        }

        if (node->val == other)
        {
            isAfter = true;
            continue;
        }

        if (node->val == mid && isAfter)
        {
            ListNode *temp = node->next;
            node->next = newNode;
            newNode->next = temp;
            return;
        }

        node = node->next;
    }
}

void traverse(int target, ListNode *node)
{
    ListNode *pre = node;
    node = node->next;
    while (node && node->next)
    {
        int a = node->val;
        int b = node->next->val;
        printf("%d %d %d\n", a, b, target);
        fflush(0);
        int mid;
        cin >> mid;

        if (mid == target)
        {
            ListNode *newNode = new ListNode(target);
            ListNode *tempNode = node->next;
            node->next = newNode;
            newNode->next = tempNode;
            return;
        }
        else if (mid == a)
        {
            ListNode *newNode = new ListNode(target);
            pre->next = newNode;
            newNode->next = node;
            return;
        }
        else if (mid == b)
        {
            if (node->next->next == nullptr)
            {
                ListNode *newNode = new ListNode(target);
                node->next->next = newNode;
                return;
            }
        }

        pre = node;
        node = node->next;
    }
}

void rsolve(int N)
{
    vector<int> v;
    ListNode *dummy = new ListNode(0);
    ListNode *node = dummy;

    // initialize
    printf("%d %d %d\n", 1, 2, 3);
    fflush(0);

    int mid;
    cin >> mid;

    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);

    if (1 == mid)
    {
        node->next = b;
        node = node->next;
        node->next = a;
        node = node->next;
        node->next = c;
        node = node->next;
    }
    else if (2 == mid)
    {
        node->next = a;
        node = node->next;
        node->next = b;
        node = node->next;
        node->next = c;
        node = node->next;
    }
    else
    {
        node->next = b;
        node = node->next;
        node->next = c;
        node = node->next;
        node->next = a;
        node = node->next;
    }

    for (int i = 4; i <= N; i++)
    {
        ListNode *temp = dummy;
        traverse(i, temp);
    }

    dummy = dummy->next;
    while (dummy)
    {
        cout << dummy->val;
        if (dummy->next)
            cout << " ";
        dummy = dummy->next;
    }
    cout << "\n";
    fflush(0);

    int correct;
    cin >> correct;
}

void solve()
{
    int T, N, Q;
    cin >> T >> N >> Q;
    for (int casenum = 1; casenum <= T; casenum++)
    {
        rsolve(N);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}