#include <stdio.h>
#include <stdlib.h>
#include <math.h>
                  //Jogo de Batalha Naval //
              //Desafio: nível Mestre  //
        // Habilidades especiais e áreas de efeito //

#define TAMANHO_TABULEIRO 10 
#define TAMANHO_NAVIO 3      

// Constantes para os valores das células
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Tamanho definido para as matrizes de habilidades (3 linhas x 5 colunas)
#define HABI_LINHAS 3
#define HABI_COLUNAS 5

// Função para imprimir o tabuleiro no console
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
    printf("\n");
    printf(" TABULEIRO BATALHA NAVAL\n\n");
    printf("    A B C D E F G H I J\n");
    for (int linha = 0; linha < TAMANHO_TABULEIRO; linha++)
    {
        printf("%2d  ", linha );
        for (int coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++)
        {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio na horizontal
int NavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int colunaInicio)
{
    if (colunaInicio < 0 || colunaInicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
    {
        printf("Erro: Navio horizontal fora dos limites do tabuleiro!\n");
        return 1;
    }
    // Verifica sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (tabuleiro[linha][colunaInicio + i] != AGUA)
        {
            printf("Erro: Sobreposição detectada no navio horizontal!\n");
            return 1;
        }
    }
    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[linha][colunaInicio + i] = NAVIO;
    }
    return 0;
}

// Função para posicionar um navio na vertical
int NavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicio, int coluna)
{
    if (linhaInicio < 0 || linhaInicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
    {
        printf("Erro: Navio vertical fora dos limites do tabuleiro!\n");
        return 1;
    }
    // Verifica sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (tabuleiro[linhaInicio + i][coluna] != AGUA)
        {
            printf("Erro: Sobreposição detectada no navio vertical!\n");
            return 1;
        }
    }
    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[linhaInicio + i][coluna] = NAVIO;
    }
    return 0;
}

// Função para posicionar um navio na diagonal crescente (de cima para baixo, coluna aumenta)
int NavioDiagonalC(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicio, int colunaInicio)
{
    if (linhaInicio < 0 || linhaInicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        colunaInicio < 0 || colunaInicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
    {
        printf("Erro: Navio diagonal crescente fora dos limites do tabuleiro!\n");
        return 1;
    }
    // Verifica sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (tabuleiro[linhaInicio + i][colunaInicio + i] != AGUA)
        {
            printf("Erro: Sobreposição detectada no navio diagonal crescente!\n");
            return 1;
        }
    }
    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[linhaInicio + i][colunaInicio + i] = NAVIO;
    }
    return 0;
}

// Função para posicionar um navio na diagonal decrescente (de cima para baixo, coluna diminui)
int NavioDiagonalD(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicio, int colunaInicio)
{
    if (linhaInicio < 0 || linhaInicio + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        colunaInicio < (TAMANHO_NAVIO - 1))
    {
        printf("Erro: Navio diagonal decrescente fora dos limites do tabuleiro!\n");
        return 1;
    }
    // Verifica sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        if (tabuleiro[linhaInicio + i][colunaInicio - i] != AGUA)
        {
            printf("Erro: Sobreposição detectada no navio diagonal decrescente!\n");
            return 1;
        }
    }
    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++)
    {
        tabuleiro[linhaInicio + i][colunaInicio - i] = NAVIO;
    }
    return 0;
}

/*
   Criação das matrizes de habilidade:
   Cada função recebe uma matriz 3x5 e utiliza laços aninhados com condicionais para definir onde o efeito deve ocorrer.
*/

// Habilidade Cone: Ponto de origem no topo – expande-se lateralmente a cada linha
void criarMatrizCone(int matriz[HABI_LINHAS][HABI_COLUNAS])
{
    int centro = HABI_COLUNAS / 2; // Para 5 colunas, centro é 2
    for (int i = 0; i < HABI_LINHAS; i++)
    {
        for (int j = 0; j < HABI_COLUNAS; j++)
        {
            // Na linha i, as colunas afetadas estão entre (centro - i) e (centro + i)
            if (j >= (centro - i) && j <= (centro + i))
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Habilidade Cruz: O efeito aparece na linha central ou na coluna central
void criarMatrizCruz(int matriz[HABI_LINHAS][HABI_COLUNAS])
{
    int centroLinha = HABI_LINHAS / 2;   // Linha 1
    int centroColuna = HABI_COLUNAS / 2; // Coluna 2
    for (int i = 0; i < HABI_LINHAS; i++)
    {
        for (int j = 0; j < HABI_COLUNAS; j++)
        {
            if (i == centroLinha || j == centroColuna)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Habilidade Octaedro: Representa um losango com o centro no meio
void criarMatrizOctaedro(int matriz[HABI_LINHAS][HABI_COLUNAS])
{
    int centroLinha = HABI_LINHAS / 2;   // Linha 1
    int centroColuna = HABI_COLUNAS / 2; // Coluna 2
    for (int i = 0; i < HABI_LINHAS; i++)
    {
        for (int j = 0; j < HABI_COLUNAS; j++)
        {
            // Usando a "distância Manhattan" a partir do centro
            if (abs(i - centroLinha) + abs(j - centroColuna) <= 1)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

/*
   Função para sobrepor uma matriz de habilidade sobre o tabuleiro.
   A variável "origemLinha" e "origemColuna" definem a célula do tabuleiro
   que corresponderá ao centro da matriz de habilidade (nesse caso, posição (1,2) na matriz 3x5).
*/
void sobreporHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                        int habilidade[HABI_LINHAS][HABI_COLUNAS],
                        int origemLinha, int origemColuna)
{
    int centroLinha = HABI_LINHAS / 2;   // Célula central da habilidade (linha 1)
    int centroColuna = HABI_COLUNAS / 2; // Célula central da habilidade (coluna 2)
    for (int i = 0; i < HABI_LINHAS; i++)
    {
        for (int j = 0; j < HABI_COLUNAS; j++)
        {
            // Calcula a posição correspondente no tabuleiro
            int boardLinha = origemLinha - centroLinha + i;
            int boardColuna = origemColuna - centroColuna + j;
            // Verifica se a posição está dentro dos limites do tabuleiro
            if (boardLinha >= 0 && boardLinha < TAMANHO_TABULEIRO &&
                boardColuna >= 0 && boardColuna < TAMANHO_TABULEIRO)
            {
                if (habilidade[i][j] == 1)
                {
                    // Marca a posição com o valor da habilidade (5)
                    tabuleiro[boardLinha][boardColuna] = HABILIDADE;
                }
            }
        }
    }
}

int main()
{
    // Inicializa o tabuleiro com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

  
    // Posicionamento dos navios
 
    // Navio Horizontal: linha 2 (índice 1), coluna D (índice 3)
    if (NavioHorizontal(tabuleiro, 1, 2) != 0)
        return 1;
    // Navio Vertical: linha 6 (índice 5), coluna G (índice 6)
    if (NavioVertical(tabuleiro, 5, 5) != 0)
        return 1;
    // Navio Diagonal Crescente: inicia em A1 (linha 0, coluna 0)
    if (NavioDiagonalC(tabuleiro, 0, 0) != 0)
        return 1;
    // Navio Diagonal Decrescente: inicia em J1 (linha 0, coluna J, índice 9)
    if (NavioDiagonalD(tabuleiro, 0, TAMANHO_TABULEIRO - 1 ) != 0)
        return 1;

    // Criação das matrizes de habilidade
  
    int cone[HABI_LINHAS][HABI_COLUNAS];
    int cruz[HABI_LINHAS][HABI_COLUNAS];
    int octaedro[HABI_LINHAS][HABI_COLUNAS];

    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);


    // Definição dos pontos de origem para as habilidades
    
    int origemCone_linha = 2, origemCone_coluna = 5;         // Exemplo: (3ª linha, 6ª coluna)
    int origemCruz_linha = 5, origemCruz_coluna = 2;         // Exemplo: (6ª linha, 3ª coluna)
    int origemOctaedro_linha = 7, origemOctaedro_coluna = 7; // Exemplo: (8ª linha, 8ª coluna)

    
    // Sobrepõe as áreas de efeito das habilidades no tabuleiro
    
    sobreporHabilidade(tabuleiro, cone, origemCone_linha, origemCone_coluna);
    sobreporHabilidade(tabuleiro, cruz, origemCruz_linha, origemCruz_coluna);
    sobreporHabilidade(tabuleiro, octaedro, origemOctaedro_linha, origemOctaedro_coluna);

    
    // Exibe o tabuleiro final com navios e áreas afetadas pelas habilidades
    
    imprimirTabuleiro(tabuleiro);

    return 0;
}