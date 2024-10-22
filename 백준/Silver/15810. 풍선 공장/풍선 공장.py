import sys
input=sys.stdin.readline

n, m=map(int, input().split())
arr=list(map(int,input().split()))

low, high=1, min(arr) * m


result=high

while low<=high :
    mid=(low+high)//2
    balloon=0
    
    for time in arr:
        balloon+=mid//time

        if balloon >= m:
            high= mid
            
    if balloon >= m:
            result=mid
            high=mid-1
    else:
        low=mid+1
        
print(result)