#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

#define columnas 60
#define filas 10

char iniciar_tablero(char tablero[filas][columnas])
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            tablero[i][j] = ' ';
        }
    }
}

void imprimir_tablero(char tablero[filas][columnas])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            printf("%c", tablero[i][j]);
        }
        printf("\n");
    }
}

char iniciar_naves(char tablero[filas][columnas], int naves)
{
    for (int i = 0; i < naves; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tablero[0][i * 5] = ' ';
            tablero[0][(i * 5) + 1] = '*';
            tablero[0][(i * 5) + 2] = ' ';
            tablero[0][(i * 5) + 3] = '*';
            tablero[0][(i * 5) + 4] = ' ';

            tablero[1][i * 5] = ' ';
            tablero[1][(i * 5) + 1] = ' ';
            tablero[1][(i * 5) + 2] = '*';
            tablero[1][(i * 5) + 3] = ' ';
            tablero[1][(i * 5) + 4] = ' ';
        }
    }
}

void mover_naves(char tablero[filas][columnas])
{
    for (int i = 1; i > 0; i--)
    {
        for (int j = 0; j < 60; j++)
        {
            if (tablero[-1][j == '*'] || tablero[-1][j == ' '])
            {
                tablero[i][j] = tablero[i - 1][j];
                tablero[i - 1][j] = ' ';
            }
            printf("%c", tablero[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char tablero[filas][columnas];
    iniciar_tablero(tablero);
    iniciar_naves(tablero, 6);
    imprimir_tablero(tablero);

    for (int tick = 0; tick < 8; tick++)
    {
        mover_naves(tablero);
        Sleep(1000);
    }

    return 0;
}