class RLEIterator:

    def __init__(self, encoding: List[int]):
        self.encoding = encoding

    def next(self, n: int) -> int:
        ret = -1
        while self.encoding and n > 0:
            if n <= self.encoding[0]:
                self.encoding[0] -= n
                n = 0
                ret = self.encoding[1]
            else:
                n -= self.encoding[0]
                if len(self.encoding) >= 2:
                    self.encoding = self.encoding[2:]
                else:
                    self.encoding = None
                    break
        if n > 0:
            return -1
        return ret
            


    #def __init__(self, encoding: List[int]):
    #    self.arr = []
    #    for i in range(0, len(encoding), 2):
    #        temp = [encoding[i+1]]
    #        temp *= encoding[i]
    #        #print('temp: ', temp)
    #        self.arr += temp
    #    #print('decoded: ', self.arr)
#
    #def next(self, n: int) -> int:
    #    if len(self.arr) < n:
    #        return -1
    #    else:
    #        ret = self.arr[n-1]
    #        if len(self.arr) > n:
    #            self.arr = self.arr[n:]
    #        else:
    #            self.arr = None
    #        return ret
        


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(encoding)
# param_1 = obj.next(n)