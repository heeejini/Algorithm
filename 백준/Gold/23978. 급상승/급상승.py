n, k =0,0
data=[]
def total_money(mid):
    result = 0
    interval = 0

    for i in range(len(data)):
        if i<len(data)-1 :
            interval = min(data[i+1]-data[i], mid)
        else : 
            interval = mid
        
        first = mid
        last = mid - (interval -1)

        sum = (first+last)*interval /2
        result+=sum

        if result >= k : break

    return result 

def solve():
    lo , hi = 0, 1e18
    answer  = -1

    while lo <= hi :
        mid = (lo+hi)//2

        if total_money(mid) >= k:
            answer = mid
            hi = mid -1
        else :
            lo = mid +1 
    print(int(answer))

def main():
    global n,k, data
    n, k = map(int, input().split())
    data = list(map(int, input().split()))
   # print(data)
    solve()

if __name__=="__main__":
    main()