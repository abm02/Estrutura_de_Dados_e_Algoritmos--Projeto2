#ifndef CFICHEIRO_H
#define CFICHEIRO_H

#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <iomanip>
#include "crecuperadados.h"
using namespace std;


using namespace std;
const int NUM = 50;

class CFicheiro
{
private:
char nome[NUM];

public:
//Construtor
CFicheiro (char tab[]) {strcpy(nome, tab);}

//Método que guarda os pontos do jogador
bool leEescreveFicheiros (string nomeUtilizador, double pontos);
//Método que lê do ficheiro os pontos e os nomes dos jogadores
bool leFicheiroNomesEPontos(void);
//Método que conta o número de temasque existe num ficheiro
int numTemas(void);
//Método que conta o número de palavras do tema de índice i
int numPalavrasDeTema(int t);
//Método que devolve o tema de índice t
string devolveTema(int t);
//Método que devolve a palavra de índice p do tema índice t
string devolvePalavra(int p, int t);
//Método que escreve no ecrã todos os temas que existem no ficheiro
bool escreveTemas(void);
//Método que escreve no ecrã todas as palavras de um tema de índice t
bool escrevePalavras(int t);
//Método que permite inserir um tema novo no ficheiro
bool insereTemaNovo(int num);
//Método que permite eliminar um tema inteiro
bool eliminaTema(int ind);
//Método que elimina a palavra de índice p do tema índice t
bool eliminaPalavra(int p, int t);
//Método que acrescenta uma palavra no tema de índice t
bool inserePalavra(int t);
//Método que escreve todos os dados do jogo
bool escreveDadosJogo (CRecuperaDados &p);
//Método que lê todos os dados do jogo
bool leDadosJogo (CRecuperaDados &p);
//Método que devolve o número de palavras diferentes que nele existem
int devolveNumPalavrasDiferentes(void);
//Método que devolve o número de vezes que cada palavra é lida numa tabela de inteiros, e a ordem das palavras correspondentes numa tabela de strings
bool devolveNumRepeticoesCadaPalavra (int tab[], string tab2[], int tam);
//Método que descobre qual o índice do tema a que uma palavra pertence
int descobreIndiceTema(string palavra);
//Método que escreve uma palavra no ficheiro da palavras para as probabilidade
bool escrevePalavraParaProbabilidade(string palavra);
//Método que elimina todos os dados do ficheiro com as palavras que já saíram
bool eliminaFicheiroProb(void);
//Método que elimina todas as repetições num dado ficheiro da palavra passada como argumento
bool eliminaPalavraFicheiroProb(string palavra);
};

#endif // CFICHEIRO_H
