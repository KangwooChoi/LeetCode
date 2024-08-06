class Solution:
    def minimumPushes(self, word: str) -> int:
        counter = defaultdict(int)
        for c in word:
            counter[c] += 1
        counter = list(counter.values())
        counter.sort(reverse=True)
        return sum(counter[0:8]) + 2 * sum(counter[8:16]) + 3 * sum(counter[16:24]) + 4 * sum(counter[24:])
        #counter = [0] * 26
        #for c in word:
        #    index = ord(c) - ord('a')
        #    counter[index] += 1
        #counter.sort(reverse=True)
        #ans = 0
        #ans += sum(counter[0:8]) + 2 * sum(counter[8:16]) + 3 * sum(counter[16:24]) + 4 * sum(counter[24:])
        #return ans