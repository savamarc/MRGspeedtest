#!/usr/bin/python3
import os
gen = ['lcg16', 'mrg16_1', 'mrg16_2', 'mrg16_3', 'mrg8', 'mrg59k3a', 'mrg59p2a',
        'mrg59p2b', 'mrg59p2c', 'mrg32k3a_double', 'mrg32k3a_vigna',
        'mrg31k3p_original', 'mrg31k3p_fast']

with open("results.txt", "w+") as results:
    files = os.listdir()
    for res in gen:
        content = None
        try:
            content = open(res+'.res').read()
        except:
            print("No file " + res + '.res')
            continue
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
        results.write(res)
        if len(genname) < 20:
            for i in range(20-len(genname)):
                results.write(' ')
        results.write(': %.5f s\n' %(total/num))
        # print(total)
