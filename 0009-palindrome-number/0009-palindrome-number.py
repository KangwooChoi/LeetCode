class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        str_x = str(x)
        if str_x[-1] == 0:
            return False
        left, right = 0, len(str_x)-1 
        while left < right:
            if str_x[left] != str_x[right]:
                return False
            left += 1
            right -= 1
        return True