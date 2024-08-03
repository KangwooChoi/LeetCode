class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        m = len(target)
        n = len(arr)

        if m != n:
            return False

        target.sort()
        arr.sort()
        
        for i in range(m):
            if target[i] != arr[i]:
                return False 
        return True