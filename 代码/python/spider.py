import requests
import bs4
from bs4 import BeautifulSoup
#从网络上获取大学排名网页内容 
def getHTMLText(url): 
    try:
        r = requests.get(url,timeout = 30)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return ""

#提取网页内容中信息到合适的数据结构
def fillUnivList(ulist,html): 
    soup = BeautifulSoup(html,"html.parser")
    for tr in soup.find('tbody').children:  #找到tbody标签的子标签
        if isinstance(tr,bs4.element.Tag):#检测tr标签是否是bs4库定义的tag类型，不是就过滤，比如过滤注释
            a = tr('a')
            tds = tr('td') #将tr中的所有td标签存为列表赋值给tds
            ulist.append([tds[0].text.strip(), a[0].string.strip(), tds[4].text.strip()])
            #print(tds[0],tds[1],tds[4])
   
#利用数据结构展示并输出
def printUnivList(ulist,num):
    tplt = "{0:^10}{1:{3}^10}{2:^16}"
    print("{:^10}\t{:^6}\t{:^10}".format("排名","学校名称","总分"))
    for i in range(num):
        u = ulist[i]
        print(tplt.format(u[0],u[1],u[2],chr(12288)))
    
#主函数
def main():
    uinfo = []
    url = 'https://www.shanghairanking.cn/rankings/bcur/202011'
    html = getHTMLText(url)
    fillUnivList(uinfo,html)
    printUnivList(uinfo,20) 
main()
