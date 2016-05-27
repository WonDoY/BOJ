testcase=int(input())
for i in range(testcase):
    string=input().split() # 건물 갯수, 순서 규칙 갯수
    
    node=int(string[0]);rule=int(string[1]);
    
    noderesult=[0]
    nodetime=[0]
    string=input().split()
    for x in range(node):
        nodetime.append(int(string[x]))
        noderesult.append(0);
    noderesult[1]=nodetime[1]
    for x in range(rule):
        string=input().split()
        noderesult[int(string[1])]=max(noderesult[int(string[0])]+nodetime[int(string[1])],noderesult[int(string[1])])
        
##        
##        print(nodetime)
##        print(noderesult)
        
    
        
        
    dest=int(input())

    print(noderesult[dest])
    
    
    


    # compute
    #
    #
    #
    #
    #
    
    
