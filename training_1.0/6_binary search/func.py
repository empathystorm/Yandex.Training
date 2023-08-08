def import_files():
    fin = open("input.txt", 'r')
    fout = open("output.txt", 'w')
    return fin, fout


def l_binary_search(l, r, check, checkArgs):
    while l < r:
        m = (l + r) // 2
        if check(m, checkArgs):
            r = m
        else:
            l = m + 1
    return l


def r_binary_search(l, r, check, checkArgs):
    while l < r:
        m = (l + r + 1) // 2
        if check(m, checkArgs):
            l = m
        else:
            r = m - 1
    return l
