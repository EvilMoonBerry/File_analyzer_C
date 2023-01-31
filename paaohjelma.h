/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:C-Harjoitustyö. Perustaso
 * Tekijä:Petra Sjögren
 * Opiskelijanumero:610435
 * Päivämäärä:17.03.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:https://www.geeksforgeeks.org/ (Linkitetty listan toiminta), Tomi Enberg(Tiedoston luku),Roope Luukkainen(tiedoston luku)
 */
/*******************************************************************/
#ifndef paaohjelma_h
#define paaohjelma_h
#include <time.h>

typedef struct DATA{
    struct tm time;
    char taskName[15];
    int taskID, studentID;
    struct DATA *pNext;
}data;

typedef struct TASK{
    char taskN[15];
    int kpl;
}task;

int menu(int choice);
int main(void);
#endif
/*******************************************************************/
/* eof */