#include <stdio.h>
#include <string.h>

int main() {

    char palaraSecreta[20];

    sprintf(palaraSecreta, "Melancia");

    int acertou = 0;
    int enforcou = 0;
    char chutes[26];
    int tentativas = 0;

    printf("********************");
    printf("*   Jogo Da Forca   ");
    printf("********************");


    do{

        for(int i=0; i < strlen(palaraSecreta); i++) {
            
            int achou = 0;

            printf("Estou vendo a letra secreta %c\n", palaraSecreta[i]);
            
            for(int j = 0; j < tentativas; j++){
                printf("-> Chute %c\n", chutes[j]);
                if(chutes[j] == palaraSecreta[i]){
                    printf("---> chute correto \n");
                    achou = 1;
                    break;
                }
            }

            if(achou){
                printf("%c ", palaraSecreta[i]);
            }else{
                printf("_ ");
            }
        }
        printf("\n");

        char chute;
        scanf(" %c, &chute");

        chutes[tentativas] = chute;
        tentativas++;

    }while(!acertou && !enforcou);
}