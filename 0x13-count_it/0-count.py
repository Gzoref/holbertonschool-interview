#!/usr/bin/python3

""" Queries the Reddit API, parses the title of all hot articles, and prints a sorted count of given keywords
"""

import requests

def count_words(subreddit, word_list):
    """ Recursive function that queries the Reddit API,
        parses the title of all hot articles,
        and prints a sorted count of given keywords
    """
    if subreddit is None or subreddit == "" or word_list is None:
        return None

    r = requests.get('https://www.reddit.com/r/{}.json'.format(subreddit), headers={'limit': '100'}, allow_redirects=False)
    print(r.text)
