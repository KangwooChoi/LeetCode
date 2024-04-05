class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        if len(arr) <= k:
            return max(arr) * k
        ans = [0] * len(arr)
        for i in range(len(arr)):
            if i < k:
                ans[i] = max(arr[:i+1])*(i+1)
                #print(f"ans[{i}] = {ans[i]}")
                continue
            temp = []
            for j in range(1, k+1):
                temp.append(ans[i-j]+j*max(arr[i-j+1:i+1]))
            #print(f"temp = {temp}")
            ans[i] = max(temp)
            #print(f"ans[{i}] = {ans[i]}")
        return ans[-1]