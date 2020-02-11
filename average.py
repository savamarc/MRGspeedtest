#!/usr/bin/python3
import os
gen = ['lcg16', 'mrg16_1', 'mrg16_2', 'mrg16_3', 'mrg16c', 'mrg8', 'mrg59k3a', 'mrg59p2a',
        'mrg59p2b', 'mrg59p2c', 'mrg32k3a_double', 'mrg32k3a_vigna', 'mrg32k3a_plus',
        'mrg31k3p_original', 'mrg31k3p_fast', 'mrg37k3a', 'mrg37k3b', 'mrg39k3a']

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
        num_tot = 0
        average = 0
        num_average = 0
        if content[0] == 'Sum:':
            for i in range(len(content)):
                if i%11 == 3:
                    total += float(content[i])
                    num_tot += 1
                if i%11 == 1:
                    average += float(content[i])
                    num_average += 1
        else:
            for i in range(len(content)):
                if i%9 == 1:
                    total += float(content[i])
                    num_tot += 1
        if num_tot > 0:
            results.write(res)
            if len(res) < 20:
                for i in range(20-len(res)):
                    results.write(' ')
            results.write(': %.5f s\n' %(total/num_tot))
        if num_average > 0:
            results.write(res + '_sum')
            if len(res) < 16:
                for i in range(16-len(res)):
                    results.write(' ')
            results.write(': %.0f\n' %(average/num_average))
        # print(total)
