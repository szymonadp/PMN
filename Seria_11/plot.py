import matplotlib.pyplot as plt

def read_data(filename):
    t_values = []
    x_values = []
    with open(filename, 'r') as file:
        for line in file:
            t, x, _ = line.split()  
            t_values.append(float(t))
            x_values.append(float(x))
    return t_values, x_values

t1, x1 = read_data("oscylator_duffing_1.010000.dat")
t2, x2 = read_data("oscylator_duffing_1.00000.dat")
t3, x3 = read_data("oscylator_duffing_0.990000.dat")

plt.plot(t1, x1, label='1.01')
plt.plot(t2, x2, label='1.00')
plt.plot(t3, x3, label='0.99')

plt.title('Data Plots')
plt.xlabel('t')
plt.ylabel('x')

plt.legend()

plt.show()
