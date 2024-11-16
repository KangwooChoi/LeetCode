class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        length = len(nums)
        result = [-1] * (length - k + 1)
        index_deque = collections.deque()

        for current_index in range(length):
            if index_deque and index_deque[0] < current_index - k + 1:
                index_deque.popleft()
            if (
                index_deque
                and nums[current_index] != nums[current_index - 1] + 1
            ):
                index_deque.clear()

            index_deque.append(current_index)

            if current_index >= k - 1:
                if len(index_deque) == k:
                    result[current_index - k + 1] = nums[index_deque[-1]]
                else:
                    result[current_index - k + 1] = -1

        return result
#class Solution:
#    def resultsArray(self, nums: List[int], k: int) -> List[int]:
#        n = len(nums)
#        ans = [] 
#        consec = [1] * n
#        prev = nums[0]
#        for i in range(1, n):
#            if nums[i] > prev:
#                consec[i] = consec[i - 1] + 1
#            prev = nums[i]
#        for i in range(k - 1, n):
#            if consec[i] >= k:
#                ans.append(max(nums[i-k+1:i+1]))
#            else:
#                ans.append(-1)
#        return ans