class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        from collections import deque, defaultdict
        weights_counter = defaultdict(int)
        for p in people:
            if weights_counter[p]:
                weights_counter[p] += 1
            else:
                weights_counter[p] = 1
        weights_keys = sorted(weights_counter.keys(), reverse = True)
        #print(weights_keys)
        ans = 0
        while weights_keys:
            remain = limit - weights_keys[0] 
            weights_counter[weights_keys[0]] -= 1
            if weights_counter[weights_keys[0]] == 0:
                weights_keys.remove(weights_keys[0]) 
            while remain > 0:
                if weights_counter[remain]:
                    weights_counter[remain] -= 1
                    if weights_counter[remain] == 0:
                        weights_keys.remove(remain)
                    break
                else:
                    remain -= 1
            ans += 1
        return ans