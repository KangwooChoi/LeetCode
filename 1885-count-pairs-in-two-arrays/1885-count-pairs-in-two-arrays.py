class Solution:
    def countPairs(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1) 
        diff = [nums1[i] - nums2[i] for i in range(n)]
        diff.sort()
        ans = 0
        for i in range(0, n):
            if diff[i] > 0:
                ans += n - 1 -i
            else:
                left = i + 1
                right = n - 1
                while left <= right:
                    mid = (left + right) // 2
                    if diff[i] + diff[mid] > 0:
                        right = mid - 1
                    else:
                        left = mid + 1
                ans += n - left
        return ans

        # Time-outed Solution
        #diff1 = defaultdict(int)
        #diff2 = defaultdict(int)
        #for i in range(n):
        #    diff1[i] = nums1[i] - nums2[i]
        #    diff2[i] = nums2[i] - nums1[i]
        #    
        #for i in range(n-1):
        #    for j in range(i+1, n):
        #        if diff1[i] > diff2[j]:
        #            ans += 1 
        #return ans