from heapq import heappop, heappush
class SmallestInfiniteSet:

    def __init__(self):
        self.ptr = 1 
        self.added = []

    def popSmallest(self) -> int:
        if self.added:
            if self.added[0] < self.ptr:
                return heappop(self.added)
            ans = self.ptr
            self.ptr += 1
            self.added = []
            return ans
        else:
            ans = self.ptr
            self.ptr += 1
            return ans 
        
    def addBack(self, num: int) -> None:
        if num >= self.ptr:
            return
        if num == self.ptr - 1:
            self.ptr -= 1
        heappush(self.added, num) 
        


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)