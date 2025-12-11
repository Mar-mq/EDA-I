from collections import namedtuple
Planeta = namedtuple('Planeta', ['nombre', 'numero'])
planeta = Planeta('Mercurio', 1)
print(planeta)
print (planeta.nombre)
print(planeta[1])
