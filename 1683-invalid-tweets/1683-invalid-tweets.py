import pandas as pd

def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    is_invalid = tweets['content'].str.len() > 15
    return tweets[is_invalid][['tweet_id']]