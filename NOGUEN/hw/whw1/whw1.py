import sys

def binomial(n, r) :
    cache = [[0 for _ in range(r + 1)] for _ in range(n + 1)]

    for i in range(n + 1) :
        cache[i][0] = 1
    for i in range(r + 1) :
        cache[i][i] = 1
    for i in range(1, n + 1) :
        for j in range(1, r + 1) :
            cache[i][j] = cache[i - 1][j] + cache[i - 1][j - 1]
    return cache[n][r]

sys.stdout = open('whw1.txt', 'w')

for i in range(0, 101) :
    if i < 10 :
        print("catalan[" + str(i) + "]" + "    :   " + str(binomial(i * 2, i) / (i + 1)))
    elif 10 <= i < 100 :
        print("catalan[" + str(i) + "]" + "   :   " + str(binomial(i * 2, i) / (i + 1)))
    else :
        print("catalan[" + str(i) + "]" + "  :   " + str(binomial(i * 2, i) / (i + 1)))

sys.stdout.close()

