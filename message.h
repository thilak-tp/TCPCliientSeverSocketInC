
// This is a header file created for common code that belongs to a TCP client server socket
// Thilak T P, 05 December 2022  



// The message structure that contains the Employee ID , Name and desk number.
struct Data
{
	int rCount;
	char empId[20];
	char empName[50];
	int deskNumber;
};


// A function to get the info from the user
void getMsg(struct Data *clientMsg)
{
	printf("\n Enter the Employee ID: \n");
	gets(clientMsg->empId);
	
	printf("\n Enter the Employee Name: \n");
	gets(clientMsg->empName);

	printf("\n Enter the Employee's Desk number: \n");
	scanf("%d",&clientMsg->deskNumber);
}

// A function to display the information
void displayMsg(struct Data clientMsg)
{
        printf("\nEmployee ID: %s",clientMsg.empId);
	printf("| Employee Name: %s |",clientMsg.empName);
	printf( " Employee's Desk number: %d \n",clientMsg.deskNumber);

}

