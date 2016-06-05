#/BOJ/etc/mergeSort

#average O(n log n)
#Worst O(n log n)
def mergeSort(lst):
    ######
    # len(lst) 10
    # 0 1 2 3 4 5 6 7 8 9
    # front int(rear/2)
    # int(rear/2)+1 rear
    ######
    # 
    #
    if len(lst) <= 1:
        return lst
    size = len(lst) // 2
    front = mergeSort(lst[:size])
    rear = mergeSort(lst[size:])

    
    return merge(front, rear)
#d n c
def merge(front, rear):
    if not front: return rear
    if not rear: return front
    if front[0] < rear[0]:
        return [front[0]] + merge(front[1:], rear)
    return [rear[0]] + merge(front, rear[1:])
   
    


lst=map(int,input().split())

print("merge Sort")
print(lst)
lst=mergeSort(lst)
print(lst)
