/*
** EPITECH PROJECT, 2025
** B-CCP-400-NAN-4-1-panoramix-albane.merian
** File description:
** my
*/

#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#ifndef MY_H_
    #define MY_H_

/* Strucutres */
typedef struct shared_data_s {
    int pot_size;
    int servings_left;
    int nb_refills;
    int refills_left;
    int total_fights;
    sem_t pot_empty;
    sem_t pot_full;
    pthread_mutex_t mutex;
    pthread_mutex_t print_mutex;
} shared_data_t;

typedef struct villager_s {
    int id;
    int nb_fights;
    shared_data_t *shared;
} villager_t;

typedef struct args_s {
    int nb_villagers;
    int nb_fights;
    villager_t *villagers;
    shared_data_t *shared;
} args_t;

/* Parsing function */
int parse(char **av);
void helper(void);

/* Villager print function */
void battle(int id);
void drink(int id, int nb_servings_left);
void refill(int id);
void fight(int id, int fights_left);
void sleep_villager(int id);

/* Druid print Function */
void wake_up(void);
void brew_refill(int refill);
void out_of_ingredients(void);


/* Thread function */
void panoramix(args_t *args);


#endif /* !MY_H_ */
