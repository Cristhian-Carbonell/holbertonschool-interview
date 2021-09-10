#!/usr/bin/python3
"""Count it!
"""
import requests


def count_words(subreddit, word_list, keyWord_cont={}, next_pag=None, reap_keyWord={}):
    """recursive function that queries the Reddit API,
    parses the title of all hot articles,
    and prints a sorted count of given keywords
    """
    headers = auth()

    if next_pag:
        res = requests.get('https://reddit.com/r/' + subreddit +
                            '/hot.json?after=' + next_pag, headers=headers)
    else:
        res = requests.get('https://reddit.com/r/' + subreddit +
                            '/hot.json', headers=headers)

    if res.status_code == 404:
        return

    if keyWord_cont == {}:
        for word in word_list:
            keyWord_cont[word] = 0
            reap_keyWord[word] = word_list.count(word)

    res_dict = res.json()
    res_data = res_dict['data']
    next_pg = res_data['after']
    res_posts = res_data['children']

    for post in res_posts:
        data = post['data']
        title = data['title']
        titleWords = title.split()
        for w in titleWords:
            for key in keyWord_cont:
                if w.lower() == key.lower():
                    keyWord_cont[key] += 1

    if next_pg:
        count_words(subreddit, word_list, keyWord_cont, next_pg, reap_keyWord)

    else:
        for key, value in reap_keyWord.items():
            if value > 1:
                keyWord_cont[key] *= val

        sorted_abc = sorted(keyWord_cont.items(), key=lambda x: x[0])
        sorted_res = sorted(sorted_abc, key=lambda x: (-x[1], x[0]))
        for res in sorted_res:
            if res[1] > 0:
                print('{}: {}'.format(res[0], res[1]))

    


def auth():
    """Request a temporary OAuth token from Reddit
    """
    auth = requests.auth.HTTPBasicAuth('BqiqtJ5VmwjnxfbhmEiUSQ',
                                       'yDmd9DYbCgYlzRi0jjnoiP0i_6dGqw')

    data = {'grant_type': 'password',
            'username': 'Tolkien-retr0',
            'password': 'cla741236'}

    headers = {'User-Agent': 'holberton/0.0.1'}

    res = requests.post('https://www.reddit.com/api/v1/access_token',
                        auth=auth, data=data, headers=headers)
    TOKEN = res.json()['access_token']

    headers = {**headers, **{'Authorization': f"bearer {TOKEN}"}}

    return headers
    