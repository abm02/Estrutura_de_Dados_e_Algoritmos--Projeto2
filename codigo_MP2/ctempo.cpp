#include "ctempo.h"

//Definição do método que obtém o tempo no momento exato do código
void CTempo :: tempoAgora(void){  //devolve no atributo segundos da classe chamada
    time_t tempo;
    struct tm tzero = {0};
    tzero.tm_hour = 0; tzero.tm_min = 0; tzero.tm_sec = 0;
    tzero.tm_year = 0; tzero.tm_mon = 0; tzero.tm_mday = 0;

    tempo = time(NULL);     //lê o tempo neste exato momento
    segundos = difftime(tempo, mktime(&tzero));
}
