#ifndef covid19
#define covid19
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

typedef struct _cases_data
{
    char *year_week;
    int *weekly_cases, *total_cases;
    double *cases_100m;
    struct _cases_data *nextCD;
} cases_data;

typedef struct _deaths_data
{
    char *year_week;
    int *weekly_deaths, *total_deaths;
    double *deaths_1M;
    struct _deaths_data *nextDD; 
} deaths_data; // Simple Linked List Node

typedef struct _country_data
{
    char *country, *country_code, *continent;
    int *population;
    cases_data *nextCD;
    deaths_data *nextDD;
    struct _country_data *nextC; 
} country_data; // Simple Linked List Node

country_data *read_file(char *, char *, char *, char *, int *, char *, char *, country_data *);
country_data *data_structure_placement(char *, char *, char *, int *, char *, char *, country_data *, char *, char *, char *, int *, char *, int *, char *, double *, int *, char *);
int selection(char *, char *, char *, country_data *, char *, int *, int *, double *);
int restriction(char *, int *, char *, char *, int *, char *);
country_data *order(country_data *, char *, char *);
void erros();
country_data *troca(country_data *, country_data *);
country_data *search_country(country_data *, char *);
country_data *create_country_data(char *, char *, char *, int *, char *, int *, int *, double *, country_data *, char *, char *);
void create_cases_data(char *, int *, int *, double *, country_data *, country_data *);
void create_deaths_data(char *, int *, int *, double *, country_data *, country_data *);
void write_file(char *, country_data *);
void free_list(country_data *);
void erros();

#endif