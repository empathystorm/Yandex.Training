from func import import_files, l_binary_search

def check_grater(index, checkArgs):
    seq, x = checkArgs
    return seq[index] >= x


def count_less(seq, x):
    ans = l_binary_search(0, len(seq) - 1, check_grater, (seq, x))
    if seq[ans] < x:
        return len(seq)
    return ans

def count_grater(seq, x):
    return len(seq) - count_less(seq, x+1)

def median_merge(seq1, seq2):
    l = min(seq1[0], seq2[0])
    r = max(seq1[-1], seq2[-1])
    while l < r:
        m = (l + r) // 2
        less = count_less(seq1, m) + count_less(seq2, m)
        grater = count_grater(seq1, m) + count_grater(seq2, m)
        if less <= len(seq1) - 1 and grater <= len(seq1):
            return m
        if grater > len(seq1):
            l = m + 1
        if less > len(seq1) - 1:
            r = m - 1
    return l


fin, fout = import_files()
n, l = map(int, fin.readline().strip().split())
seq = []
for i in range(n):
    seq.append(list(map(int, fin.readline().strip().split())))

for i in range(n):
    for j in range(i+1, n):
        print(median_merge(seq[i], seq[j]), file=fout)
