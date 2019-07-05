#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int multiplicarMatrizes(int matrizes[], int n) {
  int matriz[n][n];

  // Tamanho da cadeia
  int L;
  // Custo escalar das multiplicações
  int q;

  int j;

  for (int i = 1; i < n; i++) {
    matriz[i][i] = 0;
  }
  for (L = 2; L < n; L++) {
    for (int i = 0; i < n-L+1; i++) {
      j = i + L - 1;
      matriz[i][j] = INT_MAX;
      for (int k = i; k <= j-1; k++) {
        q = matriz[i][k] + matriz[k+1][j] + matrizes[i-1]*matrizes[k]*matrizes[j];
        if (q < matriz[i][j]) {
          matriz[i][j] = q;
        }
      }
    }
  }
  return matriz[1][n-1];
}

int main () {
  int matrizes[] = {1, 2, 3, 4};
  
  // Tamanho do vetor
  int n = sizeof(matrizes) / sizeof(matrizes[0]);

  int numeroMultiplicacoes = multiplicarMatrizes(matrizes, n);

  cout << "Numero minimo de multiplicacoes: " << numeroMultiplicacoes << endl;

  return 0;
}