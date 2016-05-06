#Alphabet number
#String
def atoi(s):
    if(s=='a'): return 0
    elif(s=='b'): return 1
    elif(s=='c'): return 2
    elif(s=='d'): return 3
    elif(s=='e'): return 4
    elif(s=='f'): return 5
    elif(s=='g'): return 6
    elif(s=='h'): return 7
    elif(s=='i'): return 8
    elif(s=='j'): return 9
    elif(s=='k'): return 10
    elif(s=='l'): return 11
    elif(s=='m'): return 12
    elif(s=='n'): return 13
    elif(s=='o'): return 14
    elif(s=='p'): return 15
    elif(s=='q'): return 16
    elif(s=='r'): return 17
    elif(s=='s'): return 18
    elif(s=='t'): return 19
    elif(s=='u'): return 20
    elif(s=='v'): return 21
    elif(s=='w'): return 22
    elif(s=='x'): return 23
    elif(s=='y'): return 24
    elif(s=='z'): return 25
    
    
    
string = input()
st = ""
lst = [0 for x in range(26)]
for i in range(len(string)):
    lst[atoi(string[i])] += 1
for x in range(len(lst)):
    st += str(lst[x])+" "
print(st)
