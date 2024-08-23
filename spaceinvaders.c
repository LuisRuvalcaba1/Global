#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

#define columnas 60
#define filas 10

void GoToXY(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (!SetConsoleCursorPosition(hConsole, coord))
    {
    }
}

void iniciar_tablero(char tablero[filas][columnas])
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
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%c", tablero[i][j]);
        }
        printf("\n");
    }
}

void iniciar_naves(char tablero[filas][columnas], int fila)
{
    char tablero2[filas][columnas];
    for (int i = 0; i < 6; i++)
    {
        int col = i * 5;
        if (fila > 0)
        {
            for (int j = 0; j < 60; j++)
            {
                tablero[fila - 1][j] = ' ';
            }
            tablero[fila][col] = ' ';
            tablero[fila][col + 1] = '*';
            tablero[fila][col + 2] = ' ';
            tablero[fila][col + 3] = '*';
            tablero[fila][col + 4] = ' ';

            tablero[fila + 1][col] = ' ';
            tablero[fila + 1][col + 1] = ' ';
            tablero[fila + 1][col + 2] = '*';
            tablero[fila + 1][col + 3] = ' ';
            tablero[fila + 1][col + 4] = ' ';
        }
        else
        {

            tablero[fila][col] = ' ';
            tablero[fila][col + 1] = '*';
            tablero[fila][col + 2] = ' ';
            tablero[fila][col + 3] = '*';
            tablero[fila][col + 4] = ' ';

            tablero[fila + 1][col] = ' ';
            tablero[fila + 1][col + 1] = ' ';
            tablero[fila + 1][col + 2] = '*';
            tablero[fila + 1][col + 3] = ' ';
            tablero[fila + 1][col + 4] = ' ';
        }
    }
}

void imprimir_fila(char tablero[filas][columnas], int fila)
{
    GoToXY(0, fila);
    for (int j = 0; j < columnas; j++)
    {
        printf("%c", tablero[fila][j]);
    }
    printf("\n");
}

void borrar_pantalla()
{
    system("cls");
}

int main()
{
    char tablero[filas][columnas];
    int fila = 0;
    iniciar_tablero(tablero);

    for (int i = 0; i < filas; i++)
    {
        imprimir_fila(tablero, i);
    }

    do
    {
        iniciar_naves(tablero, fila);
        
        if (fila > 0)
        {
            imprimir_fila(tablero, fila - 1);
        }
        imprimir_fila(tablero, fila);
        imprimir_fila(tablero, fila + 1);

        Sleep(1000);
        fila++;

    } while (fila <= 8);

    return 0;
}