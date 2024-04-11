class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        location = [i for i in range(len(people))]
        #print(location)
        people.sort()
        ans = [[]] * len(people)
        #print('ans: ', ans)
        prev = -1
        cnt = 0
        for h, i in people:
            if h == prev:
                cnt += 1
            else:
                cnt = 0
            print(f'h={h}, i={i}')
            ans[location[i-cnt]] = [h, i]
            location.pop(i-cnt)
            #print(ans)
            prev = h
        return ans
        #people.sort()
        #print(people)
        #ans = [[]] * len(people)
        #print(ans)
        #for idx in range(len(people)):
        #    h, loc = people[idx]
        #    #print(h, loc)
        #    cnt = 0
        #    for j in range(len(ans)):
        #        if cnt == loc and not ans[j]:
        #            ans[j] = [h, loc]
        #        if ans[j]:
        #            if ans[j][0] >= h:
        #                cnt += 1
        #        else:
        #            cnt += 1
        #    #print("ans: ", ans)
        #return ans
                