#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "dico.h"
///on fait cet script pour acceder au fichier dictionnaire et afficher une mot alea pour le jeu


int piocherMot(char *motPioche)
{
FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
int nombreMots = 0, numMotChoisi = 0, i = 0;
int caractereLu = 0;
dico = fopen("dico.txt","r"); //fonction pour ouvrir certain fichier with read only mode
    if(dico == NULL)
    {
        printf("\nImpossible de charger le dictionnaire de mots");
    return 0;
    }
// On compte le nombre de mots dans le fichier (il suffit de compter les entrées \n
do
{
caractereLu = fgetc(dico); ///fgetc (caractère par caractère) checker char by char
if (caractereLu == '\n')
        nombreMots++;
} while(caractereLu != EOF); //!= END OF FILE
numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard
// On recommence à lire le fichier depuis le début. On s'arrête lorsqu'on est arrivé au bon mot
rewind(dico); ///Moves the file position indicator to the beginning of the given file stream
while (numMotChoisi > 0)
{
///En fait cette boucle nous assure que notre mot ne sera pas vide(\n)
caractereLu = fgetc(dico);///fgetc (caractère par caractère) checker char by char
if (caractereLu == '\n')
        numMotChoisi--; ///tell me why
}

fgets(motPioche, 100, dico);
motPioche[strlen(motPioche) - 1] = '\0';
fclose(dico);

return 1;
}
int nombreAleatoire(nombreMots)
{
    srand(time(NULL));
    return (rand() % nombreMots);
}


