def obtieneMayor(param1,param2):
    if param1 < param2:
        return param2
    else:
        return param1
print ("El mayor es {}".format(obtieneMayor(4, 20)))
print ("El mayor es {}".format(obtieneMayor(11, 6)))
x = y = z = 3
if x == y == z:
    print("número iguales")
else:
    print("El mayor es {}".format(obtieneMayor(x,y,z)))
def obtieneMayorv2(param1,param2):
    valor = 0
    if param1 < param2:
        valor = param2
    else:
        valor = param1
    return valor
print ("El mayor es {}".format(obtieneMayorv2(11, 6)))
def obtieneMayorv3(param1,param2):
    return param1 if param1 > param2 else param2
print ("El mayor es {}".format(obtieneMayorv3(11, 6)))
import random
num = random.random()
print(num)
if num < 0.25:
    print("num es menor que 0.25")
elif num < 0.5:
    print("num es menor que 0.5")
elif num < 0.75:
    print("num es menor que 0.75")
else:
    print("num es mayor que 0.75")
def evaluacion(nota):
    valoracion = "Suspenso"
    if nota < 5:
        valoracion = "Suspenso"
    elif nota < 7:
        valoracion = "Aprobado"
    elif nota < 9:
        valoracion = "Notable"
    else:
        valoracion = "Excelente"
    return valoracion
print (evaluacion(8))
