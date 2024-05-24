class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        cnt = 0
        if n == 0:
            return True
        if len(flowerbed) == 1:
            return False if flowerbed[0] else True
        if flowerbed[0] == 0 and flowerbed[1] == 0:
            cnt += 1
        for i in range(1, len(flowerbed)-1):
            if flowerbed[i-1] == 0 and flowerbed[i] == 0 and flowerbed[i+1] == 0:
                print("i: ", i)
                flowerbed[i] = 1
                cnt += 1
        if flowerbed[-2] == 0 and flowerbed[-1] == 0:
            cnt += 1
        print("cnt: ", cnt)
        if cnt >= n:
            return True
        else:
            return False
