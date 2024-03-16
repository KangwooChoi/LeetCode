class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        if len(arr) == 1:
            return False
        if arr[0] >= arr[1]:
            return False
        turn_flag = False
        for i in range(1, len(arr)-1):
            if turn_flag == False:
                if arr[i] > arr[i+1]:
                    turn_flag = True
                elif arr[i] == arr[i+1]:
                    return False
            else:
                if arr[i] <= arr[i+1]:
                    return False
        return turn_flag