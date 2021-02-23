#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <rpc/rpc.h>
#include "date.h"


#define MAX_LEN 100
long get_response(void);

long get_response()
{   
    long choice;
    
    printf("===========================================\n");
    printf("    Choose what info you want to see: \n");
    printf("-------------------------------------------\n");
    printf("                1. Date\n");
    printf("                2. Time\n");
    printf("                3. Both\n");
    printf("                4. CPU usage\n");
    printf("                5. Memory Usage\n");
    printf("                6. Load Procs per min\n");
    printf("                7. Quit\n");
    printf("-------------------------------------------\n");
    printf("               Choice (1-7):");
    scanf("%ld",&choice);
    printf("===========================================\n");
    return(choice);
}

 int main(int argc, char **argv)
 {
     CLIENT  *cl;        /* RPC handle */
         char    *server;
         char    **sresult;  /* return value from date_1()      */
         char    s[MAX_LEN];    /* character array to hold output */
         long    response;  /* user response                           */
         long    *lresult;    /* pointer to user response          */

         if (argc != 2) {
             fprintf(stderr, "usage: %s hostname\n", argv[0]);
             exit(1);
          }

         server = argv[1];
         lresult = (&response);

         /*
         * Create the client "handle."
         */
         if ( (cl = clnt_create(server, getDate, getDateVersion, "udp")) == NULL) {
                 clnt_pcreateerror(server);
                 exit(2);
         }

         response = get_response();
         while(response != 7) {
                if ((sresult = date_1(lresult, cl)) == NULL){
                        clnt_perror(cl, server);
                        exit(3);
                 }                                                                                               
                //printf("here\n");
                printf("%s\n", *sresult);
                //printf("here3\n"); 
                response = get_response();
        }

        clnt_destroy(cl);               /* done with the handle */
        printf("goodbye\n");
        exit(0);
}



