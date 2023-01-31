/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:C-Harjoitustyö. Perustaso
 * Tekijä:Petra Sjögren
 * Opiskelijanumero:610435
 * Päivämäärä:17.03.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:https://www.geeksforgeeks.org/ (Linkitetty listan toiminta), Tomi Enberg(Tiedoston luku),Roope Luukkainen(tiedoston luku)
 */
/*******************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ali1.h"
#include "ali2.h"
#include "paaohjelma.h"
#include <time.h>

/*Ohjelma, joka kysyy ja palauttaa luettavan tiedoston nimen*/
char* fileName(char filename[]){
    char name[50];
    printf("Anna tiedoston nimi: ");
    scanf("%s", name);
    strcat(filename, name);
    return filename;
}

/*Tutkitaan linkitetyn listan tiedot ja lisätään ne listaan*/
task *analyzer(data *pD, task *arr_task){
    int i, ID,summ=0,avrg=0,total;

    data *ptr=pD;
    if (ptr == NULL) {
         printf("Ei analysoitavaa, lue ensin palautustiedosto.\n");
         printf("\n");
    }
    
    else{
        for (i=0;i<=MAX;++i){
            strcpy(arr_task[i].taskN,"Tyhjä");/*Alustetaan lista*/
            arr_task[i].kpl=0;
        }
        /*Lisätään linkitetyn listan tiedot uuteen pohjustettuun listaan*/
        while (ptr != NULL) {
            ID=ptr->taskID;
            strcpy(arr_task[ID-1].taskN,ptr->taskName);
            arr_task[ID-1].kpl++;
            ptr = ptr->pNext;
        }
    /*Käydään lista läpi ja tutkitaan, jos läytyy tehtäviä ne lasketaan yhteen ja lasketaa monesta tehtävästä löytyy palautettuja tehtäviä*/
    for(i=0;i<MAX;++i){
        if(arr_task[i].kpl!= 0){
            summ = summ + arr_task[i].kpl;
            avrg = avrg +1;
        }
    }

    total=summ/avrg; /*Lasketaan keskiarvo*/
    printf("Palautuksia oli yhteensä %d, %d eri tehtävässä, keskimäärin %d per tehtävä.\n",summ,avrg,total);
    printf("\n");
    }
    return arr_task;
}


/*tulostaa tehtävänumeron ja monta tehtävää on palautettu*/
void loop(task pT){
    printf("%s;%d\n",pT.taskN,pT.kpl);
}

/*Kirjoitetaan tiedotstoon listan tiedot*/
task *writeInFile(char *fileName,task *pT){
    char t[]="Tehtävä;Lkm\n";
    int i=0;
    FILE *name;
    /*Tiedoston avaus ja virheen tarkastus*/
    if ((name = fopen(fileName,"w"))== NULL){
        perror("Tiedoston avaaminen epäonnistui.\n");
        exit(1);
    }
    /*Tulostetaan tiedostoon*/
    fprintf(name,"%s",t);
    while(i<MAX){
        fprintf(name, "%s;%d\n",pT[i].taskN,pT[i].kpl);
        ++i;
        }
        
    fclose(name);
    return 0;
    }

/*Tulostetaan listan tiedot*/
task *printer(task *pT){
    char filename[50]="";
    char x;
    int i;
    task *ptr=pT;
    if (ptr == NULL) {
         printf("Ei tulostettavaa, analysoi ensin palautustiedosto.\n");
    }else{
        printf("Tulosta tiedostoon (k/e): ");
        getchar();
        scanf("%c",&x);
        if (x=='k'){
            fileName(filename);
            writeInFile(filename,pT);
        }else if(x=='e'){
			printf("Tehtävä;Lkm\n");
            for(i=0; i<MAX;++i){
                loop(pT[i]);
            }
        }else{
            printf("Tunnistamaton valinta.\n");
        }
    }
    printf("\n");
    return pT;
}

/*Vapautetaan linkitetty lista*/
data *freeDataMemory(data *pD){
    data*ptr = pD;
    while (ptr != NULL) {
        pD = ptr->pNext;
        free(ptr);
        ptr = pD;
    }
    return pD;
}

/*******************************************************************/
/* eof */