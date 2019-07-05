#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

// Popula o tamanho de cada subsequencia onde o valor de cada posição do vetor
// corresponde ao primeiro elemento da subsequencia.
void populaVetorBest(int sequencia[], int best[], int n) {
  best[n] = 1;
  for (int i = n-1; i >= 0; i--) {
    best[i] = 1;
    for (int j = i+1; j < n; j++) {
      if (sequencia[j] > sequencia[i] && 1 + best[j] > best[i]) {
        best[i] = 1 + best[j];
      }
    }
  }
}

// Retorna qual o tamanho da maior subsequencia do problema
int encontraMaiorElementoDeBest(int best[], int n) {
  int maior = 0;
    for (int i = 0 ; i < n ; i++) {
      if (best[i] > maior) {
        maior = best[i];
        cout << best[i];
      }
    }
  return maior;
}

int main() {
  int sequencia[] = {7, 6, 10, 3, 4, 1, 8, 9, 5, 2};

  // Tamanho da sequencia
  int n = sizeof(sequencia) / sizeof(sequencia[0]);

  int *best = new int[INT_MAX];
  populaVetorBest(sequencia, best, n);

  int maiorValor = encontraMaiorElementoDeBest(best, n);

  cout << "O tamanho da maior subsquencia é: " << maiorValor << endl;
 
  return 0;
}