memo = [-1] * 50

def fibo(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    elif memo[n] != -1:
        return memo[n]

    memo[n] = fibo(n - 1) + fibo(n - 2)
    return memo[n]


a = int(input())
print(f"{fibo(a - 1)} {fibo(a)}")