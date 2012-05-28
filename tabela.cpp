/*
 Tabela de Variaveis para o programa Calculadora
Constitui-se em dois vetores: um para conter a Variavel e a sua "posicao"; outro para conter o valor
desta Variavel
*/

#include <cstdlib>
#include <iostream>


using namespace std;

namespace tabela{
        struct Variavel{
    	 char nome;			// Nome da variavel, um caracter
    	 int valor;			// Valor desta variavel
    	};
    
    	struct Node{					// Cada variavel eh um node
    	 struct Variavel *pVariavel;	// Conteudo da variavel
    	 struct Node *pNext;			// apontando para a proxima variavel
    	};
    
        struct Node *pNode;
     //*pNode = NULL;
        struct Node *pStart;

	

	int busca_valor (char nomeVar){			//funcao para buscar o valor de uma variavel ao informar o nome desta
		int found = 0;
//		int valorVar = 0;
	
		if (pStart == NULL){			 	// caso tabela vazia, nao h� o que buscar
			printf("Variavel %c nao encontrada.\n", nomeVar);
		}	
		
		pNode = pStart;					// buscando na tabela
		while (pNode != NULL){
			if (nomeVar == (pNode->pVariavel->nome)){	// fazendo a comparacao entre nomeVar(entrada) e ->nome(tabelado)
			found = 1;
			return (pNode->pVariavel->valor);
			}
			else{
			pNode = pNode->pNext;
			}
		}	
		if(!found)
			printf("Variavel %c nao encontrada.\n", nomeVar);
	} 
	
	struct Variavel* create_variavel(char nome, int valor){          // criacao da nova variavel que ira conter nome e valor desta
		struct Variavel *pVariavel = NULL;
		pVariavel = (struct Variavel*)malloc(sizeof(struct Variavel)); //aloca memoria para struct dessa variavel
  		pVariavel->nome = nome;
        pVariavel->valor = valor;
		
		return pVariavel;
	}
    	
	struct Node* create_node(char nome, int valor){			// criacao do novo node para conter a variavel e pNode
		struct Node *pNode = NULL;							// ponteiro para o novo node
		pNode = (struct Node*)malloc(sizeof(struct Node));	// aloca memoria para struct desse node
		pNode->pNext = NULL; 
		pNode->pVariavel = create_variavel(nome, valor);				// criar e alocar no node a variavel em si
		return pNode;
	}
	
	
	void insert_node (struct Node *pNode){		//inserindo novo node a tabela
	
    	struct Node *pCurrent = NULL;
		
		if (pStart == NULL){			 // caso tabela vazia, novo node entra aqui
			pStart = pNode;
			return;
		}
		
		pCurrent = pStart;				// caso haja tabela, buscar o ultimo node
		while (pCurrent != NULL){
			pCurrent = pCurrent->pNext;
		}								// nesse ponto pCurrent==NULL, logo o node entrara aqui
		pCurrent = pNode;
		return;
	}
	
	
	void cleanTabela(){                 // funcao para liberar a memoria utilizada por cada node e variavel da tabela
		pNode = pStart;
		do{
			free(pNode->pVariavel);	    	//libera o conteudo do primeiro node
			pStart = pNode;			     	// grava o endere�o do primeiro node
			pNode = pNode->pNext;	      	// segue para o prox node
			free(pStart);			       	// libera o primeiro node
		} while ((pNode = pNode->pNext) != 0); // repete at� chegar ao ultimo node (aonde o pNext ser� vazio)	
	}

}



