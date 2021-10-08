#include"my_functions.h"

void riempi(vertex CC[4][MAX], int sup, int* len, int* base, int* sign, int from, int towards, int* parola_0, int* parola_1, int* sup_w)
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

void orario(vertex CC[4][MAX], int X, int Y, int L, int len_start, int start, int ending)
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
                        CC[start][j].b_i = 11; 
                        CC[ending][j].b_i = -11; 
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
							CC[start][j].b_i = 11; 
							CC[ending][j].b_i = -11; 
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
							CC[start][j].b_i = 11; 
							CC[ending][j].b_i = -11; 
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
							CC[start][j].b_i = 11; 
							CC[ending][j].b_i = -11; 
						}
						else
						{
							CC[start][j].b_i = -11; 
							CC[ending][j].b_i = 11; 
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
							CC[start][j].b_i = -11; 
							CC[ending][j].b_i = 11; 
						}
						else
						{
							CC[start][j].b_i = 11; 
							CC[ending][j].b_i = -11; 
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
						CC[start][j].b_i = -11; 
						CC[ending][j].b_i = 11; 
					}
					else
					{
						CC[start][j].b_i = 11; 
						CC[ending][j].b_i = -11; 
					}
				}
			}
}

void antiorario(vertex CC[4][MAX], int X, int Y, int L, int len_start, int start, int ending)
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
                        CC[start][j].b_i = 11; 
                        CC[ending][j].b_i = -11; 
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
							CC[start][j].b_i = 11; 
							CC[ending][j].b_i = -11; 
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
							CC[start][j].b_i = 11; 
							CC[ending][j].b_i = -11; 
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
							CC[start][j].b_i = 11; 
							CC[ending][j].b_i = -11; 
						}
						else
						{
							CC[start][j].b_i = -11; 
							CC[ending][j].b_i = 11; 
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
							CC[start][j].b_i = -11; 
							CC[ending][j].b_i = 11; 
						}
						else
						{
							CC[start][j].b_i = 11; 
							CC[ending][j].b_i = -11; 
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
            			CC[start][j].b_i = 11; 
            			CC[ending][j].b_i = -11; 
					}
					else if(j < L && j > Y)
					{
						CC[start][j].b_i = -11; 
						CC[ending][j].b_i = 11; 
					}
					else
					{
						CC[start][j].b_i = 0; 
						CC[ending][j].b_i = 0; 
					}
				}
			}
}

void segui(vertex CC[4][MAX], int cont[3], int starting_point, int len, int word[3][MAX], int DEBUG)
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
						printf(" Ho appena aggiunto %d ", word[i][cont[i]]); 
                    cont[i]++; 
                }
            }

            //metto il colore
            CC[t_C][t_vert].colour = i; 

            //percorro l'arco
            t_0 = CC[t_C][t_vert].to[0]; 
            t_1 = CC[t_C][t_vert].to[1]; 
            if(DEBUG == 1)
				printf("\n mi attacco in %d - %d ", t_0, t_1); 

			                    
            //aggiorno anche l'altro e metto il colore
            CC[t_0][t_1].visited = 1; 
            CC[t_0][t_1].colour = i; 

            //guardo di mettere il b_i
            if(CC[t_0][t_1].b_i)
            {
                word[i][cont[i]] = CC[t_0][t_1].b_i; 
                if(DEBUG == 1)
					printf("Ho appena aggiunto il b: %d \n", word[i][cont[i]]); 
                cont[i]++; 
            }

            //il prossimo è quello sotto
            t_C = (t_0 + 2) % 4; 
            t_vert = t_1; 
        }
    }
}

void stampa(int word[3][MAX], int cont[3])
{
	int ii; 
    for(int i = 0; i<3; ++i) 
    {
    	ii = 0; 
        printf("\n La %d parola e': ", i); 
        while (ii<cont[i])
        {
            if(ii!=cont[i] - 1) //se non sono in fondo
                if(word[i][ii+1] == 12)
                {
                    if(word[i][ii] == 11)
                        word[i][ii+1] = 0; 
                    else if(word[i][ii] == -11)
                        {
                            word[i][ii] = 0; 
                            word[i][ii+1] = 0; 
                        }
                }
                else if(word[i][ii] == 34) 
                    {
                        if(word[i][ii+1] == 33)
                            word[i][ii] = 0; 
                        else if(word[i][ii+1] == -33)
                            {
                                word[i][ii] = 0; 
                                word[i][ii+1] = 0; 
                            }
                    }
                    else if(word[i][ii+1] == -12)
                        {
                            if(word[i][ii] == -11)
                                word[i][ii+1] = 0; 
                            else if(word[i][ii] == 11)
                                {
                                    word[i][ii] = 0; 
                                    word[i][ii+1] = 0; 
                                }
                        }  
                        else if(word[i][ii] == -34)
                            {
                                if(word[i][ii+1] == -33)
                                    word[i][ii] = 0; 
                                else if(word[i][ii+1] == 33)
                                    {
                                        word[i][ii] = 0; 
                                        word[i][ii+1] = 0; 
                                    }
                            }
                            else if(word[i][ii+1] + word[i][ii] == 0) //Ã¨ sempre cosÃ¬? 
                                {
                                    word[i][ii] = 0; 
                                    word[i][ii+1] = 0; 
                                }
            switch (word[i][ii])
            {
                case 0: 
                    break; 
                case 1:
                    printf(" a_s^+ "); 
                    break; 
                case -1: 
                    printf(" a_s^- "); 
                    break; 
                case 11: 
                    printf(" b_s^+ "); 
                    break; 
                case -11: 
                    printf(" b_s^- "); 
                    break; 
                case 3: 
                    printf(" a_d^+ "); 
                    break; 
                case -3: 
                    printf(" a_d^- "); 
                    break; 
                case 33: 
                    printf(" b_d^+ "); 
                    break; 
                case -33: 
                    printf(" b_d^- "); 
                    break;
            }
            ii++; 
        }
        printf("\n"); 
    }
}

void debug_stampa(vertex CC[4][MAX], int len[4])
{
	for(int i = 0; i<4; ++i)
	{
		printf("Siamo al %d -- ora iniziamo a stampare tutto \n\n", i); 
		for(int j = 0; j<len[i]; ++j)
		{
			printf("j = %d, to[0] = %d, to[1] = %d, colour = %d, b_i = %d, w[0] = %d, w[1] = %d, w[2] = %d, w[3] = %d\n", j, CC[i][j].to[0], CC[i][j].to[1], CC[i][j].colour, CC[i][j].b_i, CC[i][j].word[0], CC[i][j].word[1], CC[i][j].word[2], CC[i][j].word[3]); 
		}
		printf("\n\n\n"); 
	}
}

int controllo(vertex CC[4][MAX], int len[4])
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

