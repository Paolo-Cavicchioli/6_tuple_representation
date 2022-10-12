#include<stdio.h>
#include<stdlib.h>
#include<cstdio>
#include"my_functions.h"

using namespace std; 

int main()
{
    int tuple[7]; 			//the 6-tuple, one more to be more "easy to read"
    int A, B, C, D;  			//the number of arcs
    int our_case; 
    int max_len[4]; 			//how many vertices we have in the C_i^+-
    struct vertex CC[4][MAX]; 		//the first index identifies the C_i^+- : like in a matrix
    int our_word[3][MAX]; 		//the representation using B_{2,2n}
    int temp_1, temp_2, start, ending, X, Y, L, positive, negative;
	int sup_t, len_t[2], base_t[2], sign_t[2], from_t, tow_t, word_0t[4], word_1t[4], sup_wt[2];  

	int DEBUG = 1; 
	
    printf("Input the 6-tuple like so: h_0 h_1 h_2 q_0 q_1 q_2 (values less than %d) \n", MAX/2); 
    scanf("%d %d %d %d %d %d", &tuple[1], &tuple[2], &tuple[3], &tuple[4], &tuple[5], &tuple[6]); 
	if(DEBUG == 1)
		printf("Got these values: %d %d %d %d %d %d \n", tuple[1], tuple[2], tuple[3], tuple[4], tuple[5], tuple[6]); 
    
    //check that 6-tuple is ok - 
    //////Just for now, only ordered tuples -- SISTEMARE
    //if((tuple[1] - tuple[2] % 2 == 0) && (tuple[1] - tuple[3] % 2 == 0) && (tuple[4] - tuple[5] % 2 == 0)  && (tuple[4] - tuple[6] % 2 == 0) && (tuple[1] - tuple[4] % 2 == 1))
    //{
    //    printf("Invalid 6-tuple"); 
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
		printf("Our case is %d \n", our_case); 
    
	switch(our_case)
    {
        case 1: 
            //Initialize A,B,C,D
            A = tuple[1];
            B = tuple[6]; 
            C = tuple[3] - tuple[6]; 
            D = tuple[2] - tuple[6];
            
            if(DEBUG == 1)
				printf("A = %d, B = %d, C = %d, D = %d \n", A, B, C, D); 
            
            //Max length of cicles on C_i^+-  
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
            //Initialize A,B,C,D
            A = tuple[1];
            B = tuple[2]; 
            C = tuple[3] - tuple[6]; 
            D = tuple[6] - tuple[2];
            
            if(DEBUG == 1)
				printf("A = %d, B = %d, C = %d, D = %d \n", A, B, C, D); 

            //Max length of cicles on C_i^+-  
            max_len[1]=tuple[1] + tuple[2]; 
            max_len[0]=tuple[1] + tuple[3];
            max_len[2]=max_len[0];
            max_len[3]=max_len[1];
			
          	case_3(CC, A, B, C, D, max_len, tuple); 
			
            break; 
        case 4: 
            //Initialize A,B,C,D
            A = tuple[1];
            B = tuple[2] + tuple[3] - tuple[6]; 
            C = tuple[6] - tuple[2]; 
            D = tuple[6] - tuple[3];
            
            //Max length of cicles on C_i^+-  
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
		printf("\n\nFinished filling the cases\n"); 
		debug_stampa(CC, max_len); 
		printf("Now we follow the colors\n\n"); 
	}

    //color and follow lead --> to go up or down the graph the it is enough to add +2 mod 4 in the i value of CC[i][j]
    //in the meantime we write the word
    //we always start from the third 
    int temp_C, temp_vert, temp_cont[3], t_0, t_1; 
    if(DEBUG == 1)
		printf("Visited: "); 
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
    
    if(DEBUG == 1)
	{
		printf("\n\nFinished following the colors, I found 3 bicolored cicles\n"); 
		debug_stampa(CC, max_len); 
		printf("Now I print all of it\n\n"); 
	}
    
	//print the words in numbers to be sure of obtaining the correct word 
	if(DEBUG == 1)
	{
		for(int i = 0; i<3; ++i)
		{
			printf("\n The %d word is (before translating): '", i); 
			for(int j = 0; j<temp_cont[i]; ++j)
				printf(" %d ", our_word[i][j]); 
		}	
		printf("\n\n"); 
	}
	
	//Check the 6-tuple: do I have extra arcs? Did I use all 3 colors?  
	//If not, it is not a manifold, close with error
	if(controllo(CC, max_len)) //0 is FALSE, 1 is TRUE
	{
		printf("The 6-tuple doesn't correspond to a manifold, closing with error. \n"); 
		return 1; 
	}
	
    //Now I read the word and simplify consecutive opposite elements
    stampa(our_word, temp_cont); 
	
    return 0; 
}
