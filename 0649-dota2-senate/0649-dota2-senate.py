class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        from collections import deque
        def iteration(senate):
            d_surv = deque()
            r_surv = deque()
            stack = []
            for i in range(len(senate)):
                if senate[i] == 'R':
                    if stack and stack[-1] == 'D':
                        stack.pop()
                    else:
                        stack.append('R')
                        r_surv.append(i)
                else:
                    if stack and stack[-1] == 'R':
                        stack.pop()
                    else:
                        stack.append('D')
                        d_surv.append(i)
            while stack:
                if stack[-1] == 'R':
                    if d_surv:
                        d_surv.popleft()
                        stack.pop()
                    else:
                        return 'Radiant'
                else:
                    if r_surv:
                        stack.pop()
                        r_surv.popleft()
                    else:
                        return 'Dire'
            ret = ''
            while d_surv and r_surv:
                if d_surv[0] < r_surv[0]:
                    ret += 'D'
                    d_surv.popleft()
                else:
                    ret += 'R'
                    r_surv.popleft()
            if d_surv:
                ret += 'D'*len(d_surv)
            if r_surv:
                ret += 'R'*len(r_surv)
            return ret
        while True:
            ret = iteration(senate)
            if ret == 'Radiant' or ret == 'Dire':
                return ret
            senate = ret 

