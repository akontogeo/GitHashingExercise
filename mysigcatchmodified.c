#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int count = 0; // Μετρητής

void custom_handler(int sig){
   count++; //Αύξηση του μετρητή κάθε φορά που εντοπίζω σήμα
   printf("Signal %d caught! (count: %d)\n", sig,count);
   if (count==2){
     printf("Restoring default SIGINT behavior...\n");
     signal(SIGINT, SIG_DFL); // Επαναφορά default συμπεριφοράς
   
   }
}

//ίδιο με πριν απλώς τώρα χρησιμοποιώ την custom handler
int main(){
    //Κλήση συνάρτησης signal για εντοπισμό σήματος
    signal(SIGINT, custom_handler);
    //ΠΛηκτρολόγησε το σήμα για να εντοπιστεί
    printf("Press Ctrl+C \n");
   //Βρόχος που περιμένει για το σήμα
    while(1){}
}
