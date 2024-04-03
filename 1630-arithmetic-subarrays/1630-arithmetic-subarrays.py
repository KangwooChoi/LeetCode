class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        ans = []
        for i in range(len(l)):
            s, e = l[i], r[i]
            #print("i, s, e: ", i, s, e)
            if s - e == 1 or e - s == 1:
                ans.append(True)
                continue
            if s == e:
                ans.append(False)
                continue
            sliced = sorted(nums[s:e+1])
            #print("sliced: ", sliced)
            diff_prev = sliced[1] - sliced[0] 
            for j in range(1, len(sliced)-1):
                diff_now = sliced[j+1] - sliced[j]
                if diff_now != diff_prev:
                    ans.append(False)
                    break
                else:
                    diff_prev = diff_now
                    if j == len(sliced) - 2:
                        ans.append(True)
        return ans