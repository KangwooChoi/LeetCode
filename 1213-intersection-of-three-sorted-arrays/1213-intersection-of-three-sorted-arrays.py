class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        s1 = set(arr1)
        s2 = set(arr2)
        s3 = set(arr3)
        return sorted(list(s1 & s2 & s3))