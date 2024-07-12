<h1 align="center"> Jogo da Idosa👵🎮 </h1>

<p align="center">
  <img src="src/giphy.gif" alt="">
</p>


## Introdução
Este é um código feito na linguagem C++ para representar um clássico jogo da velha, apelidado carinhosamente de Jogo da Idosa pelos criadores. O jogo pode ser jogado por 2 jogadores, no clássico estilo PVP (jogador contra jogador). Também pode ser jogado no modo PVE (jogador contra o computador). O código está organizado de forma a ser claro e fácil de entender, com funções separadas para cada parte do jogo.

## Membros do Grupo
- André Luís Furtado Cabral (241024590)
- André Monteiro Toussaint (241038058)
- Arthur Morais de Brito Simões Ferreira (241024482)
- Bernardo de Alencar Monteiro (241008460)
- Guilherme Toledo Osanai Lima (241008498)
- Gustavo Neri Alves Almeida (241008569)

## :hammer: Inclusão de Bibliotecas
- `#include <iostream>` - Biblioteca base do C++
- `#include <vector>` - Biblioteca para facilitar a manipulação de vetores
- `#include <random>` - Biblioteca para usar o random
- `#include <unistd.h>` - Biblioteca para usar a função sleep()

## Funções Importantes 

### Limpar Tela
```cpp
void LimparTela() {
#ifdef _WIN32
    system("cls");  
#else
    system("clear");  
#endif
}
```
Função para limpar a tela em diferentes sistemas operacionais.
### Gerador de Números
```cpp

random_device rd; 
mt19937 gen(rd()); 
uniform_int_distribution<> dist(0, 8); 

```
Funçao para o computador gerar numeros e assim decidir suas jogadas.

###  Declaraçao de variáveis
```cpp

vector<string> tabuleiro(9, " "); 
string situacao;
bool jogadores = true, velha;
string Jogador1 = "X"; 
string Jogador2 = "O"; 
int contadorX1 = 0, contadorO1 = 0, contadorX2 = 0, contadorO2 = 0; 

```
Declaração de variáveis globais usadas no jogo, incluindo o tabuleiro, status dos jogadores e contadores de vitórias.

###  Tabuleiro
```cpp

void TabuleiroNovo() {
    tabuleiro.clear();
    tabuleiro.resize(9, " ");
}
```
Inicia um tabuleiro clássico de jogo da velha.


###  Tabuleiro Por Jogada
```cpp

void Tabuleiro() {
    cout << "Tabuleiro:\n";
    cout << " " << tabuleiro[0] << " | " << tabuleiro[1] << " | " << tabuleiro[2] << "           1 | 2 | 3 \n";
    cout << "---+---+---          ---+---+---\n";
    cout << " " << tabuleiro[3] << " | " << tabuleiro[4] << " | " << tabuleiro[5] << "           4 | 5 | 6 \n";
    cout << "---+---+---          ---+---+---\n";
    cout << " " << tabuleiro[6] << " | " << tabuleiro[7] << " | " << tabuleiro[8] << "           7 | 8 | 9 \n";
}

```

Exibe o tabuleiro atual do jogo, atualizando após cada rodada.

### Função Casa Ocupada
```cpp
bool CasaOcupada(int posicao) {
    return tabuleiro[posicao - 1] != " ";
}
```
Verifica se uma posiçao no tabuleiro está ocupada.

### Verificação de empate





```cpp


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



```
Verifica se deu velha, ou seja, não houve vencedor.




### Funções de Verificação de Vitória
```cpp


bool vitoriaX() {
    if ((tabuleiro[0] == tabuleiro[1] && tabuleiro[1] == tabuleiro[2] && tabuleiro[0] == "X") ||
        (tabuleiro[3] == tabuleiro[4] && tabuleiro[4] == tabuleiro[5] && tabuleiro[3] == "X") ||
        (tabuleiro[6] == tabuleiro[7] && tabuleiro[7] == tabuleiro[8] && tabuleiro[6] == "X")) {
        return true;
    }
    if ((tabuleiro[0] == tabuleiro[3] && tabuleiro[3] == tabuleiro[6] && tabuleiro[0] == "X") ||
        (tabuleiro[1] == tabuleiro[4] && tabuleiro[4] == tabuleiro[7] && tabuleiro[1] == "X") ||
        (tabuleiro[2] == tabuleiro[5] && tabuleiro[5] == tabuleiro[8] && tabuleiro[2] == "X")) {
        return true;
    }
    if ((tabuleiro[0] == tabuleiro[4] && tabuleiro[4] == tabuleiro[8] && tabuleiro[0] == "X") ||
        (tabuleiro[2] == tabuleiro[4] && tabuleiro[4] == tabuleiro[6] && tabuleiro[2] == "X")) {
        return true;
    }
    return false;
}

bool vitoriaO() {
    if ((tabuleiro[0] == tabuleiro[1] && tabuleiro[1] == tabuleiro[2] && tabuleiro[0] == "O") ||
        (tabuleiro[3] == tabuleiro[4] && tabuleiro[4] == tabuleiro[5] && tabuleiro[3] == "O") ||
        (tabuleiro[6] == tabuleiro[7] && tabuleiro[7] == tabuleiro[8] && tabuleiro[6] == "O")) {
        return true;
    }
    if ((tabuleiro[0] == tabuleiro[3] && tabuleiro[3] == tabuleiro[6] && tabuleiro[0] == "O") ||
        (tabuleiro[1] == tabuleiro[4] && tabuleiro[4] == tabuleiro[7] && tabuleiro[1] == "O") ||
        (tabuleiro[2] == tabuleiro[5] && tabuleiro[5] == tabuleiro[8] && tabuleiro[2] == "O")) {
        return true;
    }
    if ((tabuleiro[0] == tabuleiro[4] && tabuleiro[4] == tabuleiro[8] && tabuleiro[0] == "O") ||
        (tabuleiro[2] == tabuleiro[4] && tabuleiro[4] == tabuleiro[6] && tabuleiro[2] == "O")) {
        return true;
    }
    return false;
}
```
Nesta parte, é verificado as condiçoes de vitória padrões do jogo da velha.

### Função Principal
```cpp

    int resposta, XouO, Continuar;

    LimparTela(int);

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

        if (resposta == 1) { 
            bool jogo = true;
            TabuleiroNovo();

            while (jogo) {
                LimparTela();
                Tabuleiro();

                if (jogadores) { 
                    cout << "Jogador 1(X), faca sua jogada: " << endl;
                    cin >> XouO;
                    while (CasaOcupada(XouO)) { 
                    cout << "Casa ocupada! Escolha outra casa: ";
                    cin >> XouO;
                    }
                } else { 
                    cout << "Jogador 2(O), faca sua jogada: " << endl;
                    sleep(2);
                    do{
                    XouO = dist(gen); 
                    } while (CasaOcupada(XouO)); 
                }


                if (jogadores) { // Revezamento dos jogadores
                    tabuleiro[XouO - 1] = Jogador1;
                    jogadores = false;
                } else {
                    tabuleiro[XouO - 1] = Jogador2;
                    jogadores = true;
                }

                if (vitoriaX()) { 
                    LimparTela();
                    Tabuleiro();
                    cout << "\n\n\nJOGADOR 1(X) GANHOU!!! Parebens :D\n\n\n";
                    contadorX1++;
                    cout << "Pontuacao! \nJogador 1(X): " << contadorX1 << "  Jogador 2(O): " << contadorO1 << endl;
                    jogo = false;
                } else if (vitoriaO()) { 
                    LimparTela();
                    Tabuleiro();
                    cout << "\n\n\nJOGADOR 2(O) GANHOU!!! Parebens :D\n\n\n";
                    contadorO1++;
                    cout << "Pontuacao! \nJogador 1(X): " << contadorX1 << "  Jogador 2(O): " << contadorO1 << endl;
                    jogo = false;
                }

                    bool velha = true; 
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

        } else if (resposta == 2) { 
            bool jogo = true;
            TabuleiroNovo();

            while (jogo) {
                LimparTela();
                Tabuleiro();

                if (jogadores) { 
                    cout << "Jogador 1(X), faca sua jogada: " << endl;
                } else {
                    cout << "Jogador 2(O), faca sua jogada: " << endl;
                }

                cin >> XouO;

                while (CasaOcupada(XouO)) {
                    cout << "Casa ocupada! Escolha outra casa: ";
                    cin >> XouO;
                }

                if (jogadores) { 
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
```

Função principal do código, apresentando o menu e suas opções de jogo e o conteudo em geral que faz o programa funcionar de sua melhor maneira.

## 📍Conclusão

Este jogo da velha é uma aplicação simples que demonstra conceitos fundamentais de programação em C++. Foi feito como projeto computacional para a matéria Computação para Engenharia. O jogo apresenta os conceitos de vetores, funções, loops e manipulação de entradas/saídas em C++.

