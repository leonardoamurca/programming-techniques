#include <iostream>
#include<stdio.h> 
#define N 8

using namespace std;

void imprimirSolucao(int solucao[N][N]) {
  for (int x = 0; x < N; x++) {
    for (int y = 0; y < N; y++) {
      cout<<solucao[x][y]<< "             ";
    }
    cout<<"\n"<<endl;
  }
}


void inicializarMatrizSolucao(int solucao[N][N]) {
  for (int x = 0; x < N; x++) {
    for (int y = 0; y < N; y++) {
      solucao[x][y] = -1;
    }
  }
}

// Verifica se o movimento realizado está nos limites do tabuleiro
bool estaNoLimiteDoTabuleiro(int x, int y, int solucao[N][N]) {
  return (x >= 0 && x < N && y >= 0 && y < N && solucao[x][y] == -1);
}

// Funcao utilitaria que soluciona os movimentos do cavalo
int movimentosDoCavalo(int x, int y, int movimentoI, int solucao[N][N], int eixoX[N], int eixoY[N]) {
  int k, proximoX, proximoY;

  if (movimentoI == N*N) {
    return true;
  }

  for (k = 0; k < 8; k++) {
    proximoX = x + eixoX[k];
    proximoY = y + eixoY[k];
    if (estaNoLimiteDoTabuleiro(proximoX, proximoY, solucao)) {
      solucao[proximoX][proximoY] = movimentoI;
      if (movimentosDoCavalo(proximoX, proximoY, movimentoI + 1, solucao, eixoX, eixoY) == true) {
        return true;
      } else {
        // O passo do backingtrack ocorre aqui
        solucao[proximoX][proximoY] = -1;
      }
    }
  }
  return false;
}


bool inicializarAlgoritmo() {
  int solucao[N][N];

  // Inicializa todas as posicoes da matriz com -1
  inicializarMatrizSolucao(solucao);

  // Ambos os vetores definem o proximo movimento do Cavalo no seu eixo (x e y)
  int eixoX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
  int eixoY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

  // O cavalo é inicializado no primeiro block (Pode-se alterar seu ponto de partida)
  solucao[0][0] = 0;

  if (movimentosDoCavalo(0, 0, 1, solucao, eixoX, eixoY) == false) {
    cout << "Nao existe solucao! " << endl;
    return false;
  } else {
    imprimirSolucao(solucao);
  }



}

int main() {

  inicializarAlgoritmo();
  return 0;
}