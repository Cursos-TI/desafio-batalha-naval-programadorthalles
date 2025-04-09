#include <stdio.h>

int main(){
     
    int tabuleiro[10][10] = {
        {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
        {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
        {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
        {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
        {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
        {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
        {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
        {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
        {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0},
        {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0}

    };
    printf("\n   0 1 2 3 4 5 6 7 8 9\n\n"); //numeração colunas

         for (int i = 0;  i <10; i++){
          printf("%d  ", i); // Numeração das linhas

           for (int j = 0; j < 10; j++){
           printf("%d ", tabuleiro[i][j]);
                }
               printf("\n");
              

              int navio1 =3;
              int navio2 =3;
              navio1 = tabuleiro[3][3]= 3;
              navio1 = tabuleiro[3][4]= 3;
              navio1 = tabuleiro[3][5]= 3;
              navio2 = tabuleiro[6][8]= 3;
              navio2 = tabuleiro[7][8]= 3;
              navio2 = tabuleiro[8][8]= 3;

              
                }
 return 0;

}
