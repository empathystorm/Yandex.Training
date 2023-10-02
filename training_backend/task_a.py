#https://contest.yandex.ru/contest/50668/problems/A/
def count_diff_symbols(str):
    symbols = set()
    for c in str:
        if c not in symbols:
            symbols.add(c)
    return len(symbols)

def sum_digits(num):
    s = 0
    while num > 0:
        s += num % 10
        num //= 10
    return s

def edit_hex(code16):
    return code16[-3:].zfill(3).upper()

fin = open("input.txt", 'r')
fout = open("output.txt", 'w')

n = int(fin.readline())

for i in range(n):
    f, i, o, d, m, y  = map(str, fin.readline().strip().split(','))
    #подсчёт количества различных символов в ФИО
    numDiffSymb = count_diff_symbols(f+i+o)
    #Сумма цифр в дне и месяце рождения
    sumDigitsDM = sum_digits(int(d)) + sum_digits(int(m))
    #Номер в алфавите первой буквы фамилии
    numFirstLet = ord(f[0]) - (ord('A') if f[0].isupper() else ord('a')) + 1
    #суммирование значений и конвертация в 16-чную СС
    code10 = numDiffSymb + sumDigitsDM * 64 + numFirstLet * 256
    code16 = edit_hex(hex(code10))
    print(code16, end=' ', file=fout)
