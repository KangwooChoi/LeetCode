class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        n = len(skill)
        if n == 2:
            return skill[0] * skill[1]
        sum_skill = sum(skill)
        #if sum_skill % 2 != 0: 
        #    return -1
        target = sum_skill / n * 2
        target = int(target)
        #print("target: ", target)
        if target > 2000:
            return -1 
        arr = [0] * 1001
        ret = 0
        for sk in skill:
            comp = target - sk
            if comp > 1000:
                return -1
            if arr[comp]:
                arr[comp] -= 1
                ret += comp * sk
            else:
                arr[sk] += 1
        if any(arr):
            return -1
        else:
            return ret