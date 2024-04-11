class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort()
        print(people)
        ans = [[]] * len(people)
        print(ans)
        for idx in range(len(people)):
            h, loc = people[idx]
            #print(h, loc)
            cnt = 0
            for j in range(len(ans)):
                if cnt == loc and not ans[j]:
                    ans[j] = [h, loc]
                if ans[j]:
                    if ans[j][0] >= h:
                        cnt += 1
                else:
                    cnt += 1
            #print("ans: ", ans)
        return ans
                