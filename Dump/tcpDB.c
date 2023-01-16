#include<stdio.h>
#include "message.h"

struct Data clientMsg;
// A databuilder application for TCP socket that
// Take info from the user and stores and appends it into a file

int main()
{	FILE *dbFile, *dbFileRead;;
	int c;
	char flag;
	int flag1;
	struct Data clientMsg;
	dbFile = fopen("dbFile","a");

	printf("----------------TCP Data Builder------------------------\n");
	printf("Enter your choice: \n a - Add recordsto the file.\n d - Display records in the file\n r - Remove the file\n q - Quit the App\n");
	printf("--------------------------------------------------------\n");
	scanf("%c",&flag);
	while ((c = getchar()) != '\n' && c != EOF);
		while(flag!='q')
	{
	switch(flag)
	{
		case 'a' :     while(flag!='q')
				{
				getMsg(&clientMsg);
				fwrite(&clientMsg,sizeof(clientMsg),1,dbFile);
				printf("Press Any key to continue adding another or 4 to exit\n");
 				scanf("%c",&flag);
				while ((c = getchar()) != '\n' && c != EOF);
				fclose(dbFile);
	                        }
				return -1;
		
		case 'd' :
				dbFileRead = fopen("dbFile","r");
                               // while
					(fread(&clientMsg,sizeof(clientMsg),1,dbFileRead));
          			{
                  			printf("\n\n\nEmployee ID: %s",clientMsg.empId);
                  			printf("| Employee Name: %s |",clientMsg.empName);
                  			printf( " Employee's Desk number: %d \n",clientMsg.deskNumber);
          			}
    
          			fclose(dbFileRead);
				return -1;
		case 'r' :      remove("dbFile");
				printf("\nThe file was removed sucessfully!\n");
				return -1;
		case 'q' :	return -1;
		default  : 	printf("Error! Invalid Choice.");
				return -1;
	}
	}
	
	fclose(dbFile);
	return 0;
} 
