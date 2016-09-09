/*****************************************************************

NAME: Nancy Mogire

DATE: JUL, 2016

FILE: headers.c

DESCRIPTION: This file contains declarations for the functions defined in header.c as well as a denition of the tcp header struct

****************************************************************/
#include <stdio.h>

struct t_header{
    unsigned short src_port;
    unsigned short dest_port;
    unsigned int seq_no;
    unsigned int ack_no;
    unsigned short data_offset;
    unsigned short reserved;
    unsigned short control;
    unsigned short window;
    unsigned short checksum;
    unsigned short urgent_ptr;
};


int printheader();
int buildResponse();
