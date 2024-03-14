class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        for row in image:
            for i in range((len(row)+1)//2):
                row[i], row[~i] = row[~i]^1, row[i]^1
        return image
        #ans = [] 
        #for row in image:
        #    new = []
        #    for i in range(len(row)-1, -1, -1):
        #        if row[i]:
        #            new.append(0)
        #        else:
        #            new.append(1)
        #    ans.append(new)
        #return ans
