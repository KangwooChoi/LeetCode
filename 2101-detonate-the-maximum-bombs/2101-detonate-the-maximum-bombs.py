#from collections import deque
#import math

class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        # DFS, recursive
        graph = collections.defaultdict(list)
        n = len(bombs)

        # Build the graph
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                xi, yi, ri = bombs[i]
                xj, yj, _ = bombs[j]

                if ri ** 2 >= (xj-xi) ** 2 + (yj-yi) ** 2:
                    graph[i].append(j)

        # DFS to get the number of nodes reachable from a given node cur
        def dfs(cur, visited):
            visited.add(cur)
            for neighbor in graph[cur]:
                if neighbor not in visited:
                    dfs(neighbor, visited) 
            return len(visited)
        
        answer = 0
        for i in range(n):
            visited = set()
            answer = max(answer, dfs(i, visited))

        return answer


        ## 2nd solution: Fisrt, calcuate denotaed bombs by each bomb
        ## And then, put together because math.pow is heavy
        #detonated_dict = dict()
        #for i, selected in enumerate(bombs):
        #    detonated = [i]
        #    x_i, y_i, r_i = selected
        #    r2 = math.pow(r_i, 2)
        #    for j, bomb in enumerate(bombs):
        #        if j == i:
        #            continue
        #        x_j, y_j, r_j = bomb
        #        if r2 >= math.pow(x_j-x_i, 2) + math.pow(y_j-y_i, 2):
        #            detonated.append(j)
        #    detonated_dict[i] = detonated
        ##print(detonated_dict) 
        #
        ## chain
        #max_index = 0
        #max_detonated = 0 
        #for i in range(len(bombs)):
        #    #print('current i: ', i)
        #    detonated_deq = deque()
        #    detonated_deq.append(i) 
        #    detonated_set = {i}
        #    while detonated_deq:
        #        #print('deq: ', detonated_deq)
        #        current = detonated_deq.popleft()
        #        #print('set: ', detonated_set)
        #        #print('current: ', current)
        #        #print('affected by current: ', detonated_dict[current])
        #        for affected in detonated_dict[current]:
        #            if affected not in detonated_set: 
        #                detonated_deq.append(affected)
        #                detonated_set.add(affected)
        #        #print('current({0}) is done'.format(current))
        #    if len(detonated_set) > max_detonated:
        #        max_index = i
        #        max_detonated = len(detonated_set)
        #
        #return max_detonated
        
        ## 1st solution
        #cnt_list = [0] * len(bombs)
        ##print(cnt_list)
        #for i in range(len(bombs)):
        #    detonated_bomb = []
        #    bombing_deq = deque()
        #    bombing_deq.append(i)
        #    while bombing_deq:
        #        current_bomb = bombing_deq.popleft()
        #        #print('bombing now: ', current_bomb)
        #        detonated_bomb.append(current_bomb)
        #        x_i, y_i, r_i = bombs[current_bomb]
        #        r2 = math.pow(r_i, 2)
        #        for j, bomb in enumerate(bombs):
        #            if j in detonated_bomb or j in bombing_deq:
        #                continue
        #            x_j, y_j, r_j = bomb
        #            if r2 >= (math.pow(x_j-x_i, 2) + math.pow(y_j-y_i, 2)):
        #                bombing_deq.append(j)
        #                #print('affected bomb: ', j)
        #    #print(i, detonated_bomb)
        #    cnt_list[i] = len(detonated_bomb)
        #    #print(cnt_list)
        #return max(cnt_list)