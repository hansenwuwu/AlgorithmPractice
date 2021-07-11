T = int(input())
for test in range(T):
    R, C = map(int, input().split())
    g = [ ]
    for _ in range(R):
        x = list(map(int, input().split()))
        g.append(x)

    # find unacceptable first
    unaccept = []

    for i in range(R):
        for j in range(C):
            check = True
            if i-1>=0 and abs(g[i][j]-g[i-1][j])>1:
                check = False
            if i+1<R and abs(g[i][j]-g[i+1][j])>1:
                check = False
            if j-1>=0 and abs(g[i][j]-g[i][j-1])>1:
                check = False
            if j+1<C and abs(g[i][j]-g[i][j+1])>1:
                check = False
            
            if check == False:
                unaccept.append((i, j))
        
    while len(unaccept) > 0:
        isHighest = True
        if i-1>=0 and abs(g[i][j]-g[i-1][j])>1 and (g[i][j]<g[i-1][j]):
            isHighest = False
        if i+1<R and abs(g[i][j]-g[i+1][j])>1 and (g[i][j]<g[i+1][j]):
            isHighest = False
        if j-1>=0 and abs(g[i][j]-g[i][j-1])>1 and (g[i][j]<g[i][j-1]):
            isHighest = False
        if j+1<C and abs(g[i][j]-g[i][j+1])>1 and (g[i][j]<g[i][j+1]):
            isHighest = False
        
        if isHighest:
            temp = unaccept.pop(0)
            unaccept.append(temp)
        else:
            if i-1>=0 and abs(g[i][j]-g[i-1][j])>1 and (g[i][j]<g[i-1][j]):
                isHighest = False
            if i+1<R and abs(g[i][j]-g[i+1][j])>1 and (g[i][j]<g[i+1][j]):
                isHighest = False
            if j-1>=0 and abs(g[i][j]-g[i][j-1])>1 and (g[i][j]<g[i][j-1]):
                isHighest = False
            if j+1<C and abs(g[i][j]-g[i][j+1])>1 and (g[i][j]<g[i][j+1]):
                isHighest = False
    
    print('Case #'+str(test+1)+': '+ str(total))