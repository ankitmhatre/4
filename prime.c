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

int b = m_get_myid();
printf("id  = %d", b);
    int a;
printf("enter a number to check if prime or not: ");
scanf("%d", &a);
m_lock();
printf("%d\n", is_prime(a));
printf("%d\n", a);

m_unlock();

  
}

int main() {
    // Generate a random number between 1 and 100

    initialize();
   // srand( (unsigned int) time(NULL));

    value = (int *)shmalloc(sizeof(int));
     m_set_procs(8);
    m_fork(check);
    m_kill_procs();

//printf("value = %d\n", value[0]);
    // int num = rand() % 10000 + 1;
    
    // printf("Randomly generated number: %d\n", num);
    
    // if (is_prime(num)) {
    //     printf("%d is a prime number\n", num);
    // } else {
    //     printf("%d is not a prime number\n", num);
    // }
    clean();
    return 0;
}
