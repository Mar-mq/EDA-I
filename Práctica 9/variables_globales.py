vg = 'Global'
def funcion_v1():
    print (vg)
funcion_v1()
print(vg)
def funcion_v2():
    global vg
    vg = 'Local'
    print (vg)
funcion_v2()
print(vg)
def funcion_v4():
    vg = 'Local'
    print (vg)
funcion_v4()
print (vg)
def funcion_v5():
    print (vg)
    print (vg)
funcion_v5()
