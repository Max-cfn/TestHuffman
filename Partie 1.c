#include <stdio.h>
#include <stdlib.h>
#include "Partie 1.h"

void traduire(){
 int i;

 FILE* fichier;
 FILE* fichier2;
 fichier=fopen("entree.txt","r+");
 fichier2=fopen("sortie.txt","w");
 int bit[8];
 if(fichier !=NULL && fichier2 !=NULL){
    int lettre;
    while((lettre=fgetc(fichier)) != EOF){

    for(i=0;i<8;i++){
        bit[i]=0;
    }
    for(i=7;lettre>0;i--){
        bit[i]=lettre%2;
        lettre=lettre/2;
    }
    for(i=0;i<8;i++){
        if(bit[i]==0){
            fputc('0',fichier2);
        }
        else
            fputc('1',fichier2);
    }

 }
 fclose(fichier);
 fclose(fichier2);
 }
 }

void nombre(){
     FILE* fichier=NULL;
     FILE* fichier2=NULL;
     fichier=fopen("entree.txt","r");
     fichier2=fopen("sortie.txt","r");
     int choix;
     int stock;
     int compteur=0;
     if(fichier ==NULL || fichier2 == NULL){
        exit(1);
     }
     printf("Vous voulez calculer le nombre de caractere dans quel fichier ?\n");
     printf("1) Fichier d'entree\n");
     printf("2) Fichier traduit\n");
     scanf("%d",&choix);
     if(choix==1){
        while((stock = fgetc(fichier)) != EOF){
            compteur=compteur+1;
        }
        printf("Il y a %d caracteres dans le fichier\n",compteur);
     }
     else{
        while((stock=fgetc(fichier2)) != EOF){
            compteur=compteur+1;
        }
        printf("Il y a %d caracteres dans le fichier\n",compteur);
     }
     fclose(fichier);
     fclose(fichier2);
 }

