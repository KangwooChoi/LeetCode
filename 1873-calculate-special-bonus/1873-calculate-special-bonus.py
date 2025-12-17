import pandas as pd

def calculate_special_bonus(employees: pd.DataFrame) -> pd.DataFrame:
    #bonus_id = (employees['employee_id'] % 2 == 1) & (~employees['name'].str.startswith('M'))
    #employees['bonus'] = employees['salary']
    #employees['bonus'][~bonus_id] = 0
    #return employees[['employee_id', 'bonus']].sort_values('employee_id')
    employees['bonus'] = employees.apply(
        lambda x: x['salary'] if x['employee_id'] % 2 and not x['name'].startswith('M') else 0,
        axis = 1
    )
    return employees[['employee_id','bonus']]
    # Editorial
    #employees['bonus'] = employees.apply(
    #    lambda x: x['salary'] if x['employee_id'] % 2 and not x['name'].startswith('M') else 0,
    #    axis = 1
    #)
    #return employees[['employee_id','bonus']].sort_values('employee_id')