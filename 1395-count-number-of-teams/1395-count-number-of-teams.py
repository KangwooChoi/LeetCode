class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        inc_cnt = 0
        dec_cnt = 0
        for i in range(n):
            for j in range(i+1, n):
                if rating[i] < rating[j]: 
                    for k in range(j+1, n):
                        if rating[j] < rating[k]:
                            inc_cnt += 1
                elif rating[i] > rating[j]:
                    for k in range(j+1, n):
                        if rating[j] > rating[k]:
                            dec_cnt += 1

        return inc_cnt + dec_cnt