#6996
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
    elif(s=='A'): return 26
    elif(s=='B'): return 27
    elif(s=='C'): return 28
    elif(s=='D'): return 29
    elif(s=='E'): return 30
    elif(s=='F'): return 31
    elif(s=='G'): return 32
    elif(s=='H'): return 33
    elif(s=='I'): return 34
    elif(s=='J'): return 35
    elif(s=='K'): return 36
    elif(s=='L'): return 37
    elif(s=='M'): return 38
    elif(s=='N'): return 39
    elif(s=='O'): return 40
    elif(s=='P'): return 41
    elif(s=='Q'): return 42
    elif(s=='R'): return 43
    elif(s=='S'): return 44
    elif(s=='T'): return 45
    elif(s=='U'): return 46
    elif(s=='V'): return 47
    elif(s=='W'): return 48
    elif(s=='X'): return 49
    elif(s=='Y'): return 50
    elif(s=='Z'): return 51

T = int(input())
for x in range(T):
    string = input().split()
    lst1 = [0 for x in range(52)]
    lst2 = [0 for x in range(52)]
    equal = False
    if(len(string[0]) != len(string[1])):
        equal=False
    else:
        for i in range(len(string[0])):
            lst1[atoi(string[0][i])] += 1
            lst2[atoi(string[1][i])] += 1
        for i in range(52):
            if(lst1[i]!=lst2[i]):
                equal = False
                break
            equal = True
    if(equal):
        print(string[0],'&',string[1],"are anagrams.")
    else:
        print(string[0],'&',string[1],"are NOT anagrams.")
    
