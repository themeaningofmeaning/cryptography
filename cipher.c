// Dylan G
// This is crypotgraphy progam I wrote (read below for directions)
// Demonstration of dynamic memory allocation w/ strings
// 
/*
*******************************************************************************	
*******************************************************************************
*******************************************************************************
			Project Description:
*******************************************************************************
In this program, I will implement three basic cryptography procedures 
at the user’s choice:

	1. Encode input file with key and write cipher text to output
	2. Decode input file with key and write plain text to output
	3. Break the cipher text input and write plain text to output

****************************************************************************************************************************************************************
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE !FALSE

//Prototype all functions

void encode(void);
void decode(void);
void ceaser(void);
int searching(char mod, char set[]);
int checking(char first[], int fcheck, char second[], int scheck);
void create_alphabet(void);

//Declare global variables

int count=0, x, key, shaba, s3=0, test, myes=0, programcheck, lt=0, done;
char alphabet[70], *store, c1, c2, c1, c2, *array1;
FILE *f1,*f2,*f3;
char *yo;
int sd=0;

//**********************************************************
//************Beggining of Main function********************
//**********************************************************

int main (int argc,char *argv[]){

   
//Open neccessary input text file to read and open the output file

   f1 = fopen(argv[2],"r");
   f2 = fopen(argv[3],"w");

   if (argc==4)
	   f3 = fopen("mydictional.txt","r");		//open the dictionary file

  
//Safety Check

   if (f1==NULL){
      printf("Error!  The plain text file does not exist.\n");
      return 0;
   }
   if (f2==NULL){
      printf("Error!  The ciphered text file does not exist.\n");
      return 0;
   }

   if (argc==5){
      key=atoi(argv[4]);
      if (key<1 || key>71){
         printf("You have entered an invalid key.  Please enter an integer 1-71\n");
         exit(0);
      }
   }
    if ( argc > 5 ) {
        puts("Too many command line arguments");
        return EXIT_FAILURE;}

    else if ( argc < 4 ) {
        puts("There are not enough command line arguments");
        return EXIT_FAILURE;}

//End of safety check***

create_alphabet();			//create the alphabet

programcheck=atoi(argv[1]);		//read in the program option

//determine which option must be executed

if(programcheck==1){			//encode option
	done = FALSE;
	char ch;
	system("clear");
	printf("You have decided to encode %s with the key %s.  Is this correct?\n[Enter 'Y' to continue or 'N' to quit]: ",argv[2], argv[4]);
	while(!done)
	{
		ch = getchar();
		printf("\n");
		switch(ch)
		{	case 'N':
			case 'n':
				printf("Goodbye!\n");
				done = TRUE;	//quit program
				exit(0);
			case 'Y':
			case 'y':
				done = TRUE;
				break;
			default:
				printf("Careful, you have made an invalid entry!\n[Enter 'Y' to continue with the program or 'N' to quit]: ");
				break;
			//	fflush(stdin);
		} /* end switch */
		ch = getchar();
	} /* end while */
	encode();
	printf(".....encoding process complete!\n");
}
if(programcheck==2){			//decode option
	done = FALSE;
	char ch;
	system("clear");
	printf("You have decided to decode %s with the key %s.  Is this correct?\n[Enter 'Y' to continue or 'N' to quit]: ",argv[2], argv[4]);
	while(!done)
	{
		ch = getchar();
		printf("\n");
		switch(ch)
		{	case 'N':
			case 'n':
				printf("Goodbye!\n");
				done = TRUE;	//quit program
				exit(0);
			case 'Y':
			case 'y':
				done = TRUE;
				break;
			default:
				printf("Careful, you have made an invalid entry!\n[Enter 'Y' to continue with the program or 'N' to quit]: ");
				break;
			//	fflush(stdin);
		} /* end switch */
		ch = getchar();
	} /* end while */
	decode();
	printf(".....decoding process complete!\n");}
if(programcheck==3){			//computer find key option
	done = FALSE;
	char ch;
	system("clear");
	printf("You have decided to have the computer determine the key and decode %s.\nIs this correct? [Enter 'Y' to continue or 'N' to quit]: ", argv[2]);
	while(!done)
	{
		ch = getchar();
		printf("\n");
		switch(ch)
		{	case 'N':
			case 'n':
				printf("Goodbye!\n");
				done = TRUE;	//quit program
				exit(0);
			case 'Y':
			case 'y':
				done = TRUE;
				break;
			default:
				printf("Careful, you have made an invalid entry!\n[Enter 'Y' to continue with the program or 'N' to quit]: ");
				break;
			//	fflush(stdin);
		} /* end switch */
		ch = getchar();
	} /* end while */
//************************
//ceasear()	//consult dr.qu about why this didn't work on tue
key=1;
      count++;
      fscanf(f3,"%c",&c1);
      store=(char*)malloc(sizeof(char));   //create enough memory store
      *store=c1;
      while(!feof(f3)){
          count++;
          fscanf(f3,"%c",&c1);
          array1=(char*)malloc(sizeof(char)*count);
          for (x=0;x<(count-1);x++)
             *(array1+x)=*(store+x);
          *(array1+x)=c1;
          free(store);
          store=(char*)malloc(sizeof(char)*count);
          for (x=0;x<(count);x++)
             *(store+x)=*(array1+x);
          free(array1);
      }
//Clear the screen

system("clear");

//Print the key and the # of word matches with that key to the monitor 

      printf("Key   | Matches\n");
      printf("---------------\n");

//Test Keys 1-72
      for (key=1;key<72;key++){       
         sd=0;
         fscanf(f1,"%c",&c1);

//Decode same as before but using the key in question 

         shaba=searching(c1,alphabet)-key;
         if (shaba<0)
            shaba=shaba+72;
         while(!feof(f1)){
            if (searching(c1,alphabet)==70){
               fscanf(f1,"%c",&c2);
	       //while(!feof(f1)){
               if (!feof(f1)){
                  if (searching(c2,alphabet)!=70){
                     fprintf(f2,"%c",alphabet[shaba]);
                     shaba=searching(c2,alphabet)-key;
                     if (shaba<0)
                        shaba=shaba+72;
                     fprintf(f2,"%c",alphabet[shaba]);
                     fscanf(f1,"%c",&c1);
                     shaba=searching(c1,alphabet)-key;
                     if (shaba<0)
                        shaba=shaba+72;
                  }
		  else{
                     fprintf(f2,"%c",alphabet[shaba]);
                     c1=c2;
                  }
               }
            }
	    else{ 
               fprintf(f2,"%c",alphabet[shaba]);
               fscanf(f1,"%c",&c1);
               shaba=searching(c1,alphabet)-key;
               if (shaba<0)
                  shaba=shaba+72;
            }
         }                             
         fprintf(f2,"\n");

	 //close/switch after 
         fclose(f1);
         f1 = fopen(argv[2],"r");
         fclose(f2);
         f2 =fopen(argv[3],"r");	//read mode inital

//track wordcount

         while(!feof(f2)){
            lt=0;

            fscanf(f2,"%c",&c1);
            shaba=searching(c1,alphabet);
	    //while(shaba<62){
	    //while(!feof(f2)){
           
	   //implement DMA method discussed in thurs lecture
	    while(shaba<62 && !feof(f2)){
               lt++; 
               array1=(char*)malloc(sizeof(char)*lt);  //create enough memory array1 
               for (x=0;x<(lt-1);x++)
                 	*(array1+x)=*(yo+x);   //p copy
               		*(array1+x)=c1;
               if (x!=0)
                  free(yo);
               yo=(char*)malloc(sizeof(char)*lt);	//create enough memory yo
               for (x=0;x<lt;x++)
                  *(yo+x)=*(array1+x);
               free(array1);
               fscanf(f2,"%c",&c1);
               shaba=searching(c1,alphabet);
            }


            if (lt>0 && checking(yo,lt,store,count)==1)
                sd++;           //determine if words match

            if (lt>0 && sd>s3){
                s3=sd;
                myes=key;
            }


         }  //end of while loop
         printf(" %-2d   |    %-2d\n",key,sd);	//doesn't push text over when making frame
         fclose(f2);   
         f2=fopen(argv[3],"w"); //switch to write mode
      }
	printf("---------------");
      printf("\n***********************\n***********************\nThe Key is: %d\n***********************\n***********************\n\n",myes);
    
     //Switch the read and write modes (look up argv switching...stalled when used pointer)
     //init. file decoding
      f1=fopen(argv[2],"r");     //read 
      f2=fopen(argv[3],"w");     //write
      fscanf(f1,"%c",&c1);

    //Decode using the key comp det.

      shaba=searching(c1,alphabet)-myes;
      if (shaba<0)
         shaba=shaba+72;
      while(!feof(f1)){

         if (searching(c1,alphabet)==70){
            fscanf(f1,"%c",&c2);
            //while(!feof(f1)){
	    if (!feof(f1)){
               if (searching(c2,alphabet)!=70){
                  fprintf(f2,"%c",alphabet[shaba]);
                  shaba=searching(c2,alphabet)-myes;
                  
		  if (shaba<0)
                     	shaba=shaba+72;
                  	fprintf(f2,"%c",alphabet[shaba]);
                  	fscanf(f1,"%c",&c1);
                  	shaba=searching(c1,alphabet)-myes;
                  
		  if (shaba<0)
                     shaba=shaba+72;
               }//end if loop when search!=70
	       
	       else{
                  fprintf(f2,"%c",alphabet[shaba]);
                  c1=c2;
               }
            }//end if(feof(f1))
         }
	    
	    else{ 
            fprintf(f2,"%c",alphabet[shaba]);
            fscanf(f1,"%c",&c1);
            shaba=searching(c1,alphabet)-myes;
            if (shaba<0)
               shaba=shaba+72;
         }
      }	 
      fprintf(f2,"\n");

//Close the input and output files

      fclose(f1);		//close input text
      fclose(f2);		//close output text file
      fclose(f3);		//close dictionary text file
   }				


   return 0;			//exit the program
}

//*******************************************************************
//*****************End of the main function**************************
//*******************************************************************


//function to create an alphabet

void create_alphabet(void){

int cr, check2=0;
char c4;

//define the special characters 62-71
alphabet[62]=';'; alphabet[63]=':'; alphabet[64]=','; alphabet[65]='.'; alphabet[66]=(char)39; alphabet[67]='"'; alphabet[68]='('; alphabet[69]=')'; alphabet[70]='\n'; alphabet[71]=' ';
//define other characters 0-62
for (cr=0;cr<26;cr++){
      alphabet[cr]='a'+cr;
   }

   for (cr=26;cr<52;cr++){
      alphabet[cr]='A'+(cr-26);
   }

   for (cr=52;cr<62;cr++){
      alphabet[cr]='0'+(cr-52);
   }

}

//Function to take a letter that is scanned and convert it to a number

int searching(char mod,char set[]){ 
   int a;
   for (a=0;a<72;a++){
      if (mod==set[a])
         return a;
   }
   return -1;
}

//Begin the function to encode/encrypt the text file

void encode(void){
      fscanf(f1,"%c",&c1);
      //while(!FALSE){
      while(!feof(f1)){
	      //if(!feof(f1)){

         if (searching(c1,alphabet)==70){
         	fscanf(f1,"%c",&c2);
	 //while(!feof(f1)){
         if (!feof(f1)){
               if (searching(c2,alphabet)!=70){

	//use method suggested on dm forum
	
                  fprintf(f2,"%c",alphabet[(searching(c1,alphabet)+key)%72]);
                  fprintf(f2,"%c",alphabet[(searching(c2,alphabet)+key)%72]);
                  fscanf(f1,"%c",&c1);
               }
	       else{
                  fprintf(f2,"%c",alphabet[(searching(c1,alphabet)+key)%72]);
                  c1=c2;
               }
            }
         }
	 else{ 
            fprintf(f2,"%c",alphabet[(searching(c1,alphabet)+key)%72]);
            fscanf(f1,"%c",&c1);
         }
      }//end of while(feof(f1))
      fprintf(f2,"\n");

//Close the input and output files
      fclose(f1);
      fclose(f2); 
}

//Compare string in question to dict. string and determine if there is valid match

int checking(char first[],int fcheck, char second[],int scheck){
    int yaba=0, a, b;

    for (a=0;a<scheck;a++){
        b=0;
	//agreement
        while(second[a]!='\n'){

            if (first[b]==second[a]){
               a++;
               b++;
               yaba=1;
            }
	//no agreement
            else {
               yaba=0;
               while (second[a]!='\n')
                   a++;
               break;
            }
        }//end of while loop
        if (yaba==1 && b==fcheck)
            return 1;
    }
    return 0;
} 

//Begin function to decode the text file
void decode(void){

      fscanf(f1,"%c",&c1);			//store text to array
     
      shaba = searching(c1,alphabet)-key;	//shift text the other way to decode
      
      if (shaba < 0)
         shaba = shaba+72;

      while(!feof(f1)){
      	if (searching(c1,alphabet) == 70){
        	fscanf(f1,"%c",&c2);
       		if (!feof(f1)){

        		if (searching(c2,alphabet) != 70){
                 		 fprintf(f2,"%c",alphabet[shaba]);
				//shaba = searching(c2,alphabet)+key
                 		 shaba = searching(c2,alphabet)-key;

                 	if (shaba < 0)
                    		shaba = shaba+72;
                 		fprintf(f2,"%c",alphabet[shaba]);
                 		fscanf(f1,"%c",&c1);
				//shaba = searching(c1,alphabet)+key;
                 		shaba = searching(c1,alphabet)-key;
                     		shaba = shaba+72;
               			}

			else{
                  		fprintf(f2,"%c",alphabet[shaba]);
                  		c1 = c2;
               			}
            }//end of if(!feof) statement
         }//end of if search statement
	else{ 
            fprintf(f2,"%c",alphabet[shaba]);
            fscanf(f1,"%c",&c1);
            shaba = searching(c1,alphabet)-key;
	    //regen
            if (shaba < 0)
               shaba = shaba+72;
         }
      }                             
      fprintf(f2,"\n");

//Close the input and output files
      fclose(f1);
      fclose(f2);
}
     
