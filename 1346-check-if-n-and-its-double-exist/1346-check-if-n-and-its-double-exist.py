class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        # Brute-force
        for i, iv in enumerate(arr):
            for jv in arr[i+1:]:
                if iv == jv * 2 or jv == iv * 2:
                    return True
        return False