#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "getopt.h"
#include "temp_api.h"

int main(int argc, char* argv[])
{
    char stringFile[200];
    char file_name[200] = { 0 };
    int month = 0;
    int year = 0;
    int flag_file = 0;
    int flag_month = 0;
    int flag_year = 0;
    int opt;

    while ((opt = getopt(argc, argv, "hf:m:y:")) != -1)
    {
        switch (opt)
        {
        case 'h':
            printf("App temperature statistic (year/month: average, min, max).\n");
            printf("-f add csv file located in project folder.\n");
            printf("-y xxxx for choose xxxx year.\n");
            printf("-m xx for choose xx month.\n");
            return 0;
            break;
        case 'f': 
            printf("File name -> %s\n", optarg);
            strcpy(file_name, optarg);
            flag_file = 1;
            break;
        case 'y': 
            year = atoi(optarg);
            printf("===================================\n");
            printf("=============YEAR %d=============\n", year);
            flag_year = 1;
            break;
        case 'm': 
            month = atoi(optarg);
            printf("===================================\n");
            printf("==============MONTH %d==============\n", month);
            flag_month = 1;
            break;
        case '?': 
            printf("Error found !\n"); 
            break;
        }
    }

    if (flag_file != 0)
    {
        FILE* fp = fopen(file_name, "r");

        if (fp == NULL)
        {
            perror("Unable to open the file.");
            exit(-1);
        }
        
        if (flag_month != 0)
        {
            input_month(fp, stringFile, month);
        }
        if (flag_year != 0)
        {
            input_year(fp, stringFile, year);
        }
    }
    else
    {
        printf("Add correct file name argument!\n");
    }

    return 0;
}