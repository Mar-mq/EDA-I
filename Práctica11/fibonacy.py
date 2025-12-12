from functools import lru_cache

@lru_cache(maxsize=None)  # Memoización para evitar recomputo y stack overflow en grandes n
def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n-1) + fibonacci(n-2)

# Calcular e imprimir para las posiciones pedidas
print("Fibonacci en posición 7:", fibonacci(7))
print("Fibonacci en posición 21:", fibonacci(21))
print("Fibonacci en posición 40:", fibonacci(40))
print("Fibonacci en posición 71:", fibonacci(71))
print("Fibonacci en posición 94:", fibonacci(94))
