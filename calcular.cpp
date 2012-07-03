#include <stdio.h>
#include <stdlib.h>
#include <string>                               
#include <iostream>                             
#include <sstream>

#define ERRO_DIVISAO_POR_ZER0     1029384757

#include "calcular.h"
#include "validacao.h"

using namespace std;
using namespace oper;

double oper::operacao_subtracao(string string_auxiliar,int comeco_string,int posicao,int fim_string)
{
       // Recebe os valores da funcao calcular() e transforma para double para processá-los
       istringstream st(string_auxiliar.substr(comeco_string,(posicao- comeco_string)));
       double op1,op2,resultado;
       
       // Separa já na aquisição os valores antes e depois do sinal para realizar a operacao
       st >> op1;
       
       
       // Recebe os valores da funcao calcular() e transforma para double para processá-los
       istringstream st2(string_auxiliar.substr(posicao+1,(fim_string - posicao)));
       
       // Separa já na aquisição os valores antes e depois do sinal para realizar a operacao
       st2 >> op2;
       
       return (op1-op2);
}




double oper::operacao_soma(string string_auxiliar,int comeco_string,int posicao,int fim_string)
{      // Tratamento para o caso de numeros negativos enviados á operação
       
       if (string_auxiliar[0] == '@')
       {  
           comeco_string = comeco_string + 1;
           istringstream st(string_auxiliar.substr(comeco_string,(posicao- comeco_string)));
           double op1,op2,resultado;
           int negativos = 0;
           
           st >> op1;
           
           istringstream st2(string_auxiliar.substr(posicao+1,(fim_string - posicao)));
           
           st2 >> op2;
           if (op1 == op2)
              return(op1-op2);
           else
           if (op1 > op2)  
           { 
                   negativos++;
                   resultado = op1;
                   op1 = op2;
                   op2 = resultado;
                   return  (op1 - op2);
           }
           else
           if (op2 > op1)
              return (op2 - op1);         
       }
       else
       if ( string_auxiliar[0] != '@' )
       {
                
           istringstream st(string_auxiliar.substr(comeco_string,(posicao- comeco_string)));
           double op1,op2,resultado;
           
           st >> op1;
           
           istringstream st2(string_auxiliar.substr(posicao+1,(fim_string - posicao)));
           
           st2 >> op2;
           return (op1+op2);
       }

}


double oper::operacao_multiplicacao(string string_auxiliar,int comeco_string,int posicao,int fim_string)
{
       istringstream st(string_auxiliar.substr(comeco_string,(posicao- comeco_string)));
       double op1,op2,resultado;
       
       st >> op1;
       
       
       istringstream st2(string_auxiliar.substr(posicao+1,(fim_string - posicao)));
       
       st2 >> op2;
       return (op1*op2);
}


double oper::operacao_divisao(string string_auxiliar,int comeco_string,int posicao,int fim_string)
{
       
       istringstream st(string_auxiliar.substr(comeco_string,(posicao - comeco_string)));
       double op1,op2,resultado;
       
       st >> op1;
       
       istringstream st2(string_auxiliar.substr(posicao+1,(fim_string-posicao)));
       
       st2 >> op2;
       
       if (op2 == 0)
       {
          cout << "Nao e possivel realizar divisao por zero, o programa nao retornara solucao" << endl;
          return (0);
       }
       return (op1/op2);
}

string oper::calcular(string s)
{
    int i,tamanho,j,k;
    int comeco_string =-1;
    int fim_string= (s.size()-1);
    double result;
    string string_auxiliar;
    string s2; 
    int loop;
    
    
    tamanho = (s.length());
    
    // Procura pelos operadores, na ordem de prioridade
	if (s.find_first_of("/",0) != string::npos) 
	{
       i = s.find_first_of("/",0);
       // Varre decrescentemente procurando por um operador para separarmos apenas a equacao desejada
    	if (s.find_last_of("*/+-",i-1) != string::npos) 
    	{
    		comeco_string = (s.find_last_of("*/+-",i-1) + 1);
        }	
        else
        comeco_string = 0; // Caso nao encontrado, o começo da string acontece na posicao 0

        // Varre crescentemente procurando por um operador para separarmos apenas a equacao desejada
    	if (s.find_first_of("*/+-",i+1) != string::npos)
    	{
                                                                                
        	fim_string = (s.find_first_of("*/+-",i+1)-1);
         }
         
         
         // Separando a parte da string que nos interessa para realizar a operação
         string_auxiliar = s.substr(comeco_string,(fim_string - comeco_string +1));         
     
         // Dados importantes para os cálculos a seguir
         int tamanho_aux;
          tamanho_aux = (string_auxiliar.length());
          int comeco_string_aux = 0;
          int fim_string_aux = (string_auxiliar.length()-1);
          int j,opp;
          int negativos = 0;
         
         opp = string_auxiliar.find_first_of("@",0);
         
         if (opp != string::npos)
         {
             if ( opp == 0 )
             { 
                  string_auxiliar.erase(opp,1);
                  negativos = negativos + 1;  
                   
             }
             opp = string_auxiliar.find_first_of("@",(opp));
             if (opp != string::npos )
             {
                  string_auxiliar.erase((opp),1);
                  negativos = negativos + 1;
             }

         }
          
          
          
         j = string_auxiliar.find_first_of("/",0);         
         
         // Recebe os dados das funcoes auxiliares de operacao já convertendo pra string
         ostringstream st;
         st << fixed << operacao_divisao(string_auxiliar,comeco_string_aux,j,fim_string_aux);
      
         // Como a funcao operacao_divisao retorna um inteiro, defini um número improvavel para marcar o erro de divisao por zero
         if ( st.str() == "0" )
            return "Nao e possivel realizar a operacao";

         //Zera a string com a operacao para que adicionemos a ela o resultado final da mesma 
         string_auxiliar.clear(); 
         string_auxiliar.insert(0,st.str());
  
         if (negativos == 1 )         
            string_auxiliar.insert(0,"-"); 
         // A equacao resolvida é apagada da string e o seu resultado é inserido na mesma posicao
         s.erase(comeco_string, (fim_string - comeco_string + 1));
         s.insert(comeco_string,string_auxiliar);
         
         string string_aux;
         i = 0;
         s = validar::validacao(s);
            // Procura por outra operacao, senão, retorna o valor da string já calculada    
         	if (s.find_first_of("*/+-",0) == string::npos)
            {
               if (negativos == 1 )
               { 
                  i = s.find_first_of("@",0);
                  s[i] = '-';
               }              
            return s;
            }          
            else
            {
		        string_aux = calcular(s);
            }
		       

        return string_aux;
    }
    // Realiza os mesmos passos descritos acima para as outras operacoes
	else
    	  if (s.find_first_of("*",0) != string::npos)
          {
		     	i = s.find_first_of("*",0);
		     	
		     	
	     		if (s.find_last_of("*/+-",i-1) != string::npos) 
            	{
            		comeco_string = (s.find_last_of("*/+-",i-1)+1);
                }	
                else
                comeco_string = 0;
                	
                	
            	if (s.find_first_of("*/+-",i+1) != string::npos)
            	{
                	fim_string = (s.find_first_of("*/+-",i+1) - 1);
                 }	

		         
                 string_auxiliar = s.substr(comeco_string,(fim_string - comeco_string + 1));

                 

                 int tamanho_aux;
                     tamanho_aux = (string_auxiliar.length());
                 int comeco_string_aux = 0;
                 int fim_string_aux = (string_auxiliar.length()-1);
                 int j = 0;
                 int opp;
                 int negativos = 0;
                 
                 opp = string_auxiliar.find_first_of("@",0);
                 
                 if (opp != string::npos)
                 {
                     if ( opp == 0 )
                     { 
                          string_auxiliar.erase(opp,1);
                          negativos = negativos + 1;  
                           
                     }
                     opp = string_auxiliar.find_first_of("@",(opp));
                     if (opp != string::npos )
                     {
                          string_auxiliar.erase((opp),1);
                          negativos = negativos + 1;
                     }
        
                 }
                 
                 j = string_auxiliar.find_first_of("*",0);         
         
         
                 ostringstream st;
                 st << fixed << operacao_multiplicacao(string_auxiliar,comeco_string_aux,j,fim_string_aux);
                             
                             
                 string_auxiliar.clear();   
                 string_auxiliar.insert(0,st.str());
                 
                 if (negativos == 1 )         
                               string_auxiliar.insert(0,"-"); 
                            
                 s.erase(comeco_string,(fim_string - comeco_string + 1));
                 s.insert(comeco_string,string_auxiliar);
                             
                 string string_aux;
                 i = 0;
                 s = validar::validacao(s);       
                 if (s.find_first_of("*/+-",0) == string::npos)
                 {
                    if (negativos == 1 )
                    { 
                    i = s.find_first_of("@",0);
                    s[i] = '-';
                    }  
                    return s;
                 }
                 else
		             string_aux = calcular(s);
	
	

                 return string_aux;
          }
          // Para soma e subtração, existe a prioridade da primeira ocorrência
          int id;
          id = s.find_first_of("+-",0);  
		
     			if (s[id] == '+')
                {
        				i = s.find_first_of("+",0);
        				
                    	if (s.find_last_of("*/+-",i-1) != string::npos) 
                    	{
                    		comeco_string = (s.find_last_of("*/+-",i-1) + 1);
                        }	
                        else
                             comeco_string = 0;
                    		
                    	if (s.find_first_of("*/+-",i+1) != string::npos)
                    	{
                        	fim_string = (s.find_first_of("*/+-",i+1) - 1);
                         }	
                         string_auxiliar = s.substr(comeco_string,(fim_string - comeco_string + 1));
                        
                         int tamanho_aux;
                             tamanho_aux = (string_auxiliar.length());
                         int comeco_string_aux = 0;
                         int fim_string_aux = (string_auxiliar.length()-1);
                         int opp,negativos;
                         double op1,op2,aux;
                         
                        negativos = 0;
		                     if (s[0] == '@' )
		                     {
                                negativos++;
                                comeco_string = 1;
                             } 


                         ostringstream st;
                         st << fixed << operacao_soma(string_auxiliar,comeco_string_aux,i,fim_string_aux);
                         
                         //cout << st.str() << endl;
                         
                         string_auxiliar.clear();
                         string_auxiliar.insert(0,st.str());
                         
                         
                         
                         if (negativos == 1)
                            comeco_string = 0;
                            
                            s.erase(comeco_string, (fim_string - comeco_string + 1));
                            s.insert((comeco_string ),string_auxiliar);
                         
                         string string_aux;
                         i = 0;
                         s = validar::validacao(s);
                 
                         if (s.find_first_of("*/+-",0) == string::npos)
                         {
                            if (s.find_first_of("@",0) != string::npos ) //&& negativos ==
                            { 
                            i = s.find_first_of("@",0);
                            s[i] = '-';
                            } 
                            return s;
                         }
                         else
        		             string_aux = calcular(s);
        	
        	
        
               return string_aux;
}
			    else
                    if (s[id] == '-')
				    {
                       	   i = s.find_first_of("-",0);
                        	if (s.find_last_of("*/+-",i-1) != string::npos) 
                        	{
                        		comeco_string = (s.find_last_of("*/+-",i-1) + 1);
                            }	
                            else
                            comeco_string = 0;
                            
                            		
                        	if (s.find_first_of("*/+-",i+1) != string::npos)
                        	{
                            	fim_string = (s.find_first_of("*/+-",i+1)- 1);
                             }
                      
                         // Modificações
                         int negativos = 0;
                         
		                     if (s[0] == '@' )
		                     {
                                negativos++;
                                comeco_string = 1;
                                int position = s.find_first_of("-",0);
                                s[position] = '+';
                             } 
                             string_auxiliar = s.substr(comeco_string,(fim_string - comeco_string + 1));
                         
                             
                             int tamanho_aux;
                                 tamanho_aux = (string_auxiliar.length());
                             int comeco_string_aux = 0;
                             int fim_string_aux = (string_auxiliar.length()-1);
                             int j;
                             
                            // comeco_string_aux = comeco_string;
                             if ( ( string_auxiliar.find_first_of("-",0) ) != string::npos )
                             {
                                 j = s.find_first_of("-",0);
                                 
                                 ostringstream st;
                                 st << fixed << operacao_subtracao(string_auxiliar,comeco_string_aux,j,fim_string_aux);
                                 

                                 if (negativos == 1 )         
                                     string_auxiliar.insert(0,"-"); 

                                 string_auxiliar.clear();
                                 string_auxiliar.insert(0,st.str());
                             }
                             else
                             if ( ( string_auxiliar.find_first_of("+",0) ) != string::npos )
                             {

                                 j = string_auxiliar.find_first_of("+",0);
                          

                         
                                 ostringstream st;
                                 st << fixed << operacao_soma(string_auxiliar,comeco_string_aux,j,fim_string_aux);
                                
                         
                                 string_auxiliar.clear();
                                 string_auxiliar.insert(0,st.str());
                             }
                         
                            if (negativos == 1 )         
                               string_auxiliar.insert(0,"-"); 
                               comeco_string = 0;
                         
                               
                             s.erase(comeco_string, (fim_string - comeco_string  + 1));
                             s.insert(comeco_string,string_auxiliar);
                                                         
                             string string_aux;

                             i = 0;
                              s = validar::validacao(s);
                         
                             if (s.find_first_of("@",0) != string::npos )
                                    negativos = 1;
                                    
                             if (s.find_first_of("*/+-",0) == string::npos)
                             {
                                if (negativos == 1 )
                                { 
                                    i = s.find_first_of("@",0);
                                    s[i] = '-';
                                }  
                                return s;
                             }
                             else
            		             string_aux = calcular(s);
                             
                             return string_aux;		
                        }
}


