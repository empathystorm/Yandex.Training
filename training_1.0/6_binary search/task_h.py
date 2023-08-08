from func import import_files, r_binary_search


def check_wires(size, checkArgs):
    wires, k = checkArgs
    count = 0
    for w in wires:
        count += w // size
    return count >= k


fin, fout = import_files()
n, k = map(int, fin.readline().strip().split())
wires = list(map(int, fin.readlines()))

print(r_binary_search(0, sum(wires) // k, check_wires, (wires, k)), file=fout)
