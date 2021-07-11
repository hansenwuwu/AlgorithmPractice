import sys

def toNum(c):
    if c.isupper():
        return (ord(c)-65)
    else:
        return (ord(c)-97 + 26)

def check_valid(target, current):
    for i in range(len(target)):
        if target[i]!=0:
            if target[i] > current[i]:
                return False
    return True

def minWindow(s: str, t: str) -> str:
    n = len(s)
    res = sys.maxsize
    res_i = -1
    res_j = -1

    target = [0 for _ in range(52)]
    current = [0 for _ in range(52)]

    for c in t:
        if c.isupper():
            target[ ord(c)-65 ] += 1
        else:
            target[ ord(c)-97 + 26 ] += 1
    
    i = -1
    j = -1

    while i<=j and i<n and j<n:
        # print(i, ', ',  j)
        if check_valid(target, current):
            if res > j-i:
                res = j-i
                res_i = i
                res_j = j

            i += 1
            if i<j and i<n:
                current[ toNum(s[i]) ] -= 1
            else:
                break
        else:
            j += 1
            if j<n:
                current[ toNum(s[j]) ] += 1
            else:
                break
    
    if res == sys.maxsize:
        return ""
    print('i: ', res_i, '\n', 'j: ', res_j)
    return s[res_i+1:res_j+1]
    
s = "ADOBECODEBANC"
t = "ABC"

output = minWindow(s, t)
print(output)