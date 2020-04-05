from math import *
import numpy as np
#1  En initialisant u[0] à une valeur négative la racine est négative -2 (2 et -2 sont deux racines de la fonction)
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

def h(x,y):
        return x**2 + 2*x*y -1 , (x**2)*(y**2) - y - 3
print("Pour le couple (2,-3/4) on a h(2,-3/4) = ",h(2,-3/4))


def jacobienne(x,y):
        return [[2*x + 2*y ,2*x] , [2*x*y**2 ,2*(x**2)*y - 1]]

def factolu(A):
        n= length(A[0])
        L = np.identity(n)
        U = np.zeros(shape=(n,n))
        for i in range(n):
            for j in range(i+1, n):
                L[j,i] = A[j,i]/A[i,i]
            for j in range(i, n):
                U[i,j] = A[i,j]
            for j in range(i+1, n):       
                for k in range(i + 1, n):
                    A[j,k] -= L[j, i] * U[i, k]
            
        U[-1,-1] = A[-1,-1]
        return L, U
V = (3.,-1.)        
for n in range(6):
        Jn = jacobienne(V)
        mfn = -1 * h(V)
        l, u = factolu(Jn)
        y = np.linalg.solve(l, mfn)
        z = np.linalg.solve(u, y)
        S = [[V[0],V[1]],]
        S = S + [z]
    print(V)