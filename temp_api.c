#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "temp_api.h"
#define N 6

void input_month(FILE* fp, char* string, int month_num)
{
    int year, month, day, hour, minute, temperature;
    int param_counter = 0;
    int struct_counter = 0;
    int month_exist = 0;
    int n_row = 1;
    int i = 1000000;
    struct sensor* month_data;

    month_data = (struct sensor*)malloc(i * sizeof(struct sensor));

    printf("===================================\n");

    while ((param_counter = fscanf(fp, "%d;%d;%d;%d;%d;%d", &year, &month, &day, &hour, &minute, &temperature)) > 0)
    {
        
        char s[30], c;

        if (param_counter < N)
        {
            param_counter = fscanf(fp, "%[^\n]%c", s, &c);
            printf("%d ERROR %d=%s %x\n", n_row, param_counter, s, c);
            n_row++;
        }
        if(month == month_num)
        {
            add_entry(month_data, struct_counter++, year, month, day, hour, minute, temperature);
            month_exist = 1;
        }
        param_counter = fscanf(fp, "%[^\n]%c", s, &c);

        if (param_counter > 0)
        {
            printf("%d EDN %d=%s %x\n", n_row, param_counter, s, c);
        }
    }

    if (month_exist == 1)
    {
        print_month_data(month_data, struct_counter);
    }
    else
    {
        printf("\n<<Sorry can't find %d month in dataset!>>\n", month_num);
    }
    
    free(month_data);
    fclose(fp);
}

void input_year(FILE* fp, char* string, int year_num)
{
    int year, month, day, hour, minute, temperature;
    int param_counter;
    int struct_counter = 0;
    int year_exist = 0;
    int n_row = 1;
    int i = 1000000;
    struct sensor* year_data;

    year_data = (struct sensor*)malloc(i * sizeof(struct sensor));

    printf("===================================\n");

    while ((param_counter = fscanf(fp, "%d;%d;%d;%d;%d;%d", &year, &month, &day, &hour, &minute, &temperature)) > 0)
    {
        char s[30], c; 
        if (param_counter < N)
        {
            param_counter = fscanf(fp, "%[^\n]%c", s, &c);
            printf("%d ERROR %d=%s %x\n", n_row, param_counter, s, c);
            n_row++;
        }
        else if(year == year_num)
        {
            add_entry(year_data, struct_counter++, year, month, day, hour, minute, temperature);
            year_exist = 1;
        }
        param_counter = fscanf(fp, "%[^\n]%c", s, &c);

        if (param_counter > 0)
        {
            printf("%d EDN %d=%s %x\n", n_row, param_counter, s, c);
        }
        n_row++;
    }

    if (year_exist == 1)
    {
        print_year_data(year_data, struct_counter);
    }
    else
    {
        printf("\n<<Sorry can't find %d year in dataset!>>\n", year_num);
    }

    free(year_data);
    fclose(fp);
}

void swap(struct sensor* data, int i, int j)
{
    struct sensor temp;
    temp = data[i];

    data[i] = data[j];
    data[j] = temp;
}

void sort_by_temperature(struct sensor* data, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (data[i].temperature >= data[j].temperature)
            {
                swap(data, i, j);
            } 
        }
    }
}

unsigned int DateToInt(struct sensor* data)
{
    return data->year << 16 | data->month << 8 | data->day;
}

void SortByDate(struct sensor* data, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (DateToInt(data + i) >= DateToInt(data + j))
            {
                swap(data, i, j);
            }
        }
    }  
}

int max_temp(struct sensor* data, int len)
{
    int max_num = 0;
    max_num = data[0].temperature;

    for (int i = 1; i < len; i++)
    {
        if (max_num < data[i].temperature)
        {
            max_num = data[i].temperature;
        }
    }
    return max_num;
}

int min_temp(struct sensor* data, int len)
{
    int min_num = 0;
    min_num = data[0].temperature;

    for (int i = 1; i < len; i++)
    {
        if (min_num > data[i].temperature)
        {
            min_num = data[i].temperature;
        }
    }
    return min_num;
}

float mean_temp(struct sensor* data, int len)
{
    int summ = 0;
    for (int i = 0; i < len; i++)
    {
        summ += data[i].temperature;
    }

    return (float)summ / len;
}

void add_entry(struct sensor* data, int number, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t temperature)
{
    data[number].year = year;
    data[number].month = month;
    data[number].day = day;
    data[number].hour = hour;
    data[number].minute = minute;
    data[number].temperature = temperature;
}

void print_all_data(struct sensor* data, int number)
{
    printf("===================================\n");
    for (int i = 0; i < number; i++)
    {
        printf("%04d-%02d-%02d, %02d:%02d t=%3d\n", data[i].year, data[i].month, data[i].day, data[i].hour, data[i].minute, data[i].temperature);
    }
    printf("===================================\n");
}

void print_month_data(struct sensor* month_data, int number)
{
    //for (int i = 0; i < number; i++)
    //{
    //    printf("%04d-%02d-%02d, %02d:%02d t=%3d\n", month_data[i].year, month_data[i].month, month_data[i].day, month_data[i].hour, month_data[i].minute, month_data[i].temperature);
    //}
    printf("===================================\n");
    printf("min T = %d; max T = %d; mean T = %.2f\n", min_temp(month_data, number), max_temp(month_data, number), mean_temp(month_data, number));
    printf("===================================\n");
}

void print_year_data(struct sensor* year_data, int number)
{
    //for (int i = 0; i < number; i++)
    //{
    //    printf("%04d-%02d-%02d, %02d:%02d t=%3d\n", year_data[i].year, year_data[i].month, year_data[i].day, year_data[i].hour, year_data[i].minute, year_data[i].temperature);
    //}
    printf("===================================\n");
    printf("min T = %d; max T = %d; mean T = %.2f\n", min_temp(year_data, number), max_temp(year_data, number), mean_temp(year_data, number));
    printf("===================================\n");
}