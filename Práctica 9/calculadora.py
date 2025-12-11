def suma(a, b):
    return a + b
def resta(a, b):
    return a - b
def multi(a, b):
    return a * b
def div(a, b):
    if b != 0:
        return a / b
    else:
        return "Error division por cero"
print ("---Calculadora---")
print ("1- Sumar")
print ("2- Restar")
print ("3- Multiplicar")
print ("4- Dividir")
print ("5- Salir")
op = int(input('Opcion: '))
if op == 5:
    print("Adios")
else:
    a = float(input("Num 1: "))
    b = float(input("Num 2: "))
    if op == 1:
        print(suma(a, b))
    elif op == 2:
        print(resta(a, b))
    elif op == 3:
        print(multi(a, b))
    elif op == 4:
        print(div(a, b))
