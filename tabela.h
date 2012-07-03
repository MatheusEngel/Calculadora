/*
 Tabela de Variaveis para o programa Calculadora (v2.0)
 Constitui-se em duas structs: Variavel, contendo nome e valor da variavel e
Node, que contem um ponteiro para Variavel e outro ponteiro para o proximo Node.


      Funcoes "publicas", que serao chamadas pelo resto do programa

    string tabela::busca_valor (char nomeVar);
     funcao utilizada para retornar o valor de uma variavel nomeVar informada
    
    
    void tabela::create_node(char nome, double valor);
     funcao utilizada para criar o node na tabela, com o nome e valor informados da variavel,
     alem de incluir este node na lista encadeada de nodes. 
     no caso de "a=10", essa funcao deve ser chamanda tendo nome = a e valor = 10
     
     
     void tabela::cleanTabela()
      funcao para libera a memoria ao fim do programa. Deve ser chamada quando a calculadora
      for encerrada pelo usuario

     deve-se utilizar #include "tabela2.0.h" no programa principal para poder acessar essas funcoes
     ex: valorVar = tabela::busca_valor(nomeVar);
*/


#ifndef tabelaOK_h
#define tabelaOK_h

#include <cstdlib>
#include <iostream>
#include <string>

#define ERRO_LISTA_VAZIA "9997";
#define ERRO_VARIAVEL_INEXISTENTE "9987";


using namespace std;

namespace tabela{
          
    string busca_valor (char nomeVar);
    
    void create_node(char nome, string valor);
   
    void tabela::cleanTabela();
}

 

#endif
