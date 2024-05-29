class Solution:
    def numSteps(self, s: str) -> int:
        step = 0
        carry = 0
        for i in range(len(s)-1, 0, -1):
            check = int(s[i]) + carry
            if check == 0:
                step += 1
            elif check == 1:
                step += 2
                carry = 1
            elif check == 2:
                step += 1
                carry = 1
        check = carry + int(s[0])
        if check == 0:
            step += 1
        elif check == 2:
            step += 1
        return step