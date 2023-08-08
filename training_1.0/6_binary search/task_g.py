from func import import_files, r_binary_search


def check_tile(size, checkArgs):
    n, m, t = checkArgs
    return n * m - (n - 2*size) * (m - 2*size) <= t


fin, fout = import_files()
n, m, t = map(int, fin.readlines())

print(r_binary_search(0, min(n, m) // 2, check_tile, (n, m, t)), file=fout)
