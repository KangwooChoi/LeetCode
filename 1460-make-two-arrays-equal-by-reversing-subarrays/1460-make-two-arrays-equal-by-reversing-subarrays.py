class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        m = len(target)
        n = len(arr)

        if m != n:
            return False

        counter = [0] * 1001
        for val in target:
            counter[val] += 1
        
        for val in arr:
            if counter[val] == 0:
                return False
            else:
                counter[val] -= 1
        return True

        #target.sort()
        #arr.sort()
        #
        #for i in range(m):
        #    if target[i] != arr[i]:
        #        return False 
        #return True