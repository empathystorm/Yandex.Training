from func import import_files, l_binary_search


def check_desk(m, checkArgs):
    w, h, n = checkArgs
    return (m // w) * (m // h) >= n


fin, fout = import_files()
w, h, n = map(int, fin.readline().strip().split())

print(l_binary_search(0, max(w, h) * n, check_desk, (w, h, n)), file=fout)
