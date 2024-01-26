#include <iostream>
#include <string.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <random>

#include "cficheiro.h"
#include "cpalavra.h"
#include "ctempo.h"
#include "crecuperadados.h"

using namespace std;
//---------------FORCA------------------------------------------------------------------------------------
void desenhaForca(int erros){
    switch (erros){
    case 0:{
        cout << "\n";
        break;}
    case 1:{
        cout << "\n\n\n\n\n\n\n\n\n\n\n";
        cout << "-------------" << endl;
        break;}
    case 2:{
        cout << endl;
        cout << "     |  /" << endl;
        cout << "     | /" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    case 3:{
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "     |  /             |" << endl;
        cout << "     | /              |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    case 4:{
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "     |  /             |" << endl;
        cout << "     | /              |" << endl;
        cout << "     |                O" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    case 5:{
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "     |  /             |" << endl;
        cout << "     | /              |" << endl;
        cout << "     |                O" << endl;
        cout << "     |                |" << endl;
        cout << "     |                |" << endl;
        cout << "     |                |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    case 6:{
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "     |  /             |" << endl;
        cout << "     | /              |" << endl;
        cout << "     |                O" << endl;
        cout << "     |                |" << endl;
        cout << "     |            ----|" << endl;
        cout << "     |                |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    case 7:{
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "     |  /             |" << endl;
        cout << "     | /              |" << endl;
        cout << "     |                O" << endl;
        cout << "     |                |" << endl;
        cout << "     |            ----|----" << endl;
        cout << "     |                |" << endl;
        cout << "     |" << endl;
        cout << "     |" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    case 8:{
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "     |  /             |" << endl;
        cout << "     | /              |" << endl;
        cout << "     |                O" << endl;
        cout << "     |                |" << endl;
        cout << "     |            ----|----" << endl;
        cout << "     |                |" << endl;
        cout << "     |               /" << endl;
        cout << "     |              /" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    case 9:{
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "     |  /             |" << endl;
        cout << "     | /              |" << endl;
        cout << "     |                O" << endl;
        cout << "     |                |" << endl;
        cout << "     |            ----|----" << endl;
        cout << "     |                |" << endl;
        cout << "     |               / \\" << endl;
        cout << "     |              /   \\" << endl;
        cout << "     |"<< endl;
        cout << "     |"<< endl;
        cout << "-------------" << endl;
        break;}
    }
}

//---------------Funções Variadas------------------------------------------------------------------------------------
bool procuraLetranoArray(char tab[], char c, int n){
    //Recebe uma letra e vê se a letra está no array tab ou não
    for (int i = 0 ; i < n ; i++)
        if (tab[i] == c)
            return (true);
    return (false);
}

int mudaTemas (int m4){
/* return (-1) == terminar o programa com -1
 * return (1) == goto erroFicheiro
 * return (2) == goto MENU
 * return (3) === goto opcaoInvalida;
 * return (4) == continua o jogo no mesmo local
*/
    int c1, c2, cAux, cAux2;
    string cs;
    bool aux;
    char f2[] = "TemasEPalavras.txt";
    CFicheiro FTemasEPalavras(f2);

    cout << "\nCONFIGURAR TEMAS E PALAVRAS POR TEMA: \n1 - Inserir novo tema \n2 - Modificar tema existente \n3 - Apagar tema existente \n";
    cin >> c1;
    switch (c1){
    case 1:{    // 1 - Inserir novo tema
        cout << "\nQuantas palavras pretende inserir no novo tema?\n";
        cin >> cAux;
        if (cAux < 8){
            cout << "Nao foi possivel criar o novo tema.\n\n";
            return (-1);
        }
        else{
            aux = FTemasEPalavras.insereTemaNovo(cAux);
            if (aux == false)
                return (1);
            else{
                if (m4 == 4)
                    return (4);
                else
                    return (2);
            }
        }}
    case 2:{    //2 - Modificar tema existente
        cout << "\nMODIFICAR TEMA EXISTENTE: \n1 - Acrescentar palavra de um tema \n2 - Apagar palavra de um tema\n";
        cin >> c2;
        switch (c2){
        case 1:{    //1 - Acrescentar palavra de um tema
            cout << "Qual o tema cuja palavra pretende acrescentar?\n";
            aux = FTemasEPalavras.escreveTemas();
            if (aux == false)
                return (1);
            cin >> cAux;
            if (cAux >= FTemasEPalavras.numTemas())
                return (-1);
            aux = FTemasEPalavras.inserePalavra(cAux);
            if (aux == false)
                return (1);
            if (m4 == 4)
                return (4);
            else
                return (2);}
        case 2:{
            cout << "Qual o indice do tema cuja palavra pretende apagar?\n";
            aux = FTemasEPalavras.escreveTemas();
            if (aux == false)
                return (1);
            cin >> cAux;
            if ((cAux >= FTemasEPalavras.numTemas()) || FTemasEPalavras.numPalavrasDeTema(cAux) <= 8)
                return (-1);
            cout << "Qual o indice da palavra pretende apagar?\n";
            aux = FTemasEPalavras.escrevePalavras(cAux);
            if (aux == false)
                return (1);
            cin >> cAux2;
            if(cAux2 >= FTemasEPalavras.numPalavrasDeTema(cAux))
                return (-1);
            aux = FTemasEPalavras.eliminaPalavra(cAux2, cAux);
            if (aux == false)
                return (1);
            if (m4 == 4)
                return (4);
            else
                return (2);}
        default:
            return (3);
        }}
    case 3:{    //3 - Apagar tema existente
        if (FTemasEPalavras.numTemas() <= 3){
            cout << "Nao foi possivel apagar o tema.\n";
            return (-1);}
        cout << "Qual o indice do tema que pretende eliminar?\n";
        aux = FTemasEPalavras.escreveTemas();
        if (aux == false)
            return (1);
        cin >> cAux;
        if (cAux >= FTemasEPalavras.numTemas())
            return (-1);
        aux = FTemasEPalavras.eliminaTema(cAux);
        if (aux == false)
            return (1);
        else if (m4 == 4)
            return (4);
        else
            return (2);}
    }
    return (-1);
}


//---------------MAIN----------------------------
int main()
{
//Variáveis a utilizar
    int m1 = -5, m2, m3, m4, c1, c2, cAux, cAux2, oTema = 0, oTempo = 0, oLetras, xx = 0;
    string cs, nome;
    bool aux;
    char f1[] = "NomesEPontuacoes.txt", f2[] = "TemasEPalavras.txt", f3[] = "DadosJogo.txt", f4[] = "PalavrasAnteriores.txt";
    CFicheiro FNomesEPontuacoes(f1), FTemasEPalavras(f2), FDadosJogo(f3), FPalavrasAnteriores(f4);
    CRecuperaDados DadosJogo;

if (m1 != -5){
erroFicheiro:
    cout << "\n\nOCORREU UM ERRO AO TENTAR ABRIR O FICHEIRO...\n\n";
    return (-1);
opcaoInvalida:
    cout << "\n\nOPCAO INVALIDA...\n\n";
    return (-1);
}


MENU:
//MENU --------------------------------------------------------------------------------------------------------
    cout << "MENU: \n1 - Iniciar novo jogo \n2 - Sair \n3 - Mostrar pontuacoes totais de jogadores\n4 - Configurar temas e palavras por tema\n";
    cin >> m1;
    switch (m1){
    case 1:{    //1 - Iniciar novo jogo
        cout << "\nINICIAR NOVO JOGO: \n1 - Continuar jogo suspenso \n2 - Comecar jogo novo\n";
        cin >> m2;
        switch (m2){
        case 1:{
            cout << "\nCONTINUAR JOGO SUSPENSO: \n";
            goto ContinuarJogo;
            break;}
        case 2:{
            cout << "\nCOMECAR JOGO NOVO: \n1 - Jogar com modo pre-definido \n2 - Jogar escolhendo as opcoes \n";
            cin >> m3;
            if (m3 == 1)
                goto JogoModoPreDefinido;
            else if (m3 == 2)
                goto JogoEscolhendo;
            else
                goto opcaoInvalida;}
        default:
                goto opcaoInvalida;
        }
    }
    case 2:{    //2 - Sair
        //Perguntar ao utilizador se quer continuar a jogar ou se quer sair
        cout << "\nSe quiser continuar a jogar, introduza S/s. Caso contrario, introduza qualquer outro caracter: ";
        cin >> cs;
        if ((cs == "s") || (cs == "S"))
            goto MENU;
        else
            return 0;}
    case 3:{    //3 - Mostrar pontuacoes totais de jogadores
        aux = FNomesEPontuacoes.leFicheiroNomesEPontos();
        if (aux == false)
            goto erroFicheiro;
        cout << "\nSe quiser continuar a jogar, introduza S/s. Caso contrario, introduza qualquer outro caracter: ";
        cin >> cs;
        if ((cs == "s") || (cs == "S"))
            goto MENU;
        else
            return 0;}
    case 4:{    // 4 - Configurar temas e palavras por tema
        cAux = mudaTemas(0);
        if (cAux == -1)
            return (-1);
        if (cAux == 1)
            goto erroFicheiro;
        if (cAux == 2)
            goto MENU;
        if (cAux == 3)
            goto opcaoInvalida;
    }
    default:
        goto opcaoInvalida;
    }


ContinuarJogo:
    aux = FDadosJogo.leDadosJogo(DadosJogo);
    if (aux == false)
        goto erroFicheiro;
    if (DadosJogo.xx == 0){
        cout << "\nNao existe nenhum jogo para continuar...\n";
        return (-1);
    }
    goto JOGO;

JogoModoPreDefinido:
    cout << "\nJOGAR COM MODO PRE-DEFINIDO: \n1 - Elementar \n2 - Basico \n3 - Medio \n4 - Avancado \n5 - Profissional \n";
    cin >> m4;

    if (!(m4== 1 || m4== 2 || m4== 3 || m4== 4 || m4== 5))
        goto opcaoInvalida;
    if (m4 == 2 || m4 == 3 || m4 == 4)               //se oTema == 1, é para o jogador escolher o tema.
        oTema = 1;
    if (m4 == 2 || m4 == 3 || m4 == 4 || m4== 5)     //se oTempo == 1, é para ser feita a contagem do tempo.
        oTempo = 1;
    if (m4 == 3 || m4 == 4 || m4== 5)                //se oLetras == 1, é para serem apresentadas no ecrã as letras já erradas.
        oLetras = 1;
    goto JOGO;


JogoEscolhendo:
    cout << "\nJOGAR ESCOLHENDO AS OPCOES: \n";
    cout << "\n\nDeseja selecionar o tema do jogo? Se sim, introduza S/s. ";
    cin >> cs;
    if ((cs == "s") || (cs == "S"))
        oTema = 1;
    cout << "\n\nDeseja cronometrar o jogo? Se sim, introduza S/s. ";
    cin >> cs;
    if ((cs == "s") || (cs == "S"))
        oTempo = 1;
    cout << "\n\nDeseja que durante o jogo sejam apresentadas as letras incorretas ja introduzidas? Se sim, introduza S/s. ";
    cin >> cs;
    if ((cs == "s") || (cs == "S"))
        oLetras = 1;
    goto JOGO;

JOGO:
    char c;
    int numLetrasCorretas, numErros, numCaracteresCorretos, numRepeticoesLetra, valorLido, numLetrasErradas;
    char LetrasCorretas[27]; //27, tendo em conta que existem 26 letras no alfabeto
    char LetrasErradas[27];
    CTempo temp;
    double tempoMax, tempoInicial, tempoAqui, tempoSobra=0, pontos=0;

AtribuirValoresIniciais:
    if (m2 == 1){
        xx = DadosJogo.xx;
        m4 = DadosJogo.m4;
        oTema = DadosJogo.oTema;
        oTempo = DadosJogo.oTempo;
        oLetras = DadosJogo.oLetras;
        numLetrasCorretas = DadosJogo.numLetrasCorretas;
        numErros = DadosJogo.numErros;
        numCaracteresCorretos = DadosJogo.numCaracteresCorretos;
        numRepeticoesLetra = DadosJogo.numRepeticoesLetra;
        numLetrasErradas = DadosJogo.numLetrasErradas;
        strcpy(LetrasCorretas, DadosJogo.LetrasCorretas);
        strcpy(LetrasErradas, DadosJogo.LetrasErradas);
        tempoMax = DadosJogo.tempoMax;
        tempoSobra = DadosJogo.tempoSobra;
        pontos = DadosJogo.pontos;
    }
    else{
        numLetrasCorretas = 0;
        numCaracteresCorretos = 0;
        numLetrasErradas = 0;
        numErros = 0;
        strcpy(LetrasCorretas, " ");
        strcpy(LetrasErradas, " ");
        tempoSobra=0;
    }

    //Modificar os temas existentes (se for esta a opção selecionada anteriormente)
    if (m4 == 4 && xx == 0){
        cAux = mudaTemas(m4);
        if (cAux == -1)
            return (-1);
        if (cAux == 1)
            goto erroFicheiro;
        if (cAux == 2)
            goto MENU;
        if (cAux == 3)
            goto opcaoInvalida;
    }

    //Escolher o tema com que vai jogar (se for esta a opção selecionada anteriormente)
    if (oTema == 1 && xx == 0){
        cout << "Escolha um dos seguintes temas: \n";
        aux = FTemasEPalavras.escreveTemas();
        if (aux == false)
            goto erroFicheiro;
        cin >> valorLido;}
    else if (m4 == 5)
        valorLido = -5;        //-5 <=> o tema é escolhido aleatoriamente tendo em conta a probabilidade
    else
        valorLido = -1;        //-1 <=> o tema é escolhido aleatoriamente

    CPalavra P(valorLido);     //Escolhe automaticamente e aleatoriamente qual a palavra a ser utilizada
    if (xx == 1)
        P.definePalavraETema(DadosJogo.palavra, DadosJogo.tema);    //Se se estiver a continuar um jogo antigo, vai buscar as palavras já definidas antes
    if (P.devolveNumLetras() < 0){ //Verifica que a palavra e o tema foram escolhidos corretamente, ou seja, se não existiu nenhum erro
        cout << "\nERRO!\n";
        return (-1);}

    if (m4 == 5 && xx == 0){ //Escrever no ficheiro a nova palavra para que esta seja tida em conta na probabilidade de uma próxima palavra ser escolhida
        aux = FPalavrasAnteriores.escrevePalavraParaProbabilidade(P.devolvePalavra());
        if (aux == false)
            goto erroFicheiro;}


    //Informar o que fazer se quiser suspender o jogo
    cout << "\nSe quiser suspender o jogo, insira '0' em qualquer momento do jogo.\n";

    //Informar o utilizador o tema
    cout << "\nTEMA: ";
    P.imprimeTema();
    cout << endl;

    //Define o tempo máximo que o jogador vai ter para adivinhar a palavra
    if (oTempo == 1){
        if (xx == 0){
            cout << "\nQual o nivel de dificuldade que pretende? \n0 - Facil \n1 - Medio \n2 - Dificil\n";
            cin >> valorLido;
            tempoMax = P.defineTempoMax(valorLido);
            cout << "\n\nTem " << tempoMax << " segundos para descobrir a palavra!\n\n";
        }
    //Definir o tempo no início deste jogo
        temp.tempoAgora();
        tempoInicial = temp.devolveSegundos();
    }
    else if (oTempo != 1 && xx == 0){
        tempoAqui = 0;
        tempoInicial = 0;
        tempoMax = 0;
    }

    while (1){
        //Verifica se a palavra já foi descoberta ou se já foram cometidos 9 erros
        if (numErros == 9){
            desenhaForca(numErros);
            cout << "\n\nPERDEU...\n";
            goto End2;}
        if (numCaracteresCorretos == P.devolveNumLetras()){
            cout << "                                       ";
            P.imprimePalavraDescoberta(LetrasCorretas, numLetrasCorretas);
            cout << "\n\nCONSEGUIU ADIVINHAR!!!\n";
            break;}
        if (oTempo == 1){
        //Verifica se o tempo já foi excedidio
            temp.tempoAgora();
            tempoAqui = temp.devolveSegundos();
            if ((tempoAqui-tempoInicial) > tempoMax && xx == 0){
                cout << "\n\nFOI EXCEDIDIO O TEMPO...";
                goto End2;}
            if ((tempoAqui-tempoInicial) > tempoSobra && xx == 1){
                cout << "\n\nFOI EXCEDIDIO O TEMPO...";
                goto End2;}
        }

        cout << "                                       ";
        P.imprimePalavraDescoberta(LetrasCorretas, numLetrasCorretas);
        desenhaForca(numErros);

        if (oLetras == 1){
        //Mostra as letras já erradas
            cout << "\n\n                        ";
            for (int i = 0 ; i<numLetrasErradas ; i++)
                cout << LetrasErradas[i] << "       ";
        }

        //Informar de quanto tempo é que o jogador ainda dispõe para jogar
        if (oTempo == 1){
            if (xx == 0){
                temp.tempoAgora();
                tempoAqui = temp.devolveSegundos();
                cout << "\nAinda tem "<< tempoMax - (tempoAqui-tempoInicial) << " segundos para adivinhar a palavra!\n";
            }
            else if (xx == 1){
                temp.tempoAgora();
                tempoAqui = temp.devolveSegundos();
                cout << "\nAinda tem "<< tempoSobra - (tempoAqui-tempoInicial) << " segundos para adivinhar a palavra!\n";
            }
        }


        cout << "\n\n" << "Introduza uma letra (em maiusculas): ";
        cin >> c;

        if (c == '0'){
            cout << "\n\nDeseja mesmo terminar o jogo agora guardando o jogo atual para continuar mais tarde? Se sim, introduza S/s. ";
            cin >> cs;
            if ((cs == "s") || (cs == "S")){
                temp.tempoAgora();
                tempoAqui = temp.devolveSegundos();
                tempoSobra = tempoMax - (tempoAqui-tempoInicial);
                xx = 1;
                goto guardarDados;}
        }

        if(procuraLetranoArray(LetrasCorretas, c, numLetrasCorretas) == false){
            numRepeticoesLetra = P.procuraLetra(c);
            if (numRepeticoesLetra == 0){
                numErros = numErros + 1;
                if(procuraLetranoArray(LetrasErradas, c, numLetrasErradas) == false){
                    numLetrasErradas = numLetrasErradas + 1;
                    LetrasErradas[numLetrasErradas-1] = c;
                }
            }
            else{
                numLetrasCorretas = numLetrasCorretas + 1;
                numCaracteresCorretos = numCaracteresCorretos + numRepeticoesLetra;
                LetrasCorretas[numLetrasCorretas-1] = c;
            }
        }
    }
    //Atribuir os pontos conseguidos na ronda jogada
    pontos = pontos + P.atruibuiPontos(tempoAqui-tempoInicial, tempoMax, numErros, oTempo);     //(double t, double tmax, int mod)
    cout << "\nPontuacao: " << pontos;

    //Colocar o ficheiro dos dados do jogo todo a zero = não existe nenhum jogo inacabado
    DadosJogo.colocaAZero();
    xx = 0;
    aux = FDadosJogo.escreveDadosJogo(DadosJogo);
    if(aux == false)
        goto erroFicheiro;

    //Atualiza os valores das variáveis para dizer que já não está a ser jogado o jogo que foi guardado no ficheiro
    m2 = 2;
    xx = 0;

    //Perguntar ao utilizador se quer continuar a jogar ou se quer sair
    cout << "\nSe quiser continuar a jogar, introduza S/s. Caso contrario, introduza qualquer outro caracter: ";
    cin >> cs;
    if ((cs == "s") || (cs == "S"))
        goto AtribuirValoresIniciais;
    else
        goto End2;

End2:
    if (pontos > 0){
        //Pede o nome ao utilizador e escreve os seus dados (ou substitui a pontuação) no ficheiro de texto
        cout << "\nIntroduza o seu nome: ";
        cin.ignore();
        getline(cin, nome);

        //Escreve os dados no ficheiro
        aux = FNomesEPontuacoes.leEescreveFicheiros (nome, pontos);
        if (aux == false)
            goto erroFicheiro;
    }

    cout << "\nPONTUACAO FINAL: " << pontos << "!!!";
    cout << "\n\n";
    return (0);


guardarDados:
    DadosJogo.palavra = P.devolvePalavra();
    DadosJogo.tema = P.devolveTema();
    DadosJogo.xx = xx;
    DadosJogo.m4 = m4;
    DadosJogo.oTema = oTema;
    DadosJogo.oTempo = oTempo;
    DadosJogo.oLetras = oLetras;
    DadosJogo.numLetrasCorretas = numLetrasCorretas;
    DadosJogo.numErros = numErros;
    DadosJogo.numCaracteresCorretos = numCaracteresCorretos;
    DadosJogo.numRepeticoesLetra = numRepeticoesLetra;
    DadosJogo.numLetrasErradas = numLetrasErradas;
    strcpy(DadosJogo.LetrasCorretas, LetrasCorretas);
    strcpy(DadosJogo.LetrasErradas, LetrasErradas);
    DadosJogo.tempoMax = tempoMax;
    DadosJogo.tempoSobra = tempoSobra;
    DadosJogo.pontos = pontos;
    aux = FDadosJogo.escreveDadosJogo(DadosJogo);
    if(aux == false)
        goto erroFicheiro;
    return (-1);
}
