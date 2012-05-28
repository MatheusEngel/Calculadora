/*

Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL670 - Linguagens de Programacao - Turma 2012/1
Prof. Leonardo de Oliveira Nunes

Autores: Héron Silva, Matheus Engel, Rafael Estevam, Tiago Monteiro e Vitor Tavares
DREs: 
Data: 28/05/12
Descricao: Programa principal da calculadora em linha de comando em C++
           
*/

// DECLARACAO DAS BIBLIOTECAS

#include "interface.h"

// PROGRAMA PRINCIPAL

int main()
{
  unsigned n, aux;
  string stringTeste;
  string *expressoes;
  
  instruirUsuario();
  stringTeste = receberExpressao();
  n = contarSeparador(stringTeste);
  expressoes = new string[n];
  separarExpressao (stringTeste, expressoes);
  
  for (aux=0; aux<n; aux++)
  {
    cout << expressoes[aux] << endl;
  }
  
  free (expressoes);
  system("PAUSE");
  
  return 0;
}
