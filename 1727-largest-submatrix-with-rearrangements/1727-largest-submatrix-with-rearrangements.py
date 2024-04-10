class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        ans = []
        for i in range(len(matrix)):
            temp = []
            for j in range(i, -1, -1):
                #print(f'j={j}, i={i}')
                if j == i:
                    and_list = copy.deepcopy(matrix[j])
                    temp.append(sum(matrix[j]))
                else:
                    for idx in range(len(matrix[j])):
                        and_list[idx] = and_list[idx] * matrix[j][idx]
                    temp.append((i-j+1)*sum(and_list))
                #print("matrix[j]: ", matrix[j])
                #print("and_list: ", and_list)
                #print("temp: ", temp)
            ans.append(max(temp))
            #print("ans: ", ans)
        return max(ans)