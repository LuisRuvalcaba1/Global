import os
import time

#Alumno : Luis Alejandro Ruvalcaba Martinez
#Numero de registro: 24310198

def borrarPantalla():
    os.system("cls" if os.name == "nt" else "clear")

def imprimirTablero(tablero):
    for renglon in tablero:
        print("".join(renglon))

def inicializarTablero(filas, columnas, naves):
    tablero = [[" " for _ in range(columnas)] for _ in range(filas)]
    for i in range(naves):
        tablero[0][i * 5:(i * 5) + 5] = " * * "
        tablero[1][i * 5:(i * 5) + 5] = "  *  "
    return tablero

def moverNaves(tablero, direccion):
    filas = len(tablero)
    columnas = len(tablero[0])
    borde_izquierdo, borde_derecho = False, False

    for i in range(filas):
        for j in range(columnas):
            if tablero[i][j] != " ":
                if direccion == 1 and j >= columnas - 5: 
                    borde_derecho = True
                if direccion == -1 and j <= 4:
                    borde_izquierdo = True

    if borde_derecho or borde_izquierdo:
        direccion *= -1
        tablero = [[" " for _ in range(columnas)]] + tablero[:-1] + [[" " for _ in range(columnas)]]

    nuevo_tablero = [[" " for _ in range(columnas)] for _ in range(filas)]
    for i in range(filas):
        for j in range(columnas):
            if tablero[i][j] != " ":
                if tablero[i][j] == "*":
                    nuevo_tablero[i][j + direccion] = "*"
                else:
                    nuevo_tablero[i][j + direccion] = tablero[i][j]

    return nuevo_tablero, direccion

def main():
    filas = 10
    columnas = 60
    naves = 10
    tablero = inicializarTablero(filas, columnas, naves)
    direccion = 1

    while True:
        borrarPantalla()
        imprimirTablero(tablero)
        tablero, direccion = moverNaves(tablero, direccion)
        time.sleep(0.2)

if __name__ == "__main__":
    main()