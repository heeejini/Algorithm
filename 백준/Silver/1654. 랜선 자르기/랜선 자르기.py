import sys
input = sys.stdin.readline

k, n = 0, 0
data = []
sum = 0

def is_possible(mid):
    global sum
    sum = 0
    for item in data:
        sum += item // mid
    return sum

def solve():
    lo, hi = 1, max(data)  # lo를 1로 설정하고, hi를 막대기 중 가장 긴 길이로 설정
    answer = -1  # 정답을 저장할 변수 

    while lo <= hi:
        mid = (lo + hi) // 2

        if is_possible(mid) < n:  # 필요한 막대의 개수보다 작다면
            hi = mid - 1
        else:
            answer = mid  # 가능한 길이 중 하나이므로, 정답으로 설정
            lo = mid + 1

    print(answer)

def main():
    global k, n, data
    k, n = map(int, input().split())
    for _ in range(k):
        data.append(int(input()))

    solve()

if __name__ == "__main__":
    main()
