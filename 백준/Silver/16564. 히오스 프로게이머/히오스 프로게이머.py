# 히오스 프로게이머 
n, k = 0, 0
level = []

def is_possible (mid) :
    cnt = 0
    
    for lev in level :
        if lev <= mid :
            cnt += (mid-lev) 

    return cnt 

def solve():
    lo, hi = 1, 1e10
    answer = -1 
    while lo <= hi :
        mid = (lo+hi)//2

        if is_possible(mid)<= k:
            answer = mid
            lo = mid + 1 
        else : 
            hi = mid - 1

    print(int(answer))
    return 

def main():
    global n, k, level

    n, k = map(int, input().split())
    for _ in range(n):
        level.append(int(input()))
    
    solve()

if __name__=="__main__":
    main()