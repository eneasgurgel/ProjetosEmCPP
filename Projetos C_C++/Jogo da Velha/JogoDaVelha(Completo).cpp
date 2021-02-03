#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void MenuInicial();

void LimpaTela(){
    system("CLS");
}

void iniciaTabuleiro(char tabuleiro[3][3]){
    int linha,coluna;
    for(linha = 0;linha < 3;linha++){
        for(coluna = 0;coluna < 3;coluna++){
            tabuleiro[linha][coluna] = '-';
        }
    }
}

void exibeTabuleiro(char tabuleiro[3][3]){
    int linha,coluna;
    for(linha = 0;linha < 3;linha++){
        for(coluna = 0;coluna < 3;coluna++){
            cout << tabuleiro[linha][coluna];
        }
        cout << endl;
    }
}

int confereTabuleiro(char tabuleiro[3][3]){
    int linha,coluna,resultado = 0;
    for(linha = 0;linha < 3;linha++){
                if(tabuleiro[linha][0] == tabuleiro[linha][1] && tabuleiro[linha][1] == tabuleiro[linha][2]){
                    if(tabuleiro[linha][0] == 'X'){
                        resultado = 1;
                    }else if(tabuleiro[linha][0] == 'O'){
                        resultado = 2;
                    }
                }
        }
        for(coluna = 0;coluna < 3;coluna++){
                if(
                   tabuleiro[0][coluna] == tabuleiro[1][coluna] && tabuleiro[1][coluna] == tabuleiro[2][coluna]){
                    if(tabuleiro[0][coluna] == 'X'){
                        resultado = 1;
                    }else if(tabuleiro[0][coluna] == 'O'){
                        resultado = 2;
                    }
                }
        }
        if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]){
            if(tabuleiro[0][0] == 'X'){
                        resultado = 1;
                    }else if(tabuleiro[0][0] == 'O'){
                        resultado = 2;
                    }
        }else if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]){
            if(tabuleiro[0][2] == 'X'){
                        resultado = 1;
                    }else if(tabuleiro[0][2] == 'O'){
                        resultado = 2;
                    }
        }
        return resultado;
}
void exibeinstrucoes(){
    cout << "\nMapa de Posicoes:\n";
    cout << "---------------\n";
    cout << "  7 | 8 | 9\n";
    cout << "  4 | 5 | 6\n";
    cout << "  1 | 2 | 3\n";
    cout << "---------------\n";

}

void jogo(string nome1,string nome2,int ponto1, int ponto2){
    char tabuleiro[3][3];
    int linhajog,colunajog,rodadas=0,turno = 1;
    int estadoJogo = 1,linha,coluna,opcao,posicao;
    bool jogadacerta;
    iniciaTabuleiro(tabuleiro);
    string nome;
    nome = nome1;
    while(rodadas < 9 && estadoJogo == 1){
        exibeTabuleiro(tabuleiro);
        exibeinstrucoes();
        cout << nome1 << " " << ponto1 << " X " << ponto2 << " " << nome2 << endl;
        cout << "\nRodada: " << rodadas << endl;
        jogadacerta = false;
        int posicoes[9][2] = {{2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2}};
        while(jogadacerta == false){
            cout << nome << ", digite um numero no mapa:";
            cin >> posicao;
            linhajog = posicoes[posicao - 1][0];
            colunajog = posicoes[posicao - 1][1];
            if(tabuleiro[linhajog][colunajog] == '-'){
                jogadacerta = true;
                if(turno == 1){
                    tabuleiro[linhajog][colunajog] = 'X';
                    nome = nome2;
                    turno = 2;
                }else{
                    tabuleiro[linhajog][colunajog] = 'O';
                    nome = nome1;
                    turno = 1;
                }
            }
        }

        LimpaTela();
        if(confereTabuleiro(tabuleiro) == 1){
            cout << "O jogador X venceu!\n";
            ponto1++;
            estadoJogo = 0;
        }else if(confereTabuleiro(tabuleiro) == 2){
            cout << "O jogador O venceu!\n";
            ponto2++;
            estadoJogo = 0;
        }
        rodadas++;
    }
    cout << "Fim de jogo!\n";
    exibeTabuleiro(tabuleiro);
    cout << "\nDeseja Reiniciar o jogo?\n";
    cout << "1 - Continuar jogando\n";
    cout << "2 - Menu inicial\n";
    cout << "3 - Sair\n";
    cin >> opcao;
    if(opcao == 1){
        LimpaTela();
        jogo(nome1,nome2,ponto1,ponto2);
    }else if(opcao == 2){
        LimpaTela();
        MenuInicial();
    }
}

void MenuInicial(){
    int opcao = 0;
    string nome1,nome2;
    while(opcao < 1 || opcao > 3){
        cout << endl;
        cout << "MENU:\n";
        cout << "Opcao 1 - Jogar\n";
        cout << "Opcao 2 - Sobre\n";
        cout << "Opcao 3 - Sair\n";
        cout << "Escolha uma opcao e tecle ENTER: ";
        cin >> opcao;
        LimpaTela();
        switch(opcao){
        case 1:
            cout << "Digite o nome do jogador 1:\n";
            cin >> nome1;
            cout << "Digite o nome do jogador 2:\n";
            cin >> nome2;
            jogo(nome1,nome2,0,0);
            break;
        case 2:
            cout << "Informacoes do jogo\n";
            break;
        case 3:
            cout << "Ate mais!\n";
            break;
        }
    }
}


int main(){
    cout << "Bem vindo ao Jogo da Velha!\n";
    MenuInicial();

    return 0;
}
