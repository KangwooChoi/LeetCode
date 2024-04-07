class Solution:
    def frequencySort(self, s: str) -> str:
        from heapq import heappop, heappush
        s_dict = defaultdict()
        for c in s:
            if c not in s_dict.keys():
                s_dict[c] = 1
            else:
                s_dict[c] += 1
        queue = []
        for key, val in s_dict.items():
            heappush(queue, [-val, key])

        ans = ''
        while queue:
            val, key = heappop(queue)
            for _ in range(-val):
                ans += key
        return ans

