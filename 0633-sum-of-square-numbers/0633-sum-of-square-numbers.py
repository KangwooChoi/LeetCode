class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        i = 0
        isq = i ** 2
        sq_list = [isq]
        while isq < c:
            i += 1
            isq = i ** 2 
            sq_list.append(isq)
        left, right = 0, len(sq_list) - 1
        while left < right:
            base = sq_list[left] + sq_list[right]
            if c == base:
                return True
            elif c > base:
                left += 1
            elif c < base:
                right -= 1
        return False