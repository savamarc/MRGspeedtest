#!/usr/bin/python3
import os

with open("results.txt", "w+") as results:
    files = os.listdir()
    for res in files:
        if '.res' not in res:
            continue
        content = open(res).read()
        genname = res[:-4]
        # print(genname)
        content = content.split()
        # print(content)
        total = 0
        num = 0
        if content[0] == 'Sum:':
            for i in range(len(content)):
                if i%11 == 3:
                    total += float(content[i])
                    num += 1
        else:
            for i in range(len(content)):
                if i%9 == 1:
                    total += float(content[i])
                    num += 1
        results.write(genname)
        if len(genname) < 20:
            for i in range(20-len(genname)):
                results.write(' ')
        results.write(': %.5f s\n' %(total/num))
        # print(total)
