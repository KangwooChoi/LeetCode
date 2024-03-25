class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        #return list(map(int, list(str(int(''.join(map(str, digits)))+1))))
        carry = 0
        for i in range(len(digits)-1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits
            else:
                digits[i] = 0
                carry = 1
        
        return digits if carry == 0 else [1] + digits