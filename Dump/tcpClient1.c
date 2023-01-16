#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "message.h"

// A TCP client program implementation
// Thilak T P, 05 December 2022
// The program takes input of the employee details from the user and stores that
// in a structure aid then into a file.

int main()
{
    FILE *dbFile;
    int socketDesc;
    struct sockaddr_in serverAddr;
    char serverMsg[1000];
    struct Data clientMsg;
	int counter = 0;
	    

    // Clean buffers:
    memset(serverMsg,'\0',sizeof(serverMsg));
    memset(&clientMsg,'\0',sizeof(clientMsg));
    
    // Create socket:
    socketDesc = socket(AF_INET, SOCK_STREAM, 0);
    
    if(socketDesc < 0){
        printf("Error while creating the socket\n");
        return -1;
    }
    
    printf("The Socket was created successfully!\n");
    
    // Set port and IP the same as server-side:
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12000);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    // Send connection request to server:
    if(connect(socketDesc, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0){
        printf("Error! Unable to connect\n");
        return -1;
    }
    printf("Connected with server successfully\n");
    // Inserting dummy value to server msg string to check
    strcpy(serverMsg,"Dummy Inserted!"); 
    // Get input from the user:
    
   dbFile = fopen("dbFile","r");
    // A loop to copy the data from the file and into the 
    while(fread(&clientMsg,sizeof(clientMsg),1,dbFile))
    {    
	
   	 // Send the message to server:
	if(send(socketDesc, &clientMsg, sizeof(clientMsg), 0) < 0){
       		printf("Error! Unable to send message\n");
	        return -1;
    	}
	usleep(1000000);
	counter = counter + 1;
	printf("Record sent count %d \n", counter);
	if(counter == 3){
		if(recv(socketDesc, serverMsg, sizeof(serverMsg), 0) < 0){
			printf("Error! Unable to send message\n");
			return -1;

		}else{
			printf("Server's response: %s\n",serverMsg);
			close(socketDesc);
		}
		break;
	}
	
    }    
    fclose(dbFile);
    // Receive the server's response:
/*    if(recv(socketDesc, serverMsg, sizeof(serverMsg), 0) < 0){
        printf("Error while receiving server's Message\n");
        return -1;
    }
    
    printf("Server's response: %s\n",serverMsg);
    
    // Close the socket:
    close(socketDesc);*/
    
    return 0;
}

