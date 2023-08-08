from func import import_files, r_binary_search


def count_modules(d, a, b, w, h):
    return (w // (a + 2*d)) * (h // (b + 2*d))


def check_protection(d, checkArgs):
    n, a, b, w, h = checkArgs
    return max(count_modules(d, a, b, w, h), count_modules(d, a, b, h, w)) >= n


fin, fout = import_files()
n, a, b, w, h = map(int, fin.readline().strip().split())

print(r_binary_search(0, max(w, h), check_protection, (n, a, b, w, h)), file=fout)
