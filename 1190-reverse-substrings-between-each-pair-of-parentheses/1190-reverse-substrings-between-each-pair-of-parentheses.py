class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        temp = ''
        for c in s:
            if c == '(':
                stack.append(temp)
                temp = ''
            elif c == ')':
                #print(temp)
                #print(stack)
                if stack:
                    temp = stack.pop() + temp[::-1]
                else:
                    temp.reverse()
            else:
                temp += c
        return temp