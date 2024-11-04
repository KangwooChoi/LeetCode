class Solution:
    def compressedString(self, word: str) -> str:
        ans = ''
        n = len(word)
        if n == 1:
            return '1' + word
        cnt = 1
        for i in range(n - 1):
            if word[i] == word[i + 1]:
                cnt += 1 
            else:
                if cnt <= 9:
                    ans += str(cnt) + word[i]
                else:
                    p, q = cnt // 9, cnt % 9
                    p_str = ('9' + word[i]) * p
                    q_str = str(q) + word[i]
                    if q != 0:
                        ans += p_str + q_str
                    else:
                        ans += p_str
                cnt = 1
        if word[-1] == word[-2]:
            if cnt <= 9:
                ans += str(cnt) + word[-1]
            else:
                p, q = cnt // 9, cnt % 9
                p_str = ('9' + word[i]) * p
                q_str = str(q) + word[i]
                if q != 0:
                    ans += p_str + q_str
                else:
                    ans += p_str
        else:
            ans += '1' + word[-1]
        return ans