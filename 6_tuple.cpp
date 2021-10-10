#include<stdio.h>
#include<stdlib.h>
#include"my_functions.h"

using namespace std; 

int main()
{
    int tuple[7]; 				//the 6-tuple, one more to be more "easy to read"
    int A, B, C, D;  			//the n� of arcs
    int our_case; 
    int max_len[4]; 			//how many vertices we have in the C_i^+-
    struct vertex CC[4][MAX]; 	//the first index identifies the C_i^+- : like in a matrix
    int our_word[3][MAX]; 		//the representation using B_{2,2n}
    int temp_1, temp_2, start, ending, X, Y, L, positive, negative;
	int sup_t, len_t[2], base_t[2], sign_t[2], from_t, tow_t, word_0t[4], word_1t[4], sup_wt[2];  

	int DEBUG = 0; 
	
    printf("Input the 6-tuple like so: h_0 h_1 h_2 q_0 q_1 q_2 (values less than %d) \n", MAX/2); 
    scanf("%d %d %d %d %d %d", &tuple[1], &tuple[2], &tuple[3], &tuple[4], &tuple[5], &tuple[6]); 
	if(DEBUG == 1)
		printf("Got these values: %d %d %d %d %d %d \n", tuple[1], tuple[2], tuple[3], tuple[4], tuple[5], tuple[6]); 
    
	//check that 6-tuple is ok - 
    //////PER ORA SOLO TUPLE ORDINATE -- SISTEMARE FACENDO LE OPERAZIONI PER ORDINARE TUTTO
    //if((tuple[1] - tuple[2] % 2 == 0) && (tuple[1] - tuple[3] % 2 == 0) && (tuple[4] - tuple[5] % 2 == 0)  && (tuple[4] - tuple[6] % 2 == 0) && (tuple[1] - tuple[4] % 2 == 1))
    //{
    //    printf("6-tuple non valida"); 
    //    return 1; 
    //}

    //initialization

    initialize_CC(CC);

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

           	case_1(CC, A, B, C, D, max_len, tuple); 
		    
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
			
          	case_3(CC, A, B, C, D, max_len, tuple); 
			
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
			
          	case_4(CC, A, B, C, D, max_len, tuple); 
			
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
	//SE NO DIRE CHE NON � UN MANIFOLD E CHIUDERE MAGARI CON UN ERRORE
	if(controllo(CC, max_len)) //0 � falso, 1 � vero
	{
		printf("The 6-tuple doesn't correspond to a manifold, closing with error. \n"); 
		return 1; 
	}
	
    //ora leggo la word e sistemo i punti dove ci sono lettere contrarie successive
    stampa(our_word, temp_cont); 
	
    return 0; 
}
