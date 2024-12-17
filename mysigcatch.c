//Εισαγωγή Βιβλιοθηκών

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

//Μύνημα εντόπισης ζητουμένου
void handle_sigint(int sig){
	printf("SIGINT signal caught!");
	exit(0);
}
int main(){
    //Κλήση συνάρτησης signal για εντοπισμό σήματος
    signal(SIGINT, handle_sigint);
    //ΠΛηκτρολόγησε το σήμα για να εντοπιστεί
    printf("Press Ctrl+C \n");
   //Βρόχος που περιμένει για το σήμα
    while(1){}
}
