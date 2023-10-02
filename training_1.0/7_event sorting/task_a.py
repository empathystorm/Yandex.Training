def count_unobserved_tables(n, m, tin, tout):
    tables = []
    for i in range(m):
        tables.append((tin[i], -1))
        tables.append((tout[i], 1))
    tables.sort()
    observed = 0
    unobserved = n
    left = None
    for table in tables:
        if table[1] == -1:
            if observed == 0:
                left = table[0]
            observed += 1
        else:
            observed -= 1
            if observed == 0:
                unobserved -= (table[0] - left + 1)
    return unobserved


fin = open("input.txt", 'r')
fout = open("output.txt", 'w')
n, m = map(int, fin.readline().strip().split())
tin, tout = [0] * m, [0] * m

for i in range(m):
    tin[i], tout[i] = map(int, fin.readline().strip().split())

print(count_unobserved_tables(n, m, tin, tout), file=fout)
