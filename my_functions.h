#ifndef MY_FUNCTIONS
#define MY_FUNCTIONS
#include<stdio.h>
#include<stdlib.h>

#define MAX 100
struct vertex
{
    int to[2]; 
    int colour; 
    int b_i; 
    int word[4];
    int visited;  
}; 

#define as_p 1
#define as_m -1
#define ad_p 3
#define ad_m -3
#define bs_p 11
#define bs_m -11
#define bd_p 33
#define bd_m -33
#define bs_sp 12
#define bs_sm -12
#define bd_sp 34
#define bd_sm -34

//input-output CC[4][MAX]
//input-output cont[3]
//input-output word[3][MAX]
//input len[4]

void initialize_CC(vertex CC[][MAX]); 

void case_1(vertex CC[][MAX], int A, int B, int C, int D, int *len, int *tuple);

void case_3(vertex CC[][MAX], int A, int B, int C, int D, int *len, int *tuple);

void case_4(vertex CC[][MAX], int A, int B, int C, int D, int *len, int *tuple);

void riempi(vertex CC[][MAX], int sup, int* len, int* base, int* sign, int from, int towards, int* parola_0, int* parola_1, int* sup_w);

void orario(vertex CC[][MAX], int X, int Y, int L, int len_start, int start, int ending, int positive, int negative);

void antiorario(vertex CC[][MAX], int X, int Y, int L, int len_start, int start, int ending, int positive, int negative);

void segui(vertex CC[][MAX], int *cont, int starting_point, int len, int word[][MAX], int DEBUG);

void stampa(int word[][MAX], int *cont);

void debug_stampa(vertex CC[][MAX], int *len);

int controllo(vertex CC[][MAX], int *len); 

#endif
