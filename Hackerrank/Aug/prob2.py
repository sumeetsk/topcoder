import itertools
a = raw_input()
b = dict([(x,a.count(x)/2) for x in a])
s = ''
for i in b:
    s += b[i]*i

perm = itertools.permutations(sorted(s));

success = False
n = len(a)
t1 = list(perm.next())
while (True):
    t1 = perm.next()
    t1 = t1[::-1]
    t2 = list(t1)
    count = 0
    for ch in a:
        if (t1[count]==ch):
            count+=1
            if (count==n/2):
                success = True
                break
            continue
        try:
            t2.remove(ch)
        except ValueError:
            success = False
            break
    if success==True:
        print ''.join(t1[::-1])
        break
