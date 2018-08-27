#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define nameMaxLength 20
void printRecords (int numRecords,char **fNameArray,char **lNameArray,float *score);
void addRecords (int numRecords,char **fNameArray,char **lNameArray,float *score);
void deleteRecords (int numRecords,char **fNameArray,char **lNameArray,float *score);
void searchRecord (int numRecords,char **fNameArray,char **lNameArray,float *score);
void sortScore (int numRecords,char **fNameArray,char **lNameArray,float *score);
void sortLastName (int numRecords,char **fNameArray,char **lNameArray,float *score);
void medianScore (int numRecords,char **fNameArray,char **lNameArray,float *score);

int main()
{
    int i,menuInput=1;
    int numRecords;

    puts("Please indicate number of records you want to enter (min 5, max 15): ");
    scanf("%d",&numRecords);
    char **fNameArray;
    char **lNameArray;
    float *score;

    fNameArray= (char**)calloc((numRecords),sizeof(char*));
    lNameArray=(char**)calloc(numRecords,sizeof(char*));
    score= (float*) calloc (numRecords,sizeof(float));


    printf("Please input records of students (enter a new line after each record), with following format\nfirst name last name score\n");
    for(i=0; i<numRecords; i++)
    {
        fNameArray[i]=(char*) calloc(nameMaxLength+1,sizeof(char));
        lNameArray[i]=(char*) calloc(nameMaxLength+1,sizeof(char));
        scanf("%s%s%f",fNameArray[i],lNameArray[i],&score[i]);
    }
    for (i=0; i<numRecords; i++)
    {
        fNameArray[i][0]=toupper(fNameArray[i][0]);
        lNameArray[i][0]=toupper(lNameArray[i][0]);
    }

    while (menuInput!= 0)
    {
        printf("\n");
        puts("Print records (press 1) ");
        puts("Add a new record (press 2) ");
        puts("Delete Record(s) (press 3) ");
        puts("Search by last name (press 4) ");
        puts("Sort by score (press 5) ");
        puts("Sort by last name (press 6)  ");
        puts("Find median score (press 7) ");
        puts("Exit the program (press 0) ");
        printf("\n");
        scanf("%d",&menuInput);

        switch(menuInput)
        {

        case 1:
            printRecords(numRecords,fNameArray,lNameArray,score);
            break;

        case 2:
            addRecords(numRecords,fNameArray,lNameArray,score);
            break;

        case 3:
            deleteRecords(numRecords,fNameArray,lNameArray,score);
            break;

        case 4:
            searchRecord(numRecords,fNameArray,lNameArray,score);
            break;

        case 5:
            sortScore(numRecords,fNameArray,lNameArray,score);
            break;

        case 6:
            sortLastName(numRecords,fNameArray,lNameArray,score);
            break;
        case 7:
            medianScore(numRecords,fNameArray,lNameArray,score);
            break;

        case 0:
            exit(0);
            break;

        }

    }
    return 0;
}

void printRecords ( int numRecords,char **fNameArray,char **lNameArray,float *score)
{

    int i;
    printf("\n");
    for (i=0; i<numRecords; i++)
    {
        printf("First Name: %s, Last Name: %s, Score: %0.2f\n", fNameArray[i],lNameArray[i],score[i]);
    }
}



void addRecords (int numRecords,char **fNameArray,char **lNameArray,float *score)
{
    char **newFName, **newLName;
    int *newScore;
    int addNumber,i;

    puts("Please enter the number of records you want to add \n");
    scanf("%d",&addNumber);
    /*
    //code to add records
    newFName=(char**)realloc( *fNameArray,(numRecords+addNumber)*sizeof(char*));
    newLName=(char**)realloc( *lNameArray,(numRecords+addNumber)*sizeof(char*));
    newScore=(float*)realloc(score,(numRecords+addNumber)*sizeof(float));
    puts("Please enter the records you want to add \n(enter a new line after each record), with following format\nfirst name last name score\n");
    for(i=numRecords; i<(numRecords+addNumber); i++)
    {
        newFName[i]=(char*) calloc(nameMaxLength+1,sizeof(char));
        newLName[i]=(char*) calloc(nameMaxLength+1,sizeof(char));
        scanf("%s%s%f",newFName[i],newLName[i],&newScore[i]);
    }
    numRecords=numRecords+addNumber;


    for (i=0; i<numRecords; i++)
    {
        printf("First Name: %s, Last Name: %s, Score: %0.2f\n", newFName[i],newLName[i],newScore[i]);
    }

*/
}




void deleteRecords (int numRecords,char **fNameArray,char **lNameArray,float *score)
{
    int i,counter;
    char test[20];
    printf("\n");
    puts("Please input the Last Name of student you want to Delete: ");
    scanf("%s",&test);
    test[0]=toupper(test[0]);



    /*

    Here goes code to delete records

    */


}

void searchRecord (int numRecords,char **fNameArray,char **lNameArray,float *score)
{
    int i;
    char test[20];
    printf("\n");
    puts("Please input the Last Name of person you want to Search: ");
    scanf("%s",&test);
    test[0]=toupper(test[0]);

    for (i=0; i<numRecords; i++)
    {
        if (strcmp(lNameArray[i],test)==0)
        {
            printf("\nFirst Name: %s, Last Name: %s, Score: %0.2f", fNameArray[i],lNameArray[i],score[i]);
        }

    }
    printf("\n");
}
void sortScore (int numRecords,char **fNameArray,char **lNameArray,float *score)
{
    int i,j, tempScore;
    char tempFName[20], tempLName[20];

    for (i=0; i<numRecords-1; i++)
    {
        for (j=0; j<numRecords-1-i; j++)
        {
            if (score[j]>score[j+1])
            {
                tempScore=score[j];
                score[j]=score[j+1];
                score[j+1]= tempScore;

                strcpy(tempFName,fNameArray[j]);
                strcpy(fNameArray[j],fNameArray[j+1]);
                strcpy(fNameArray[j+1],tempFName);

                strcpy(tempLName,lNameArray[j]);
                strcpy(lNameArray[j],lNameArray[j+1]);
                strcpy(lNameArray[j+1],tempLName);
            }
        }
    }
    printf("\nThe records sorted in ascending order by score are:\n");
    printRecords(numRecords,fNameArray,lNameArray,score);
}
void sortLastName (int numRecords,char **fNameArray,char **lNameArray,float *score)
{
    int i,j,tempScore;
    char tempLName[20], tempFName[20];

    for (i=0; i<numRecords-1; i++)
    {
        for (j=0; j<numRecords-i-1; j++)
        {
            if (strcmp(lNameArray[j],lNameArray[j+1])>0)
            {
                strcpy(tempLName,lNameArray[j]);
                strcpy(lNameArray[j],lNameArray[j+1]);
                strcpy(lNameArray[j+1],tempLName);

                tempScore=score[j];
                score[j]=score[j+1];
                score[j+1]= tempScore;

                strcpy(tempFName,fNameArray[j]);
                strcpy(fNameArray[j],fNameArray[j+1]);
                strcpy(fNameArray[j+1],tempFName);
            }
        }


    }
    printf("\nThe records sorted in ascending order by their last name are:\n");
    printRecords(numRecords,fNameArray,lNameArray,score);
}
void medianScore (int numRecords,char **fNameArray,char **lNameArray,float *score)
{

    int i,j, tempScore;

    for (i=0; i<numRecords-1; i++)
    {
        for (j=0; j<numRecords-1-i; j++)
        {
            if (score[j]>score[j+1])
            {
                tempScore=score[j];
                score[j]=score[j+1];
                score[j+1]= tempScore;
            }
        }
    }


    if(numRecords%2==0)
    {
        printf("\nThe median score is: %0.2f.\n",(score[numRecords/2] + score[numRecords/2 - 1]) / 2.0);
    }
    else
    {
        printf("\nThe median score is: %0.2f\n",score[numRecords/2]);
    }

}

