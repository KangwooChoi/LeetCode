class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        def backtrack(contains, remains):
            cnt = 0
            for i in range(len(contains)):
                for j in range(len(remains)):
                    if contains[i] - remains[j] != k:
                        #print(contains[i], remains[j])
                        cnt += 1
                        if j != len(remains) - 1:
                            cnt += backtrack(contains.append(remains[j]), remains[j+1:])
            return cnt

        if len(nums) == 1:
            return len(nums)
        nums.sort(reverse=True)
        ans = 0
        for i in range(len(nums)):
            ans += 1
            if i != len(nums) - 1:
                 ans += backtrack([nums[i]], nums[i+1:])
        return ans