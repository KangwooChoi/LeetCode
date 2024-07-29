class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        teams = 0

        # Tables for increasing and decreasing sequences
        increasing_teams = [[0] * 4 for _ in range(n)]
        decreasing_teams = [[0] * 4 for _ in range(n)]

        # Fill the base cases. (Each soldier is a sequence of length 1)
        for i in range(n):
            increasing_teams[i][1] = 1
            decreasing_teams[i][1] = 1

        # Fill the tables
        for count in range(2, 4):
            for i in range(n):
                for j in range(i + 1, n):
                    if rating[j] > rating[i]:
                        increasing_teams[j][count] += increasing_teams[i][
                            count - 1
                        ]
                    if rating[j] < rating[i]:
                        decreasing_teams[j][count] += decreasing_teams[i][
                            count - 1
                        ]

        # Sum up the results (All sequences of length 3)
        for i in range(n):
            teams += increasing_teams[i][3] + decreasing_teams[i][3]

        return teams
#class Solution:
#    def numTeams(self, rating: List[int]) -> int:
#        n = len(rating)
#        inc_cnt = 0
#        dec_cnt = 0
#        for i in range(n):
#            for j in range(i+1, n):
#                if rating[i] < rating[j]: 
#                    for k in range(j+1, n):
#                        if rating[j] < rating[k]:
#                            inc_cnt += 1
#                elif rating[i] > rating[j]:
#                    for k in range(j+1, n):
#                        if rating[j] > rating[k]:
#                            dec_cnt += 1
#
#        return inc_cnt + dec_cnt