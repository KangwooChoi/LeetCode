class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        INF = int(1e9)
        cost_map = [[INF] * 26 for _ in range(26)]
        for i in range(26):
            cost_map[i][i] = 0
        for i in range(len(original)):
            src = ord(original[i]) - ord('a')
            dest = ord(changed[i]) - ord('a')
            cost_map[src][dest] = min(cost[i], cost_map[src][dest])
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    if cost_map[i][j] > cost_map[i][k] + cost_map[k][j]:
                        cost_map[i][j] = cost_map[i][k] + cost_map[k][j]

        #print(cost_map)
        #print(cost_map[1][2])
        #print(cost_map[2][4])
        #print(cost_map[4][1])
        #print(cost_map[3][4])

        ans = 0
        for i in range(len(source)):
            src = ord(source[i]) - ord('a')
            tar = ord(target[i]) - ord('a')
            if cost_map[src][tar] == INF:
                return -1
            else:
                ans += cost_map[src][tar]
        
        return ans