#ifndef _GLOBALDEF_H
#define _GLOBALDEF_H
#ifdef DEBUG
#define DPRINT(fmt,args...) fprintf(stderr,fmt,##args)
#else
#define DPRINT(fmt,args...)
#endif
#define CUSTOMERLOGO "images/essar.jpg"
#define PRODNAME     "PetroMark 1.0"
#define DBTITLE      "Inventory Systems"
/*message levels */
#define INFO    0
#define ERROR   1


/*messages  */
#define MSGCONNFAILED "Unable to connect to server"
#define MSGQUERYFAILED "Failed to execute a query"


void feedback_msg (int status, char *msg);
#endif /* _GLOBALDEF_H */
