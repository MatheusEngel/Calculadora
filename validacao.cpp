#include <stdio.h>
#include <stdlib.h>
#include <string>                               
#include <iostream>                             
#include <sstream>

#define ERRO_DIVISAO_POR_ZER0     1029384757
#define ERRO_POSICAO_SINAL        "Erro"
#define ERRO_POSICAO_SINAL_INT    2

#include "validacao.h"
#include "tabelaOK.h"


using namespace std;
using namespace validar;

string validar::validacao (string entrada)
{
int posicao_partida = 0;
int posicao_operador;
int posicao_abre_parenteses;
int posicao_erro;
    
       // Recebe a equacao
       string string_auxiliar = entrada;
       

        // Apaga os espaços
       	while (entrada.find(' ',0) != string::npos)
	    	entrada.erase( entrada.find(' ',0), 1);
	    entrada = entrada;
       

/*        //Testar a string para o mau uso do operador '='
       	if (entrada.find('=',0) != string::npos)
	    {
                   cout<<"Digite alguma variavel para ser armazenada"<<endl;
		           return ERRO_POSICAO_SINAL;
	    }
  */     



 




       // Testa para o mau uso dos operadores matemáticos
       if (entrada[0] ==  '*' ||  entrada[0] == '/' )
       {
                      cout << "A equacao nao deve comecar pelos operadores '*' ou '/'. Por favor, reescreva a equacao." << endl;
                      return ERRO_POSICAO_SINAL;
       }
       
       if(entrada[entrada.size()-2] == ('*' ||  '/' || '+' || '-' ))
       {
                      cout << "Certifique-se de estar escrevendo a equacao corretamente, ela nao deve ser finalizada por nenhum operador." << endl;   
                      return ERRO_POSICAO_SINAL;
       }
       
                   
       // Testa para erro de posicionamento (sinal negativo antecedendo fecha parenteses)
       posicao_erro = string_auxiliar.find_first_of(")",0);
       if (string_auxiliar[posicao_erro - 1] == '-')
          return ERRO_POSICAO_SINAL;

      

        // Procura por sinais positivos e se o sucessor for um sinal de subtracao, o sinal negativo irá sobressair
       posicao_operador = string_auxiliar.find_first_of("+",0);

       
       while (posicao_operador != string::npos)
       {
             if(string_auxiliar[posicao_operador + 1] == '-')
                                   return string_auxiliar.erase( (posicao_operador),1);
             else
             if (string_auxiliar[posicao_operador - 1] == '-')
                                                 return string_auxiliar.erase( (posicao_operador),1);
             else
                 posicao_operador = string_auxiliar.find_first_of("+", posicao_operador + 1);
       }
       posicao_operador = 0;
       
       // Procura por sinais negativos e se o sucessor for outro negativo, o resultado vira um positivo
       posicao_operador = string_auxiliar.find_first_of("-",0);
       
       while (posicao_operador != string::npos)
       {
             if (string_auxiliar[posicao_operador + 1] == '-' )
             {
                string_auxiliar[posicao_operador] = '+' ;
                return string_auxiliar.erase( (posicao_operador + 1), 1);
             }
             else
                 posicao_operador = string_auxiliar.find_first_of("-",posicao_operador + 2);
       }          

       //Procura por sinais negativos na primeira posicao da string
       if (string_auxiliar[0] == '-' )
       {                      
                // @ foi o caracter selecionado para indicar um numero negativo
                string_auxiliar[0] = '@';                       
       }
       
     
       
       // Procura por sinais negativos logo após sinais de outras operacoes
       posicao_operador = string_auxiliar.find_first_of("/*+-",posicao_partida);

       
       while (posicao_operador != string::npos )
       {
       if( string_auxiliar[posicao_operador + 1] == '-' )
       {
                    string_auxiliar[posicao_operador + 1] = '@';                                                                    
       }     
       else
                    posicao_operador = string_auxiliar.find_first_of("/*+-", posicao_operador + 1);
                    
       }
       
       //Procura por sinais negativos logo após o abre parenteses
       posicao_abre_parenteses = string_auxiliar.find_first_of("(",0) ;
       
       while (posicao_abre_parenteses != string::npos )
       {
             if (string_auxiliar[posicao_abre_parenteses + 1] == '-' )
             {
                string_auxiliar[posicao_abre_parenteses + 1] = '@';
             }
             else
                 posicao_abre_parenteses = string_auxiliar.find_first_of("(", posicao_abre_parenteses + 1);
       } 
       
       return string_auxiliar;
}


