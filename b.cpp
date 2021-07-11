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
#include <string.h>
#include <climits>

using namespace std;

void printVec(vector<int> &v)
{
    for (auto &e : v)
        cout << e << " ";
}

void rsolve()
{
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;
    int mod = 1e9 + 7;
    int res = 0;
    string tmp = S;
    int half = (N + 1) / 2;
    int mid = N / 2;
    if (N % 2 == 0)
        mid -= 1;
    for (int i = 0; i < half; i++)
    {
        int p = mid - i;
        int remain = (S[i] - 'a');
        if (remain > 0)
        {
            res += (remain * (int)pow(K, p) % mod);
        }
        tmp[i] = S[i];
        tmp[N - i - 1] = S[i];
    }

    if (tmp < S)
        res = (res + 1) % mod;
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