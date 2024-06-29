class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        ans = [] 
        queue = deque([])
        for ast in asteroids:
            if ast < 0:
                if not queue:
                    ans.append(ast)
                else:
                    flg = True
                    while queue:
                        if queue[-1] < -ast:
                            queue.pop()
                        elif queue[-1] == -ast:
                            queue.pop()
                            flg = False
                            break
                        else:
                            flg = False
                            break
                    if flg:
                        ans.append(ast)
            else:
                queue.append(ast)
        
        while queue:
            ans.append(queue.popleft())
        
        return ans
                