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
    int a, b;
    cin >> a >> b;

    int w = 201;

    w = min(w, max(a, b + b));
    w = min(w, max(a + a, b));

    cout << w * w << endl;
}

void solve()
{
    int t;
    cin >> t;
    for (int casenum = 1; casenum <= t; casenum++)
    {
        //cout << "Case #" << casenum << ": ";
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