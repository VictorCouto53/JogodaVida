#include <stdio.h>
#include <stdlib.h>

int lin, col = 5;
int matriz[5][5];


void GridLim() 
{
	printf("\n");
		for(int k = 0; k < col; k++){
			printf("+-----");
		}
		printf("+");
		printf("\n");
}

void intmatriz()
{
  GridLim();
  for(int s = 0; s < 5; s++){
    for (int k = 0; k < 5; k++)
      {
        matriz[s][k] = 0;
        printf("|");
        printf("  %d  ", matriz[s][k]);
      }
    printf("|");
    GridLim();
  }
}

void imprimir()
{
  GridLim();
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++)
    { 
      printf("|");
      printf("  %i  ", matriz[i][j]);
    }
    printf("|");
    GridLim();
  }
}

void substituicao(int lin, int col)
{
  matriz[lin-1][col-1] = 1;
}

void leitura()
{
  int linv = 0;
  int colv = 0;
  
  printf("\nSelecione as células que iniciarão vivas, informando as respectivas linhas e colunas.\nInsira um número negativo para confirmar as células inseridas.\n");
  
	while(linv >= 0){
		printf("\nLinha: ");
		scanf("%d",&linv);
		if(linv < 0){
			break;
		}
		printf("\nColuna: ");
		scanf("%d",&colv);

    substituicao(linv, colv);
  }
}

void Regras()
{
  int proxima = 0;
  for(int i = 0; i < 5; i++)
  {
      for(int j = 0; j < 5; j++)
      {
        if(matriz[i][j] == 1){
				proxima = 0;
				
				if(matriz[i-1][j] == 1 || matriz[i-1][j] == -1){
					proxima++;
				}
				if(matriz[i][j-1] == 1 || matriz[i][j-1] == -1){
					proxima++;
				}
				if(matriz[i][j+1] == 1 || matriz[i][j+1] == -1){
					proxima++;
				}
				if(matriz[i+1][j] == 1 || matriz[i+1][j] == -1){
					proxima++;
				}
				
				if(matriz[i-1][j-1] == 1 || matriz[i-1][j-1] == -1){
					proxima++;
				}
				if(matriz[i+1][j+1] == 1 || matriz[i+1][j+1] == -1){
					proxima++;
				}
				if(matriz[i+1][j-1] == 1 || matriz[i+1][j-1] == -1){
					proxima++;
				}
				if(matriz[i-1][j+1] == 1 || matriz[i-1][j+1] == -1){
					proxima++;
				}
				if(proxima <= 1 || proxima >= 4){
					matriz[i][j] = -1;
        }
      }
    }
  }
  
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 5; j++)
    {
      if(matriz[i][j] == 0){
				proxima = 0;
        
        if(matriz[i-1][j] == 1 || matriz[i-1][j] == -1){
					proxima++;
				}
				if(matriz[i][j-1] == 1 || matriz[i][j-1] == -1){
					proxima++;
				}
				if(matriz[i][j+1] == 1 || matriz[i][j+1] == -1){
					proxima++;
				}
				if(matriz[i+1][j] == 1 || matriz[i+1][j] == -1){
					proxima++;
				}
				if(matriz[i-1][j-1] == 1 || matriz[i-1][j-1] == -1){
					proxima++;
				}
				if(matriz[i+1][j+1] == 1 || matriz[i+1][j+1] == -1){
					proxima++;
				}
				if(matriz[i+1][j-1] == 1 || matriz[i+1][j-1] == -1){
					proxima++;
				}
				if(matriz[i-1][j+1] == 1 || matriz[i-1][j+1] == -1){
					proxima++;
				}
				
				if(proxima == 3){
					matriz[i][j] = 2;
        }
      }
    }
  }

  for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				if(matriz[i][j] == -1){
					matriz[i][j] = 0;
				}
				
				if(matriz[i][j] == 2){
					matriz[i][j] = 1;
				}
			}
		}
}

int main() 
{
  printf("====================  Jogo da Vida  ====================\n\nEsse programa apresenta a simulação do Jogo da Vida utilizando uma matriz 5x5.\n\n");
  intmatriz();
  leitura();
  printf("Matriz inicial com as células vivas informadas.\n");
  imprimir();

  int resp;
  int k = 1;
  while(resp != 0){
    printf("\nInsira um número inteiro diferente de 0 para rodar uma geração ou 0 (zero) para parar: ");
    scanf("%d", &resp);
    if(resp == 0)
      break;
    Regras();
    printf("\n===============================================================\n");
    printf("\nGeração atual: %d\n", k);
    imprimir();
    k++;
    }

  //Trecho escrito para imprimir as 4 primeiras gerações de imediato.
  for(int i = 1; i < 5; i++){
    Regras();
    printf("================================================");
    printf("\nGeração atual: %d\n", i);
    imprimir();
  }

  printf("\n=====================  Fim da Simulação  =====================");
}	

