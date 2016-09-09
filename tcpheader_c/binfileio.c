/*****************************************************************

NAME: Nancy Mogire

DATE: JUL, 2016

FILE: binfileio.c

DESCRIPTION: This file contains the binary file input and output functions

****************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "headers.h"

extern unsigned char *read_in;
extern unsigned char replyheader[20];
extern struct t_header header;

/*****************************************************************

Function name: readfile

DESCRIPTION: file reader function

reads from a specified binary file and assigns to a struct

Parameters: char *

Return values: int

****************************************************************/

int readfile(char filename[])
{   
  
    FILE *fileToRead;
    int i=0;
    int filelen;
    unsigned char mask=0xc;
          
    fileToRead= fopen(filename, "rb");
        
    if (fileToRead!=NULL)
    {   
        fseek(fileToRead, 0, SEEK_END);
        filelen = ftell(fileToRead);
        rewind(fileToRead);
        read_in = (unsigned char *)malloc((filelen+1)*sizeof(unsigned char));
        for(i = 0; i < filelen; i++) 
        {
            fread(read_in+i, 1, 1, fileToRead);
        }
        
        fclose(fileToRead);
    }
    else
    {
        printf("unable to read file.\n");
    }

    printf("Header length in bytes: %d\n", filelen);
    header.src_port=read_in[0]<<8|read_in[1];
    header.dest_port=read_in[2]<<8|read_in[3];
    header.seq_no=read_in[4]<<24|read_in[5]<<16|read_in[6]<<8|read_in[7];
    header.ack_no=read_in[8]<<24|read_in[9]<<16|read_in[10]<<8|read_in[11];
    header.data_offset=read_in[12]<<4;
    header.reserved=(unsigned int)0;
    header.control= (read_in[13]<<2) & mask;
    header.window=read_in[14]<<8|read_in[15];
    header.checksum= read_in[16]<<8|read_in[17];
    header.urgent_ptr= read_in[18]<<8|read_in[19];

    printheader();       
    return 0;
}

/*****************************************************************

Function name: writefile

DESCRIPTION: file writer functions

writes bytes onto a file

Parameters: char *

Return values: int

****************************************************************/

int writefile(char filename[])
{
  
    FILE *fileToWrite;

    fileToWrite = fopen(filename, "w");
    if (fileToWrite == NULL)
    {
        printf("Error: could not open the file!\n");
    }
    else
    {
        fwrite(&replyheader, 20, 1, fileToWrite);
    }
        fclose(fileToWrite);

return 0;
}
