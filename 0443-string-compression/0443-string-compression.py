class Solution:
    def compress(self, chars: List[str]) -> int:
        n = len(chars)
        i, curr = 0, 0
        while i < len(chars):
            cnt = 1
            while (i + cnt < len(chars) and chars[i+cnt] == chars[i]):
                cnt += 1
            chars[curr] = chars[i]
            curr += 1
            if cnt > 1:
                str_repr = str(cnt)
                chars[curr:curr+len(str_repr)] = list(str_repr)
                curr += len(str_repr)
            i += cnt
        return curr
            
        #prev = chars[0]
        #cnt = 1
        #ans = chars[0]
        #for i in range(1, len(chars)):
        #    if prev == chars[i]:
        #        cnt += 1
        #        chars.pop(i)
        #    else:
        #        if cnt > 1:
        #            ans += str(cnt)
        #            cnt = 1
        #            ans += chars[i]
        #            prev = chars[i]
        #if cnt != 1:
        #    ans += str(cnt)
        #print(ans)
        #return len(ans)