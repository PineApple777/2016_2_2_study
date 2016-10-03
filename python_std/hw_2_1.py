
# coding: utf-8

# In[2]:

from bs4 import BeautifulSoup as bs
from urllib.request import urlopen

rep = int(input())
dr = []
for lx in range(rep):
    dr +=[input()]
for drs in dr:
    url = drs
    res = urlopen('http://comic.naver.com/webtoon/weekdayList.nhn?week=' + url)
    content = bs(res,'lxml')
    divs = content.body.findAll("div",{ "class" : "list_area" })
    for div in divs :
        lis = div.findAll('li')
        fst = lis[len(lis) - 1].findAll('dt')[0].findAll('a')[0]
        for li in lis:
            dt = li.findAll('dt')
            a = dt[0].findAll('a')[0]
            if a == fst:
                print(a.string)
            else :
                print(a.string,end= ", ")


# In[ ]:



