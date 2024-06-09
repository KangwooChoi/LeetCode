class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        ans = 0
        remains = defaultdict(int)
        remain = 0
        for num in nums:
            remain = (remain + num) % k
            remains[remain] += 1
        #print(remains)
        for key in remains.keys():
            n = remains[key]
            ans += n * (n-1) // 2 
        if remains[0] > 0:
            ans += remains[0]
        return ans