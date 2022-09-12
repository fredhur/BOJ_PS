# Traverse all folder, and then get solved problem's index
# then crawling problem's name and then add to file name
# if possible, make problem category to it.
from concurrent.futures import process
import os
import re
from pathlib import Path
from bs4 import BeautifulSoup
import requests
def MakeProgramsList() :
    result = list(Path(".").rglob("*.cpp"))
    result = result + list(Path(".").rglob("*.py"))
    return result 


def login():
    return
    

def htmlParse(url):
    #print(url)
    webpage = requests.get(url)
    soup = BeautifulSoup(webpage.content, "html.parser")
    return soup



def statusBar(n , total) : 

    print("\rWebCrawling... {0} %".format(int(n/total * 100)), end="")

def CrawlingAllProblems(problemList):
   
    solvedProblemList = []
    for problem in problemList:
        problemParse = re.split('[/._]', str(problem))
        if problemParse[0] != "BOJ" :continue
        solvedProblemList.append(problemParse) # number of probelm

    totalProblem = len(solvedProblemList)
    processcedCnt = 0;
    for number in solvedProblemList:
        url = "https://www.acmicpc.net/problem" + "/" + number[3] 
        soup = htmlParse(url)
        

        title = soup.find("span",{"id":"problem_title"} )
        number.append(title.text)
        statusBar(processcedCnt, totalProblem)
        processcedCnt+=1
    print("\nWebCrawling is Done!! start re-naming problems")
    for i in solvedProblemList:
        print(i)
    return solvedProblemList

if __name__ == "__main__" :
    problemList = MakeProgramsList()
    login()
    AddProblemName = CrawlingAllProblems(problemList)


    


