/*******************************************************************/
/*
 * Päivämäärä:17.03.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:https://www.geeksforgeeks.org/ (Linkitetty listan toiminta)
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paaohjelma.h"
#include "ali2.h"
#include "ali1.h"
/*Valikon tulostus*/
int menu(int choice)
{
    printf("1) Lue tiedosto\n");
    printf("2) Analysoi tiedot\n");
    printf("3) Tulosta tulokset\n");
    printf("0) Lopeta\n");
    printf("Valintasi: ");
    scanf("%d", &choice);
    return choice;
}

/*Pääohjelma*/
int main(void)
{
    task arr_task[MAX];
    data *pStart = NULL;

    int choice;
    do
    {
        choice = menu(choice);
        switch (choice)
        {
        case 1:
            pStart = openFile(pStart);
            break;
        case 2:
            analyzer(pStart, arr_task);
            break;
        case 3:
            printer(arr_task);
            break;
        case 0:
            printf("Kiitos ohjelman käytöstä.\n");
            printf("\n");
            freeDataMemory(pStart);
            break;
        default:
            printf("Tuntematon valinta, yritä uudestaan.\n");
            printf("\n");
            break;
        }
    } while (choice != 0);
    return (0);
}

/*******************************************************************/
/* eof */