#include <stdio.h>
#include <stdlib.h>
#include <string>                               
#include <iostream>                             
#include <sstream>

#include "validacao.h"
#include "calcular.h"
#include "interface.h"
#include "tabela.h"
#include "parenteses.h"

#define ERRO_DIVISAO_POR_ZER0     1029384757
#define VARS "abcdefghijklmnoprstuvxyz"

using namespace std;
using namespace parenteses;
using namespace tabela;

int main(void)
{
int i;

    string s = "0";
    string quit = "0+:q;";
    unsigned n,aux;
    string *expressoes;
    double aux_to_string;
    
    cout << "CLC2012/1 v2.7" << endl << endl;
    cout << "Calculadora em linha de comando desenvolvida pelos alunos: ";
    cout << "Heron Silva, Matheus Engel, Rafael Estevam, Tiago Monteiro e Vitor Tavares."<< endl;
    cout << "Orientada pelo professor Leonardo Nunes." << endl;
    cout << "Ela realiza as seguintes operacoes: " << endl << endl << endl;
    cout << "           Adicao -> operador + ;" << endl;
    cout << "           Subtracao -> operador - ;" << endl;
    cout << "           Multiplicacao -> operador * ;" << endl;
    cout << "           Divisao -> operador / ;" << endl;
    cout << "           Atribuicao -> operador = ;" << endl << endl;
    cout << "Parenteses podem ser utilizados." << endl;  
    cout << "Equacoes devem sempre ser finalizadas por ';'" << endl;      
    cout << "Para fechar o programa, digite "":q ." << endl << endl << endl;


    while (s.compare(quit) != 0 )
    {
    cout <<"Descreva a equacao a ser resolvida"<<endl;
    getline (cin,s);

    //Insere '0+' no começo da string para evitar problemas com o cálculo dos parênteses
    s.insert(0, "0+");
    if (s.size() != 0  &&  s[s.size()- 1] != ';')
               s.insert(s.size(),";"); 
    
    s = validar::validacao(s);
    if (s.compare("Erro_parenteses") == 0 )
    {
         cout << "Erro na leitura dos parenteses, por favor, certifique-se de que a equacao foi digitada corretamente." << endl;
    }
    
    n = contarSeparador(s);
    
    
    // inicio edicao Rafael                  substituir variaveis aqui. "s" é a string inserida pelo usuario
    
string valor;
size_t found = 0;
  found=s.find_first_of(VARS);	             //busca qualquer variavel na string
  while (found!=string::npos)	             // enquanto houver alguma variavel
  {       
	if (s[found+1] == '=') {        //caso variavel seguida por "=", incluir variavel
    int fim =0;
    fim = s.find_first_of(";",(found+1));   
    
    valor = s.substr( (found+2), (fim-(found+2)) );// valor estara entre (found+1) e 
    valor.erase((valor.length()-1), 0); //apagando o ";" no final do valora
cout<<s[found]<<valor<<endl;
    tabela::create_node(s[found],valor);    // variavel criada     
    cout<< "Variavel >" <<s[found]<<"< criada. "<<tabela::busca_valor(s[found])<<endl;    
	}        
   
   else{                          //senao, substituir variaveis na expressao                                         
            valor = tabela::busca_valor(s[found]);  //substituir o s[found] pelo valor da variavel "a+1"->"99+1"         
            s.erase(found, 1);            // apaga a variavel
            s.insert(found, valor);       // insere o valor da variavel na found em que ela estava          
         }	
	found=s.find_first_of(VARS,found+1);
		
  }
  int counter =0; counter++; ;
    
// fim edicao Rafael  
    
    expressoes = new string[n];    
    separarExpressao (s,expressoes);
    
       
    
    if (s.compare(quit) != 0)
    {
      
                                 
       if (s.find_first_of(";",0) == string::npos )
              cout << "O resultado da equacao e: " << s << " = " << oper::calcular(s) << endl;
       else
       {
           for (aux = 0; aux < n; aux++)
           {   
               if (s.compare(expressoes[aux]) != 0 )
               { 
                   if ((expressoes[aux].find_first_of("(",0)) != string::npos )
                   {                    
                        expressoes[aux] = parenteses::parenteses(expressoes[aux]);  
                        if (expressoes[aux] == "Nao e possivel realizar a operacao")    
                               return 0;                 
                        cout << "Expressao[" << (aux+1) << "] = " << expressoes[aux] << endl;
                   } 
                   else
                   {
                       expressoes[aux] = oper::calcular(expressoes[aux]);
                       if (expressoes[aux] == "Nao e possivel realizar a operacao") 
                          return 0;
                          
                        cout << "Expressao[" << (aux+1) << "] = " << expressoes[aux] << endl;
                   }

               }
                else
                        cout << "O resultado das equacoes sao: " << expressoes[aux] << " = " << oper::calcular(expressoes[aux]) << endl;                     

            }
       }
     }
  }    
           free(expressoes);  
           return 0;
}
		
