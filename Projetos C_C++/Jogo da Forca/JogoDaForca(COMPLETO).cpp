#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

void LimpaTela(){
    system("CLS");
}

string RetornaPalavraAleatoria(){
    string palavras[3] = {"abacaxi","manga","morango"};
    int aleatorio = rand() % 3;
    return palavras[aleatorio];
}

string RetornaMascara(string palavra,int tamanho){
    int i = 0;
    string mascara;
    while(i < tamanho){
        mascara += "_";
        i++;
    }
    return mascara;
}

void ExibeStatus(string mascara,string letrasarriscadas,int tamanho,int tentativasrestantes,string mensagem){
    cout << mensagem << endl;
    cout << "Palavra: " << mascara << "   (Tamanho: "<< tamanho << ")"<< endl;
    cout << "Tentativas: " << tentativasrestantes << endl;
    cout << "Letras Arriscadas: ";
    int i;
    for(i = 0;i < letrasarriscadas.size();i++){
        cout << letrasarriscadas[i] << ", ";
    }

}

int Jogar(int jogadores){
    string palavra;
    if(jogadores == 1){
        palavra = RetornaPalavraAleatoria();
    }else{
        cout << "Digite a palavra a ser adivinhada:\n";
        cin >> palavra;
    }
    int tamanho = palavra.size();
    string mascara = RetornaMascara(palavra,tamanho);
    string letrasarriscadas,chute;
    string mensagem = "Bem-Vindo ao jogo!";
    int tentativas = 0,maximotentativas = 10,i,opcao;
    char letra;
    bool letrarepetida = false, acertouletra = false;
    while((maximotentativas - tentativas > 0) && (palavra != mascara)){
        LimpaTela();
        ExibeStatus(mascara,letrasarriscadas,tamanho,maximotentativas - tentativas,mensagem);
        cout << "\nDigite uma letra:  ";
        cin >> letra;
        if(letra == '1'){
            cout << endl;
            cout << "Digite a palavra:\n";
            cin >> chute;
            if(chute == palavra){
                mascara = palavra;
            }else{
                tentativas = maximotentativas;
            }
        }
        for(i = 0;i < tentativas;i++){
        if(letrasarriscadas[i] == letra){
            mensagem = "Essa letra ja foi digitada!";
            letrarepetida = true;
        }
    }
    if(letrarepetida == false){
        letrasarriscadas += tolower(letra);
        for(i = 0;i < tamanho;i++){
            if(palavra[i] == tolower(letra)){
                mascara[i] = palavra[i];
                acertouletra = true;
            }
        }
        if(acertouletra == false){
            mensagem = "Errou uma letra!";
        }else{
            mensagem = "Acertou uma letra!";

        }
        tentativas++;
    }
        letrarepetida = false;
        acertouletra = false;
    }
    if(palavra == mascara){
        LimpaTela();
        cout << "Voce Venceu!\n";
        cout << "A palavra era: " << palavra << endl;
        cout << "Deseja reiniciar?\n";
        cout << "1 - Sim\n";
        cout << "2 - Nao\n";
        cin >> opcao;
        return opcao;
    }else{
        LimpaTela();
        cout << "Voce Perdeu!\n";
        cout << "A palavra era: " << palavra << endl;
        cout << "Deseja reiniciar?\n";
        cout << "1 - Sim\n";
        cout << "2 - Nao\n";
        cin >> opcao;
        return opcao;
    }
}

void MenuInicial(){
    int opcao = 0;
    while(opcao < 1 || opcao > 4){
        LimpaTela();
        cout << "MENU:\n";
        cout << "Opcao 1 - Jogar\n";
        cout << "Opcao 2 - Jogar em Dupla\n";
        cout << "Opcao 3 - Sobre\n";
        cout << "Opcao 4 - Sair\n";
        cout << "Escolha uma opcao e tecle ENTER: ";
        cin >> opcao;
        switch(opcao){
        case 1:
            if(Jogar(1) == 1){
                MenuInicial();
            }
            break;
        case 2:
             if(Jogar(2) == 1){
                MenuInicial();
            }
        case 3:
            LimpaTela();
            cout << "Jogo desenvolvido por Eneas em 2020.\n" << endl;
            cout << "1 - Voltar\n";
            cout << "2 - Sair\n";
            cin >> opcao;
            if(opcao == 1){
                MenuInicial();
            }
            break;
        case 4:
            cout << "Ate mais!\n";
            break;
        }
    }
}


int main(){
    srand((unsigned)time(NULL));
    cout << "Bem vindo ao jogo!\n";
    MenuInicial();

    return 0;
}
