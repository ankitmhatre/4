#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sequent.h"
#include <time.h>



int *value;


bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    
    return true;
}



void check()
{

if( m_get_myid() ==0){

    int a;
printf("\nenter a number to check if prime or not: ");
scanf("%d", &a);
m_lock();
if(is_prime(a)){
printf("\n%d is prime\n", a);
}else{
printf("\n%d is not prime\n", a);
}


m_unlock();
}else{
printf("Process id is not 0 as requested");
  
}
}

int main() {
    // Generate a random number between 1 and 100

    initialize();
   // srand( (unsigned int) time(NULL));

    value = (int *)shmalloc(sizeof(int));
     m_set_procs(0);
    m_fork(check);
    m_kill_procs();
    clean();
    return 0;
}
