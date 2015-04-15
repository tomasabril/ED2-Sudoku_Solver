#include <stdio.h>
#include <stdlib.h>

#include <cstdio>

using namespace std;

int tamCasa;
int tamMatriz;
int **matriz;
int verificador = 0;

void lerArq();
void lerMat();
void imprimeMatriz();
void percorreMatriz();
void preenche(int linha, int coluna);
int verifica(int linha, int coluna, int valor);

int main()
{

    lerMat();

    imprimeMatriz();

    preenche(0, 0);

    imprimeMatriz();

    return 0;
}

void lerArq()
{
    char url[]="input (copy).txt";
    char leitor[1];
    int i, j;

    FILE *arq;
    arq = fopen(url, "r");

    while(!feof(arq))
    {
        leitor[0] = fgetc(arq);

        if( leitor[0] > 47 && leitor[0] < 58 )
        {
            tamCasa = atoi(leitor);

            tamMatriz = tamCasa*tamCasa;

            break;
        }
    }

    matriz = (int**)malloc(tamMatriz * sizeof(int*));

    for(i = 0; i < tamMatriz; i++)
    {
        matriz[i] = (int*)malloc(tamMatriz * sizeof(int));
    }

    for(i = 0; !feof(arq) && i<tamMatriz; i++)
    {
        for(j = 0; !feof(arq) && j<tamMatriz; )
        {
            leitor[0] = fgetc(arq);

            if(  leitor[0] > 47 && leitor[0] < 58 )
            {
                matriz[i][j] = atoi(leitor);
                j++;
            }
        }
    }

    fclose(arq);
}

void lerMat()
{
    int i,j,n;
    scanf("%d", &n);                        //ler tamanho do sudoku

    tamCasa=n;
    tamMatriz=n*n;

    for(i=0; i<tamMatriz; i++)
        for(j=0; j<tamMatriz; j++)
        {
            scanf("%d", &matriz[i][j]);
        }


}
void imprimeMatriz()
{
    int i, j;

    for(i = 0; i < tamMatriz; i++)
    {
        for(j = 0; j < tamMatriz; j++)
            printf("%d ", matriz[i][j]);

        printf("\n");
    }
    printf("\n");
}

void preenche(int linha, int coluna)
{
    int i;

    if(coluna > tamMatriz-1)
    {
        coluna = 0;
        linha++;
    }

    if(linha > tamMatriz-1)
    {
        verificador=1;
        return;
    }

    if(matriz[linha][coluna] != 0)
        preenche(linha, coluna+1);

    else
    {
        for(i = 1; i <= tamMatriz; i++)
        {
            if(verifica(linha, coluna, i) != 0)
            {
                matriz[linha][coluna] = i;
                preenche(linha, coluna+1);
                if(verificador)
                    return;
                matriz[linha][coluna] = 0;
            }
        }
    }
}

int verifica(int linha, int coluna, int valor)
{
    int i,j;

    for(i = 0; i < tamMatriz; i++)
        if(matriz[linha][i] == valor)
            return 0;

    for(i = 0; i < tamMatriz; i++)
        if(matriz[i][coluna] == valor)
            return 0;

    for(i = (linha/tamCasa)*tamCasa; i < ((linha/tamCasa)*tamCasa + tamCasa); i++)
        for(j = (coluna/tamCasa)*tamCasa; j < ((coluna/tamCasa)*tamCasa + tamCasa); j++)
            if(matriz[i][j] == valor)
                return 0;

    return 1;
}

