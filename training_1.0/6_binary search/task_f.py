from func import import_files, l_binary_search


def check_xerox(m, checkArgs):
    n, x, y, fastest = checkArgs
    t = m - fastest
    return t // x + t // y + 1 >= n


fin, fout = import_files()
n, x, y = map(int, fin.readline().strip().split())

print(l_binary_search(min(x, y), max(x, y) * n, check_xerox, (n, x, y, min(x, y))), file=fout)
