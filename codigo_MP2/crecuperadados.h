#ifndef CRECUPERADADOS_H
#define CRECUPERADADOS_H
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

class CRecuperaDados
{
public:
    string palavra, tema;
    int xx, m4, oTema, oTempo, oLetras, numLetrasCorretas, numErros, numCaracteresCorretos, numRepeticoesLetra, numLetrasErradas;
    char LetrasCorretas[27], LetrasErradas[27];
    double tempoMax, tempoSobra, pontos;

    //Construtor
    CRecuperaDados() {colocaAZero();}

    //Método que colocar todos os elementos a 0
    void colocaAZero(void);
};

#endif // CRECUPERADADOS_H
