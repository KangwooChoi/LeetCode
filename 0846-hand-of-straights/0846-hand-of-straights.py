class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False
        counter = defaultdict(int)
        for num in hand:
            counter[num] += 1
        print(counter)
        while counter:
            keys = list(counter.keys())
            key = min(keys)
            if counter[key] >= 1:
                counter[key] -= 1
                if counter[key] == 0:
                    del counter[key]
                for i in range(1, groupSize):
                    if counter[key+i] >= 1:
                        counter[key+i] -= 1
                        if counter[key+i] == 0:
                            del counter[key+i]
                    else:
                        return False
        return True