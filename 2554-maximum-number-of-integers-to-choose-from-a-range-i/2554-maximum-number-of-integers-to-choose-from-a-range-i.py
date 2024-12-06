class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned_dic = defaultdict(bool)
        for b in banned:
            banned_dic[b] = True
        print(banned_dic)
        ans = 0
        check_sum = 0
        for i in range(1, n + 1):
            if banned_dic[i] == True:
                continue
            check_sum += i
            if check_sum > maxSum:
                return ans
            ans += 1
        return ans