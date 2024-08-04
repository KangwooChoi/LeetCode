class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        sum_arr = [0]
        for i in range(n):
            temp = nums[i]
            sum_arr.append(temp)
            for j in range(i+1, n):
                temp += nums[j]
                sum_arr.append(temp)
        sum_arr.sort()
        return int(sum(sum_arr[left:right+1]) % (1e9+7))