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
    print("\r Processing... {0} %".format(int(n/total * 100)), end="")

def CrawlingAllProblems(problemList):
   
    solvedProblemList = []
    for problem in problemList:
        problemParse = re.split('[/._]', str(problem))
        if problemParse[0] != "BOJ" :continue
        solvedProblemList.append(problemParse) # number of probelm

    totalProblem = len(solvedProblemList)
    processcedCnt = 0;

    print("Start WebCrawling !! ")
    for number in solvedProblemList:
        url = "https://www.acmicpc.net/problem" + "/" + number[3] 
        soup = htmlParse(url)
        

        title = soup.find("span",{"id":"problem_title"} )
        number.append(title.text)
        statusBar(processcedCnt, totalProblem)
        processcedCnt+=1
       
    print("\nWebCrawling is Done!!")
   
    return solvedProblemList


def AddProblemTitleToTheTopOfFile(file, problemName) :
    
    for i in file :
        print(i,end="")
    print()
    path = "./" + file[0] + "_" +  file[1] + "/"
  
    filename = "_".join(file[2:4]) + "."+file[4]
    print(path+filename);
    filePath = path+filename;
    addLine = ""
    url = "hhttps://www.acmicpc.net/problem/"+file[3]
    prefix = "// " if file[4]=='cpp' else "# "
    addLine = prefix + "Title : " + file[5] + " " + url
    
    with open(filePath , 'r+') as f:
        content = f.read()
        oneline = f.readline()
        f.seek(0,0)
        if("(https://acmicpc.net) Problem Title" not in oneline):
             f.write(addLine.rstrip('\r\n')+'\n' + content)
   
           
        
    return;

def MakeProblemTitle(AddProblenName):
    print("Start Make problem title !!")
    statusCnt = 0;
    AllDoneCnt = len(AddProblemName)
    for file in AddProblemName:
        filePath = "./" + file[0] + "_" +  file[1] + "/"
        
        fileName = "_".join(file[2::])
        
        f = open(filePath+fileName,'w')
        f.close()
        AddProblemTitleToTheTopOfFile(file, file[-1])

        statusBar(statusCnt, AllDoneCnt)
        statusCnt+=1
    
    print()

if __name__ == "__main__" :
    problemList = MakeProgramsList()
    login()
    AddProblemName = CrawlingAllProblems(problemList)

    MakeProblemTitle(AddProblemName)
    
                 


    


