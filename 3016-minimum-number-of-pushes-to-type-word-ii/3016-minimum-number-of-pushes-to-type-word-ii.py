class Solution:
    def minimumPushes(self, word: str) -> int:
        cnt = Counter(word)
        ans = 0
        for i, x in enumerate(sorted(cnt.values(), reverse=True)):
            ans += (i // 8 + 1) * x
        return ans
        #from collections import Counter
        #freq_map = Counter(word)
        #counter = list(freq_map.values())
        #counter.sort(reverse=True)
        #return sum(counter[0:8]) + 2 * sum(counter[8:16]) + 3 * sum(counter[16:24]) + 4 * sum(counter[24:])

        #counter = [0] * 26
        #for c in word:
        #    index = ord(c) - ord('a')
        #    counter[index] += 1
        #counter.sort(reverse=True)
        #ans = 0
        #ans += sum(counter[0:8]) + 2 * sum(counter[8:16]) + 3 * sum(counter[16:24]) + 4 * sum(counter[24:])
        #return ans