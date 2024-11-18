class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        if k == 0:
            return [0] * n 
        code = code * 3
        print(code)
        ans = []
        if k > 0:
            for i in range(n, 2 * n):
                ans.append(sum(code[i + 1:i + 1 + k]))
        else:
            for i in range(n, 2 * n):
                ans.append(sum(code[i + k:i]))
        return ans