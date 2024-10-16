import sys

def main():
    MOD = 1000000009
    MAX_N = 100000

    # dp[i]는 i를 1, 2, 3의 합으로 나타내는 **대칭적인** 방법의 수
    dp = [0] * (MAX_N + 1)
    
    # 초기값 설정 (dp[0]은 사용하지 않음, 문제에 따라 다를 수 있음)
    if MAX_N >= 0:
        dp[0] = 0
    if MAX_N >= 1:
        dp[1] = 1
    if MAX_N >= 2:
        dp[2] = 2
    if MAX_N >= 3:
        dp[3] = 2
    if MAX_N >= 4:
        dp[4] = 3
    if MAX_N >= 5:
        dp[5] = 3
    if MAX_N >= 6:
        dp[6] = 6

    # dp[7]부터 dp[100000]까지 계산
    for i in range(7, MAX_N + 1):
        dp[i] = (dp[i-2] + dp[i-4] + dp[i-6]) % MOD

    # 입력을 한 번에 읽고 분할
    input = sys.stdin.read().split()
    T = int(input[0])
    test_cases = list(map(int, input[1:T+1]))

    # 결과를 저장할 리스트
    output = []
    for tc in test_cases:
        if 0 <= tc <= MAX_N:
            output.append(str(dp[tc]))
        else:
            output.append("0")  # n이 범위를 벗어날 경우 0으로 처리 (문제에 따라 다를 수 있음)
    
    # 결과 출력
    print("\n".join(output))

if __name__ == "__main__":
    main()
