from collections import deque

def bfs(selected, i, j, n, m):
    queue = deque()
    vis[i][j] = 1
    queue.append((i, j))

    cnt = 0
    while queue:
        cur = queue.popleft()
        cnt += 1

        for k in range(4):
            nx = cur[0] + dx[k]
            ny = cur[1] + dy[k]

            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if arr[nx][ny] == selected and vis[nx][ny] == 0:
                vis[nx][ny] = 1
                queue.append((nx, ny))

    return cnt

def main():
    global w_power, b_power

    n, m = map(int, input().split())
    arr.clear()
    vis.clear()

    for _ in range(m):
        arr.append(list(input().strip()))

    for i in range(m):
        vis.append([0] * n)

    for i in range(m):
        for j in range(n):
            if arr[i][j] == 'W' and vis[i][j] == 0:
                cnt = bfs('W', i, j, m, n)
                w_power += (cnt * cnt)
            elif arr[i][j] == 'B' and vis[i][j] == 0:
                cnt = bfs('B', i, j, m,n)
                b_power += (cnt * cnt)

    print(w_power, b_power)

if __name__ == "__main__":
    w_power = 0
    b_power = 0
    arr = []
    vis = []
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    main()
