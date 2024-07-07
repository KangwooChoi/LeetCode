class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        ans,empty = 0, 0
        ans += numBottles 
        empty = numBottles 
        while empty >= numExchange:
            #print(empty)
            p, q = empty // numExchange, empty % numExchange
            ans += p
            empty = p + q
            #print(empty)
        return ans