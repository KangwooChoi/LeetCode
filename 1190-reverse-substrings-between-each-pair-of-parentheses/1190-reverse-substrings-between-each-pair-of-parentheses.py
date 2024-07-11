class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        ans = ''
        for c in s:
            if c == '(':
                stack.append(ans)
                ans = ''
            elif c == ')':
                ans = stack.pop() + ans[::-1]
            else:
                ans += c
        return ans