
def main():

    r,c,q = map(int, input().split())

    arr = [[0]*(c+1) for _ in range(r+1)]
    dp = [[0]*(c+1) for _ in range(r+1)]

    data = [list(map(int, input().split())) for _ in range(r)]

    #print(data)
    for i in range(1,r+1):
        for j in range(1, c+1):
            arr[i][j] = data[i-1][j-1]
            dp[i][j] = arr[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]

    for i in range(0, q) :
        a,b,c,d = map(int, input().split())
        mean = (d-b+1) * (c-a+1)
        result = dp[c][d] - dp[a-1][d] - dp[c][b-1]+dp[a-1][b-1]
        print(int(result/mean))


if __name__=="__main__":
    main()
