from math import *
#1  En initialisant u[0] à une valeur négative la racine est négative -2
#2  
def f(x):
    return (x-2)**2
def df(x):
    return 2*(x-2)
v = [3]*11
for i in range(10):
    v[i+1] = v[i] - f(v[i])/df(v[i])
    print(v[i+1])
print("########################")
#3
def f2(x):
    return x**2 - 3
def df2(x):
    return 2*x

u = [5]*11
for i in range(10):
    u[i+1] = u[i] - f2(u[i])/df2(u[i])
    print(u[i+1])

