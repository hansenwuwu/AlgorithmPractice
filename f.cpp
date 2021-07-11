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
#include <unordered_set>
#include <stack>
#include <vector>
#include <string.h>
#include <climits>

using namespace std;

// Returns true if str1 is smaller than str2.
bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;

    return false;
}

// Function for find difference of larger numbers
string findDiff(string str1, string str2)
{
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i = 0; i < n2; i++)
    {
        // Do school mathematics, compute difference of
        // current digits

        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);

        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of larger number
    for (int i = n2; i < n1; i++)
    {
        int sub = ((str1[i] - '0') - carry);

        // if the sub value is -ve, then make it positive
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // reverse resultant string
    reverse(str.begin(), str.end());
    int c = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] != '0')
            break;
        else if (str[i] == '0')
            c++;
    }
    return str.substr(c);
}

// Function for finding sum of larger numbers
string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');

        // Calculate carry for next step
        carry = sum / 10;
    }

    // Add remaining digits of larger number
    for (int i = n1; i < n2; i++)
    {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry + '0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}

void printVec(vector<int> &v)
{
    for (auto &e : v)
        cout << e << " ";
}

void rsolve()
{
    string G;
    cin >> G;

    string t = G;
    t = findSum(t, "1");
    // cout << t << endl;

    string i = "1";
    string j = "0";
    string count = "0";
    string slow = "0";
    int res = 0;
    while (isSmaller(j, t))
    {
        j = findSum(j, "1");
        count = findSum(count, j);

        while (isSmaller(i, j) && isSmaller(G, findDiff(count, slow)))
        {
            slow = findSum(slow, i);
            i = findSum(i, "1");
        }
        // cout << count << ", " << slow << " - " << findDiff(count, slow) << " : " << G << endl;
        if (findDiff(count, slow) == G)
        {
            // cout << i << ", " << j << endl;
            res++;
        }
    }

    cout << res << endl;
}

void solve()
{
    int t;
    cin >> t;
    for (int casenum = 1; casenum <= t; casenum++)
    {
        cout << "Case #" << casenum << ": ";
        rsolve();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}