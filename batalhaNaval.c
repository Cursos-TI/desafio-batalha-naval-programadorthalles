#include <stdio.h>

      // Desafio: nível aventureiro
     //Tabuleiro Completo e Navios Diagonais
    //jogo de Batalha Naval 
int main(){
        
    int navio1 =3 ,navio2 =3,navio3 =3,navio4 =3;
    
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
         //printando na tela o tabuleiro
         printf(" TABULEIRO BATALHA NAVAL\n\n");
         printf("   A B C D E F G H I J\n"); //numeração colunas

         // Exibindo a matriz 
         for (int i = 0;  i <10; i++){
         printf("%d  ", i); // Numeração das linhas

         for (int j = 0; j < 10; j++){
         printf("%d ", tabuleiro[i][j]);
         }
  
         //Posicionamento do Navios 1       //LINHA[2]
          for (int i = 2;  i <5; i++){
           tabuleiro[2][i] = navio1 ; 

         //Posicionamento do Navios 2     // COLUNA[8]
         for (int j = 6; j < 9; j++){
          tabuleiro[j][8] = navio2;

         //Posicionamento do Navios 3   // [6 + i] o numero seguinifica a diagonal 
         for (int i = 5;  i <8; i++){
          tabuleiro[i][6+i] = navio3 ; 

         //Posicionamento do Navios 4    // [0 - j] o numero seguinifica a diagonal segundaria eo "menos - ' seguinifica ela invertida !
         for (int j = 1; j < 5; j++){
          tabuleiro[j][0-j] = navio4;
                        
          }
             }
                }
                   }
          printf("\n");
            }
                   
 return 0;

}
