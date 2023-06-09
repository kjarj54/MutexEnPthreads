#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>  
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
float balance = 0;

void* deposit(void* arg) {
    int i = 0;
    float amount;
    srand (time(NULL));
    while (i < 5) {
        pthread_mutex_lock(&mutex);
        if (balance > 200) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        amount = (rand() % 20+1) + 1;
        printf("Depositando $%.2f\n", amount);
        balance += amount;
        pthread_mutex_unlock(&mutex);
        sleep(1);
        // Incrementar la variable en cada ciclo
        i++;
    }
    return NULL;
}

int main() {
    int i = 0;
    pthread_t threads[10];
	srand (time(NULL));
    while (i <+ 10) {
        pthread_create(&threads[i], NULL, deposit, NULL);
        // Incrementar la variable en cada ciclo
        i++;
    }

    // Reiniciar la variable para el siguiente bucle
    i = 0;

    while (i <= 10) {
        pthread_join(threads[i], NULL);
        // Incrementar la variable en cada ciclo
        i++;
    }

    printf("Balance Final de la cuenta: $%.2f\n", balance);

    return 0;
}
