class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        indexer = dict()
        counter = 0
        n = len(values)
        for i in range(n):
            s, e = equations[i]
            if s not in indexer:
                indexer[s] = counter
                counter += 1      
            if e not in indexer:
                indexer[e] = counter
                counter += 1
        sheet = [[-1.0] * counter for _ in range(counter)]
        for i in range(n):
            s_, e_ = equations[i]
            s = indexer[s_]
            e = indexer[e_]
            val = values[i]
            sheet[s][e] = val
            sheet[e][s] = 1.0/val
            sheet[s][s] = 1.0
            sheet[e][e] = 1.0
        
        for k in range(counter):
            for i in range(counter):
                for j in range(counter):
                    if sheet[i][j] > 0.0:
                        continue
                    if sheet[i][k] > 0.0 and sheet[k][j] > 0.0:
                        sheet[i][j] = sheet[i][k] * sheet[k][j]
                        sheet[j][i] = 1.0/sheet[i][j]
        ans = []
        for s_, e_ in queries:
            if s_ not in indexer:
                ans.append(-1.0)
                continue
            if e_ not in indexer:
                ans.append(-1.0)
                continue
            s = indexer[s_]
            e = indexer[e_]
            ans.append(sheet[s][e])
        return ans