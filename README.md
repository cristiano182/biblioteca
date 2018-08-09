# BIBLIOTECA DE LIVROS EM LINGUAGEM C
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,p;
    int matriz[4][4];
    int matrizQntRepete[4][4];

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {

            matriz[i][j] = rand() % 11;

        }
    }

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

    for(k=0; k<4; k++)
    {
        for(p=0; p<4; p++)
        {
            for(i=0; i<4; i++)
            {
                for(j=0; j<4; j++)
                {

                    if(matriz[i][j] == matriz[k][p])
                    {

                        matrizQntRepete[k][p] += 1;

                    }
                }
            }
        }
    }

    printf("\n\n");

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%d ",matrizQntRepete[i][j]);
        }
        printf("\n");
    }
    return 0;
}
