	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include<time.h>
	
	typedef struct faculitydetails //struct initialization
	{
	    char faculityname[16];
	    char Subjectname[10];
	    short int lectures;
	    char start[30];
	    
	}fac;
	
	
	int main()
	{
		printf("\n\n\n\n--------------------------------------------------TIME TABLE GENERATOR-------------------------------------------------\n\n\n");
	    fac app[100];  // naming struct as app
	    int as[300] , ad=0 , g;    //initializing some variables
		char univ[20], course[10] ;      //initializing some variables
		int section;                     //initializing some variables
		int share;
		int sec = 1;
		
		printf("\tINPUT \n\t-----\n");
		printf("Enter the name of university :- ");
		gets(univ);                                     //scanning university name
		
		printf("Enter the name of the course :-");
		scanf("%s" , course);                           //scanning course name 
		
		printf("Enter the number of sections :-");
		scanf("%d" , &section);                         //scanning number of sections 
		 
		int sub,per;
		
		printf("Enter the number of subjects to be taught in this course :- ");
		scanf("%d" , &sub);      
		
		int i=0;
		for(i=1; i<=sub ; i++)
		{
		printf("Enter the name of subject %d :-" , i);
		scanf("%s" , app[i].Subjectname) ;
		}                                                    //scanning number of subjects and subject names
	-
		printf("Enter the number of periods u want daily :- ");
		scanf("%d" , &per);     
		
		int j=0;
		for(j=1; j<=per ; j++)                                             //scanning the periods string with for loop 
		{
		printf("Enter the start and end time of period %d and mention am or pm without gap !! \n ex :-(9.00am-10.00am) :- " , j);
		scanf("%s" , app[j].start);
		}
		  
		printf("\n\n !! for %d subjects we will have %d different faculty \n for how many sections do u want to share this faculty ?? !! \n the share should perfectly divide no. of sections i.e %d \n Enter the no. of sections u want to share the faculty with :-" , sub , sub , section);   
		scanf("%d" , &share);                                               //Message which didvides faculty among different sets 
		                                                                    // if we have 10 sections we should enter share as 5 or 2 because they divide 10 and the faculty gets equal share 
		
		int div=section/share;                                                   // div determines how many times the below for loop with r runs  
		int r=0;
		
		for(r=1 ; r<=div ; r++)                                             // for loop for different sets of sections 
		{
		                                                                   //for every set u should enter new faculty names for new set of sections 
		printf("\n\n Enter the %d set of faculty names for set %d containig %d sections with same faculty \n" ,r , r , share);
		
		int u;
		int low =1 , upp=sub;                                                          //here low and upp are the constraints in between which we have to create random numbers
		                                                                               // here we took low as 1 and upp as subjects because we want random subjects between the given day 
		srand(time(NULL));                                                            // code to randomise number according to time using time.h header file
		
		for(i=1; i<=sub ; i++)
		{
		printf("Enter the name of the lecturer for %s :-" ,app[i].Subjectname );     //scanning subject and faculty name with for loop
		scanf("%s" , app[i].faculityname) ;
		}
		
		
		int arr[per][6];                                                    // initializing the 2d array
		int l=0 , m=0;
		char temp;
		
		printf("\n\n");
		printf(" %s\n" , univ);
		printf(" %s\n" , course);
		printf(" section %d\n\n" ,sec );                                         // printting university , course and section name before the time table  
		printf("\n");
		
	for(l=0 ; l<=per ; l++)
	{     
		for(m=0 ; m<=5 ; m++)
		{
	
	if(m==0&&l==0)
	{
	printf("  PERIOD");                                                          // printing period in (0,0) space 
	for(int z=1 ; z<16-strlen(app[l].start) ;z++) //this for loop is used for printing spaces between the columns
	{printf(" ");}                                //take lenght of a string is 20 in which the string is printed and remaining spaces are printed 
	
	}
	else if(m==0)                                                                //printing periods in first column
	{
	printf("  %s" , app[l].start);
	for(int z=1 ; z<20-strlen(app[l].start) ;z++)                                // printing spaces
	{printf(" ");}
	
	}
	else if(l==0)                                                               //printing  weekdaays in 1st row
	{
	switch(m)                                                                    // switch caes for printing weekdays
	{
	case 1:(m==1);
	printf("   MONDAY         ");
	break;
	
	case 2:(m==2);
	printf("   TUESDAY        ");
	break;
	
	case 3:(m==3);
	printf("   WEDNESDAY      ");
	break;
	
	case 4:(m==4);
	printf("   THURSDAY       ");
	break;
	
	case 5:(m==5);
	printf("   FRIDAY         ");
	break; }
	
	}
	else
	{
		
	 u = (rand()%(upp-low+1))+low;                                               //rand function to produce random numbers between upper limit and lower limit 
	                                                                            // which are lower limit =1 and upper limit  = number of subjects 
	                                                                            
	 as[ad]=u;                                                                  //storing all the u values in this array for use in 2nd to n sections
	                                                                            // there will be as many as 6*no.of subjects iterations 
																				// so that many values will be saved in as[ad]array  
	
	printf("  %s" , app[u].Subjectname );                                       //printing subject name 
	
	for(int z=1 ; z<14-strlen(app[u].Subjectname) ;z++)                         //printing spaces 
	{ 
	printf(" "); 
	}
		
	}
	 ad++;}          // this is for the inner for loop that is m
	 printf("\n"); }//this foe the outer for loop that is with l //printing an end line in a 2d carray                  
	                                                                             
																				 //incrementing add which helps to store u value for every iteration that comes 
	                                                                            //no. of iteration = 6(week days) * no. of subjects}
		
	                                                          //printing an end line after the table 
		
		printf("\nFaculty Name :-\n\n");                                         //printing faculty details 
		for(i=1; i<=sub ; i++)
		{
		printf("%s - %s\n" , app[i].Subjectname , app[i].faculityname );
		}
	
	int sec1 =1;    
	int k=0;                     //sec1 is initialized inorder to minus valu of g in the time table
	                                     
	//now time table for first section is aldready printed 
	// now we have to print the second to n section time tables 
	sec=sec+1;
	for(k=1 ; k<=share-1 ; k ++)
	{
		ad=0;
	printf("\n---------------------------------------------------------------------------------------------------------------------\n");
		printf(" %s\n" , univ);
		printf(" %s\n" , course);
		printf(" section %d\n\n" , sec);
		printf("\n");
	for(l=0 ; l<=per ; l++)
	{     
		for(m=0 ; m<=5 ; m++)
		{
	
	if(m==0&&l==0)
	{
		
	printf("  PERIOD");
	for(int z=1 ; z<16-strlen(app[l].start) ;z++)
	{printf(" ");}
	
	}
	else if(m==0)
	{
		
	printf("  %s" , app[l].start);
	for(int z=1 ; z<20-strlen(app[l].start) ;z++)
	{printf(" ");}
	
	}
	else if(l==0)
	{
		
	switch(m)
	{
	case 1:(m==1);
	printf("   MONDAY         ");
	break;
	
	case 2:(m==2);
	printf("   TUESDAY      ");
	break;
	
	case 3:(m==3);
	printf("  WEDNESDAY      ");
	break;
	
	case 4:(m==4);
	printf("   THURSDAY       ");
	break;
	
	case 5:(m==5);
	printf("   FRIDAY         ");
	break;}
	
	}
	else
	{
	   
	g=as[ad];                                    //before we have stored all the values of random u in as[ad] array 
	                                             //now we are storing as[ad] values in g , the logic here is that 
	   
	if(g<sub)                                    //if sumject number is less than the no. of subjects 
	{
		g=(g+sec1);                              //we will increment the subject number with section number  so that we dont get same values in all time tables 
		if(g>=sub)                               // but what if the subject number is 5 and section number ia 3 , we get subject number = 8 
		{
			g=g-(sub-1);                         // so we use this to make it lie between 1 and no. of subjects only 
		}
		
	}else if(g=sub)                              // if g = no. of subject 
	{
		g=(g-sec1);                              // if g = no. of subject means its the highes + 1 , so we minus 1 in each section 
		if(g<0)                                  // if g becomes less than 0 also we get an error , so we make it lie between 1 and no. of subjects
		{g = g + (sub+1);}	
	}
	
	printf("  %s" , app[g].Subjectname);                     //prinitng subject names
	for(int z=1 ; z<14-strlen(app[g].Subjectname) ;z++)     // printing spaces
	{printf(" ");}
		
	}
	ad++;
	}                                                            //ending of m for loop
	printf("\n"); }                                              
	                                                            // ending of l for loop
	                                                            //printing of faculty names for every section
		 sec1++;
		 printf("\n");
		 printf("Faculty Name :-\n\n");
		for(i=1; i<=sub ; i++)
		{
		printf("%s - %s\n" , app[i].Subjectname , app[i].faculityname );
		}
	
	 sec++;  }                                                            //ending of section for loop                                                           
	}                                                                     //ending of for loop of sets of sections
		return 0;
	}	                                                           //ending of document
