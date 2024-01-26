#include <random>
#include "cpalavra.h"
#include "cficheiro.h"


int NumAleatorioComPonderacao(int tabN[], int tam){
    default_random_engine generator;
    //Definir os pesos de cada palavra
    vector<int> weights;
    for(int i1=0; i1<tam; ++i1){
        for(int i2 = 0 ; i2<tabN[i1] ; i2++)
            weights.push_back(i1);
    }

    // Criar uma distribuição com esses pesos
    discrete_distribution<> distribution(weights.begin(), weights.end());

    int num = distribution(generator)+1; //gerar um número aleatório tendo em conta esses pesos
    return (num);
}


//Definição do método que escolhe ateatoriamente uma das palavras
bool CPalavra :: escolhePalavra(void){
    string aux;
    char nomeFicheiro[] = "TemasEPalavras.txt";
    CFicheiro f(nomeFicheiro);
    int nT = f.numTemas();
    int nAleatorioT = rand() % nT;       //gera aleatroriamente o tema (um número para o seu indíce)
    int nP = f.numPalavrasDeTema(nAleatorioT);
    int nAleatorioP = rand() % nP;       //gera aleatroriamente a palavra (um número para o seu indíce)

    if((nT != -1) && (nP != -1)){
        aux = f.devolvePalavra(nAleatorioT, nAleatorioP);
        aux.erase (0,10);   //apaga os primeiros 10 caracteres da string, pq os espaços que existem no ficheiro
        strcpy(palavra, aux.c_str());
        aux = f.devolveTema(nAleatorioT);
        strcpy(tema, aux.c_str());
        return (true);
    }
    else
        return (false);
}

//Definição do método que escolhe ateatoriamente uma das palavras de um dado tema
bool CPalavra :: escolhePalavraDeTema(int t){
    string aux;
    char nomeFicheiro[] = "TemasEPalavras.txt";
    CFicheiro f(nomeFicheiro);
    int nT = f.numTemas();
    if(t < nT){
        int nP = f.numPalavrasDeTema(t);
        int nAleatorioP = rand() % nP;       //gera aleatroriamente a palavra (um número para o seu indíce)
        if((nT != -1) && (nP != -1)){
            aux = f.devolvePalavra(t, nAleatorioP);
            aux.erase (0,10);   //apaga os primeiros 10 caracteres da string, pq os espaços que existem no ficheiro
            strcpy(palavra, aux.c_str());
            aux = f.devolveTema(t);
            strcpy(tema, aux.c_str());
            return (true);
        }
        else
            return (false);
    }
    else
        return (false);
}

//Definição do método que escolhe a palavra tendo em conta a probabilidade desta sair
bool CPalavra :: escolhePalavraComProbabilidade(){
    char nomeFicheiro[] = "PalavrasAnteriores.txt", nomeFicheiro2[] = "TemasEPalavras.txt";
    CFicheiro f(nomeFicheiro), f2(nomeFicheiro2);;
    int numP, numA, ind;
    bool b;
    string aux;

    numP = f.devolveNumPalavrasDiferentes();
    int tabela[numP+1];
    string tabelaPalavras[numP+1];

    b = f.devolveNumRepeticoesCadaPalavra(tabela, tabelaPalavras, numP);
    if (b == false)
        return (false);

    numA = NumAleatorioComPonderacao(tabela, numP);
    ind = f2.descobreIndiceTema(tabelaPalavras[numA-1]);
    if (ind == -1)
        return (false);

    aux = f2.devolveTema(ind-1);
    strcpy(palavra, tabelaPalavras[numA-1].c_str());
    strcpy(tema, aux.c_str());
    return (true);
}

//Definição do método para imprimir no ecrã a palavra, apenas com as letras já descobretas
void CPalavra :: imprimePalavraDescoberta(const char letrasdescobertas[], const int n){
    for (int i=0 ; i<numletras ; i++){
        bool descoberta = false;
        for (int j=0 ; j<n ; j++){
            if (palavra[i] == letrasdescobertas[j])
                descoberta = true;
        }
        if (descoberta == true)
            cout << palavra[i] << " ";
        else
            cout << "__ ";
    }
}

//Definição do método que verifica se uma letra se encontra na palavra definida, ou não
int CPalavra :: procuraLetra(char ch){
    int num = 0;
    for (int i=0 ; i<numletras ; i++){
        if (palavra[i] == ch)
            num = num + 1;
    }
    return (num);
}

//Definição do método que define o tempo máximo para o jogador adivinhar a palavra
double CPalavra :: defineTempoMax(int dif){
    switch (dif){
    case 0:    //0 - nível de dificuldade = fácil
        return (numletras * 100 / 15.0);
        break;
    case 1:
        return (numletras * 100 / 25.0);
        break;
    case 2:
        return (numletras * 100 / 30.0);
        break;
    default:
        return (0.0);
    }
}

//Definição do método que atribui a pontuação para uma ronda do jogo
double CPalavra :: atruibuiPontos(double t, double tmax, int numErros, int mod){
    switch (mod){
    case 0:    //sem contagem de tempo
        return (50 - 5*numErros);
    case 1:{    //com contagem de tempo
        if (t<tmax)
            return (150 - t - 5*numErros);
        break;}
    }
    return (0);
}
