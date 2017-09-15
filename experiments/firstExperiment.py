import random
import subprocess
import math
import os

# string subtract
def str_subtract(s1, s2):
    for ch in s2:
        if ch in s1:
            s1 = s1.replace(ch, '', 1)
    return s1


# http://konect.uni-koblenz.de/networks/ego-facebook

# (1) We first set up a text file in the
# right folder, to save the results

numberNodes = 2888
numberEdges = 2981

cwd = os.getcwd()
st = cwd + "/(1+1)EA.txt"

file = open(st, 'w')
file.write("Algorithm "
           + "nodes "
           + "edges "
           + "steps "
           + "fitness "
           + "seed\n")
file.close()

for timeBudget in range (100, 15000, 100) :

    # (2) We first generate a random graph that has a
    # given number of nodes and with exp = 2.5

    x = cwd + "/ego-facebook.txt"

    # (3) We then run the algorithm via a C++
    # executable and save the results 100 times

    for i in range (1, 101) :

        # make command
        seed = i
        cmd = cwd + "/graphExplorerExe EA " \
                  + x + " " \
                  + str(timeBudget) + " " \
                  + str(seed)

        # make subprocess
        process = subprocess.Popen(cmd, shell=True,
                               stdout=subprocess.PIPE,
                               stderr=subprocess.PIPE)

        # wait for the process to terminate
        out = str(process.stdout.read()).split(" ")

        # print to file
        file = open(st, 'a')
        file.write("EA " + str(numberNodes) + " "
                         + str(numberEdges)
                         + " " +  str(timeBudget)
                         + " " + str_subtract(out[1], "'")
                         + " " + str(seed))
        file.write("\n")
        file.close()

    print("Total time budget:" + str(timeBudget))

file.close()






