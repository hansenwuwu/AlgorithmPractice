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
int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
    {
        int r, n;
        scanf("%d%d%d", &r, &r, &n);
        int l = 1, m, res;
        char s[32];
        while (l <= r)
        {
            m = (l + r) / 2;
            printf("%d\n", m);
            fflush(0);
            scanf("%s", s);
            if (s[0] == 'C')
                break;
            if (s[4] == 'S')
                l = m + 1;
            else
                r = m - 1;
        }
    }
    return 0;
}