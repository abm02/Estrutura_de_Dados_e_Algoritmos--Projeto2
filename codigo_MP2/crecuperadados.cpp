#include "crecuperadados.h"
#include "cficheiro.h"
#include <string>


//Definição do método que colocar todos os elementos a 0
void CRecuperaDados :: colocaAZero(void){
    palavra = "\0";
    tema = "\0";
    xx = 0;
    m4 = 0;
    oTema = 0;
    oTempo = 0;
    oLetras = 0;
    numLetrasCorretas = 0;
    numErros = 0;
    numCaracteresCorretos = 0;
    numRepeticoesLetra = 0;
    numLetrasErradas = 0;
    for (int i = 0 ; i < sizeof(LetrasCorretas) ; i++)
        LetrasCorretas[i] = '\0';
    for (int i = 0 ; i<sizeof(LetrasErradas) ; i++)
        LetrasErradas[i] = '\0';
    tempoMax = 0.0;
    tempoSobra = 0.0;
    pontos = 0.0;

}

