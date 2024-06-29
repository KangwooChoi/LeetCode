class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
       
        if not M:
            return 0
        
        n = len(M)
        visit = [False]*n
        
        def dfs(u):
            for v in range(n):
                if M[u][v] ==1 and visit[v] == False:
                    visit[v] = True
                    dfs(v)
        
        count = 0
        for i in range(n):
            if visit[i] == False:
                count += 1
                visit[i] = True
                dfs(i)
        
        return count
    #def findCircleNum(self, isConnected: List[List[int]]) -> int:
    #    # building our root list
    #    l1 = [0]*len(isConnected[0])
    #    for i in range(len(l1)):
    #        l1[i] = i
    #    
    #    # returns root of existing vertex
    #    def get_root(x):
    #        return l1[x]
    #    
    #    # update root of existing index
    #    def union(x,y):
    #        Rx = get_root(x)
    #        Ry = get_root(y)
#
    #        if Rx != Ry:
    #            for i in range(0,len(l1)):
    #                if l1[i] == Ry:
    #                    l1[i] = Rx
#
    #    # traversing only the upper traingular matrix to save time
    #    for i in range(0,len(isConnected)):
    #        for j in range(i+1,len(isConnected[0])):
    #            if isConnected[i][j] == 1:
    #                union(i,j)
    #        
    #    return len(set(l1))
    #def findCircleNum(self, isConnected: List[List[int]]) -> int:
    #    def union(i, j):
    #        p_i = parents[i]
    #        p_j = parents[j]
    #        if p_i != p_j:
    #            for k in range(0, n):
    #                if parents[k] == p_j:
    #                    parents[k] = p_i
#
    #    def find(k):
    #        pass
    #        
    #    n = len(isConnected)
    #    parents = [i for i in range(n)]
    #    for i in range(n):
    #        for j in range(i+1, n):
    #            if isConnected[i][j]:
    #                union(i,j)
#
    #    #print(parents)
    #    return len(set(parents))