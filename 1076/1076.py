#1076 저항

def compute(s1,s2,s3):
    result=""
    result=int(str(match(s1))+str(match(s2)))
    
    result=result*match2(s3)
    return result

def match(s):
    if(s.find("black")==0):
        return 0
    elif(s.find("brown")==0):
        return 1
    elif(s.find("red")==0):
        return 2
    elif(s.find("orange")==0):
        return 3
    elif(s.find("yellow")==0):
        return 4
    elif(s.find("green")==0):
        return 5
    elif(s.find("blue")==0):
        return 6
    elif(s.find("violet")==0):
        return 7
    elif(s.find("grey")==0):
        return 8
    elif(s.find("white")==0):
        return 9
        
def match2(s):
    if(s.find("black")==0):
        return 1
    elif(s.find("brown")==0):
        return 10
    elif(s.find("red")==0):
        return 100
    elif(s.find("orange")==0):
        return 1000
    elif(s.find("yellow")==0):
        return 10000
    elif(s.find("green")==0):
        return 100000
    elif(s.find("blue")==0):
        return 1000000
    elif(s.find("violet")==0):
        return 10000000
    elif(s.find("grey")==0):
        return 100000000
    elif(s.find("white")==0):
        return 1000000000
    
s1=input()
s2=input()
s3=input()
print(compute(s1,s2,s3))
