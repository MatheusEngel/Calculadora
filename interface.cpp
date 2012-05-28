/*

Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL670 - Linguagens de Programacao - Turma 2012/1
Prof. Leonardo de Oliveira Nunes

Autores: Heron Silva, Matheus Engel, Rafael Estevam, Tiago Monteiro e Vitor Tavares
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

void instruirUsuario ()
{
  cout << "CALCULADORA\n";
  cout << "===========\n\n";
  cout << "INSTRUCOES:\n\n";
  cout << "1) Sua expressao pode conter letras, numeros, parenteses e os quatro operadores aritmeticos;\n";
  cout << "2) Utilize o caracter de ';' para terminar ou separar as expressoes;\n";
  cout << "3) Nao utilize espacos.\n\n";
  cout << "Insira uma expressao:\n\n";
}

string receberExpressao ()
{
  string stringAuxiliar;
  
  cin >> stringAuxiliar;
  
  return stringAuxiliar;
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

void exibirResultado (double resultado)
{
  cout << resultado << endl;
}