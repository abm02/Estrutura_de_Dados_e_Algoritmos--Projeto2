#include "cficheiro.h"
#include "cpalavra.h"
#include "crecuperadados.h"

void ordenaInsercao (int tab[], int dim, string tabNomes[]){
    for (int i = 1 ; i < dim ; i++){
        int aux = tab[i];
        string aux2 = tabNomes[i];
        int j;
        for (j = i ; (j>0) && (aux < tab[j-1]) ; j--){
            tab[j] = tab[j-1];
            tabNomes[j] = tabNomes[j-1];
        }
        tab[j] = aux;
        tabNomes[j] = aux2;
    }
}

//Definição do método que guarda os pontos do jogador
bool CFicheiro :: leEescreveFicheiros (string nomeUtilizador, double pontos){
    string dadosLidos, aux;
    string cpp_nome = nomeUtilizador;

    //Abrir os dois ficheiros que vão ser necessários e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return (false);
    ofstream ficheiroAux("FicheiroAuxiliar.txt");               //abrir o ficheiro para escrita
    if ( !ficheiroAux.is_open())
        return (false);

    //Vai copiar todos os dados do ficheiro original para um auxiliar, exceto o do jogador atual, caso já exista
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        aux = dadosLidos;
        aux.resize(NUM, ' ');
        cpp_nome.resize(NUM, ' ');
        if (cpp_nome == aux)                //é o nome do jogador => já tem uma pontuação atribuída => não escreve os dados no novo ficheiro
            continue;
        ficheiroAux << dadosLidos << endl; //não é o nome do jogador => escreve os dados no novo ficheiro
    }

    //Escreve os dados novos do jogador no final do ficheiro
    ficheiroAux << left << setw(50) << cpp_nome;
    ficheiroAux << left << setw(10) << pontos << endl;

    //Fecha os ficheiros, elimina o ficheiro inicial e altera o nome do ficheiro auxiliar
    ficheiro.close();
    ficheiroAux.close();
    remove(nome);
    rename ("FicheiroAuxiliar.txt", nome);
    return (true);
}

//Definição do método que lê do ficheiro os pontos e os nomes dos jogadores
bool CFicheiro :: leFicheiroNomesEPontos(void){
    string dadosLidos;
    string *nomes, *pontuacao;
    int *auxPontuacao;
    int i = 0, linhas = 0;

    //Abrir o ficheiro necessário e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return (false);

    //Conta o número de linhas do ficheiro
    ficheiro.seekg (0, ficheiro.end);
    linhas = ficheiro.tellg();
    ficheiro.seekg (0, ficheiro.beg);

    //Alocar memória para as tabelas dos nomes e das pontuações
    nomes = new string[linhas];
    pontuacao = new string[linhas];
    auxPontuacao = new int[linhas];

    //Lê cada linha do ficheiro, uma a uma, e imprime-a no ecrã
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        nomes[i] = dadosLidos.substr(0, NUM);
        pontuacao[i] = dadosLidos.substr(NUM-1, 10);
        auxPontuacao[i] = stoi(pontuacao[i]);       //transforma a strings de pontuacao num inteiro
        i = i+1;
    }
    //ordena por ordem crescente a tabela de pontuações utilizando o método da insercão
    ordenaInsercao(auxPontuacao, i, nomes);
    //Cabeçalho para a tabela
    cout << left << setw(50) << "\nNome do jogador:" << setw(10) << "Pontuacao:\n";
    for (int j = i-1 ; j>=0 ; j--){     //começamos a imprimir a tabela pelo fim para imprimir em ordem decrescente
        cout << setw(NUM) << nomes[j] << setw(10) << auxPontuacao[j] << endl;
    }

    //Fecha os ficheiros, elimina o ficheiro inicial e as alocações de memória
    ficheiro.close();
    delete []nomes;
    delete []pontuacao;
    delete []auxPontuacao;
    return (true);
}

//Definição do método que conta o número de temas que existe num ficheiro
int CFicheiro :: numTemas(void){
    int num = 0;
    string dadosLidos;

    //Abrir o ficheiro necessário e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return (-1);

    //Lê cada linha do ficheiro, uma a uma, vê se nessa linha está escrito um tema ou uma palavra
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        if (!(dadosLidos[0] == ' '))        //não estamos a ler uma palavra = estamos a ler um tema
            num = num+1;
    }
    ficheiro.close();
    return (num);
}

//Definição do método que conta o número de palavras do tema de índice i
int CFicheiro :: numPalavrasDeTema(int t){
    int numT = 0, numP = 0;
    string dadosLidos;

    //Abrir o ficheiro necessário e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return (-1);

    //Lê cada linha do ficheiro, uma a uma, vê se nessa linha está escrito um tema ou uma palavra
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        if (!(dadosLidos[0] == ' '))        //não estamos a ler uma palavra == estamos a ler um tema
            numT = numT+1;
        if (numT == t+1)                    //chegámos ao tema de que estamos à procura
            break;
    }
    while(getline(ficheiro, dadosLidos)){   //conta o número de palavras do tema que pretendemos
        if(dadosLidos[0] == ' ')
            numP = numP + 1;
        else
            break;
    }
    ficheiro.close();
    return (numP);
}

//Método que devolve o tema de índice t
string CFicheiro :: devolveTema(int t){
    int numT = 0;
    string dadosLidos;

    //Abrir o ficheiro necessário e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return ("-1");

    //Lê cada linha do ficheiro, uma a uma, vê se nessa linha está escrito um tema ou uma palavra
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        if (!(dadosLidos[0] == ' '))        //não estamos a ler uma palavra == estamos a ler um tema
            numT = numT+1;
        if (numT == t+1)                    //chegámos ao tema que queremos, por isso devolvemos esse tema
            break;
    }
    ficheiro.close();
    return (dadosLidos);
}

//Definição do método que devolve a palavra de índice p do tema t
string CFicheiro :: devolvePalavra(int t, int p){
    int numT = 0, numP = 0;
    string dadosLidos;

    //Abrir o ficheiro necessário e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return ("-1");

    //Lê cada linha do ficheiro, uma a uma, vê se nessa linha está escrito um tema ou uma palavra
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        if (!(dadosLidos[0] == ' '))        //não estamos a ler uma palavra == estamos a ler um tema
            numT = numT+1;
        if (numT == t+1)
            break;
    }
    while (1){
        getline(ficheiro, dadosLidos);
        if(dadosLidos[0] == ' ')
            numP = numP + 1;
        if(numP == p+1)
            break;
    }
    ficheiro.close();
    return (dadosLidos);
}

//Definição do método que escreve no ecrã todos os temas que existem no ficheiro
bool CFicheiro :: escreveTemas(void){
    int numT = 0;
    string dadosLidos;

    //Abrir o ficheiro necessário e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return (false);

    //Lê cada linha do ficheiro, uma a uma, vê se nessa linha está escrito um tema ou uma palavra
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        if (!(dadosLidos[0] == ' ')){        //não estamos a ler uma palavra == estamos a ler um tema
            cout << numT << " - " << dadosLidos << endl;
            numT = numT+1;
        }
    }
    ficheiro.close();
    return (true);
}

//Definição do método que escreve no ecrã todas as palavras de um tema de índice t
bool CFicheiro :: escrevePalavras(int t){
    int numT = 0, numP = 0;
    string dadosLidos;

    //Abrir o ficheiro necessário e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return (false);

    //Lê cada linha do ficheiro, uma a uma, vê se nessa linha está escrito um tema ou uma palavra
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        if (!(dadosLidos[0] == ' '))        //não estamos a ler uma palavra == estamos a ler um tema
            numT = numT+1;
        if (numT == t+1)
            break;
    }
    while(getline(ficheiro, dadosLidos)){
        if(dadosLidos[0] == ' '){
            dadosLidos.erase (0,10);   //apaga os primeiros 10 caracteres da string, pq os espaços que existem no ficheiro
            cout << numP << " - " << dadosLidos << endl;
            numP = numP + 1;
        }
        else
            break;
    }
    ficheiro.close();
    return (true);
}

//Definição do método que permite inserir um tema novo no ficheiro
bool CFicheiro :: insereTemaNovo(int num){
    string aux;
    ofstream ficheiro;

    //Abrir o ficheiro necessário e garantir que tal é feito de forma sucedida
    ficheiro.open(nome, ios_base::app);
    if ( !ficheiro.is_open())
        return (false);

    cout << "Introduza o tema que pretende acrescentar (em maiusculas): ";
    cin >> aux;
    ficheiro << "\n" << aux;        //escreve no ficheiro o novo tema
    for(int i = 0 ; i<num ; i++){   //escreve no ficheiro todas as palavras para o novo tema
        cout << "Introduza uma palavra para o tema (em maiusculas): ";
        cin >> aux;
        ficheiro << "\n          " << aux << "";
    }
    ficheiro.close();
    return (true);
}

//Definição do método que permite eliminar um tema inteiro
bool CFicheiro :: eliminaTema(int ind){
    char nomeFicheiro2[] = "PalavrasAnteriores.txt";
    CFicheiro f2(nomeFicheiro2);

    int cont = 0;
    int numP = numPalavrasDeTema(ind);
    if (numP == -1)
        return (false);
    string dadosLidos, palavras[numP];
    bool aux;

    //Abrir os dois ficheiros que vão ser necessários e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return (false);
    ofstream ficheiroAux("FicheiroAuxiliar.txt");               //abrir o ficheiro para escrita
    if ( !ficheiroAux.is_open())
        return (false);

    //Vai copiar todos os dados do ficheiro original para um auxiliar, exceto as linhas correspondentes ao tema a eliminar
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        if (!(dadosLidos[0] == ' '))
            cont = cont + 1;
        if (cont == ind+1){       //"salta" o tema a eliminar
            for (int i = 0 ; i<numP ; i++){
                getline(ficheiro, dadosLidos);
                palavras[i] = dadosLidos.erase (0,10);
                continue;
            }
            break;}
        ficheiroAux << dadosLidos << endl;
    }
    while (getline(ficheiro, dadosLidos))   //escreve todas as outras linhas que sobrarem
        ficheiroAux << dadosLidos << endl;

    //Fecha os ficheiros, elimina o ficheiro inicial e altera o nome do ficheiro auxiliar
    ficheiro.close();
    ficheiroAux.close();
    remove(nome);
    rename ("FicheiroAuxiliar.txt", nome);

    //Elimina as palavras do tema a eliminar do ficheiro das probabilidades
    for (int i = 0 ; i<numP ; i++){
        aux = f2.eliminaPalavraFicheiroProb(palavras[i]);
        if (aux == false)
            return (false);
    }
    return (true);

}

//Definição do método que elimina a palavra de índice p do tema índice t
bool CFicheiro :: eliminaPalavra(int p, int t){
    char nomeFicheiro2[] = "PalavrasAnteriores.txt";
    CFicheiro f2(nomeFicheiro2);

    string dadosLidos, palavra;
    int numT = 0, numP = 0;
    bool aux;

    //Abrir os dois ficheiros que vão ser necessários e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return (false);
    ofstream ficheiroAux("FicheiroAuxiliar.txt");               //abrir o ficheiro para escrita
    if ( !ficheiroAux.is_open())
        return (false);

    //Vai copiar todos os dados do ficheiro original para um auxiliar, exceto as linhas até chegar ao tema da palavra que queremos eliminar
    ficheiro.seekg (0, ficheiro.beg);     //coloca o "cursor" no início do ficheiro
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        if (!(dadosLidos[0] == ' '))
            numT = numT + 1;
        ficheiroAux << dadosLidos << endl;
        if (numT == t+1)       //já estamos no tema da palavra que queremos eliminar
            break;
    }
    while(getline(ficheiro, dadosLidos)){   //escreve todas as palavras do tema exceto aquela que queremos eliminar
        if(dadosLidos[0] == ' '){
            numP = numP + 1;
            if(numP == p+1){
                palavra = dadosLidos.erase (0,10);
                continue;}
            ficheiroAux << dadosLidos << endl;
        }
        else{
            ficheiroAux << dadosLidos << endl;
            break;}
    }
    while (getline(ficheiro, dadosLidos))   //escreve todas as outras linhas que sobrarem
        ficheiroAux << dadosLidos << endl;

    //Fecha os ficheiros, elimina o ficheiro inicial e altera o nome do ficheiro auxiliar
    ficheiro.close();
    ficheiroAux.close();
    remove(nome);
    rename ("FicheiroAuxiliar.txt", nome);

    //Elimina as palavras do tema a eliminar do ficheiro das probabilidades
    aux = f2.eliminaPalavraFicheiroProb(palavra);
    if (aux == false)
        return (false);
    return (true);
}

//Definição do método que acrescenta uma palavra no tema de índice t
bool CFicheiro :: inserePalavra(int t){
    string dadosLidos, aux;
    int numT = 0;

    cout << "Introduza a palavra que pretende acrescentar (em maiusculas): ";
    cin >> aux;

    //Abrir os dois ficheiros que vão ser necessários e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return (false);
    ofstream ficheiroAux("FicheiroAuxiliar.txt");               //abrir o ficheiro para escrita
    if ( !ficheiroAux.is_open())
        return (false);

    //Vai copiar todos os dados do ficheiro original para um auxiliar até chegar ao tema onde queremos acrescentar a palavra
    ficheiro.seekg (0, ficheiro.beg);     //coloca o "cursor" no início do ficheiro
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        if (!(dadosLidos[0] == ' '))
            numT = numT + 1;
        ficheiroAux << dadosLidos << endl;
        if (numT == t+1){       //já estamos no tema da palavra que queremos acrescentar
            break;}
    }
    //escreve a palavra nova
    ficheiroAux << "          " << aux << endl;
    while (getline(ficheiro, dadosLidos))   //escreve todas as outras linhas que sobrarem
        ficheiroAux << dadosLidos << endl;

    //Fecha os ficheiros, elimina o ficheiro inicial e altera o nome do ficheiro auxiliar
    ficheiro.close();
    ficheiroAux.close();
    remove(nome);
    rename ("FicheiroAuxiliar.txt", nome);
    return (true);
}

//Definição do método que escreve todos os dados do jogo
bool CFicheiro :: escreveDadosJogo (CRecuperaDados &p){
    //Abrir o ficheiro que vai ser necessário e garantir que tal é feito de forma sucedida
    ofstream ficheiro(nome);               //abrir o ficheiro para escrita
    if ( !ficheiro.is_open())
        return (false);

    //Escreve os dados do jogo no ficheiro, um em cada linha
    ficheiro << p.palavra << endl;
    ficheiro << p.tema << endl;
    ficheiro << p.xx << endl;
    ficheiro << p.m4 << endl;
    ficheiro << p.oTema << endl;
    ficheiro << p.oTempo << endl;
    ficheiro << p.oLetras << endl;
    ficheiro << p.numLetrasCorretas << endl;
    ficheiro << p.numErros << endl;
    ficheiro << p.numCaracteresCorretos << endl;
    ficheiro << p.numRepeticoesLetra << endl;
    ficheiro << p.numLetrasErradas << endl;
    ficheiro << p.LetrasCorretas << endl;
    ficheiro << p.LetrasErradas << endl;
    ficheiro << p.tempoMax << endl;
    ficheiro << p.tempoSobra << endl;
    ficheiro << p.pontos << endl;

    ficheiro.close();
    return (true);
}

//Definição do método que lê todos os dados do jogo
bool CFicheiro :: leDadosJogo (CRecuperaDados &p){
    string dadosLidos;

    //Abrir o ficheiro necessário e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return (false);

    //Lê cada linha do ficheiro, uma a uma, vê se nessa linha está escrito um tema ou uma palavra
    getline(ficheiro, dadosLidos);      p.palavra = dadosLidos;
    getline(ficheiro, dadosLidos);      p.tema = dadosLidos;
    getline(ficheiro, dadosLidos);      p.xx = stoi(dadosLidos);
    getline(ficheiro, dadosLidos);      p.m4 = stoi(dadosLidos);
    getline(ficheiro, dadosLidos);      p.oTema = stoi(dadosLidos);
    getline(ficheiro, dadosLidos);      p.oTempo = stoi(dadosLidos);
    getline(ficheiro, dadosLidos);      p.oLetras = stoi(dadosLidos);
    getline(ficheiro, dadosLidos);      p.numLetrasCorretas = stoi(dadosLidos);
    getline(ficheiro, dadosLidos);      p.numErros = stoi(dadosLidos);
    getline(ficheiro, dadosLidos);      p.numCaracteresCorretos = stoi(dadosLidos);
    getline(ficheiro, dadosLidos);      p.numRepeticoesLetra = stoi(dadosLidos);
    getline(ficheiro, dadosLidos);      p.numLetrasErradas = stoi(dadosLidos);
    getline(ficheiro, dadosLidos);      strcpy(p.LetrasCorretas, dadosLidos.c_str());
    getline(ficheiro, dadosLidos);      strcpy(p.LetrasErradas, dadosLidos.c_str());
    getline(ficheiro, dadosLidos);      p.tempoMax = stod(dadosLidos);
    getline(ficheiro, dadosLidos);      p.tempoSobra = stod(dadosLidos);
    getline(ficheiro, dadosLidos);      p.pontos = stod(dadosLidos);

    ficheiro.close();
    return (true);
}

//Definição do método que devolve o número de palavras diferentes que nele existem
int CFicheiro :: devolveNumPalavrasDiferentes(void){
    int linhas = 0;
    string dadosLidos;
    int i1 = 0, num = 0;

    //Abrir o ficheiro necessário e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return (-1);

    //Conta o número de linhas do ficheiro
    while (getline(ficheiro, dadosLidos))   //lê uma linha do ficheiro de texto
        linhas++;
//    ficheiro.seekg (0, ficheiro.beg);       //coloca o cursor no início do ficheiro
    string p[linhas];

ficheiro.close();
ifstream ficheiro1(nome);                      //abrir o ficheiro para leitura
if ( !ficheiro1.is_open())
    return (-1);

    //Lê cada linha do ficheiro, uma a uma e vê se essa palavra já foi lida antes ou não
    while (getline(ficheiro1, dadosLidos)){   //lê uma linha do ficheiro de texto
        int aux = 0;
        for (int i2 = 0 ; i2 < i1 ; i2++){
            if (dadosLidos == p[i2]){
                num++;
                aux = 1;
            }
        }
        if (aux == 0){
            p[i1] = dadosLidos;}
        i1++;
    }
    ficheiro1.close();
    return (linhas-num);
}

//Definição do método que devolve o número de vezes que cada palavra é lida numa tabela de inteiros, e a ordem das palavras correspondentes numa tabela de strings
bool CFicheiro :: devolveNumRepeticoesCadaPalavra (int tab[], string tab2[], int tam){
    //tabela de zeros cujo tamanho é o número de palavras diferentes que existem no ficheiro de texto
    string dadosLidos;
    int i1 = 0, i3 = 0;

    //Abrir o ficheiro necessário e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return (false);
    for (int j = 0 ; j<tam ; j++)
        tab[j] = 1;

    //Lê cada linha do ficheiro, uma a uma e vê se essa palavra já foi lida antes ou não
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        int aux = 0;
        for (int i2 = 0 ; i2 < i1 ; i2++){
            if (dadosLidos == tab2[i2]){
                tab[i2]++;
                aux = 1;
            }
        }
        if (aux == 0){
            tab2[i3] = dadosLidos;
            i3++;}
        i1++;
    }
    ficheiro.close();
    return (true);
}

//Definição do método que descobre qual o índice do tema a que uma palavra pertence
int CFicheiro :: descobreIndiceTema(string palavra){
    int numT = 0;
    string dadosLidos;

    //Abrir o ficheiro necessário e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return (-1);

    //Lê cada linha do ficheiro, uma a uma, vê se nessa linha está escrito um tema ou uma palavra
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        if (!(dadosLidos[0] == ' '))        //não estamos a ler uma palavra == estamos a ler um tema
            numT = numT+1;
        else {
            dadosLidos.erase (0,10);
            if (dadosLidos == palavra){
                ficheiro.close();
                return (numT);
            }
        }
    }

    ficheiro.close();
    return (-1);
}

//Definição do método que escreve uma palavra no ficheiro da palavras para as probabilidade
bool CFicheiro :: escrevePalavraParaProbabilidade(string palavra){
    string aux;
    ofstream ficheiro;

    //Abrir o ficheiro necessário e garantir que tal é feito de forma sucedida
    ficheiro.open(nome, ios_base::app);
    if ( !ficheiro.is_open())
        return (false);

    ficheiro << "\n" << palavra;        //escreve no fim do ficheiro a nova palavra
    ficheiro.close();
    return (true);
}

//Definição do método que elimina todos os dados do ficheiro com as palavras que já saíram
bool CFicheiro :: eliminaFicheiroProb(void){
    remove(nome);

    //Criar um novo ficheiro com o mesmo nome e abrir para verificar que este está pronto a ser utilizado assim que for necessário
    ifstream ficheiro(nome);
    if ( !ficheiro.is_open())
        return (false);

    ficheiro.close();
    return (true);
}

//Definição do método que elimina todas as repetições num dado ficheiro da palavra passada como argumento
bool CFicheiro :: eliminaPalavraFicheiroProb(string palavra){
    string dadosLidos;

    //Abrir os dois ficheiros que vão ser necessários e garantir que tal é feito de forma sucedida
    ifstream ficheiro(nome);                      //abrir o ficheiro para leitura
    if ( !ficheiro.is_open())
        return (false);
    ofstream ficheiroAux("FicheiroAuxiliar.txt");               //abrir o ficheiro para escrita
    if ( !ficheiroAux.is_open())
        return (false);

    //Vai copiar todos os dados do ficheiro original para um auxiliar, exceto as linhas em que aparecer a palavra passada como parâmetro
    ficheiro.seekg (0, ficheiro.beg);     //coloca o "cursor" no início do ficheiro
    while (getline(ficheiro, dadosLidos)){   //lê uma linha do ficheiro de texto
        if (dadosLidos == palavra)
            continue;
        else
            ficheiroAux << dadosLidos << endl;
    }

    //Fecha os ficheiros, elimina o ficheiro inicial e altera o nome do ficheiro auxiliar
    ficheiro.close();
    ficheiroAux.close();
    remove(nome);
    rename ("FicheiroAuxiliar.txt", nome);
    return (true);
}
