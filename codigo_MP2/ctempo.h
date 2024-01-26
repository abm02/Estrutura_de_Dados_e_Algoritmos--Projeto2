#ifndef CTEMPO_H
#define CTEMPO_H

#include <iostream>
#include <time.h>
#include <iomanip>


class CTempo
{
private:
    double segundos;

public:
    //Construtor
    CTempo () {segundos = 0.0;}

    //Método que obtém o tempo no momento exato do código
    void tempoAgora(void);
    //Método que devolve o atributo "segundos" da classe
    double devolveSegundos (void){return segundos;}
};

#endif // CTEMPO_H
