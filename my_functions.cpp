#include<stdio.h>
#include<stdlib.h>
#include"my_functions.h"

using namespace std;

void initialize_CC(vertex CC[][MAX])
{
	for(int i = 0; i<MAX; ++i)
    {
        CC[0][i].to[0] = -1; 
        CC[1][i].to[0] = -1; 
        CC[2][i].to[0] = -1; 
        CC[3][i].to[0] = -1;
        CC[0][i].to[1] = -1; 
        CC[1][i].to[1] = -1; 
        CC[2][i].to[1] = -1; 
        CC[3][i].to[1] = -1;
        CC[0][i].word[0] = 0; //ricorda: 0 ï¿½ falso
        CC[1][i].word[0] = 0; 
        CC[2][i].word[0] = 0; 
        CC[3][i].word[0] = 0;
        CC[0][i].word[1] = 0; 
        CC[1][i].word[1] = 0; 
        CC[2][i].word[1] = 0; 
        CC[3][i].word[1] = 0;
        CC[0][i].word[2] = 0; 
        CC[1][i].word[2] = 0; 
        CC[2][i].word[2] = 0; 
        CC[3][i].word[2] = 0;
        CC[0][i].word[3] = 0; 
        CC[1][i].word[3] = 0; 
        CC[2][i].word[3] = 0; 
        CC[3][i].word[3] = 0;
        CC[0][i].colour = -1; 
        CC[1][i].colour = -1; 
        CC[2][i].colour = -1; 
        CC[3][i].colour = -1; 
        CC[0][i].b_i = 0; 
        CC[1][i].b_i = 0; 
        CC[2][i].b_i = 0; 
        CC[3][i].b_i = 0;
        CC[0][i].visited = 0; //ricorda che 0 ï¿½ falso
        CC[1][i].visited = 0; 
        CC[2][i].visited = 0; 
        CC[3][i].visited = 0; 
    }
}

void case_1(vertex CC[][MAX], int A, int B, int C, int D, int *len, int *tuple)
{
	int sup_t, from_t, tow_t; 
	int base_t[2], len_t[2], sign_t[2], sup_wt[2], word_0t[4], word_1t[4]; 
	int start, ending, X, Y, L, positive, negative; 
	
	//e ora metto i vari "to"
    //a sopra da 1 a 0
    sup_t = A; 
    len_t[0] = len[1]; 
	len_t[1] = len[0]; 
    base_t[0] = 0; 
    base_t[1] = tuple[1] + tuple[2] - 1; 
    sign_t[0] = +1; 
    sign_t[1] = -1; 
    from_t = 1; 
    tow_t = 0; 
    word_0t[0] = as_p; 
    word_1t[0] = ad_m; 
    sup_wt[0] = 1; 
    sup_wt[1] = 1; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 
    
    //a sotto da 3 a 2
    sup_t = A; 
    len_t[0] = len[3]; 
	len_t[1] = len[2]; 
    base_t[0] = tuple[4]; 
    base_t[1] = tuple[5] - 1; 
    sign_t[0] = +1; 
    sign_t[1] = -1; 
    from_t = 3; 
    tow_t = 2; 
    word_0t[0] = as_m; 
    word_1t[0] = ad_p; 
    sup_wt[0] = 1; 
    sup_wt[1] = 1; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 

    //d da 0 a 2
    sup_t = D; 
    len_t[0] = len[0]; 
	len_t[1] = len[2]; 
    base_t[0] = 0; 
    base_t[1] = tuple[5] + tuple[6]; 
    sign_t[0] = +1; 
    sign_t[1] = +1; 
    from_t = 0; 
    tow_t = 2; 
    word_0t[0] = as_m; 
    word_1t[0] = as_p; 
    sup_wt[0] = 1; 
    sup_wt[1] = 1; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 
    
    //c da 1 a 3
    sup_t = C; 
    len_t[0] = len[1]; 
	len_t[1] = len[3]; 
    base_t[0] = tuple[1]; 
    base_t[1] = tuple[1] + tuple[4] + tuple[6]; 
    sign_t[0] = +1; 
    sign_t[1] = +1; 
    from_t = 1; 
    tow_t = 3; 
    word_0t[0] = ad_p; 
    word_1t[0] = ad_m; 
    sup_wt[0] = 1; 
    sup_wt[1] = 1; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 
    
    //b in mezzo da 0 a 3
    sup_t = B; 
    len_t[0] = len[0]; 
	len_t[1] = len[3]; 
    base_t[0] = tuple[2] - tuple[6]; 
    base_t[1] = tuple[4] + tuple[1]; 
    sign_t[0] = +1; 
    sign_t[1] = +1; 
    from_t = 0; 
    tow_t = 3; 
    word_0t[0] = ad_p; 
    word_1t[0] = as_p; 
    sup_wt[0] = 1; 
    sup_wt[1] = 1; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 
    
    //b fuori da 1 a 2
    sup_t = B; 
    len_t[0] = len[1]; 
	len_t[1] = len[2]; 
    base_t[0] = tuple[1] + tuple[3] - tuple[6]; 
    base_t[1] = tuple[4]; 
    sign_t[0] = +1; 
    sign_t[1] = +1; 
    from_t = 1; 
    tow_t = 2; 
    word_0t[0] = bd_sm;
	word_0t[1] = bd_p; 
	word_0t[2] = as_m;
	word_0t[3] = bs_sm;
    word_1t[0] = bs_sp; 
	word_1t[1] = bd_m;
	word_1t[2] = ad_m;
	word_1t[3] = bd_sp;
    sup_wt[0] = 4; 
    sup_wt[1] = 4; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 
    
    //dichiaro i b_i a sinistra 
	//ANTIORARIO
	start = 0; 
	ending = 2; 
	X = (tuple[5] + B) % len[ending];
	Y = (tuple[5] - 1) % len[ending];
	L = 0;
	positive = bs_p; 
	negative = bs_m; 
	antiorario(CC, X, Y, L, len[ending], start, ending, positive, negative); 

    //dichiaro i b_i a destra 
	//ANTIORARIO
	start = 1; 
	ending = 3; 
    X = 0;
	Y = (tuple[1] + tuple[3] - tuple[6] - 1) % len[start];
	L = tuple[4] % len[start];
	positive = bd_p; 
	negative = bd_m; 
	antiorario(CC, X, Y, L, len[start], start, ending, positive, negative); 
	
}

void case_3(vertex CC[][MAX], int A, int B, int C, int D, int *len, int *tuple)
{
	int sup_t, from_t, tow_t; 
	int base_t[2], len_t[2], sign_t[2], sup_wt[2], word_0t[4], word_1t[4]; 
	int start, ending, X, Y, L, positive, negative; 
	
	//e ora metto i vari "to"
    //a sopra da 1 a 0
    
    sup_t = A; 
    len_t[0] = len[1]; 
	len_t[1] = len[0]; 
    base_t[0] = tuple[5] + B; 
    base_t[1] = tuple[4] + tuple[1] - 1; 
    sign_t[0] = +1; 
    sign_t[1] = -1; 
    from_t = 1; 
    tow_t = 0; 
    word_0t[0] = as_p; 
    word_1t[0] = ad_m; 
    sup_wt[0] = 1; 
    sup_wt[1] = 1; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 
    
    //a sotto da 3 a 2
    
    sup_t = A; 
    len_t[0] = len[3]; 
	len_t[1] = len[2]; 
    base_t[0] = tuple[2]; 
    base_t[1] = tuple[1] - 1; 
    sign_t[0] = +1; 
    sign_t[1] = -1; 
    from_t = 3; 
    tow_t = 2; 
    word_0t[0] = as_m; 
    word_1t[0] = ad_p; 
    sup_wt[0] = 1; 
    sup_wt[1] = 1; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 
    
    //d da 0 a 2 --> il 2° sotto
    
    sup_t = D; 
    len_t[0] = len[0]; 
	len_t[1] = len[2]; 
    base_t[0] = tuple[4] + tuple[1] + tuple[3] - tuple[6] + tuple[2]; 
    base_t[1] = tuple[1]; 
    sign_t[0] = +1; 
    sign_t[1] = +1; 
    from_t = 0; 
    tow_t = 2; 
    word_0t[0] = bd_p; 
    word_0t[1] = as_m; 
    word_0t[2] = bs_sm; 
    word_1t[0] = bs_sp; 
    word_1t[1] = bd_m; 
	word_1t[2] = as_p; 
    sup_wt[0] = 3; 
    sup_wt[1] = 3; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 
    
    //c da 0 a 2
    
    sup_t = C; 
    len_t[0] = len[0]; 
	len_t[1] = len[2]; 
    base_t[0] = tuple[4] + tuple[1]; 
    base_t[1] = tuple[1] + tuple[6]; 
    sign_t[0] = +1; 
    sign_t[1] = +1; 
    from_t = 0; 
    tow_t = 2; 
    word_0t[0] = -1; 
    word_1t[0] = 1; 
    sup_wt[0] = 1; 
    sup_wt[1] = 1; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 
    
    //b in mezzo da 0 a 3
    
    sup_t = B; 
    len_t[0] = len[0]; 
	len_t[1] = len[3]; 
    base_t[0] = tuple[4] + A + C; 
    base_t[1] = 0; 
    sign_t[0] = +1; 
    sign_t[1] = +1; 
    from_t = 0; 
    tow_t = 3; 
    word_0t[0] = 3; 
    word_1t[0] = 1; 
    sup_wt[0] = 1; 
    sup_wt[1] = 1; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 
    
    //b fuori da 1 a 2
    
    sup_t = B; 
    len_t[0] = len[1]; 
	len_t[1] = len[2]; 
    base_t[0] = tuple[4]; 
    base_t[1] = tuple[1] + tuple[6] - tuple[2]; 
    sign_t[0] = +1; 
    sign_t[1] = +1; 
    from_t = 1; 
    tow_t = 2; 
    word_0t[0] = -34; 
    word_0t[1] = 33; 
    word_0t[2] = -1; 
    word_0t[3] = -12;  
    word_1t[0] = 12; 
    word_1t[1] = -33; 
	word_1t[2] = -3;
	word_1t[3] = 34;  
    sup_wt[0] = 4; 
    sup_wt[1] = 4; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 
    
    //dichiaro i b_i a sinistra 
	//ANTIORARIO
	start = 0; 
	ending = 2; 
	X = (tuple[1] + tuple[6]) % len[ending];
	Y = (tuple[1] - 1) % len[ending];
	L = (tuple[4] + tuple[1]) % len[ending];
	positive = bs_p; 
	negative = bs_m; 
	antiorario(CC, X, Y, L, len[start], start, ending, positive, negative); 
    
    //dichiaro i b_i a destra 
	//ANTIORARIO
    start = 1; 
	ending = 3; 
    X = (tuple[5] + tuple[2]) % len[start];
	Y = (tuple[5] - 1) % len[start];
	L = tuple[2] % len[start]; 
	positive = bd_p; 
	negative = bd_m; 
	antiorario(CC, X, Y, L, len[start], start, ending, positive, negative);            
}

void case_4(vertex CC[][MAX], int A, int B, int C, int D, int *len, int *tuple)
{
	int sup_t, from_t, tow_t; 
	int base_t[2], len_t[2], sign_t[2], sup_wt[2], word_0t[4], word_1t[4]; 
	int start, ending, X, Y, L, positive, negative; 
	
    //e ora metto i vari "to"
    //a sopra da 1 a 0
    
    sup_t = A; 
    len_t[0] = len[1]; 
	len_t[1] = len[0]; 
    base_t[0] = 0; 
    base_t[1] = len[0] - 1; 
    sign_t[0] = +1; 
    sign_t[1] = -1; 
    from_t = 1; 
    tow_t = 0; 
    word_0t[0] = 1; 
    word_1t[0] = -3; 
    sup_wt[0] = 1; 
    sup_wt[1] = 1; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 
    
    //a sotto da 3 a 2
    
    sup_t = A; 
    len_t[0] = len[3]; 
	len_t[1] = len[2]; 
    base_t[0] = tuple[4]; 
    base_t[1] = tuple[5] - 1; 
    sign_t[0] = +1; 
    sign_t[1] = -1; 
    from_t = 3; 
    tow_t = 2; 
    word_0t[0] = -1; 
    word_1t[0] = 3; 
    sup_wt[0] = 1; 
    sup_wt[1] = 1; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt);
    
    //d da 0 a 2
    
    sup_t = D; 
    len_t[0] = len[0]; 
	len_t[1] = len[2]; 
    base_t[0] = tuple[2] + tuple[3] - tuple[6]; 
    base_t[1] = tuple[5]; 
    sign_t[0] = +1; 
    sign_t[1] = +1; 
    from_t = 0; 
    tow_t = 2; 
    word_0t[0] = -1; 
    word_1t[0] = 1; 
    sup_wt[0] = 1; 
    sup_wt[1] = 1; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt);
    
    //c da 1 a 3
    
    sup_t = C; 
    len_t[0] = len[1]; 
	len_t[1] = len[3]; 
    base_t[0] = tuple[1] + tuple[2] + tuple[3] - tuple[6]; 
    base_t[1] = tuple[4] + tuple[1]; 
    sign_t[0] = +1; 
    sign_t[1] = +1; 
    from_t = 1; 
    tow_t = 3; 
    word_0t[0] = 3; 
    word_1t[0] = -3; 
    sup_wt[0] = 1; 
    sup_wt[1] = 1; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt);
    
    //b in mezzo da 0 a 3
    
    sup_t = B; 
    len_t[0] = len[0]; 
	len_t[1] = len[3]; 
    base_t[0] = 0; 
    base_t[1] = tuple[4] + A + C; 
    sign_t[0] = +1; 
    sign_t[1] = +1; 
    from_t = 0; 
    tow_t = 3; 
    word_0t[0] = 3; 
    word_1t[0] = 1; 
    sup_wt[0] = 1; 
    sup_wt[1] = 1; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt);
    
    //b fuori da 1 a 2
    
    sup_t = B; 
    len_t[0] = len[1]; 
	len_t[1] = len[2]; 
    base_t[0] = tuple[1]; 
    base_t[1] = tuple[5] + D; 
    sign_t[0] = +1; 
    sign_t[1] = +1; 
    from_t = 1; 
    tow_t = 2; 
    word_0t[0] = -34;
	word_0t[1] = 33;
	word_0t[2] = -1;
	word_0t[3] = -12;
    word_1t[0] = 12; 
    word_1t[1] = -33; 
    word_1t[2] = -3; 
    word_1t[3] = 34; 
    sup_wt[0] = 4; 
    sup_wt[1] = 4; 
    
    riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt);
    
    //dichiaro i b_i a sinistra 
	//ORARIO
	start = 0; 
	ending = 2; 
    X = (tuple[5] + D + B) % len[ending];
	Y = (tuple[5] + D - 1) % len[ending];
	L = (B + D - 1) % len[ending]; 
	positive = bs_p; 
	negative = bs_m; 
	orario(CC, X, Y, L, len[start], start, ending, positive, negative); 
    
    //dichiaro i b_i a destra
	//ORARIO
	start = 1; 
	ending = 3; 
	X = (A + B) % len[start];
	Y = (A - 1) % len[start];
	L = (tuple[4] + tuple[1] - 1) % len[start];
	positive = bd_p; 
	negative = bd_m; 
	orario(CC, X, Y, L, len[start], start, ending, positive, negative); 
}

void riempi(vertex CC[][MAX], int sup, int* len, int* base, int* sign, int from, int towards, int* parola_0, int* parola_1, int* sup_w)
{
	int t[2], k, j; 
	t[0] = 0; 
	t[1] = 0; 
	for(j = 0; j<sup; ++j)
            {
                t[0] = (base[0] + sign[0]*j + len[0]) % len[0]; 
                t[1] = (base[1] + sign[1]*j + len[1]) % len[1]; 
                
				//parto da uno
                CC[from][t[0]].to[0] = towards; 
                CC[from][t[0]].to[1] = t[1]; 
                for(k = 0; k<sup_w[0]; ++k)
					CC[from][t[0]].word[k] = parola_0[k]; 
                
				//aggiorno anche l'altro
                CC[towards][t[1]].to[0] = from;
                CC[towards][t[1]].to[1] = t[0]; 
                for(k = 0; k<sup_w[1]; ++k)
					CC[towards][t[1]].word[k] = parola_1[k]; 
            }
}

void orario(vertex CC[][MAX], int X, int Y, int L, int len_start, int start, int ending, int positive, int negative)
{
	if((X < Y) && (L > X && L < Y)) //crossa caso 1
            {
                for(int j = 0; j<len_start; ++j)
                {
                    if(j > L && j <= Y)
                    {
                        CC[start][j].b_i = 0; 
                        CC[ending][j].b_i = 0; 
                    }
                    else
                    {
                        CC[start][j].b_i = positive; 
                        CC[ending][j].b_i = negative; 
                    }
                }
            }
            else if((Y < X) && (L > X || L < Y)) //crossa caso 2
            {
            	if(L > X)
            	{
            		for(int j = 0; j<len_start; ++j)
                	{
                		if(j <= Y || j > L)
                		{
                			CC[start][j].b_i = 0; 
                			CC[ending][j].b_i = 0; 
						}
						else
						{
							CC[start][j].b_i = positive; 
							CC[ending][j].b_i = negative; 
						}
                	}
				}
				else
            	{
            		for(int j = 0; j<len_start; ++j)
                	{
                		if(j <= Y && j > L)
                		{
                			CC[start][j].b_i = 0; 
                			CC[ending][j].b_i = 0; 
						}
						else
						{
							CC[start][j].b_i = positive; 
							CC[ending][j].b_i = negative; 
						}

                	}
				}
			}
            else if(X < Y) //non crossa caso 1
            {
            	if(L > Y)
            	{
            		for(int j = 0; j<len_start; ++j)
            		{
            			if(j >= X && j <= Y)
            			{
            				CC[start][j].b_i = 0; 
            				CC[ending][j].b_i = 0; 
						}
						else if(j > Y && j <= L)
						{
							CC[start][j].b_i = positive; 
							CC[ending][j].b_i = negative; 
						}
						else
						{
							CC[start][j].b_i = negative; 
							CC[ending][j].b_i = positive; 
						}
					}
				}
				else
				{
					for(int j = 0; j<len_start; ++j)
					{
						if(j >= X && j <= Y)
						{
							CC[start][j].b_i = 0; 
							CC[ending][j].b_i = 0; 
						}
						else if(j > L && j < X)
						{
							CC[start][j].b_i = negative; 
							CC[ending][j].b_i = positive; 
						}
						else
						{
							CC[start][j].b_i = positive; 
							CC[ending][j].b_i = negative; 
						}
					}
				}
            }
            else if(Y < X) //non crossa caso 2
            {
            	for(int j = 0; j<len_start; ++j)
            	{
            		if(j >= X || j <= Y)
            		{
            			CC[start][j].b_i = 0; 
            			CC[ending][j].b_i = 0; 
					}
					else if(j > L && j < X)
					{
						CC[start][j].b_i = negative; 
						CC[ending][j].b_i = positive; 
					}
					else
					{
						CC[start][j].b_i = positive; 
						CC[ending][j].b_i = negative; 
					}
				}
			}
}

void antiorario(vertex CC[][MAX], int X, int Y, int L, int len_start, int start, int ending, int positive, int negative)
{
	if((X < Y) && (L > X && L < Y)) //crossa caso 1
            {
                for(int j = 0; j<len_start; ++j)
                {
                    if(j >= X && j < L)
                    {
                        CC[start][j].b_i = 0; 
                        CC[ending][j].b_i = 0; 
                    }
                    else
                    {
                        CC[start][j].b_i = positive; 
                        CC[ending][j].b_i = negative;  
                    }
                }
            }
            else if((Y < X) && (L > X || L < Y)) //crossa caso 2
            {
            	if(L < Y)
            	{
            		for(int j = 0; j<len_start; ++j)
                	{
                		if(j >= X || j < L)
                		{
                			CC[start][j].b_i = 0; 
                			CC[ending][j].b_i = 0; 
						}
						else
						{
							CC[start][j].b_i = positive; 
							CC[ending][j].b_i = negative; 
						}
                	}
				}
				else
            	{
            		for(int j = 0; j<len_start; ++j)
                	{
                		if(j >= X && j < L)
                		{
                			CC[start][j].b_i = 0; 
                			CC[ending][j].b_i = 0; 
						}
						else
						{
							CC[start][j].b_i = positive; 
							CC[ending][j].b_i = negative; 
						}

                	}
				}
			}
            else if(X < Y) //non crossa caso 1
            {
            	if(L < X)
            	{
            		for(int j = 0; j<len_start; ++j)
            		{
            			if(j <= Y && j >= X)
            			{
            				CC[start][j].b_i = 0; 
            				CC[ending][j].b_i = 0; 
						}
						else if(j >= L && j < X)
						{
							CC[start][j].b_i = positive; 
							CC[ending][j].b_i = negative; 
						}
						else
						{
							CC[start][j].b_i = negative; 
							CC[ending][j].b_i = positive; 
						}
					}
				}
				else
				{
					for(int j = 0; j<len_start; ++j)
					{
						if(j <= Y && j >= X)
						{
							CC[start][j].b_i = 0; 
							CC[ending][j].b_i = 0; 
						}
						else if(j > Y && j < L)
						{
							CC[start][j].b_i = negative; 
							CC[ending][j].b_i = positive; 
						}
						else
						{
							CC[start][j].b_i = positive; 
							CC[ending][j].b_i = negative; 
						}
					}
				}
            }
            else if(Y < X) //non crossa caso 2
            {
            	for(int j = 0; j<len_start; ++j)
            	{
            		if(j >= L && j < X)
            		{
            			CC[start][j].b_i = positive; 
            			CC[ending][j].b_i = negative; 
					}
					else if(j < L && j > Y)
					{
						CC[start][j].b_i = negative; 
						CC[ending][j].b_i = positive; 
					}
					else
					{
						CC[start][j].b_i = 0; 
						CC[ending][j].b_i = 0; 
					}
				}
			}
}

void segui(vertex CC[][MAX], int *cont, int starting_point, int len, int word[][MAX], int DEBUG)
{
	int t_vert, t_C, t_0, t_1; 
	for(int i = 0; i<3; ++i)
    {	
        if(DEBUG == 1)
			printf("\n-----------     %d     ----------------- \n", i); 
        cont[i] = 0; //quello della parola grande
        t_C = 3; 
        if(i != 2)
            t_vert = (starting_point - i + len) % len; 
        else
        {
        	t_vert = (t_vert - 1 + len) % len; 
            //se è 2 dobbiamo controllare che il colore dove siamo sopra sia diverso da 0 e 1 
			//--> non negativo, dato che è inizializzato a -1 
			//--> basta controllare che non sia visitato
            while(CC[t_C][t_vert].visited)
            {
                t_vert = (t_vert - 1 + len) % len;  
            }
        }
        while(!CC[t_C][t_vert].visited)
        {
           	if(DEBUG == 1)
				printf("%d - %d   ", t_C, t_vert); 
			
			//metto visitato
            CC[t_C][t_vert].visited = 1;
            
            //aggiorno la parola
            for(int j = 0; j<4; ++j)
            {
                if(CC[t_C][t_vert].word[j])
                {
                    word[i][cont[i]] = CC[t_C][t_vert].word[j]; 
                    if(DEBUG == 1)
						printf(" just added %d ", word[i][cont[i]]); 
                    cont[i]++; 
                }
            }

            //metto il colore
            CC[t_C][t_vert].colour = i; 

            //percorro l'arco
            t_0 = CC[t_C][t_vert].to[0]; 
            t_1 = CC[t_C][t_vert].to[1]; 
            if(DEBUG == 1)
				printf("\n attachment in %d - %d ", t_0, t_1); 

			                    
            //aggiorno anche l'altro e metto il colore
            CC[t_0][t_1].visited = 1; 
            CC[t_0][t_1].colour = i; 

            //guardo di mettere il b_i
            if(CC[t_0][t_1].b_i)
            {
                word[i][cont[i]] = CC[t_0][t_1].b_i; 
                if(DEBUG == 1)
					printf("Just added b: %d \n", word[i][cont[i]]); 
                cont[i]++; 
            }

            //il prossimo è quello sotto
            t_C = (t_0 + 2) % 4; 
            t_vert = t_1; 
        }
    }
}

void stampa(int word[][MAX], int *cont)
{
	int ii; 
    for(int i = 0; i<3; ++i) 
    {
    	ii = 0; 
        printf("\nThe %d-word is: ", i); 
        while (ii<cont[i])
        {
            if(ii!=cont[i] - 1) //se non sono in fondo
                if(word[i][ii+1] == bs_sp)
                {
                    if(word[i][ii] == bs_p)
                        word[i][ii+1] = 0; 
                    else if(word[i][ii] == bs_m)
                        {
                            word[i][ii] = 0; 
                            word[i][ii+1] = 0; 
                        }
                }
                else if(word[i][ii] == bd_sp) 
                    {
                        if(word[i][ii+1] == bd_p)
                            word[i][ii] = 0; 
                        else if(word[i][ii+1] == bd_m)
                            {
                                word[i][ii] = 0; 
                                word[i][ii+1] = 0; 
                            }
                    }
                    else if(word[i][ii+1] == bs_sm)
                        {
                            if(word[i][ii] == bs_m)
                                word[i][ii+1] = 0; 
                            else if(word[i][ii] == bs_p)
                                {
                                    word[i][ii] = 0; 
                                    word[i][ii+1] = 0; 
                                }
                        }  
                        else if(word[i][ii] == bd_sm)
                            {
                                if(word[i][ii+1] == bd_m)
                                    word[i][ii] = 0; 
                                else if(word[i][ii+1] == bd_p)
                                    {
                                        word[i][ii] = 0; 
                                        word[i][ii+1] = 0; 
                                    }
                            }
                            else if(word[i][ii+1] + word[i][ii] == 0) //è sempre cosÃ¬? 
                                {
                                    word[i][ii] = 0; 
                                    word[i][ii+1] = 0; 
                                }
            switch (word[i][ii])
            {
                case 0: 
                    break; 
                case as_p:
                    printf(" a_l^+ "); 
                    break; 
                case as_m: 
                    printf(" a_l^- "); 
                    break; 
                case bs_p: 
                    printf(" b_l^+ "); 
                    break; 
                case bs_m: 
                    printf(" b_l^- "); 
                    break; 
                case ad_p: 
                    printf(" a_r^+ "); 
                    break; 
                case ad_m: 
                    printf(" a_r^- "); 
                    break; 
                case bd_p: 
                    printf(" b_r^+ "); 
                    break; 
                case bd_m: 
                    printf(" b_r^- "); 
                    break;
            }
            ii++; 
        }
        printf("\n"); 
    }
}

void debug_stampa(vertex CC[][MAX], int *len)
{
	for(int i = 0; i<4; ++i)
	{
		printf("We are at %d -- begin to print everything \n\n", i); 
		for(int j = 0; j<len[i]; ++j)
		{
			printf("j = %d, to[0] = %d, to[1] = %d, colour = %d, b_i = %d, w[0] = %d, w[1] = %d, w[2] = %d, w[3] = %d\n", j, CC[i][j].to[0], CC[i][j].to[1], CC[i][j].colour, CC[i][j].b_i, CC[i][j].word[0], CC[i][j].word[1], CC[i][j].word[2], CC[i][j].word[3]); 
		}
		printf("\n\n\n"); 
	}
}

int controllo(vertex CC[][MAX], int *len)
{
	for(int i = 0; i<4; ++i)
	{
		for(int j = 0; j<len[i]; ++j)
		{
			if(CC[i][j].colour == -1)
				return 1; //vero, non è una 3-varietà
		}
	}
	return 0; //falso, è una 3-varietà
}

