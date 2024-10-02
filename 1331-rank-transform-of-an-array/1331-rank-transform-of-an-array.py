class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        arr_sort = sorted(arr)
        index = 1
        rank = dict()
        for num in arr_sort:
            if num in rank:
                continue
            else:
                rank[num] = index
                index += 1
        ans = []
        for num in arr:
            ans.append(rank[num])
        return ans