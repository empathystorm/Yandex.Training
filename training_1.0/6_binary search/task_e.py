from func import import_files, l_binary_search


def check_marks(m5, checkArgs):
    m2, m3, m4 = checkArgs
    # из-за проблем с точностью вычислений избавляемся от вещественных чисел:
    # переносим знаменатель за знак неравенства и умножаем всё неравенство на 10
    return 10 * (m2*2 + m3*3 + m4*4 + m5*5) >= 35 * (m2 + m3 + m4 + m5)


fin, fout = import_files()
a, b, c = map(int, fin.readlines())

print(l_binary_search(0, a + b + c, check_marks, (a, b, c)), file=fout)
