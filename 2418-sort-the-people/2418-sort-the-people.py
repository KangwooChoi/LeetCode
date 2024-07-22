class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        tall_names = list(zip(heights, names))
        #print(tall_names)
        tall_names.sort(reverse=True)
        ans = []
        for h, name in tall_names:
            ans.append(name)
        return ans