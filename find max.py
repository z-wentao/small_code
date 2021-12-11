print("请输入有多少天：")
n = int(input())
print("请输入每天的股票价格：（中间以空格隔开）")
print()
d = list(map(float, input().split()))

M = -1
for j in range(1, n):
    for i in range(0, j):
        if d[j] - d[i] > M:
            M = d[j] - d[i]

print("最大差价是：")
print(M)