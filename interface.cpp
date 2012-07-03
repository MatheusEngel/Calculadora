/*

Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL670 - Linguagens de Programacao - Turma 2012/1
Prof. Leonardo de Oliveira Nunes

Autores: Héron Silva, Matheus Engel, Rafael Estevam, Tiago Monteiro e Vitor Tavares
DREs: 
Data: 28/05/12
Descricao: Implementacao das funcoes auxiliares do modulo de interface
           
*/

// DECLARACAO DAS BIBLIOTECAS

#include "interface.h"

// IMPLEMENTACAO DAS FUNCOES AUXILIARES

string char2string (char caracter)
{
  ostringstream st;
  
  st << caracter;
  
  return (st.str());
}

unsigned contarSeparador (string stringLida)
{
  unsigned n=0;
  unsigned i;
  
  for (i=0; i<stringLida.length(); i++)
    if (stringLida[i] == ';')
      n = n+1;
      
  return n;  
}

void separarExpressao (string stringLida, string *expressoes)
{
  unsigned i, j, nSeparadores;
    
  nSeparadores = contarSeparador(stringLida);
    
  for (i=0; i<nSeparadores; i++)
    for (j=0; j<stringLida.length(); j++)
    {
      if (stringLida[j] != ';')
        expressoes[i].insert (expressoes[i].size(), char2string(stringLida[j]));
      else
        {
          stringLida.erase(0, (j+1));
          break;
        }
    }
}
