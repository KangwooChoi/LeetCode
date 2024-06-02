class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        from collections import Counter
        counter = Counter(arr)
        counter_again = Counter(counter.values())
        for val in counter_again.values():
            if val != 1:
                return False
        return True