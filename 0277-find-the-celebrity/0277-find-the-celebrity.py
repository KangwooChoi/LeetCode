# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:

class Solution:
    def findCelebrity(self, n: int) -> int:
        for i in range(n):
            flag = True
            for j in range(n):
                if i == j:
                    continue
                if knows(j, i):
                    continue
                flag = False
                break 
            if flag:
                for k in range(n):
                    if i == k:
                        continue
                    if knows(i, k):
                        return -1
                return i
        return -1