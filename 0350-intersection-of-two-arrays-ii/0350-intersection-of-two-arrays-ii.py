class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        nums2.sort()
        ans = []
        n1 = nums1.pop()
        n2 = nums2.pop()

        while n1 and n2:
            if n1 == n2:
                ans.append(n1)
                if nums1:
                    n1 = nums1.pop()
                else:
                    break
                if nums2:
                    n2 = nums2.pop()
                else:
                    break
            elif n1 > n2:
                if nums1:
                    n1 = nums1.pop()
                else:
                    break
            else:
                if nums2:
                    n2 = nums2.pop()
                else:
                    break

        return ans