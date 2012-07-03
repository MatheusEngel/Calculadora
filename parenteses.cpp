#include <stdio.h>
#include <stdlib.h>
#include <string>                               
#include <iostream>                             
#include <sstream>

#include "validacao.h"
#include "calcular.h"
#include "parenteses.h"

#define ERRO_DIVISAO_POR_ZER0     1029384757

using namespace oper;
using namespace std;
using namespace parenteses;

string parenteses::parenteses(string string1)
{
       int posicao_abre;
       int posicao_fecha;
       string string_auxiliar;
       
       posicao_abre = string1.find_last_of("(",string::npos);
       posicao_fecha = string1.find_first_of(")",posicao_abre);
       
       string_auxiliar = string1.substr((posicao_abre + 1),(posicao_fecha - posicao_abre - 1));

       
       string_auxiliar = validar::validacao(string_auxiliar);
       string_auxiliar = oper::calcular(string_auxiliar);
       
       
       string1.erase(posicao_abre, (posicao_fecha - posicao_abre + 1));
       string1.insert(posicao_abre,string_auxiliar);

       
       
       if (string1[string1.size() - 1] == ';' )
          string1.erase((string1.size() - 1), 1);
          
          
       if ((string1.find_first_of("(",0)) != string::npos )
       {
          string1 = validar::validacao(string1);
          return parenteses(string1);
        
        }
        string1 = validar::validacao(string1);


        
       return oper::calcular(string1);
} 
       
