#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
///**********************************Mini Projet JEU  Pendu*******************************************

int piocherMot(char *motPioche);
int existe(char mot[],char c);
char readchar();
char lirecarac(); //we always declare it before the main execution at least if you write the function later than the code source
void change(char mot[],char *m,char c);
void remplir(char *m,int n)
{
  int i;
    for(i = 0;i<n;i++)
        m[i] = '*';
    m[i] = '\0';
   // m[i] = '\0';// in order to close the string
}
void jeu(char mot[],char *m)
{
    char c = 0;
    int t;
    t = 10;
    do{

         printf("Donner un caractére adéquat il vous reste %d chances:\n",t);

         c = lirecarac();

        if(existe(mot,c)!= -1) //our existe function return the place of the char
            {
            change(mot,m,c);
            printf("\n*********ALLEZ*******\n");
            puts(m);

        }else{
        t--;
        }
    }while(existe(m,'*')!= -1 && t>0 );
    if(t>0)
        {
        printf("\nVous avez gagnés le jeu haha\n ");
        printf("\n ***********eh ben FELICITATION *******************\n ");
        }

    else
     printf("\nVous avez perdu le jeu\n");



  // printf("\n ")
}
char lirecarac()
{
char c = 0;
    do{
        c = getchar();
        c = toupper(c);
    }while( c == '\n'); //there is a one-line code that can do that, super intuitive
    //strlen(c)<0 ||
    return c;
}
void change(char mot[],char *m,char c)
{
    for(int i = 0;mot[i];i++)
        if(mot[i] == c)
            m[i] = c;

}
int existe(char mot[],char c)
{
    int i;
    i = 0;
    do{
        if(mot[i] == c)
            return i;
        i++;
    }while(mot[i]);
return -1;
}
int main()
{


    char *ms,mot[100];
    int tailleMot = 0;
    if (!piocherMot(mot))
        exit(0);
    tailleMot = strlen(mot);
    ms = (char *)malloc(tailleMot*sizeof(char));
    remplir(ms,tailleMot);


    printf("\n************************ALLEZ LE JEU À COMMENCÉ************************** \n");
   jeu(mot,ms);

exit(0);
}
