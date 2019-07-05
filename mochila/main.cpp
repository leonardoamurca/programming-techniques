#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

// Estrutura que armazena os campos de um objeto
struct Objeto {
  int id;
  int peso;
  int beneficio;
};

// Compara 2 beneficios de objetos diferentes
bool comparaObjetos(Objeto a, Objeto b);

// Ordena o vetor de objetos do maior beneficio para o maior
void ordenaObjetosBeneficio(Objeto objetos[], int n);

// Seta o vetor resultado como ZERO
void inicializaS(int s[], int n);

// Imprime vetor resultado
void imprimeVetorS(int s[], int n);

// Imprime vetor de objetos ordenado de forma descrescente em relação ao benefícios de cada objeto
void imprimeObjetosOrdenado(Objeto objetos[], int n);

//Percorre todo o vetor de objetos e realiza as comparacoes 
// dos melhores beneficios e retorna a soma dos beneficios dos objetos roubados
int beneficioTotal(Objeto objetos[], int n, int capacidadeMochila);


int main() {

  // Capacidade da mochila
  int capacidadeMochila = 23;

  Objeto objetos[] = {{1, 4, 2}, {2, 5, 2}, {3, 7, 3}, {4, 9, 4}, {5, 6, 4}};

  // Numero de objetos
  int n = sizeof(objetos) / sizeof(objetos[0]);

  ordenaObjetosBeneficio(objetos, n);
  imprimeObjetosOrdenado(objetos, n);

  int beneficioFinal = beneficioTotal(objetos, n, capacidadeMochila);

  cout << "\nBeneficio final total: " << beneficioFinal << endl;

  return 0;
}


// Compara 2 beneficios de objetos diferentes
bool comparaObjetos(Objeto a, Objeto b) {
  return a.beneficio > b.beneficio;
}

// Ordena o vetor de objetos do maior beneficio para o maior
void ordenaObjetosBeneficio(Objeto objetos[], int n) {
  sort(objetos, objetos + n, comparaObjetos);
}

// Seta o vetor resultado como ZERO
void inicializaS(int s[], int n) {
  for (int i = 0; i < n; i++) {
    s[i] = 0;
  }
}

// Imprime vetor resultado
void imprimeVetorS(int s[], int n) {
  cout << "Vetor resultado = [ "; 
  for (int i = n-1; i >= 0; i--) {
    if (i == 0) {
      cout << s[i] << " ";
    } else {
      cout << s[i] << ", ";
    }
    
  }
  cout << "]";
}

// Imprime vetor de objetos ordenado de forma descrescente em relação ao benefícios de cada objeto
void imprimeObjetosOrdenado(Objeto objetos[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "Objeto " << objetos[i].id << ": " << endl;
    cout << "Peso: " << objetos[i].peso << endl;
    cout << "Beneficio: " << objetos[i].beneficio << endl;
    cout << "============================" << endl;
  }
}

//Percorre todo o vetor de objetos e realiza as comparacoes 
// dos melhores beneficios e retorna a soma dos beneficios dos objetos roubados
int beneficioTotal(Objeto objetos[], int n, int capacidadeMochila) {
    // Vetor resultado (Ordenado do objeto de maior beneficio para o de menor beneficio)
  int *s = new int[n];

  // Seta o vetor resultado como ZERO
  inicializaS(s, n);

  // Inicializa variavel para contabilizar o peso atual da mochila a cada objeto roubado
  int pesoAtual = 0;

  // Contabiliza o beneficio total apos a mochila estar cheia
  int beneficioTotal = 0;


  int i = 0;
  for (int i = 0; i < n; i++) {
    if (pesoAtual + objetos[i].peso <= capacidadeMochila) {
      pesoAtual += objetos[i].peso;
      s[i]++;
      beneficioTotal += objetos[i].beneficio;
    } else {
      int restante = capacidadeMochila - pesoAtual;
      beneficioTotal += objetos[i].beneficio * ((double)restante / objetos[i].peso );
      break;
    }
  }
  
  // Imprime vetor resultado
  imprimeVetorS(s, n);

  return beneficioTotal;
}