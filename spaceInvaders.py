import os
import time

filas = 10
columnas = 50
naves = 5

def tableroMain(filas, columnas):
    tablero = []
    for i in range(filas):
        fila = [" "] * columnas
        tablero.append(fila)
    return tablero

def iniciarTableroNaves(filas, columnas, naves):
    tablero = []
    for i in range(filas):
        fila = [" "] * columnas
        tablero.append(fila)

    for i in range(naves):
        for j in range(5):
            tablero[0][i * 5 + j] = " * * "[j]
        for j in range(5):
            tablero[1][i * 5 + j] = "  *  "[j]

    return tablero

def imprimirtablero(tablero):
    for fila in tablero:
        print("".join(fila))

def mover_abajo(tablero, filas, columnas):
    for i in range(filas - 1, 0, -1):
        for j in range(columnas):
            tablero[i][j] = tablero[i-1][j]
    for j in range(columnas):
        tablero[0][j] = " "
    return tablero

tablero = iniciarTableroNaves(filas, columnas, naves)

for _ in range(8):
    os.system('cls' if os.name == 'nt' else 'clear') 
    imprimirtablero(tablero)
    tablero = mover_abajo(tablero, filas, columnas)
    time.sleep(1)