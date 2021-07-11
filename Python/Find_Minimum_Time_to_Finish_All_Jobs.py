from typing import List
import sys

def minimumTimeRequired(jobs: List[int], k: int) -> int:
    def backTrack(i, curMaxTime):
        nonlocal ans

        if curMaxTime >= ans:
            return

        if i == n:
            ans = min(ans, curMaxTime)
            return

        timeSet = set()
        for j in range(k):
            if w[j] not in timeSet:     
                w[j] += jobs[i]
                backTrack(i+1, max(w[j], curMaxTime))
                w[j] -= jobs[i]

                timeSet.add(w[j])

    n = len(jobs)
    w = [0]*k
    ans = sys.maxsize

    backTrack(0, 0)

    return ans

print(minimumTimeRequired([1,2,4,7,8], 2))