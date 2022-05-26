#pragma once
struct sensor
{
    uint8_t day;
    uint8_t month;
    uint16_t year;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
};

void swap(struct sensor* data, int i, int j);
void sort_by_temperature(struct sensor* data, int n);
unsigned int DateToInt(struct sensor* data);
void SortByDate(struct sensor* data, int n);
void add_entry(struct sensor* data, int number, uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t temperature);
void print_all_data(struct sensor* data, int number);
void input_month(FILE* fp, char* string, int month_num);
void input_year(FILE* fp, char* string, int year_num);
void print_month_data(struct sensor* month_data, int number);
void print_year_data(struct sensor* year_data, int number);
int min_temp(struct sensor* data, int len);
int max_temp(struct sensor* data, int len);
float mean_temp(struct sensor* data, int len);
