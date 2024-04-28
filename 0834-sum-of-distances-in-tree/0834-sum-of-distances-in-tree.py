class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        INF = 1e9
        distance = [[INF] * n for _ in range(n)]
        for i in range(n):
            distance[i][i] = 0

        for v1, v2 in edges:
            distance[v1][v2] = 1
            distance[v2][v1] = 1

        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if distance[i][j] > distance[i][k] + distance[k][j]:
                        distance[i][j] = distance[i][k] + distance[k][j]
        print("distance: ", distance)
        ans = []
        for i in range(n):
            ans.append(sum(distance[i]))
        return ans