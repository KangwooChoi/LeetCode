import pandas as pd

def fix_names(users: pd.DataFrame) -> pd.DataFrame:
    #users['name'] = users.apply(
    #    #lambda x: x['name'].title(),
    #    lambda x: x['name'].capitalize(),
    #    axis = 1
    #    )
    users['name'] = users['name'].str.capitalize()
    return users.sort_values('user_id')