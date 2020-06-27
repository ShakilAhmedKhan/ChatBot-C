//Bismillahir Rahmanir Rahim

#include <stdio.h>
#include <stdlib.h>


int countLine = 0;
int i = 0;
int count = 0;

char countQ;
char countA;

char qui[] = "quit\n";

char singleLine[200];

char human_talks[150];

char cont;

char* eof;



int main()
{


    FILE *fptr;


    fptr = fopen("Questions.txt", "r");

     if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }



    while ( !feof (fptr)){

            //fgetc(count,fptr);

//            char countQ = fgetc(fptr);
            char countA = fgets(singleLine, 200 , fptr);

            countLine++;

    }


    printf("%d\n",countLine);


    fclose(fptr);


    char *Quest[countLine];

    char *Ans[countLine];




    fptr = fopen("Questions.txt", "r");

     if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

   while((eof = fgets(singleLine, 150, fptr)) != NULL )
	{
        Quest[i] = strdup(eof);

        i++;

        count++;
    }

    fclose(fptr);


    //Assiging the answers

    FILE *fptrans;

    fptrans = fopen("Answers.txt", "r");
     if (fptrans == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    int i = 0;
    while((eof = fgets(singleLine, 150, fptrans)) != NULL )
	{
        //Quest[i][strlen(Quest[i]) - 1] = '\0';
        Ans[i] = strdup(eof);

        i++;
    }

    fclose(fptrans);




    //we will use the do - while loop here

        printf("                                   Assalamu alaikum\n");
        printf("                               I am a simple chat-bot\n");
        printf("                  Please ask only those questions that I have learnt.\n");
        printf("                                 Type 'quit' to exit                       \n\n");



       // printf("                  If you want to train me you can enter the password\n\n");


    do {

    printf("Ask : ");

    fgets(human_talks, 150, stdin);

//    strncpy(refined_talk,human_talks,strlen(human_talks)-1);


    if (strcmp(human_talks,qui)== 0){
        printf("\n***Allah Hafiz***\n");
        return 0;

    }


    for (i = 0; i <= count; i++){

    if (strcmp(human_talks,Quest[i])== 0){

        printf("Bot : %s",Ans[i]);
        break;

    }
    }

    //cont = getch();

    cont = 'y';

    }
    while (cont == 'y');

    return 0;
}
