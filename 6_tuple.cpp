#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include"my_functions.h"

#define MAX 100
using namespace std; 

struct vertex
{
    int to[2]; 
    int colour; 
    int b_i; 
    int word[4];
    int visited;  
}; 

int main()
{
    int tuple[7]; 				//the 6-tuple, one more to be more "easy to read"
    int A, B, C, D;  			//the n° of arcs
    int our_case; 
    int max_len[4]; 			//how many vertices we have in the C_i^+-
    struct vertex CC[4][MAX]; 	//the first index identifies the C_i^+- : like in a matrix
    int our_word[3][MAX]; 		//thge representation using B_{2,2n}
    int temp_1, temp_2, start, ending, X, Y, L;
	int sup_t, len_t[2], base_t[2], sign_t[2], from_t, tow_t, word_0t[4], word_1t[4], sup_wt[2];  

	int DEBUG = 0; 
	
    printf("Inserisci la 6-tuple: (valori minori di %d) \n", MAX/2); 
    scanf("%d %d %d %d %d %d", &tuple[1], &tuple[2], &tuple[3], &tuple[4], &tuple[5], &tuple[6]); 
	if(DEBUG == 1)
		printf("Preso questi valori: %d %d %d %d %d %d \n", tuple[1], tuple[2], tuple[3], tuple[4], tuple[5], tuple[6]); 
    
	//check that 6-tuple is ok - 
    //////PER ORA SOLO TUPLE ORDINATE -- SISTEMARE FACENDO LE OPERAZIONI PER ORDINARE TUTTO
    //if((tuple[1] - tuple[2] % 2 == 0) && (tuple[1] - tuple[3] % 2 == 0) && (tuple[4] - tuple[5] % 2 == 0)  && (tuple[4] - tuple[6] % 2 == 0) && (tuple[1] - tuple[4] % 2 == 1))
    //{
    //    printf("6-tuple non valida"); 
    //    return 1; 
    //}

    //initialization

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
        CC[0][i].word[0] = 0; //ricorda: 0 è falso
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
        CC[0][i].visited = 0; //ricorda che 0 è falso
        CC[1][i].visited = 0; 
        CC[2][i].visited = 0; 
        CC[3][i].visited = 0; 
    }

    //check which case it is and initialize all variables
        if((tuple[6] < tuple[2]) && (tuple[6] < tuple[3]))
            our_case = 1; 
        if((tuple[3] <= tuple[6]) && (tuple[6] <= tuple[2]))
            our_case = 2; 
        if((tuple[2] < tuple[6]) && (tuple[6] < tuple[3]))
            our_case = 3; 
        if((tuple[2] < tuple[6]) && (tuple[3] < tuple[6]))
            our_case = 4; 
    
	if(DEBUG == 1)
		printf("Il nostro caso e' %d \n", our_case); 
    
	switch(our_case)
    {
        case 1: 
            // inizializzo A,B,C,D
            A = tuple[1];
            B = tuple[6]; 
            C = tuple[3] - tuple[6]; 
            D = tuple[2] - tuple[6];
            
            if(DEBUG == 1)
				printf("A = %d, B = %d, C = %d, D = %d \n", A, B, C, D); 
            
            //lunghezza massima nei cicli sui C_i^+-  
            max_len[0]=tuple[1] + tuple[2]; 
            max_len[1]=tuple[1] + tuple[3];
            max_len[2]=max_len[0];
            max_len[3]=max_len[1];

            //e ora metto i vari "to"
            //a sopra da 1 a 0
            sup_t = A; 
            len_t[0] = max_len[1]; 
			len_t[1] = max_len[0]; 
            base_t[0] = 0; 
            base_t[1] = tuple[1] + tuple[2] - 1; 
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
            len_t[0] = max_len[3]; 
			len_t[1] = max_len[2]; 
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
            len_t[0] = max_len[0]; 
			len_t[1] = max_len[2]; 
            base_t[0] = 0; 
            base_t[1] = tuple[5] + tuple[6]; 
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
            len_t[0] = max_len[1]; 
			len_t[1] = max_len[3]; 
            base_t[0] = tuple[1]; 
            base_t[1] = tuple[1] + tuple[4] + tuple[6]; 
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
            len_t[0] = max_len[0]; 
			len_t[1] = max_len[3]; 
            base_t[0] = tuple[2] - tuple[6]; 
            base_t[1] = tuple[4] + tuple[1]; 
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
            len_t[0] = max_len[1]; 
			len_t[1] = max_len[2]; 
            base_t[0] = tuple[1] + tuple[3] - tuple[6]; 
            base_t[1] = tuple[4]; 
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
			X = (tuple[5] + B) % max_len[ending];
			Y = (tuple[5] - 1) % max_len[ending];
			L = 0;
			antiorario(CC, X, Y, L, max_len[ending], start, ending); 

            //dichiaro i b_i a destra 
			//ANTIORARIO
			start = 1; 
			ending = 3; 
            X = 0;
			Y = (tuple[1] + tuple[3] - tuple[6] - 1) % max_len[start];
			L = tuple[4] % max_len[start];
			antiorario(CC, X, Y, L, max_len[start], start, ending); 
			
            break;
        case 2: 
            //not for now
            return 1; 
            break;
        case 3: 
            // inizializzo A,B,C,D
            A = tuple[1];
            B = tuple[2]; 
            C = tuple[3] - tuple[6]; 
            D = tuple[6] - tuple[2];
            
            if(DEBUG == 1)
				printf("A = %d, B = %d, C = %d, D = %d \n", A, B, C, D); 

            //lunghezza massima nei cicli sui C_i^+-  
            max_len[1]=tuple[1] + tuple[2]; 
            max_len[0]=tuple[1] + tuple[3];
            max_len[2]=max_len[0];
            max_len[3]=max_len[1];

            //e ora metto i vari "to"
            //a sopra da 1 a 0
            
            sup_t = A; 
            len_t[0] = max_len[1]; 
			len_t[1] = max_len[0]; 
            base_t[0] = tuple[5] + B; 
            base_t[1] = tuple[4] + tuple[1] - 1; 
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
            len_t[0] = max_len[3]; 
			len_t[1] = max_len[2]; 
            base_t[0] = tuple[2]; 
            base_t[1] = tuple[1] - 1; 
            sign_t[0] = +1; 
            sign_t[1] = -1; 
            from_t = 3; 
            tow_t = 2; 
            word_0t[0] = -1; 
            word_1t[0] = 3; 
            sup_wt[0] = 1; 
            sup_wt[1] = 1; 
            
            riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 
            
            //d da 0 a 2 --> il 2° è sotto
            
            sup_t = D; 
            len_t[0] = max_len[0]; 
			len_t[1] = max_len[2]; 
            base_t[0] = tuple[4] + tuple[1] + tuple[3] - tuple[6] + tuple[2]; 
            base_t[1] = tuple[1]; 
            sign_t[0] = +1; 
            sign_t[1] = +1; 
            from_t = 0; 
            tow_t = 2; 
            word_0t[0] = 11; 
            word_0t[1] = -3; 
            word_0t[2] = 34; 
            word_1t[0] = 34; 
            word_1t[1] = -11; 
			word_1t[2] = 3; 
            sup_wt[0] = 3; 
            sup_wt[1] = 3; 
            
            riempi(CC, sup_t, len_t, base_t, sign_t, from_t, tow_t, word_0t, word_1t, sup_wt); 
            
            //c da 0 a 2
            
            sup_t = C; 
            len_t[0] = max_len[0]; 
			len_t[1] = max_len[2]; 
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
            len_t[0] = max_len[0]; 
			len_t[1] = max_len[3]; 
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
            len_t[0] = max_len[1]; 
			len_t[1] = max_len[2]; 
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
			X = (tuple[1] + tuple[6]) % max_len[ending];
			Y = (tuple[1] - 1) % max_len[ending];
			L = (tuple[4] + tuple[1]) % max_len[ending];

			antiorario(CC, X, Y, L, max_len[start], start, ending); 
            
            //dichiaro i b_i a destra 
			//ANTIORARIO
            start = 1; 
			ending = 3; 
            X = (tuple[5] + tuple[2]) % max_len[start];
			Y = (tuple[5] - 1) % max_len[start];
			L = tuple[2] % max_len[start]; 

			antiorario(CC, X, Y, L, max_len[start], start, ending); 
            
            break; 
        case 4: 
            // inizializzo A,B,C,D
            A = tuple[1];
            B = tuple[2] + tuple[3] - tuple[6]; 
            C = tuple[6] - tuple[2]; 
            D = tuple[6] - tuple[3];
            
            //lunghezza massima nei cicli sui C_i^+-  
            max_len[0]=tuple[1] + tuple[2]; 
            max_len[1]=tuple[1] + tuple[3];
            max_len[2]=max_len[0];
            max_len[3]=max_len[1];
            
            if(DEBUG == 1)
				printf("A = %d, B = %d, C = %d, D = %d \n", A, B, C, D); 

            //e ora metto i vari "to"
            //a sopra da 1 a 0
            
            sup_t = A; 
            len_t[0] = max_len[1]; 
			len_t[1] = max_len[0]; 
            base_t[0] = 0; 
            base_t[1] = max_len[0] - 1; 
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
            len_t[0] = max_len[3]; 
			len_t[1] = max_len[2]; 
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
            len_t[0] = max_len[0]; 
			len_t[1] = max_len[2]; 
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
            len_t[0] = max_len[1]; 
			len_t[1] = max_len[3]; 
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
            len_t[0] = max_len[0]; 
			len_t[1] = max_len[3]; 
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
            len_t[0] = max_len[1]; 
			len_t[1] = max_len[2]; 
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
            X = (tuple[5] + D + B) % max_len[ending];
			Y = (tuple[5] + D - 1) % max_len[ending];
			L = (B + D - 1) % max_len[ending]; 

			orario(CC, X, Y, L, max_len[start], start, ending); 
            
            //dichiaro i b_i a destra
			//ORARIO
			start = 1; 
			ending = 3; 
			X = (A + B) % max_len[start];
			Y = (A - 1) % max_len[start];
			L = (tuple[4] + tuple[1] - 1) % max_len[start];
			
			orario(CC, X, Y, L, max_len[start], start, ending); 
			
            break; 
    }
	
	if(DEBUG == 1)
	{
		printf("Ho finito di riempire il caso\n"); 
		debug_stampa(CC, max_len); 
		printf("Ora seguo i colori\n"); 
	}

    //color and follow lead --> per andare sotto-sopra basta che faccio +2 mod 4 nel i di CC[i][j]
    //in the meantime we write the word
    //partiamo sempre dal 3
    //vediamo se accontentarci di due o farne 3 --> il terzo sarebbe da controllare ... potrebbe essere che sia di nuovo dello stesso colore
    int temp_C, temp_vert, temp_cont[3], t_0, t_1; 
    if(DEBUG == 1)
		printf("Ho visitato: "); 
	switch(our_case)
    {
        case 1: 
            //start from q_0 - 1 e - 2 e -3
            start = tuple[4] - 1; 
            segui(CC, temp_cont, start, max_len[3], our_word, DEBUG);
            break; 
        case 2: 
            //not for now
            return 1; 
            break; 
        case 3: 
            //start from h_1 - 1 e - 2 e -3
            start = tuple[2] - 1; 
            segui(CC, temp_cont, start, max_len[3], our_word, DEBUG);
            break; 
        case 4: 
            //start from q_0 + h_0 - 1 e -2 e -3
            start = tuple[4] + tuple[1] - 1; 
            segui(CC, temp_cont, start, max_len[3], our_word, DEBUG);
            break; 
    }
    
	//stampo la word in numeri per essere sicuro che salti fuori la parola corretta: 
	if(DEBUG == 1)
	{
		for(int i = 0; i<3; ++i)
		{
			printf("\n La %d parola e' (prima del lavoro): '", i); 
			for(int j = 0; j<temp_cont[i]; ++j)
				printf(" %d ", our_word[i][j]); 
		}	
		printf("\n\n"); 
	}
	
	//FARE IL CONTROLLO DELLA SESTUPLA: SONO AVANZATI ARCHI NON COLORATI? HA USATO TUTTI E TRE I COLORI? 
	//SE NO DIRE CHE NON è UN MANIFOLD E CHIUDERE MAGARI CON UN ERRORE
	if(controllo(CC, max_len)) //0 è falso, 1 è vero
	{
		printf("La sestupla non corrisponde ad una 3-varieta'. Chiusura del programma con errore. "); 
		return 1; 
	}
	
    //ora leggo la word e sistemo i punti dove ci sono lettere contrarie successive
    stampa(our_word, temp_cont); 
	
    return 0; 
}
