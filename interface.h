/*

Universidade Federal do Rio de Janeiro
Escola Politecnica
Departamento de Eletronica e de Computacao
EEL670 - Linguagens de Programacao - Turma 2012/1
Prof. Leonardo de Oliveira Nunes

Autores: Héron Silva, Matheus Engel, Rafael Estevam, Tiago Monteiro e Vitor Tavares
DREs: 
Data: 28/05/12
Descricao: Arquivo de cabecalho das funcoes auxiliares do modulo de interface
           
*/

#ifndef INTERFACE_H
#define INTERFACE_H

// DECLARACAO DAS BIBLIOTECAS

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

// DECLARACAO DAS FUNCOES AUXILIARES

string char2string (char);

void instruirUsuario (void);

string receberExpressao (void);

unsigned contarSeparador (string);

void separarExpressao (string, string *);

void exibirResultado (double);

#endif
