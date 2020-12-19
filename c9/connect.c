#include "altid.h"
#include <stdio.h>
#include <string.h>

/* Connects to a named service in a thread */
void
connect_svc(Service *svc)
{
    printf("Here with %s addr %s\n", svc->name, strtok(svc->addr, ":"));
	svc->status |= CONNECTED;
}

/* Create a linked list of buffers */
void
list_buffers(Service *svc)
{

}

/* Will look for either feed or document file */
/* Returns error if neither is found, or any encountered errors */
int
read_main(Service *svc)
{
	return -1;
}

