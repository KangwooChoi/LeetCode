class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return ['']
        
        ans = []
        for left_cnt in range(n):
            for left_str in self.generateParenthesis(left_cnt):
                for right_str in self.generateParenthesis(n-1-left_cnt):
                    ans.append('('+left_str+')'+right_str)
        return ans




        #from itertools import permutations
        #base = ['(', ')'] * n
        #candidates = permutations(base, n*2)
        #candidates = list(set(candidates))
        #ans = []
        #for cand in candidates:
        #    cnt = 0
        #    flag = True
        #    for c in cand:
        #        if c == '(':
        #            cnt += 1
        #        else:
        #            cnt -= 1
        #        if cnt < 0:
        #            flag = False
        #    if flag == True:
        #        ans.append(''.join(cand))
        #return ans    