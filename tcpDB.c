#include<stdio.h>
#include "message.h"


// A databuilder application for TCP socket that
// Take info from the user and stores and appends it into a file
// Thilak T P, Bindushree N G, Bhakti Bhataria, 07 December 2022

struct Data clientMsg;
int main()
{	FILE *dbFile, *dbFileRead;;
	int c;
	char flag;
	int flag1;
	struct Data clientMsg;
	int rCount=0;
	dbFile = fopen("dbFile","a");

	printf("---------------------------TCP Data Builder----------------------------\n");
	printf("Enter your choice: \n 1 - Add recordsto the file.\n 2 - Display records in the file\n 3 - Remove the file\n 4 - Quit the App\n");
	printf("-----------------------------------------------------------------------\n");
	scanf("%d",&flag1);
	while ((c = getchar()) != '\n' && c != EOF);
	while(flag1!=4)
	{
	switch(flag1)
	{
		case 1 :     while(flag1!=4)
				{
				getMsg(&clientMsg);
				fwrite(&clientMsg,sizeof(clientMsg),1,dbFile);
				printf("Press Any key to continue adding another record or 4 to exit\n");
 				scanf("%d",&flag1);
				while ((c = getchar()) != '\n' && c != EOF);
	                       }
				fclose(dbFile);
	                        
				printf("\nDone Entering data!\n.");
				return -1;
		
		case 2 :
				dbFileRead = fopen("dbFile","r");
                                
	                        printf("--------------------------Contents of the File---------------------------------\n");
                                while(fread(&clientMsg,sizeof(clientMsg),1,dbFileRead))
				{
          			
                  			printf("\n\n\nEmployee ID: %s",clientMsg.empId);
                  			printf("| Employee Name: %s |",clientMsg.empName);
                  			printf( " Employee's Desk number: %d \n",clientMsg.deskNumber);
          				rCount++;
				}
    
	                        printf("---------------------------------------------------------------------------------\n");
				printf("There are %d records in the file.\n",rCount);
          			printf("\nReached the end of the file.\n");
				fclose(dbFileRead);
				return -1;
		case 3 :      remove("dbFile");
				printf("\nThe file was removed sucessfully!\n");
				return -1;
		case 4 :	printf("\nYou have Exited the program!\n");
				return -1;
		default  : 	printf("\nError! Invalid Choice.\n");
				return -1;
	}
	}
	
	fclose(dbFile);
	return 0;
} 
