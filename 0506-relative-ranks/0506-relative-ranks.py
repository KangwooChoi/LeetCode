class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        ans = []
        rank_dict = defaultdict()
        temp_list = sorted(score, reverse=True)

        if len(temp_list) == 1:
            return ["Gold Medal"]

        for i in range(3):
            if i == 0:
                rank_dict[temp_list[i]] = "Gold Medal"
            elif i == 1 and len(temp_list) >= 2:
                rank_dict[temp_list[i]] = "Silver Medal"
            elif i == 2 and len(temp_list) >= 3:
                rank_dict[temp_list[i]] = "Bronze Medal"

        if len(score) > 3:
            for i in range(3, len(temp_list)):
                rank_dict[temp_list[i]] = str(i+1)
        for i in range(len(temp_list)):
            ans.append(rank_dict[score[i]])
        return ans