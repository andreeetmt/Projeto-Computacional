/*
Jogo da Velha --> Membros do Grupo (Matrícula):

André Luís Furtado Cabral (241024590)
André Monteiro Toussaint (241038058)
Arthur Morais de Brito Simões Ferreira (241024482)
Bernardo de Alencar Monteiro (241008460)
Guilherme Toledo Osanai Lima (241008498)
Gustavo Neri Alves Almeida (241008569)
*/

#include <iostream> // Biblioteca base do C++
#include <vector> // Biblioteca para facilitar a manipulação de vetores
#include <random> // Biblioteca para usar o random
#include <unistd.h> // Biblioteca para usar a função sleep()

using namespace std; // Namespace std para facilitar a leitura e escrita do código

void LimparTela() { // Função para limpar a tela
#ifdef _WIN32
    system("cls");  // Limpa a tela no Windows
#else
    system("clear");  // Limpa a tela em sistemas Unix/Linux
#endif
}

random_device rd; // Gerador de números aleatórios baseado em hardware, se disponível
mt19937 gen(rd()); // Mersenne Twister 19937 como o gerador padrão

uniform_int_distribution<> dist(0, 8); // Números entre 0 e 8 (para um tabuleiro 3x3)

vector<string> tabuleiro(9, " "); // Criação do tabuleiro do jogo da velha, com 9 casas em branco
string situacao;
bool jogadores = true, velha;
string Jogador1 = "X"; // Marcação do espaço do jogador 1
string Jogador2 = "O"; // Marcação do espaço do jogador 2
int contadorX1 = 0, contadorO1 = 0, contadorX2 = 0, contadorO2 = 0; // Contadores de vitórias, os com o número 1 para o jogo contra o computador e os com o número 2 para o jogo contra outro jogador

void TabuleiroNovo() { // Função para gerar um tabuleiro em branco
    // Limpar o vetor
    tabuleiro.clear();
    // Colocando espaços vazios
    tabuleiro.resize(9, " ");
}

void Tabuleiro() { // Função para gerador o tabuleiro base
    cout << "Tabuleiro:\n";
    cout << " " << tabuleiro[0] << " | " << tabuleiro[1] << " | " << tabuleiro[2] << "           1 | 2 | 3 \n";
    cout << "---+---+---          ---+---+---\n";
    cout << " " << tabuleiro[3] << " | " << tabuleiro[4] << " | " << tabuleiro[5] << "           4 | 5 | 6 \n";
    cout << "---+---+---          ---+---+---\n";
    cout << " " << tabuleiro[6] << " | " << tabuleiro[7] << " | " << tabuleiro[8] << "           7 | 8 | 9 \n";
}

bool CasaOcupada(int posicao) { // Checar se a casa do tabuleiro está ocupada ou não
    return tabuleiro[posicao - 1] != " ";
}

bool vitoriaX() { // Aqui checamos as várias formas do jogador "X" vencer 
    // Verificar linhas
    if ((tabuleiro[0] == tabuleiro[1] && tabuleiro[1] == tabuleiro[2] && tabuleiro[0] == "X") ||
        (tabuleiro[3] == tabuleiro[4] && tabuleiro[4] == tabuleiro[5] && tabuleiro[3] == "X") ||
        (tabuleiro[6] == tabuleiro[7] && tabuleiro[7] == tabuleiro[8] && tabuleiro[6] == "X")) {
        return true;
    }
    
    // Verificar colunas
    if ((tabuleiro[0] == tabuleiro[3] && tabuleiro[3] == tabuleiro[6] && tabuleiro[0] == "X") ||
        (tabuleiro[1] == tabuleiro[4] && tabuleiro[4] == tabuleiro[7] && tabuleiro[1] == "X") ||
        (tabuleiro[2] == tabuleiro[5] && tabuleiro[5] == tabuleiro[8] && tabuleiro[2] == "X")) {
        return true;
    }
    
    // Verificar diagonais
    if ((tabuleiro[0] == tabuleiro[4] && tabuleiro[4] == tabuleiro[8] && tabuleiro[0] == "X") ||
        (tabuleiro[2] == tabuleiro[4] && tabuleiro[4] == tabuleiro[6] && tabuleiro[2] == "X")) {
        return true;
    }

    return false;
}

bool vitoriaO() { // Aqui checamos as várias formas do jogador "O" vencer
    // Verificar linhas
    if ((tabuleiro[0] == tabuleiro[1] && tabuleiro[1] == tabuleiro[2] && tabuleiro[0] == "O") ||
        (tabuleiro[3] == tabuleiro[4] && tabuleiro[4] == tabuleiro[5] && tabuleiro[3] == "O") ||
        (tabuleiro[6] == tabuleiro[7] && tabuleiro[7] == tabuleiro[8] && tabuleiro[6] == "O")) {
        return true;
    }
    
    // Verificar colunas
    if ((tabuleiro[0] == tabuleiro[3] && tabuleiro[3] == tabuleiro[6] && tabuleiro[0] == "O") ||
        (tabuleiro[1] == tabuleiro[4] && tabuleiro[4] == tabuleiro[7] && tabuleiro[1] == "O") ||
        (tabuleiro[2] == tabuleiro[5] && tabuleiro[5] == tabuleiro[8] && tabuleiro[2] == "O")) {
        return true;
    }
    
    // Verificar diagonais
    if ((tabuleiro[0] == tabuleiro[4] && tabuleiro[4] == tabuleiro[8] && tabuleiro[0] == "O") ||
        (tabuleiro[2] == tabuleiro[4] && tabuleiro[4] == tabuleiro[6] && tabuleiro[2] == "O")) {
        return true;
    }

    return false;
}

int main() {
    int resposta, XouO, Continuar;

    LimparTela();

    // Menu Principal com as várias opções

    cout << "    ___                            _          _   _        _  _             " << endl;
    cout << "   |_  |                          | |        | | | |      | || |            " << endl;
    cout << "     | |  ___    __ _   ___     __| |  __ _  | | | |  ___ | || |__    __ _  " << endl;
    cout << "     | | / _ \\  / _` | / _ \\   / _` | / _` | | | | | / _ \\| || '_ \\  / _` | " << endl;
    cout << " /\\__/ /| (_) || (_| || (_) | | (_| || (_| | \\ \\_/ /|  __/| || | | || (_| | " << endl;
    cout << " \\____/  \\___/  \\__, | \\___/   \\__,_| \\__,_|  \\___/  \\___||_||_| |_| \\__,_| " << endl;
    cout << "                 __/ |                                                      " << endl;
    cout << "                |___/                                                       " << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "                      Escolha o modo de jogo" << endl;
    cout << "" << endl;
    cout << "                          1 Jogador (1)" << endl;
    cout << "                         2 Jogadores (2)" << endl;
    cout << "                       Sair do programa (0)" << endl;
    cout << "" << endl;

    cin >> resposta;

    while (resposta != 0) {
        LimparTela();

        if (resposta == 1) { // Modo de jogo contra a máquina
            bool jogo = true;
            TabuleiroNovo();

            while (jogo) {
                LimparTela();
                Tabuleiro();

                if (jogadores) { // Jogada do jogador 1
                    cout << "Jogador 1(X), faca sua jogada: " << endl;
                    cin >> XouO;
                    while (CasaOcupada(XouO)) { // Repetição da entrada caso esteja ocupada
                    cout << "Casa ocupada! Escolha outra casa: ";
                    cin >> XouO;
                    }
                } else { // Jogada da Máquina
                    cout << "Jogador 2(O), faca sua jogada: " << endl;
                    sleep(2);
                    do{
                    XouO = dist(gen); // Gera um índice de 0 a 8 (correspondente ao vetor)
                    } while (CasaOcupada(XouO)); // Converte índice para posição de 1 a 9
                }


                if (jogadores) { // Revezamento dos jogadores
                    tabuleiro[XouO - 1] = Jogador1;
                    jogadores = false;
                } else {
                    tabuleiro[XouO - 1] = Jogador2;
                    jogadores = true;
                }

                if (vitoriaX()) { // Checar vitória do Jogador 1
                    LimparTela();
                    Tabuleiro();
                    cout << "\n\n\nJOGADOR 1(X) GANHOU!!! Parebens :D\n\n\n";
                    contadorX1++;
                    cout << "Pontuacao! \nJogador 1(X): " << contadorX1 << "  Jogador 2(O): " << contadorO1 << endl;
                    jogo = false;
                } else if (vitoriaO()) { // Checar vitória da Máquina
                    LimparTela();
                    Tabuleiro();
                    cout << "\n\n\nJOGADOR 2(O) GANHOU!!! Parebens :D\n\n\n";
                    contadorO1++;
                    cout << "Pontuacao! \nJogador 1(X): " << contadorX1 << "  Jogador 2(O): " << contadorO1 << endl;
                    jogo = false;
                }

                    bool velha = true; // Checar se "deu velha"
                    for (const string& casa : tabuleiro) {
                        if (casa == " ") {
                            velha = false;
                        break;
                        }
                    }

                if (velha) { 
                    LimparTela();
                    Tabuleiro();
                    cout << "Deu velha!" << endl;
                    cout << "Pontuacao! \nJogador 1(X): " << contadorX2 << "  Jogador 2(O): " << contadorO2 << endl;
                    jogo = false;
                }
            }

            // Opções de voltar para o menu, jogar novamente ou encerrar o programa
            cout << "\n\nJogar novamente? (1)" << endl;
            cout << "Voltar para o Menu (2) " << endl;
            cout << "Encerrar programa (0)" << endl;
            cin >> Continuar;

            if (Continuar == 0) {
                LimparTela();
                cout << "ENCERRANDO PROGRAMA!" << endl;
                return 0;
            } else if (Continuar == 1) {
                continue;
            } else if (Continuar == 2) {
                return main();
            }

        } else if (resposta == 2) { // Modo de jogo entre dois jogadores
            bool jogo = true;
            TabuleiroNovo();

            while (jogo) {
                LimparTela();
                Tabuleiro();

                if (jogadores) { // Alterna entre os jogadores
                    cout << "Jogador 1(X), faca sua jogada: " << endl;
                } else {
                    cout << "Jogador 2(O), faca sua jogada: " << endl;
                }

                cin >> XouO;

                while (CasaOcupada(XouO)) { // Função de checagem de casa ocupada
                    cout << "Casa ocupada! Escolha outra casa: ";
                    cin >> XouO;
                }

                if (jogadores) { // Jogada do Jogador 1
                    tabuleiro[XouO - 1] = Jogador1;
                    jogadores = false;
                } else { // Jogada do Jogador 2
                    tabuleiro[XouO - 1] = Jogador2;
                    jogadores = true;
                }

                if (vitoriaX()) { // Checagem de vitória do Jogador 1
                    LimparTela();
                    Tabuleiro();
                    cout << "\n\n\nJOGADOR 1(X) GANHOU!!! Parebens :D\n\n\n";
                    contadorX2++;
                    cout << "Pontuacao! \nJogador 1(X): " << contadorX2 << "  Jogador 2(O): " << contadorO2 << endl;
                    jogo = false;
                    
                } else if (vitoriaO()) { // Checagem de vitória do Jogador 2
                    LimparTela();
                    Tabuleiro();
                    cout << "\n\n\nJOGADOR 2(O) GANHOU!!! Parebens :D\n\n\n";
                    contadorO2++;
                    cout << "Pontuacao! \nJogador 1(X): " << contadorX2 << "  Jogador 2(O): " << contadorO2 << endl;
                    jogo = false;
                }

                    bool velha = true; // Função para checar se "deu velha"
                    for (const string& casa : tabuleiro) {
                        if (casa == " ") {
                            velha = false;
                            break;
                        }
                    }

                if (velha) {
                    LimparTela();
                    Tabuleiro();
                    cout << "Deu velha!" << endl;
                    cout << "Pontucao! \nJogador 1(X): " << contadorX2 << "  Jogador 2(O): " << contadorO2 << endl;
                    jogo = false;
                }
            }
            
            // Opções para voltar ao menu principal, jogar novamente ou encerrar o programa

            cout << "\n\nJogar novamente? (1)" << endl;
            cout << "Voltar para o Menu (2) " << endl;
            cout << "Encerrar programa (0)" << endl;
            cin >> Continuar;

            if (Continuar == 0) {
                LimparTela();
                cout << "ENCERRANDO PROGRAMA!" << endl;
                return 0;
            } else if (Continuar == 1) {
                continue;
            } else if (Continuar == 2) {
                return main();
            }
            } else if (resposta == 0) {
                cout << "ENCERRANDO PROGRAMA" << endl;
                break;
            } else {
                cout << "Resposta inesperada, Tente novamente :(" << endl;
            }
    }

    return 0;
}