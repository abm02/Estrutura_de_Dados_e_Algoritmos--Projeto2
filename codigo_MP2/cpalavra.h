#ifndef CPALAVRA_H
#define CPALAVRA_H

#include <iostream>
#include <string.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class CPalavra
{
private:
    char palavra[15];
    int numletras;
    char tema[10];

public:
    //Construtores
    CPalavra(int t){
        bool aux;
        if (t == -1){   //Tema aleatório
            aux = escolhePalavra();
            if (aux == false)
                numletras = -1;
            else
                numletras = strlen(palavra);
        }
        else if (t == -5){  //Tema escolhido com probabilidades
            aux = escolhePalavraComProbabilidade();
            if (aux == false)
                numletras = -1;
            else
                numletras = strlen(palavra);
        }

        else {      //Tema definido
            aux = escolhePalavraDeTema(t);
            if (aux == false)
                numletras = -1;
            else
                numletras = strlen(palavra);}
    }

    //Método que define o tema e a palavra passados como strings
    void definePalavraETema(string p, string t){
        strcpy(palavra, p.c_str());
        strcpy(tema, t.c_str());
        numletras = strlen(palavra);
    }
    //Método que escolhe ateatoriamente uma das palavras
    bool escolhePalavra(void);
    //Método que escolhe ateatoriamente uma das palavras de um dado tema
    bool escolhePalavraDeTema(int t);
    //Método que escolhe a palavra tendo em conta a probabilidade desta sair
    bool escolhePalavraComProbabilidade();
    //Método para imprimir no ecrã a palavra, apenas com as letras já descobretas
    void imprimePalavraDescoberta(const char letrasdescobertas[], const int n);
            //letrasdescobertas -> array com todas as letras que já foram adivinhadas até ao momento
            //n -> inteiro com o número de letras descobertas
    //Método que imprime o tema
    void imprimeTema(void) {cout << tema;}
    //Método que devolve o número de letras da palavra
    int devolveNumLetras(void) {return (numletras);}
    //Método que devolve a palavra
    string devolvePalavra (void) {
        string aux = palavra;
        return (aux);}
    //Método que devolve o tema
    string devolveTema (void) {
        string aux = tema;
        return (aux);}
    //Método que verifica se uma letra se encontra na palavra definida, ou não
    int procuraLetra(char ch);
    //Método que define o tempo máximo para o jogador adivinhar a palavra
    double defineTempoMax(int dif);
        //dif é a constante para o valor de dificuldade
        //devolve o valor em segundos
    //Método que atribui a pontuação para uma ronda do jogo
    double atruibuiPontos(double t, double tmax, int numErros, int mod);
};

#endif // CPALAVRA_H
