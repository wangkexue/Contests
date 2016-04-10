def read_file(input_file):
    with open(input_file, 'r') as fp:
        num_lines = int(fp.next())
        # print "num_lines: %d" % num_lines
        while True:
            try:
                chars = [];
                for j in range(0, 4):
                    chars.extend(fp.next())
                    chars.remove('\n')
                fp.next();
                yield(chars)
            except StopIteration as e:
                return


def solution(arg1):
    winner = isWin(arg1)
    if winner:
        return winner+' won'
    elif isIncomplete(arg1):
        return 'Game has not completed'
    else:
        return 'Draw'

def isWin(lst):
    for i in range(4):
        row = []
        col = []
        for j in range(4):
            row.append(lst[i*4 +j])
            col.append(lst[j*4 + i])
        winrow = isWin_helper(row)
        if winrow:
            return winrow
        wincol = isWin_helper(col)
        if wincol:
            return wincol
    diag_l = []
    diag_r = []
    for i in range(4):
        diag_l.append(lst[i*4 + i])
        diag_r.append(lst[i*4 + (3-i)])
    windial = isWin_helper(diag_l)
    if windial:
        return windial[0]
    windiar = isWin_helper(diag_r)
    if windiar:
        return windiar[0]
    return 0

def isWin_helper(lst):
    origin = lst[0]
    start = 1
    if origin == 'T':
        origin = lst[1]
        start = 2
    if origin == '.':
        return 0
    for i in range(start, 4):
        if lst[i] != origin and lst[i] != 'T':
            return 0
    return origin

def isIncomplete(lst):
    if '.' in lst:
        return True
    else:
        return False

f = open('out_small.txt', 'w')
for case_num, args in enumerate(read_file('A-small-practice.in'), start=1):
    f.write( 'Case #%d: %s\n' % (case_num, solution(args)) )
f.close()

f = open('out_large.txt', 'w')
for case_num, args in enumerate(read_file('A-large-practice.in'), start=1):
    f.write( 'Case #%d: %s\n' % (case_num, solution(args)) )
f.close()