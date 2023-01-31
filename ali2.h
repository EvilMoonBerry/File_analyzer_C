/*******************************************************************/
/*
 * Päivämäärä:17.03.2021
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:https://www.geeksforgeeks.org/ (Linkitetty listan toiminta),
 */
/*******************************************************************/

#ifndef ali2_h
#define ali2_h
#define MAX 60
#include "paaohjelma.h"

char *fileName(char filename[]);

task *analyzer(data *pD, task *arr_task);

void loop(task pT);

task *writeInFile(char *fileName, task *pT);

task *printer(task *pT);

data *freeDataMemory(data *pD);

task *freeTaskMemory(task *pT);
#endif

/*******************************************************************/
/* eof */