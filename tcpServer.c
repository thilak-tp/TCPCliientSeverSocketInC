#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include "message.h"
#include<unistd.h>
//A TCP Socket server implementation
// The program receives records from the tcpClient.c and prints out all the information and sends back the acknowledgement
// Thilak T P , 05 December 2022



int main(){
int socketDesc, clientSoc, clientSize;
struct sockaddr_in serverAddr, clientAddr;
struct Data clientMsg;
char serverMsg[1000];
int rCount=0; 
// Clearing the buffers
memset(serverMsg, '\0', sizeof(serverMsg));
memset(serverMsg, '\0', sizeof(clientMsg));

// Creating the socket
socketDesc = socket(AF_INET, SOCK_STREAM, 0);

if(socketDesc < 0){
	printf("Error while creating the socket!\n");
	return -1;
}
printf("The socket was created successfully!\n");

// Setting port and the IP
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(12000);
serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

//Bind to the set port and IP
if(bind(socketDesc,(struct sockaddr*)&serverAddr, sizeof(serverAddr))<0){
	printf("Error! Couldn't bind to the port.\n");
	return -1;	
}

printf("Binding Sucessful!\n");

//Listen for client
if(listen(socketDesc,5)!=0){
	printf("Error! Unable to listen to clients.\n");
	return -1;
}
printf("Listening for incoming clients\n");

clientSize = sizeof(clientAddr);
clientSoc = accept(socketDesc, (struct sockaddr*)&clientAddr, &clientSize);

if(clientSoc < 0){

	printf("Error! Can't accept\n");
	return -1;
}

printf("Client connected at IP %s and port %i\n",inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));


printf("---------------------------------MESSAGE FROM CLIENT-------------------------------------------\n");
// Receive messages in a loop and print them.
//recv(clientSoc,&rCount,sizeof(int),0);
//printf("Received Record count : %d",rCount);
while(rCount!=3)
{
	// Receiver client's message
	if(recv(clientSoc,&clientMsg,sizeof(clientMsg),0)<0)
	{
		printf("Error! Couldn't receive data.\n");
		return -1;
	}
	rCount++;
	displayMsg(clientMsg);
       /* strcpy(serverMsg,"\nACK_OK - Message Received\n");
  
  	if(send(clientSoc, &serverMsg, strlen(serverMsg),0)<0){
         	printf("Error! Can't send the message.");
         	 return -1;
 	 }
  */

}
printf("-----------------------------------------------------------------------------------------------\n");
strcpy(serverMsg,"\nACK_OK - Message Received\n");
if(send(clientSoc, &serverMsg, strlen(serverMsg),0)<0){
	printf("Error! Can't send the message.");
	return -1;
}

close(clientSoc);
close(socketDesc);
return 0;
}
