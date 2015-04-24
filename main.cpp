///Tomas Abril
///Daniel Silva Curi
///Diego Wesley Braga

#include <stdio.h>
#include <stdlib.h>

int tamCasa;
int tamMatriz;
int **matriz;
int verificador;

void lerMatriz();
void imprimeMatriz();
void resolve(int linha, int coluna);
int verifica(int linha, int coluna, int valor);

int main()
{
    lerMatriz();
    return 0;
}

void lerMatriz()
{
    int i,j,n;

    while(scanf("%d", &n) == 1) {
        tamCasa = n;
        tamMatriz = n*n;

        verificador = 0;

        matriz = (int**)malloc(tamMatriz * sizeof(int*));

        for(i = 0; i < tamMatriz; i++) {
            matriz[i] = (int*)malloc(tamMatriz * sizeof(int));
        }

        for(i=0; i<tamMatriz; i++)
            for(j=0; j<tamMatriz; j++) {
                scanf("%d", &matriz[i][j]);
            }

        resolve(0,0);

        if(verificador)
            imprimeMatriz();
        else
            printf("NO SOLUTION\n");
    }
}

void imprimeMatriz()
{
    int i, j;

    for(i = 0; i < tamMatriz; i++) {
        for(j = 0; j < tamMatriz; j++)
            printf("%d ", matriz[i][j]);

        printf("\n");
    }
    printf("\n");
}

void resolve(int linha, int coluna)
{
    int i;

    if(coluna > tamMatriz-1) {
        coluna = 0;
        linha++;
    }

    if(linha > tamMatriz-1) {
        verificador=1;
        return;
    }

    if(matriz[linha][coluna] != 0)
        resolve(linha, coluna+1);
    else {
        for(i = 1; i <= tamMatriz; i++) {
            if(verifica(linha, coluna, i) != 0) {
                matriz[linha][coluna] = i;
                resolve(linha, coluna+1);
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
