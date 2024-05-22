class Solution:
    def partition(self, s: str) -> List[List[str]]:
        len_s = len(s)
        dp = [[False] * len_s for _ in range(len_s)]
        result = []
        self.dfs(result, s, 0, [], dp)
        return result

    def dfs(
        self,
        result: List[List[str]],
        s: str,
        start: int,
        currentList: List[str],
        dp: List[List[bool]],
    ):
        if start >= len(s):
            result.append(list(currentList))
        for end in range(start, len(s)):
            if s[start] == s[end] and (
                end - start <= 2 or dp[start + 1][end - 1]
            ):
                dp[start][end] = True
                currentList.append(s[start : end + 1])
                self.dfs(result, s, end + 1, currentList, dp)
                currentList.pop()
#class Solution:
#    def partition(self, s: str) -> List[List[str]]:
#        ans = []
#        mid = len(s) // 2
#        for i in range(1, len(s)+1):
#            temp = []
#            for j in range(0, len(s)):
#                start = s[j:j+i]
#                flag = True
#                for k in range(len(start)//2+1):
#                    if start[k] != start[-k-1]:
#                        flag = False
#                        break
#                if flag == True:
#                    temp.append(start)
#            ans.append(temp)
#        return ans
#