import sys

def solve(b, n, m):
  if n == 1 or m == 1:
    return 'YES'
  row_max = [max(x) for x in b]
  col_max = [max(x) for x in zip(*b)]
  grass = [[100 for x in range(m)] for y in range(n)]

  for i in range(n):
    height = row_max[i]
    for j in range(m):
      if grass[i][j] > height:
        grass[i][j] = height

  for j in range(m):
    height = col_max[j]
    for i in range(n):
      if grass[i][j] > height:
        grass[i][j] = height

  #print grass

  if grass == b:
      return 'YES'
  return 'NO'


numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
  lawn = []
  n, m = [int(x) for x in sys.stdin.readline().split()]
  for i in range(n):
    lawn.append([int(x) for x in sys.stdin.readline().split()])
  print 'Case #' + repr(casenum) + ': ' + solve(lawn, n, m)