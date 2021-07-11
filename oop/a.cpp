#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// ListNode
struct ListNode
{
    ListNode(int n) : val(n) {}
    ListNode *next;
    int val;
};
ListNode *create(vector<int> &v)
{
    ListNode *dummy = new ListNode(0);
    ListNode *node = dummy;
    for (int i = 0; i < v.size(); i++)
    {
        node->next = new ListNode(v[i]);
        node = node->next;
    }
    return dummy->next;
}
void printListNode(ListNode *node)
{
    ListNode *tmp = node;
    while (tmp)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// Vector
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

void helper(ListNode *head)
{
    stack<int> st;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next)
    {
        st.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast)
        slow = slow->next;

    while (slow)
    {
        int t = st.top();
        st.pop();
        if (slow->val != t)
            cout << "false" << endl;
        slow = slow->next;
    }
    cout << "true" << endl;
}

int main()
{

    return 0;
}