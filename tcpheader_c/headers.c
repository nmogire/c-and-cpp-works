/*****************************************************************

NAME: Nancy Mogire

DATE: JUL, 2016

FILE: headers.c

DESCRIPTION: This file contains functions to manipulate and output the tcp headers

****************************************************************/

#include <stdio.h>
#include <string.h>
#include "headers.h"
#include "binfileio.h"

extern struct t_header header;
extern unsigned char *read_in;
extern unsigned char replyheader[20];

/*****************************************************************

Function name: printheader

DESCRIPTION: print function
takes values from the header struct and outputs them to the console

Parameters: none

Return values: int

****************************************************************/

int printheader()
{  
    printf("Source Port: %d\n", header.src_port);
    printf("Destination Port: %d\n", header.dest_port);
    printf("Sequence Number: %d\n", header.seq_no);
    printf("ACK number: %d\n", header.ack_no);
    printf("Data Offset: %d\n", header.data_offset);
    printf("Reserved Bytes: %d\n", header.reserved);
    printf("Control Bits: %d\n", header.control);

    if(header.control==12){
    printf("syn_flag set, ack_flag set\n");
     }
    else if (header.control==0){
      printf("syn_flag not set, ack_flag not set\n");
    }
    else if (header.control==2){
      printf("syn_flag set, ack_flag not set\n");
    }
    else{
      printf("possible flag error\n");
    }

    printf("Window Size: %d\n", header.window);
    printf("Checksum: %d\n", header.checksum);
    printf("Urgent Pointer: %d\n", header.urgent_ptr);
return 0;
}

/*****************************************************************

Function name: buildresponse

DESCRIPTION: creates a response header from the received header and loads values onto
output buffer


Parameters: none

Return values: int

****************************************************************/

int buildResponse()
{
    int i;
    unsigned char temp[2];
    
    for (i = 0; i <20; i++) {
      replyheader[i] = read_in[i];
    }
    
    temp[0]=replyheader[0];
    temp[1]=replyheader[1];
    replyheader[0]=replyheader[2];
    replyheader[1]=replyheader[3];
    replyheader[2]=temp[0];
    replyheader[3]=temp[1];
    
    printf("%d\n",header.seq_no+1);
    printf("%d\n",header.ack_no+1);
    
    header.seq_no+=1;
    header.ack_no+=1;

    replyheader[4] = header.seq_no>>24;
    replyheader[5] = header.seq_no>>16;
    replyheader[6] = header.seq_no>>8;
    replyheader[7] = header.seq_no;

    replyheader[8] = header.ack_no>>24;
    replyheader[9] = header.ack_no>>16;
    replyheader[10] = header.ack_no>>8;
    replyheader[11] = header.ack_no;
 
    return 0;
}
