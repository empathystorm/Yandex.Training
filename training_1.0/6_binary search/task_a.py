from func import import_files, l_binary_search


def check_equals_key(m, checkArgs):
    arr, key = checkArgs
    return key <= arr[m]


fin, fout = import_files()
n, k = map(int, fin.readline().strip().split())
nums = list(map(int, fin.readline().strip().split()))
keys = list(map(int, fin.readline().strip().split()))

for key in keys:
    i = l_binary_search(0, n-1, check_equals_key, (nums, key))
    if nums[i] == key:
        print("YES", file=fout)
    else:
        print("NO", file=fout)
