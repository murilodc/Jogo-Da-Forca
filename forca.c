#include <stdio.h>
#include <string.h>

void chuta(char chutes[26], int* tentativas){
    char chute;
    scanf(" %c", &chute);
    chutes[(*tentativas)] = chute;
    (*tentativas)++;
}

int jachutou(char letra, char chutes[26], int tentativas) {
    int achou = 0;
    for(int j = 0; j < tentativas; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaForca(char palavraSecreta[20], char chutes[26], int tentativas){
        for(int i=0; i < strlen(palavraSecreta); i++) {
            int achou = jachutou(palavraSecreta[i], chutes, tentativas);
            if(achou){
                printf("%c ", palavraSecreta[i]);
            }else{
                printf("_ ");
            }
        }
        printf("\n");
}

void escolhePalavra(char palavraSecreta[20]){
    sprintf(palavraSecreta, "melancia");
}

int main() {

    char palavraSecreta[20];

    int acertou = 0;
    int enforcou = 0;
    char chutes[26];
    int tentativas = 0;

    printf("********************");
    printf("*   Jogo Da Forca   ");
    printf("********************\n");


    do{
        desenhaForca(palavraSecreta, chutes, tentativas);
        chuta(chutes, &tentativas);
    }while(!acertou && !enforcou);
}