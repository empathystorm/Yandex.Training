def count_ranges_within_points(n, m, rangeSt, rangeEnd, points):
    ranges = []
    for i in range(n):
        ranges.append((rangeSt[i], -1))
        ranges.append((rangeEnd[i], 1))
    for i in range(m):
        ranges.append((points[i], 0, i))
    ranges.sort()
    count = 0
    ans = [0] * m
    for r in ranges:
        if r[1] == -1:
            count += 1
        elif r[1] == 1:
            count -= 1
        else:
            ans[r[2]] = count
    return ans


fin = open("input.txt", 'r')
fout = open("output.txt", 'w')
n, m = map(int, fin.readline().strip().split())
rangeSt, rangeEnd = [0] * n, [0] * n
for i in range(n):
    a, b = map(int, fin.readline().strip().split())
    rangeSt[i], rangeEnd[i] = min(a, b), max(a, b)
points = list(map(int, fin.readline().strip().split()))

print(*count_ranges_within_points(n, m, rangeSt, rangeEnd, points), file=fout)
