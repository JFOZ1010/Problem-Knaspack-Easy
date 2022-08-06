"""
Prueba de algoritmo de mochila voraz.
"""
import numpy as np

def mochilaVoraz(peso, beneficio, capacidad):
    
    solucion = np.zeros(peso.shape[0]) #inicializacion fila de ceros y columna de ceros. 

    #dividir beneficio entre peso
    beneficio_peso = beneficio/peso

    #ordenar por beneficio/peso de mayor a menor devolviendo el indice
    beneficio_peso_ordenado = np.argsort(beneficio_peso)[::-1]

    #establecer si se puede o no agregar el objeto
    for i in range(peso.shape[0]):
        #si el peso del objeto es menor o igual a la capacidad, si se puede agregar.
        if peso[beneficio_peso_ordenado[i]] <= capacidad:
            solucion[beneficio_peso_ordenado[i]] = 1
            capacidad -= peso[beneficio_peso_ordenado[i]] #decremento la capacidad, porque se agrega el objeto, por ende la capacidad se reduce.
        #si el peso del objeto es mayor a la capacidad, no se puede agregar.
        else:
            solucion[beneficio_peso_ordenado[i]] = 0
    print("indices de los objetos que se pueden agregar: ", beneficio_peso_ordenado)
    print("solucion: ", solucion)




bi = np.array([10,6,8])
wi = np.array([3,4,5])
cap = 9

print(mochilaVoraz(wi, bi, cap))
