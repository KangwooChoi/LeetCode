class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        mod = 10**9 + 7

        def count_and_sum(nums, n, target):
            count = 0
            current_sum = 0
            total_sum = 0
            window_sum = 0
            i = 0
            for j in range(n):
                current_sum += nums[j]
                window_sum += nums[j] * (j - i + 1)
                while current_sum > target:
                    window_sum -= current_sum
                    current_sum -= nums[i]
                    i += 1
                count += j - i + 1
                total_sum += window_sum
            return count, total_sum

        def sum_of_first_k(nums, n, k):
            min_sum = min(nums)
            max_sum = sum(nums)
            left = min_sum
            right = max_sum

            while left <= right:
                mid = left + (right - left) // 2
                if count_and_sum(nums, n, mid)[0] >= k:
                    right = mid - 1
                else:
                    left = mid + 1
            count, total_sum = count_and_sum(nums, n, left)
            # There can be more subarrays with the same sum of left.
            return total_sum - left * (count - k)

        result = (
            sum_of_first_k(nums, n, right) - sum_of_first_k(nums, n, left - 1)
        ) % mod
        # Ensure non-negative result
        return (result + mod) % mod
        #sum_arr = [0]
        #for i in range(n):
        #    temp = nums[i]
        #    sum_arr.append(temp)
        #    for j in range(i+1, n):
        #        temp += nums[j]
        #        sum_arr.append(temp)
        #sum_arr.sort()
        #return int(sum(sum_arr[left:right+1]) % (1e9+7))