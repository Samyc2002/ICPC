t = int(input())
for x in range(t):
    n = int(input())
    lst = [int(x) for x in input().split(" ")]
    lst.sort()
    ans = 0
    for k in range(len(lst)-1):
        if lst[k] == lst[k+1] :
            print("NO")
            ans = 1
            break
    if ans == 0:
        print("YES")