#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
        char nome[50];
        int gols;
}jogador;

int main( ) {
    
    FILE *fp;
    char quebra[2];
    int qtd, i, j;
    fp = fopen("highscores.txt","r+");
    if(fp == NULL) {
          exit(1);
    }
    fscanf(fp,"%d",&qtd);
    jogador jg[qtd+1], aux;
    printf("%d\n",qtd);
    fgets(quebra,2,fp);
    for(i =0; i < qtd; i++) {
            fgets(jg[i].nome,20,fp);
            fscanf(fp,"%d",&jg[i].gols);             
            jg[i].nome[strlen(jg[i].nome)-1] = '\0';   
            fgets(quebra,2,fp);
            printf("%s\n%d\n",jg[i].nome,jg[i].gols); 

            
    }
    fflush(stdin);
    gets(jg[qtd].nome);
    scanf("%d",&jg[qtd].gols);
    for(i = qtd; i >=1; i--) {
          for(j = 0; j < i; j++) {
                
                if(jg[j+1].gols >= jg[j].gols) {
                              aux = jg[j];
                              jg[j] = jg[j+1];
                              jg[j+1] = aux;
                }
          }
    }
    fseek(fp,0,SEEK_SET);
    if(qtd < 5) {
           qtd++;
    }
    else {
         qtd = 5;
    }
    fprintf(fp,"%d\n",qtd);
    for(i = 0; i < qtd; i++) {
          fprintf(fp,"%s\n%d\n",jg[i].nome,jg[i].gols);
    }
    fclose(fp);    
    system("pause");
    return 0;
}
                            
    
