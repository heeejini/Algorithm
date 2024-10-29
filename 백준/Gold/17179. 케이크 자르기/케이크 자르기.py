import sys
input = sys.stdin.readline

def is_possible(mid, data, L, cnt):
    count = 0
    last_position = 0
    for pos in data:
        if pos - last_position >= mid:
            count += 1
            last_position = pos
    # 마지막 조각도 확인
    if L - last_position >= mid:
        count += 1
    return count >= (cnt + 1)

def solve(data, L, Q):
    lo, hi = 1, L
    answer = 0
    while lo <= hi:
        mid = (lo + hi) // 2
        if is_possible(mid, data, L, Q):
            answer = mid
            lo = mid + 1
        else:
            hi = mid - 1
    return answer

def main():
    n, m, L = map(int, input().split())
    data = [int(input()) for _ in range(m)]
    cutting = [int(input()) for _ in range(n)]
    data.sort()
    for q in cutting:
        print(solve(data, L, q))

if __name__ == "__main__":
    main()
