import sys
input = sys.stdin.readline

s, c = 0, 0
v = []

def is_possible(mid):
    cnt = 0
    for values in v:
        cnt += values // mid
    return cnt

def solve():
    lo, hi = 1, max(v)
    answer = 0

    while lo <= hi:
        mid = (lo + hi) // 2
        cnt = is_possible(mid)
        if cnt >= c:  
            answer = mid
            lo = mid + 1
        else:
            hi = mid - 1

    total_length = sum(v)
    total_used = answer * c
    extra = total_length - total_used
    print(extra)

def main():
    global s, c, v
    s, c = map(int, input().split())
    v = [int(input()) for _ in range(s)]  
    solve()

if __name__ == "__main__":
    main()
