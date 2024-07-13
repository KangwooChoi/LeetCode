class Solution:
    def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
        initial = []
        for p, h, d  in zip(positions, healths, directions):
            initial.append([p, h, d])
        initial.sort()
        stack = []
        survived = dict()
        for p, h, d in initial:
            #print(p, h, d)
            if d == 'R':
                stack.append([p, h])
            elif d == 'L':
                if not stack:
                    survived[p] = h
                else:
                    if stack[-1][1] > h:
                        stack[-1][1] -= 1
                        #print(stack)
                    else:
                        flag = True
                        while stack and stack[-1][1] <= h:
                            #print(stack)
                            if stack[-1][1] == h:
                                stack.pop()
                                flag = False
                                break
                            elif stack[-1][1] < h:
                                h -= 1
                                stack.pop()
                                #print(p, h, d) 
                                #print(stack)

                        if stack and flag and stack[-1][1] > h:
                            stack[-1][1] -= 1
                                
                        if not stack and flag:
                            survived[p] = h
        
        #print(stack)

        while stack:
            p, h = stack.pop()
            #print(p, h)
            survived[p] = h
        #print(survived)
        ans = []
        for p in positions:
            if p in survived:
                ans.append(survived[p])
        return ans