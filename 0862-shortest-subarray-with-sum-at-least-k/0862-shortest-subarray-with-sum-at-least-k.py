class Solution:
    def shortestSubarray(self, nums: List[int], target_sum: int) -> int:
        n = len(nums)

        # Size is n+1 to handle subarrays starting from index 0
        prefix_sums = [0] * (n + 1)

        # Calculate prefix sums
        for i in range(1, n + 1):
            prefix_sums[i] = prefix_sums[i - 1] + nums[i - 1]

        candidate_indices = deque()

        shortest_subarray_length = float("inf")

        for i in range(n + 1):
            # Remove candidates from front of deque where subarray sum meets target
            while (
                candidate_indices
                and prefix_sums[i] - prefix_sums[candidate_indices[0]]
                >= target_sum
            ):
                # Update shortest subarray length
                shortest_subarray_length = min(
                    shortest_subarray_length, i - candidate_indices.popleft()
                )

            # Maintain monotonicity by removing indices with larger prefix sums
            while (
                candidate_indices
                and prefix_sums[i] <= prefix_sums[candidate_indices[-1]]
            ):
                candidate_indices.pop()

            # Add current index to candidates
            candidate_indices.append(i)

        # Return -1 if no valid subarray found
        return (
            shortest_subarray_length
            if shortest_subarray_length != float("inf")
            else -1
        )
#class Solution:
#    def shortestSubarray(self, nums: List[int], k: int) -> int:
#        n = len(nums)
#        sum_nums = [0] * (n + 1)
#        for i in range(n):
#            sum_nums[i + 1] = sum_nums[i] + nums[i]
#        ans = 1e9
#        print(sum_nums)
#        for left in range(n):
#            right = left + 1
#            while right <= n and right - left < ans:
#                if sum_nums[right] - sum_nums[left] >= k:
#                    ans = min(ans, right - left)
#                    break
#                right += 1
#        return ans if ans != 1e9 else -1