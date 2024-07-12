class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        def rm_substr(input, target):
            stack = []
            for c in input:
                if c == target[1] and stack and stack[-1] == target[0]:
                    stack.pop()
                else:
                    stack.append(c)
            return ''.join(stack)
            
        ans = 0
        high = 'ab' if x >= y else 'ba'
        low = 'ba' if high == 'ab' else 'ab'

        first_pass = rm_substr(s, high)
        ans += (len(s) - len(first_pass)) // 2 * max(x, y)

        second_pass = rm_substr(first_pass, low)
        ans += (len(first_pass) - len(second_pass)) // 2 * min(x, y)

        return ans