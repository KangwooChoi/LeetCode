class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        from heapq import heappush, heappop
        hq = []
        for num in nums:
            heappush(hq, num)
        
        ans = []
        while hq:
            ans.append(heappop(hq))
        
        return ans

        #def div_pivot(arr):
        #    pre = []
        #    end = []
        #    for num in arr[1:]:
        #        if arr[0] > num:
        #            pre.append(num)
        #        else:
        #            end.append(num)
        #    #print(pre)
        #    #print(end)
        #    ans = []
        #    if len(pre):
        #        ans += div_pivot(pre)
        #    ans.append(arr[0])
        #    if len(end):
        #        end_ret = div_pivot(end)
        #        ans += end_ret
        #    
        #    return ans
        #ans = div_pivot(nums)
        #return ans