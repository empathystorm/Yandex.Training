from func import import_files, l_binary_search


def check_brigades(diff, checkArgs):
    growths, r, c = checkArgs
    brigades = 0
    i = 0
    while i < len(growths) - c + 1:
        if growths[i+c-1] - growths[i] <= diff:
            brigades += 1
            i += c
        else:
            i += 1
    return brigades >= r


fin, fout = import_files()
n, r, c = map(int, fin.readline().strip().split())
growths = sorted(list(map(int, fin.readlines())))

print(l_binary_search(0, growths[-1] - growths[0], check_brigades, (growths, r, c)), file=fout)
