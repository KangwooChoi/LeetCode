class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        ans = []
        n = len(potions)
        for i in range(len(spells)): 
            base = spells[i]
            left, right = 0, n-1
            while left <= right:
                mid = (left + right) // 2
                if base * potions[mid] < success:
                    left = mid + 1
                else:
                    right = mid - 1
            ans.append(n-right-1)
                      
        return ans
                
