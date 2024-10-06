class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        s1 = sentence1.split(' ')
        s2 = sentence2.split(' ')
        if len(s1) > len(s2):
            s1, s2 = s2, s1
        n = len(s1)
        left, right = 0, 1
        # prefix
        while left < n and s1[left] == s2[left]:
            left += 1

        # suffix
        while right <= n and s1[-right] == s2[-right]:
            right += 1
        if left + right == n + 1:
            return True 
        else:
            return False
