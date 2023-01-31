/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:C-Harjoitustyö. Perustaso
 * Tekijä:Petra Sjögren
 * Opiskelijanumero:610435
 * Päivämäärä:17.03.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:https://www.geeksforgeeks.org/ (Linkitetty listan toiminta), Tomi Enberg(Tiedoston luku),Roope Luukkainen(tiedoston luku)
 */
/*******************************************************************/
#include "ali1.h"
#include "ali2.h"
#include "paaohjelma.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/*Avataan tiedosto, josta luetaan dataa ja lisätään data linkitettyyn listaan.*/
data *openFile(data *pD){
    int i=0;
    char lineData[52],buffer[100],buff[100];
    char name[50]="";
    data *pNew, *ptr, *ptrO;
    FILE *datafile;
    time_t firstT,lastT,testT;
    struct tm first,test,last;
    pD=freeDataMemory(pD);/*Vapautetaan edellisen linkitetyn listan muisti*/
    fileName(name);
    /*Avataan tiedosto ja virheen tarkastus*/
    if ((datafile = fopen(name,"r"))== NULL){
        printf("Tiedoston avaaminen epäonnistui.");
        exit(1);
    }
    /*Varataan tarvittava tila ja virheen tarkastus*/
    while (fgets(lineData, 50, datafile) !=NULL){ 
        if ((pNew =(data*)malloc(sizeof(data))) == NULL){
            printf("Muistinvaraus epäonnistui\n");
            exit(1);
        }

        memset(&(pNew->time),0,sizeof(pNew->time));
        if (lineData[0] == 'P'){
            continue;
        }else{
            pNew->time.tm_mday=atoi(strtok(lineData, "/")); /*Päivä*/
            pNew->time.tm_mon=atoi(strtok(NULL, "/"))-1;/*Kuukausi*/
            pNew->time.tm_year=atoi(strtok(NULL, ","))+100;/*Vuosi*/
            pNew->time.tm_hour=atoi(strtok(NULL, ":"));/*Tunti*/
            pNew->time.tm_min=atoi(strtok(NULL,";"));/*Minuutti*/
            strcpy(pNew->taskName,strtok(NULL,";"));/*Tehtävän nimi*/
            pNew->taskID=atoi(strtok(NULL, ";"));/*Tetvävä ID*/
            pNew->studentID = atoi(strtok(NULL, "\n"));/*Oppilas numero*/
            pNew->pNext = NULL;
            i=i+1;
            if (pD == NULL){
                pD = pNew;
            }else{
                ptr = pD;
                while (ptr->pNext !=NULL)
                    ptr = ptr->pNext;
                ptr->pNext = pNew;
            }
        }
    }
    fclose(datafile);
    ptrO=pD;
    /*Alustetaan päivien vertailua varten*/
    memset(&first,0,sizeof(first));
    memset(&last,0,sizeof(last));
    memset(&test,0,sizeof(test));

    first=ptrO->time;
    last=ptrO->time;
    firstT=mktime(&first);/*Muutetaan sekunneiksi helpomman vertailun vuoksi*/
    lastT=mktime(&last);

    /*Vertaillaan päiviä sekunttimuodossa, jotta löydetään ensimmäinen ja viimeinen päivä*/
    while (ptrO != NULL){
        test = ptrO->time;
        testT=mktime(&test);
        ptrO = ptrO->pNext;
        if(firstT>testT){
            firstT=testT;
            first =test;
        }else if (lastT<testT){
            lastT=testT;
            last=test;
        }
    }

    strftime(buffer, sizeof(buffer), "%d.%m.%Y", &first);
    strftime(buff, sizeof(buff), "%d.%m.%Y", &last);

    printf("Yhteensä %d palautusta %s - %s väliseltä ajalta.\n",i,buffer,buff);
    printf("\n");
    return pD;
}



/*******************************************************************/
/* eof */