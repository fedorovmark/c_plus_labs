import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

y = np.array([0.851255, 0.061917, 0.00596523, 0.000656327, 7.70201*10**(-5), 9.32978*10**(-6)])
x = np.array([0.0625, 0.125, 0.25, 0.5, 1, 2])
print(len(x), len(y), y)
fig, ax = plt.subplots(figsize=(10, 6), dpi=100)
yp = list(reversed(y))
print(yp)
ax.scatter(x, yp, marker='o')
# ax.plot(xp, yp_p, linestyle='--', color='red')

ax.legend(loc='upper left', fontsize=10)

ax.grid(which="major", linewidth=0.5)
ax.grid(which="minor", linestyle='--', linewidth=0.25)
plt.minorticks_on()

# ax.axis([0, 45, 0, 0.5])

ax.set_title("Gr err interpol_N for N = 3 ", loc='center', fontsize=15)
ax.set_xlabel(r"$len,\, mm$", loc='center', fontsize=10)
ax.set_ylabel(r"$err,\, u$", loc='center', fontsize=10)

plt.show()

fig.savefig("data_Nu_N3.png", dpi=500)




y = np.array([0.177106, 0.00650772, 0.0003143, 1.73017e-05, 1.01535e-06, 6.14992e-08])
x = np.array([0.0625, 0.125, 0.25, 0.5, 1, 2])
print(len(x), len(y), y)
fig, ax = plt.subplots(figsize=(10, 6), dpi=100)
yp = list(reversed(y))
print(yp)
ax.scatter(x, yp, marker='o')
# ax.plot(xp, yp_p, linestyle='--', color='red')

ax.legend(loc='upper left', fontsize=10)

ax.grid(which="major", linewidth=0.5)
ax.grid(which="minor", linestyle='--', linewidth=0.25)
plt.minorticks_on()

# ax.axis([0, 45, 0, 0.5])

ax.set_title("Gr err interpol_N for N = 4", loc='center', fontsize=15)
ax.set_xlabel(r"$len,\, mm$", loc='center', fontsize=10)
ax.set_ylabel(r"$err,\, u$", loc='center', fontsize=10)

plt.show()

fig.savefig("data_Nu_N4.png", dpi=500)



y = np.array([0.0287774, 0.000532004, 1.2867e-05, 3.54293e-07, 1.03968e-08, 3.14873e-10])
x = np.array([0.0625, 0.125, 0.25, 0.5, 1, 2])
print(len(x), len(y), y)
fig, ax = plt.subplots(figsize=(10, 6), dpi=100)
yp = list(reversed(y))
print(yp)
ax.scatter(x, yp, marker='o')
# ax.plot(xp, yp_p, linestyle='--', color='red')

ax.legend(loc='upper left', fontsize=10)

ax.grid(which="major", linewidth=0.5)
ax.grid(which="minor", linestyle='--', linewidth=0.25)
plt.minorticks_on()

# ax.axis([0, 45, 0, 0.5])

ax.set_title("Gr err interpol_N for N = 5", loc='center', fontsize=15)
ax.set_xlabel(r"$len,\, mm$", loc='center', fontsize=10)
ax.set_ylabel(r"$err,\, u$", loc='center', fontsize=10)

plt.show()

fig.savefig("data_Nu_N5.png", dpi=500)
















y = np.array([0.0934825, 0.00768728, 0.000788097, 8.94576e-05, 1.06631e-05, 1.30179e-06])
x = np.array([0.0625, 0.125, 0.25, 0.5, 1, 2])
print(len(x), len(y), y)
fig, ax = plt.subplots(figsize=(10, 6), dpi=100)
yp = list(reversed(y))
print(yp)
ax.scatter(x, yp, marker='o')
# ax.plot(xp, yp_p, linestyle='--', color='red')

ax.legend(loc='upper left', fontsize=10)

ax.grid(which="major", linewidth=0.5)
ax.grid(which="minor", linestyle='--', linewidth=0.25)
plt.minorticks_on()

# ax.axis([0, 45, 0, 0.5])

ax.set_title("Gr err interpol_Ch for N = 3", loc='center', fontsize=15)
ax.set_xlabel(r"$len,\, mm$", loc='center', fontsize=10)
ax.set_ylabel(r"$err,\, u$", loc='center', fontsize=10)

plt.show()

fig.savefig("data_Ch_N3.png", dpi=500)



y = np.array([0.012157, 0.000491384, 2.49225e-05, 1.40633e-06, 8.35628e-08, 5.09303e-09])
x = np.array([0.0625, 0.125, 0.25, 0.5, 1, 2])
print(len(x), len(y), y)
fig, ax = plt.subplots(figsize=(10, 6), dpi=100)
yp = list(reversed(y))
print(yp)
ax.scatter(x, yp, marker='o')
# ax.plot(xp, yp_p, linestyle='--', color='red')

ax.legend(loc='upper left', fontsize=10)

ax.grid(which="major", linewidth=0.5)
ax.grid(which="minor", linestyle='--', linewidth=0.25)
plt.minorticks_on()

# ax.axis([0, 45, 0, 0.5])

ax.set_title("Gr err interpol_Ch for N = 4", loc='center', fontsize=15)
ax.set_xlabel(r"$len,\, mm$", loc='center', fontsize=10)
ax.set_ylabel(r"$err,\, u$", loc='center', fontsize=10)

plt.show()

fig.savefig("data_Ch_N4.png", dpi=500)



y = np.array([0.00124767, 2.49372e-05, 6.27998e-07, 1.76505e-08, 5.23342e-10, 1.59321e-11])
x = np.array([0.0625, 0.125, 0.25, 0.5, 1, 2])
print(len(x), len(y), y)
fig, ax = plt.subplots(figsize=(10, 6), dpi=100)
yp = list(reversed(y))
print(yp)
ax.scatter(x, yp, marker='o')
# ax.plot(xp, yp_p, linestyle='--', color='red')

ax.legend(loc='upper left', fontsize=10)

ax.grid(which="major", linewidth=0.5)
ax.grid(which="minor", linestyle='--', linewidth=0.25)
plt.minorticks_on()

# ax.axis([0, 45, 0, 0.5])

ax.set_title("Gr err interpol_Ch for N = 5", loc='center', fontsize=15)
ax.set_xlabel(r"$len,\, mm$", loc='center', fontsize=10)
ax.set_ylabel(r"$err,\, u$", loc='center', fontsize=10)

plt.show()

fig.savefig("data_Ch_N5.png", dpi=500)



