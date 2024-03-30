RageE1dër
ragee1der
Invisible
consl_, V, tylercube, tsnyd

tsnyd — 03/18/2024 5:26 PM
since you need something to bridge the gap between the two languages
consl_ — 03/18/2024 5:26 PM
yeah
V — 03/18/2024 5:28 PM
free feel to place me anywhere, im down to learn the required tech for any role
consl_ — 03/18/2024 5:29 PM
looking at JNI GTK seems so much simplier
everything will already be in the langauge
tsnyd — 03/18/2024 5:30 PM
yeah JNI is aneurism inducing, it's also really bad if you need to make big changes to either part of your code
consl_ — 03/18/2024 5:31 PM
lots of specifics we need to know too
like are we running the app in linux
and can gtk be used there
tsnyd — 03/18/2024 5:33 PM
ye we would need more implementation to make it accessible from various operation systems
gtk is usable by linux and windows from what i've seen by default 
specifically gtk 4 is cross platform
consl_ — 03/18/2024 5:39 PM
can we just include it on our programs or do we have to download it
something to try
since linux comes with gimp It might not need a download
maybe
tsnyd — 03/18/2024 5:40 PM
that's true
consl_ — 03/18/2024 5:55 PM
https://www.gtk.org/docs/getting-started/hello-world/
The GTK Team
The GTK Project - A free and open-source cross-platform widget toolkit
GTK is a free and open-source cross-platform widget toolkit for creating graphical user interfaces.
Image
tsnyd — 03/18/2024 5:57 PM
-5
consl_ — 03/18/2024 5:57 PM
thats fucked
tylercube — 03/18/2024 5:57 PM
fr
tsnyd — 03/18/2024 5:57 PM
bro loves handing out the -5s
tylercube — 03/18/2024 5:57 PM
he was joking lmao
tsnyd — 03/18/2024 5:57 PM
idk lmao maybe
RageE1dër — 03/18/2024 6:54 PM
@tsnyd @tylercube @V  are you all ok working together on the gui and the client side of the server
@consl_ are you ok working with me on the server side of the code
we all can working together on the code helping each other with the parts when needed
consl_ — 03/18/2024 6:58 PM
yup
tylercube — 03/18/2024 6:58 PM
yeS
V — 03/18/2024 7:00 PM
yeye
RageE1dër
 pinned 
a message
 to this channel. See all 
pinned messages
.
 — 03/24/2024 3:53 PM
RageE1dër — 03/24/2024 3:54 PM
@consl_
RageE1dër — 03/24/2024 6:56 PM
@everyone I created the GitHub repository can all of you send your GitHub username or email so i can add you all
i will also post a video in a few minutes so you can see how to update the GitHub repository to get the code and upload the code
RageE1dër — 03/24/2024 7:48 PM
you can update your code manual or you can use a terminal to do that 

to clone a GitHub Repository 
create a folder cd into the folder then

In the terminal, you need to run
git clone https://github.com/RageE1der/ChatApplication.git


then you need to remote connection to the repository (I believe this a one-time process)
git remote add origin https://github.com/RageE1der/ChatApplication.git main


To get the updated data later you have to fetch using

you need to fetch to see if there are any changes made to the repository online 
git fetch


to confirm there are changes you need to 
git log --online

^^this line will show you which files have been changed

this line will update the code in your folder
Git pull origin main

you need to add the main at the end because it is the branch you are getting the files from

To add the updated code 

you need to get the status to make sure that the file has saved the changes
git status

when you run the line the file should show up in a red color

then you need to add the file to update
git add Client.c
 
you can use 
git add --all
 but that will update all the files i would not recommend it but GitHub does track the updates if you accidentally do all

then you need to commit the file 
git commit -m "Your descriptive commit message"
 you need to put a comment at the end of the line or it will give you an error the comment for the line above is ""Your descriptive commit message"" you can use one letter

then finally to update it you need to type 
git push origin main

you need to add the main at the end because it is the branch you are updating the files for 
consl_ — 03/25/2024 5:07 PM
Just updating everyone that im working on the code rn and adding comments
consl_ — 03/25/2024 5:43 PM
THIS IS THE SERVER CODE
/*
 * Authors: Connor Haggerty ,
 * Project: Final CMPSC311 Chat Application Server Side
 * Version: 1.0
 */
Expand
main.c
3 KB
Its not debugged or ran yet because Vbox lags my laptop
full comments
tylercube — 03/25/2024 5:46 PM
i have it too
consl_ — 03/25/2024 5:54 PM
so what is this project if hes going over 90% of it
tsnyd — 03/25/2024 5:55 PM
yeah that's how all his assignments are pretty much
He said he's going over client side too right? Do you think he will go over GUIs and stuff?
V — 03/25/2024 5:58 PM
I remember him saying he won’t teach us the GUI
I might be wrong though
consl_ — 03/25/2024 5:59 PM
Im guessing this is just gonna be GUI
tsnyd — 03/25/2024 5:59 PM
Yeah I guess that might be the only part we need to do ourselves
V — 03/25/2024 5:59 PM
Yeah it seems like it
consl_ — 03/27/2024 6:30 PM
@everyone heres fully commented Server and Client code from class we can use for the project its been fully debugged and any time you edit it add your name to the top comment
/*
 * Authors: Connor Haggerty ,
 * Project: Final CMPSC311 Chat Application Client Side
 * Version: 1.0
 */

Expand
client.c
3 KB
/*
 * Authors: Connor Haggerty ,
 * Project: Final CMPSC311 Chat Application Server Side
 * Version: 1.0
 */
Expand
server.c
3 KB
﻿
/*
 * Authors: Connor Haggerty ,
 * Project: Final CMPSC311 Chat Application Client Side
 * Version: 1.0
 */

//Libraries
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>

//Global Variables
#define SERV_TCP_PORT 23

int main(int argc, char *argv[])
{
    //Variables
    int sockfd;
    struct sockaddr_in serv_addr;
    char *serv_host = "localhost";
    struct hostent *host_ptr;
    int port;
    int buff_size = 0;

    //Logic I/O Stream

    /* Command Line: client [host [port_number]] */

    //reading the command line for the server host
    if(argc>=2)
    {
        //read the host if provided
        serv_host = argv[1];
    }//end of if[1]
    if (argc==3)
    {
        //read port if provided
        sscanf(argv[2], "%d" ,&port);

    }//end of if[1]
    else
    {
        //setting default port if not provided
        port=SERV_TCP_PORT;
    }//end of else[1]

    //Getting the Address of the host
    if((host_ptr = gethostbyname(serv_host))==NULL)
    {
        perror("Cannot get host name");
        exit(1);
    }//end of if[1]
    if(host_ptr->h_addrtype != AF_INET)
    {
        perror("Cannot get Address type");
        exit(1);
    }//end of if[1]


    //Binding the local address so that the client send to server

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = ((struct in_addr *) host_ptr->h_addr_list[0])->s_addr;
    serv_addr.sin_port = htons(port);


    //Opening a TCP Socket
    sockfd = socket(AF_INET,SOCK_STREAM,0);

    //Error Checking for the socket connection
    if(sockfd<0)
    {
        perror("Cannot open Socket Stream");
        exit(-1);
    }//end of if [1]

    //Connecting to the Server

    if(connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr))<0)
    {
        perror("Cannot connect to server");
        exit(-1);
    }

    //Writing Message to server
    write(sockfd,"hello World CMPSC311",sizeof("hello World CMPSC311"));

    //closing connection
    close(sockfd);

}// end of function 'main'
