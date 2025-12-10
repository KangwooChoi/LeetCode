import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    # 2025-12-10
    df = views[views['author_id'] == views['viewer_id']]
    df.drop_duplicates(subset=['author_id'], inplace=True)
    df.sort_values(by=['author_id'], inplace=True)
    return df.rename(columns={'author_id':'id'})[['id']]


    # method 3
    #df = views[views['author_id'] == views['viewer_id']]
#
    #df.drop_duplicates(subset=['author_id'], inplace=True)
    #df.sort_values(by=['author_id'], inplace=True)
    #return df.rename(columns={'author_id':'id'})[['id']]

    # method 2
    #views = views.query('author_id == viewer_id')[['viewer_id']]
    #views.sort_values('viewer_id', inplace=True)
    #views.drop_duplicates(inplace=True)
    #return views.rename(columns={'viewer_id': 'id'})

    # method 1
    #print((views['author_id']==views['viewer_id']))
    #df = views[(views['author_id']==views['viewer_id'])]
    #arr = df['author_id'].unique()
    #df = pd.DataFrame(arr, columns=['id']).sort_values(by='id')
    #return df