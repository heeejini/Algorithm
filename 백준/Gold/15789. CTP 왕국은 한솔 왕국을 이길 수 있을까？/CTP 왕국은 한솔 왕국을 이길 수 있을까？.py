def find(x):
    if root[x] == x:
        return x
    else:
        root[x] = find(root[x])
        return root[x]

def unionNode(x, y):
    rootX = find(x)
    rootY = find(y)
    if rootX != rootY:
        root[rootX] = rootY

def main():
    # import sys
    # input = sys.stdin.read
    # # data = input().split()
    
    # # idx = 0
    
    # # n = int(data[idx])
    # # idx += 1
    # # m = int(data[idx])
    # # idx += 1
    
    n, m = map(int, input().split())
    global root
    root = [i for i in range(n+1)]
    
    for _ in range(m):
        # a = int(data[idx])
        # idx += 1
        # b = int(data[idx])
        # idx += 1
        a, b = map(int, input().split())
        unionNode(a, b)
    ctp, hansol, k = map(int, input().split())
    # ctp = int(data[idx])
    # idx += 1
    # hansol = int(data[idx])
    # idx += 1
    # k = int(data[idx])
    # idx += 1
    
    ctp_root = find(ctp)
    hansol_root = find(hansol)
    
    arr = [0] * (n+1)
    
    for i in range(1, n+1):
        idx = find(i)
        arr[idx] += 1
    
    ctp_power = arr[ctp_root]
    arr[ctp_root] = 0
    arr[hansol_root] = 0
    
    arr.sort(reverse=True)
    
    for i in range(k):
        ctp_power += arr[i]
    
    print(ctp_power)

if __name__ == "__main__":
    main()
