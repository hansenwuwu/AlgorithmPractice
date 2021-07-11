total = 0

rdp = {}
cdp = {}

def dfs(i, j, R, C, g):
    global total
    global rdp
    global cdp
    # find x top
    xTop, xBot, yTop, yBot = 1, 1, 1, 1

    if (i-1 >= 0 and g[i-1][j] == 0) and (i+1 < R and g[i+1][j] == 0):
        return
    
    if (i-1 >= 0 and g[i-1][j] == 0) and (i+1 < R and g[i+1][j] == 0):
        return

    if (i-1, j) in rdp:
        xTop, xBot = rdp[(i-1, j)]
        xTop += 1
        xBot -= 1
    else:
        ii = i
        while ii+1 < R:
            if g[ii+1][j] == 1:
                xBot += 1
            else:
                break
            ii+=1

            
        
        ii = i
        while ii-1 >= 0:
            if g[ii-1][j] == 1:
                xTop += 1
            else:
                break
            ii-=1

        rdp[(i, j)] = (xTop, xBot)
    
    if (i, j-1) in cdp:
        yTop, yBot = cdp[(i, j-1)]
        yTop += 1
        yBot -= 1
    else:
        jj = j
        while jj+1 < C:
            if g[i][jj+1] == 1:
                yBot += 1
            else:
                break
            jj+=1
        
        jj = j
        while jj-1 >= 0:
            if g[i][jj-1] == 1:
                yTop += 1
            else:
                break
            jj-=1
        cdp[(i, j)] = (yTop, yBot)
    
    # print('-|- ',i, j, xTop, xBot, yTop, yBot)

    if min((xTop//2), yTop) >= 2:
        total += min((xTop//2), yTop) - 2 + 1
    
    if min((xTop), (yTop//2)) >= 2:
        total += min((xTop), (yTop//2)) - 2 + 1

    if min((xTop//2), yBot) >= 2:
        total += min((xTop//2), yBot) - 2 + 1
    
    if min((xTop), (yBot//2)) >= 2:
        total += min((xTop), (yBot//2)) - 2 + 1

    if min((xBot//2), yBot) >= 2:
        total += min((xBot//2), yBot) - 2 + 1
    
    if min((xBot), (yBot//2)) >= 2:
        total += min((xBot), (yBot//2)) - 2 + 1

    if min((xBot//2), yTop) >= 2:
        total += min((xBot//2), yTop) - 2 + 1
    
    if min((xBot), (yTop//2)) >= 2:
        total += min((xBot), (yTop//2)) - 2 + 1
    

T = int(input())
for test in range(T):
    total = 0
    rdp = {}
    cdp = {}
    
    R, C = map(int, input().split())

    g = [ ]

    for _ in range(R):
        x = list(map(int, input().split()))
        g.append(x)

    for i in range(R):
        for j in range(C):
            if g[i][j] != 1:
                continue
            dfs(i, j, R, C, g)
    
    print('Case #'+str(test+1)+': '+ str(total))