/*
 Tabela de Variaveis para o programa Calculadora (v3.0)
 Constitui-se em duas structs: Variavel, contendo nome e valor da variavel e
Node, que contem um ponteiro para Variavel e outro ponteiro para o proximo Node.


      Funcoes "publicas", que serao chamadas pelo resto do programa

    double tabela::busca_valor (char nomeVar);
     funcao utilizada para retornar o valor de uma variavel nomeVar informada
    
    
    void tabela::create_node(char nome, string valor);
     funcao utilizada para criar o node na tabela, com o nome e valor informados da variavel,
     alem de incluir este node na lista encadeada de nodes. 
     no caso de "a=10", essa funcao deve ser chamanda tendo nome = a e valor = 10
     
     
     void tabela::cleanTabela()
      funcao para libera a memoria ao fim do programa. Deve ser chamada quando a calculadora
      for encerrada pelo usuario

     deve-se utilizar #include "tabela2.0.h" no programa principal para poder acessar essas funcoes
     ex: valorVar = tabela::busca_valor(nomeVar);
*/

#include <cstdlib>
#include <iostream>
#include <string>

#define ERRO_LISTA_VAZIA "9997";
#define ERRO_VARIAVEL_INEXISTENTE "9987";

#include "tabela.h"

using namespace std;

//using namespace tabela;

        struct Variavel{
    	  char nome;			// Nome da variavel, um caracter
    	  string valor;			// Valor desta variavel
    	};
    
    	struct Node{					// Cada variavel eh um node
    	  struct Variavel *pVariavel;	// Conteudo da variavel
    	  struct Node *pNext;			// apontando para a proxima variavel
    	};
    
        Node *pNode;
    //*pNode = NULL;
        Node *pStart;

	

	string tabela::busca_valor (char nomeVar){	//funcao para buscar o valor de uma variavel ao informar o nome desta
		int found = 0;
	
		if (pStart == NULL){			 	// caso tabela vazia, nao há o que buscar
		    cout<<"Variavel "<<nomeVar<<" nao encontrada (Lista vazia)."<<endl;
			return ERRO_LISTA_VAZIA;
		}	
		
		pNode = pStart;					
		while (pNode != NULL){
             cout<<" Pnode atual = "<<pNode->pVariavel->nome<<endl; 
             
			if (nomeVar == (pNode->pVariavel->nome)){	// fazendo a comparacao entre nomeVar(entrada) e ->nome(tabelado)
    		cout<<"Achou "<<nomeVar<<"="<<pNode->pVariavel->nome<<endl;
            	found = 1;
    			return (pNode->pVariavel->valor);
			}
else{
                 cout<<"Nao achou a var. Pnode atual = "<<pNode->pVariavel->nome<<endl; }
			     pNode = pNode->pNext;
//			      cout<<" Pnode next = "<<pNode->pVariavel->nome<<endl;
			//}
		}
		if(!found)
			cout<<"Variavel "<<nomeVar<<" nao encontrada na lista."<<endl;
			return ERRO_VARIAVEL_INEXISTENTE; //9987
	} 
	
/*
	void update_vars(){       
         if(pCurrent->pVariavel->pNome == pNode->pVariavel->nome)
            pCurrent->pVariavel->valor = pNode->pVariavel->valor;
         return
         }
*/
	void insert_node (struct Node *pNode){		//inserindo novo node a tabela
		cout<<"1"<<endl;
    	 Node *pCurrent = NULL;
		
		if (pStart == NULL){			 // caso tabela vazia, novo node entra aqui
cout<<"2"<<endl;
			cout<<"inclusao em lista vazia"<<endl;
            pStart = pNode;
			return;
		}
	     else{
              cout<<"3"<<endl;	               
    		pCurrent = pStart;				// caso haja tabela, buscar o ultimo node
/*debug*/ // 		cout<<"inclusao em lista existente. pStart ="<<pStart->pVariavel->nome<<pStart->pVariavel->valor<<endl;
            while(pCurrent!=NULL){
                if((pCurrent->pVariavel->nome) == (pNode->pVariavel->nome)){// caso a var ja exista, deve-se atualizar o seu valor
            //    cout<<"if de atualizacao de var"<<endl;                        
                   pCurrent->pVariavel->valor = pNode->pVariavel->valor;
                   return;
                } 
                pCurrent=pCurrent->pNext;
            }                                  
pCurrent = pStart;	
            while ((pCurrent->pNext)!= NULL){
                  
/*debug*/  //       cout<<"inicio: "<<pCurrent->pVariavel->nome<<pCurrent->pVariavel->valor<<endl;

    			pCurrent = pCurrent->pNext;  			
            }
         
         pCurrent->pNext = pNode;  // dessa forma os Nodes ficaram "linkados". Caso fizesse busca até pCurrent=NULL, 
                                   // ,nao estava sendo possivel ligar um node ao outro.
/*debug*/    //cout<<"fim: "<<pCurrent->pVariavel->nome<<pCurrent->pVariavel->valor<<endl;
        }										
		return;
	}
// checar todos os substr e tratamentos de str	
	struct Variavel* create_variavel(char nomeVar, string valorVar){          // criacao da nova variavel que ira conter nome e valor desta
		Variavel *pVariavel = NULL;
		pVariavel = (struct Variavel*)malloc(sizeof(struct Variavel)); //aloca memoria para struct dessa variavel
  		pVariavel->nome = nomeVar;
        pVariavel->valor = valorVar;
		return pVariavel;
	}
    	
     void tabela::create_node(char nome, string valor){  // criacao do novo node para conter a variavel e pNode
/*struct*/ Node *pNode = NULL;							               // ponteiro para o novo node
		pNode = (struct Node*)malloc(sizeof(struct Node));	           // aloca memoria para struct desse node		
		pNode->pNext = NULL; 
		pNode->pVariavel = create_variavel(nome, valor);			   // criar e alocar no node a variavel em si
        insert_node (pNode);
	/*	return pNode;*/
	}
	
	
	
	void tabela::cleanTabela(){                 // funcao para liberar a memoria utilizada por cada node e variavel da tabela
		pNode = pStart;
		do{
			free(pNode->pVariavel);	    	//libera o conteudo do primeiro node
			pStart = pNode;			     	// grava o endereço do primeiro node
			pNode = pNode->pNext;	      	// segue para o prox node
			free(pStart);			       	// libera o primeiro node
		} while ((pNode = pNode->pNext) != 0); // repete até chegar ao ultimo node (aonde o pNext será vazio)	
	}




