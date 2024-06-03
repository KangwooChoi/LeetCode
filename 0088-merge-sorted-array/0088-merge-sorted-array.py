class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        lnums1 = len(nums1)
        cnt = 0
        for i in range(m, min(lnums1, m+n)):
            nums1[i] = nums2[i-m]
            cnt += 1
        nums1 += nums2[cnt:]
        nums1.sort() 