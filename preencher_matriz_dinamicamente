#include <stdio.h>
#include <stdlib.h>

void preencheMatriz();
void matrizQntRepete();
void imprimeMatriz();
int main()
{

int matriz[4][4];


preencheMatriz(matriz);
matrizQntRepete(matriz);


return 0;

}

void preencheMatriz(int matriz[4][4])
{
int i,j;
srand(time(NULL));
for(i=0; i<4; i++)
{
    for(j=0; j<4; j++)
    {
        matriz[i][j] = rand() % 11;
    }
}


}

void matrizQntRepete(int matriz[4][4])
{
int k,p,i,j,m;
int matriz2[4][4];
for(k=0; k<4; k++)
{
    for(p=0; p<4; p++)
    {
         matriz2[k][p] = m;
         m=0;
        for(i=0; i<4; i++)
        {

            for(j=0; j<4; j++)
            {

                if(matriz[k][p] == matriz[i][j])
                {

                    m++;

                }
            }
        }
    }
}

imprimeMatriz(matriz);





}
void imprimeMatriz(int matriz[4][4])
{
int i,j;
for(i=0; i<4; i++)
{
    for(j=0; j<4; j++)
    {
            printf("%d ",matriz[i][j]);
    }
    printf("\n");

    }




}
