class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for c in s:
            if c in ['(', '[', '{']:
                stack.append(c)
            else:
                if len(stack) == 0:
                    return False
                if stack[-1] == '(' and c == ')':
                    stack.pop()
                    continue
                if stack[-1] == '[' and c == ']':
                    stack.pop()
                    continue
                if stack[-1] == '{' and c == '}':
                    stack.pop()
                    continue
                return False 
        if len(stack) == 0:
            return True
        else:
            return False
                