#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>

char palavraSecreta[20];
char chutes[26];
int chutesDados = 0;

void chuta(){
    char chute;
    scanf(" %c", &chute);
    chutes[chutesDados] = chute;
    chutesDados++;
}

int jachutou(char letra){
    int achou = 0;

    for(int j = 0; j < chutesDados; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaForca(){
        for(int i=0; i < strlen(palavraSecreta); i++) {
            int achou = jachutou(palavraSecreta[i]);
            if(achou){
                printf("%c ", palavraSecreta[i]);
            }else{
                printf("_ ");
            }
        }
        printf("\n");
}

void escolhePalavra(){
    FILE* f;
    f = fopen("palavras.txt", "r");
    if(f == 0){
        printf("Desculpe, banco de dados nao disponivel\n\n");
        exit(1);
    }
    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;
    
    for(int i = 0; i<= randomico; i++){
        fscanf(f, "%s", palavraSecreta);
    }


    fclose(f);
}

int ganhou() {
    for(int i = 0; i < strlen(palavraSecreta); i++){
        if(!jachutou(palavraSecreta[i])){
            return 0;
        }
    }
    return 1;
}

int enforcou(){
    int erros = 0;
    for(int i = 0; i < chutesDados; i++){
        int existe = 0;
        for(int j = 0; j < strlen(palavraSecreta); j++){
            if(chutes[i] == palavraSecreta[j]){
                existe = 1;
                break;
            }
        }
        if(!existe){
            erros++;
        }
    }
    return erros >= 5;
}

int main() { 

    printf("********************");
    printf("*   Jogo Da Forca   ");
    printf("********************\n");

    escolhePalavra();

    do{
        desenhaForca();
        chuta();
        ganhou();
    }while(!ganhou() && !enforcou());

    if(ganhou()){
        printf("\n\nPARABENS VOCE GANHOU\n\n");
    }else{
        printf("\n\nVoce perdeu! A palavra secreta era %s\n\n", palavraSecreta);
    }

}