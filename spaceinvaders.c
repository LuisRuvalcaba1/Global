#include <stdio.h>
#include <conio.h>

char iniciar_tablero(char tablero[10][60])
{

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            tablero[i][j] = ' ';
        }
    }
}

void imprimir_tablero(char tablero[10][60])
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

char iniciar_naves(char tablero[10][60], int naves)
{
    for (int i = 0; i < naves; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tablero[0][i * 5] = ' ';
            tablero[0][i * 5 + 1] = '*';
            tablero[0][i * 5 + 2] = ' ';
            tablero[0][i * 5 + 3] = '*';
            tablero[0][i * 5 + 4] = ' ';

            tablero[1][i * 5] = ' ';
            tablero[1][i * 5 + 1] = ' ';
            tablero[1][i * 5 + 2] = '*';
            tablero[1][i * 5 + 3] = ' ';
            tablero[1][i * 5 + 4] = ' ';
        }
    }
}

int main()
{
    char tablero[10][60];

    iniciar_tablero(tablero);
    iniciar_naves(tablero, 6);
    imprimir_tablero(tablero);

    return 0;
}