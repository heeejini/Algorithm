import sys
input=sys.stdin.readline
k , n = 0, 0 
data = []
sum = 0 
def is_possible(mid):
    global sum 
    sum =0 
    for item in data:
      #  print(item // mid)
        sum+=item // mid 
     #   print(sum)
    return sum 

def solve():
    lo, hi = 1, max(data)
    answer = -1 # 정답을 저장할 변수 

    while lo <= hi : 
        mid = (lo+hi)//2

        if is_possible(mid) <  n :
         #   answer = mid 
            hi = mid -1 
        else :
            answer = mid
            lo = mid +1 
    
    print(answer)

def main():
    global k, n, data
    k, n = map(int, input().split())
    #data=list(map(int, input().split()))
    for _ in range(k):
        data.append(int(input()))

   
   # print(data) [802, 743, 457, 539]
    solve()


if __name__=="__main__":
    main()