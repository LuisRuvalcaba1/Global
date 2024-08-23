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
            tablero[i][j] = tablero[i-1][j]
    for j in range(columnas):
        tablero[0][j] = " "
    return tablero

tablero = iniciarTableroNaves(filas, columnas, naves)

# Mover las naves hacia abajo
for _ in range(8):
    os.system('cls' if os.name == 'nt' else 'clear') 
    imprimirtablero(tablero)
    tablero = mover_abajo(tablero, filas, columnas)
    time.sleep(1)