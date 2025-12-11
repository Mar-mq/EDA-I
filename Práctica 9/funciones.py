def imprime_nombre(nombre):
    print ("hola " + nombre)
imprime_nombre("JJ")
def cuadrado(x):
    return x**2
x = 5
print ("El cuadrado de {} es {}".format(x, cuadrado(x)))
def varios(x):
    return x**2, x**3, x**4
val1, val2, val3 = varios(2)
print (val1, val2, val3)
def cuadrado_default(x=3):
    return x**2
print (cuadrado_default())
val1, _, val3 = varios(2)
print (val1, val3)
