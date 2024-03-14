class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        if not s:
            return 0
        ans = 0
        s.sort(reverse=True)
        g.sort(reverse=True)
        print('s: ', s)
        print('g: ', g)
        index = 0
        for size in s:
            while size < g[index]:
                index += 1
                if index == len(g):
                    return ans
            ans += 1
            index += 1
            if index == len(g):
                return ans
        return ans