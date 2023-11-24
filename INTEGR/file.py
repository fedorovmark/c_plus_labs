import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import csv

x = []
y = []

with open('kv2.txt', 'r') as datafile:
    plotting = csv.reader(datafile, delimiter=' ')
    
    for ROWS in plotting:
        x.append(float(ROWS[0]))
        y.append(float(ROWS[1]))

# print(type(y[900]))

fig, ax = plt.subplots(figsize=(10, 6), dpi=100)
x1 = np.log(x)
y1 = np.log(y)
ax.scatter(x1, y1)

coefs = np.polyfit(x1[:30], y1[:30], 1)
print(coefs[0], coefs[1])

ax.grid(which="major", linewidth=0.5)
ax.grid(which="minor", linestyle='--', linewidth=0.25)
plt.minorticks_on()

ax.set_title("N = 2", loc='center', fontsize=15)
ax.set_xlabel("Число подотрезков", loc='center', fontsize=10)
ax.set_ylabel("Ошибка", loc='center', fontsize=10)

plt.show()

fig.savefig("N2.png", dpi=500)




x = []
y = []

with open('kv5.txt', 'r') as datafile:
    plotting = csv.reader(datafile, delimiter=' ')
    
    for ROWS in plotting:
        x.append(float(ROWS[0]))
        y.append(float(ROWS[1]))

fig, ax = plt.subplots(figsize=(10, 6), dpi=100)

# ax.loglog(x, y)
x1 = np.log(x)
y1 = np.log(y)
ax.scatter(x1, y1)

coefs = np.polyfit(x1[:3], y1[:3], 1)
print(coefs[0], coefs[1])

ax.grid(which="major", linewidth=0.5)
ax.grid(which="minor", linestyle='--', linewidth=0.25)
plt.minorticks_on()

ax.set_title("N = 5", loc='center', fontsize=15)
ax.set_xlabel("Число подотрезков", loc='center', fontsize=10)
ax.set_ylabel("Ошибка", loc='center', fontsize=10)

plt.show()

fig.savefig("N5.png", dpi=500)
