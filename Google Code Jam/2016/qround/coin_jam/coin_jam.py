from collections import deque
from math import sqrt

def nonPrime(num):
    i = 2
    while i < int(sqrt(num)) + 1:
        if num % i == 0:
            return i
        i += 1;
    return -1

def toNum(s, base):
    return reduce(lambda x,y: base * x + y, map(int, s))

def solve(n, j):
    s = ['1'] + ['0']*(n-2) + ['1'];
    q = deque([s])
    found = 0;
    while found < j:
        s = q.popleft()
        d = [None] * 9;
        for k in range(1, len(s)):
            if s[k] == '1':
                break
            tmp = s[:]
            tmp[k] = '1'
            q.append(tmp)
        for k in range(10, 1, -1):
            d[k - 2] = nonPrime(toNum(s, k))
            if d[k - 2] == -1:
                break
            if k == 2:
                k = k - 1
        if k == 1:
            found += 1
            print ''.join(s) + ' ' + ' '.join(map(str, d))

if __name__ == '__main__':
    t = int(raw_input().strip())
    for i in range(1, t+1):
        n, j = map(int, raw_input().strip().split())
        print 'Case #%d:' % i
        solve(n, j)