"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        def look(id):
            for employee in employees:
                if employee.id == id:
                    employees.remove(employee)
                    return employee
            
        from collections import deque
        dq = deque([id])
        ans = 0
        #print("dq: ", dq) 
        while dq:
            now_id = dq.popleft()
            #print("now_id: ", now_id)
            now = look(now_id)
            #print("now: ", now)
            ans += now.importance
            if now.subordinates:
                for sub in now.subordinates:
                    dq.append(sub)

        return ans
        

                