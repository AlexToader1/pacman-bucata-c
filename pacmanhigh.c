#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char player_name[30];
    int player_score;
}HIGHSCORE;

int main()
{
    FILE *input_score;
    FILE *highscore_list;
    HIGHSCORE high_list[11];
    char temporary_name[30];
    int temporary_score;
    int i=0;


    if ((input_score=fopen("input.txt","r"))==NULL)
        exit(1);
    if ((highscore_list=fopen("class.txt","r+t"))==NULL)
        exit(1);


    fscanf(input_score,"%s",temporary_name);
    fflush(stdin);
    fscanf(input_score,"%d",&temporary_score);
    fflush(stdin);

    fclose(fopen("input.txt", "w"));

    for (i=0;i<10;i++)
    {
        fscanf(highscore_list,"%s",high_list[i].player_name);
        fflush(stdin);
        fscanf(highscore_list,"%d",&high_list[i].player_score);
        fflush(stdin);
    }

    high_list[10].player_score=temporary_score;
    strcpy(high_list[10].player_name,temporary_name);

    char auxiliary_name[30]="";
    int auxiliary_score;

    for (i=0;i<10;i++)
    {
        for (int j=i+1;j<=10;j++)
        {
            if (high_list[i].player_score<high_list[j].player_score)
            {
                strcpy(auxiliary_name,high_list[i].player_name);
                strcpy(high_list[i].player_name,high_list[j].player_name);
                strcpy(high_list[j].player_name,auxiliary_name);

                auxiliary_score=high_list[i].player_score;
                high_list[i].player_score=high_list[j].player_score;
                high_list[j].player_score=auxiliary_score;
            }
        }
    }


    rewind(highscore_list);

    for (i=0;i<10;i++)
    {
        fprintf(highscore_list,"%s ",high_list[i].player_name);
        fprintf(highscore_list,"%d\n",high_list[i].player_score);
    }

    fclose(highscore_list);

    return 0;
}
