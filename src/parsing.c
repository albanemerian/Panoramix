/*
** EPITECH PROJECT, 2025
** B-CCP-400-NAN-4-1-panoramix-albane.merian
** File description:
** parsing
*/

#include "../include/my.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static args_t *init_struct(args_t *args, char **av)
{
    args->nb_villagers = atoi(av[1]);
    args->shared->pot_size = atoi(av[2]);
    args->nb_fights = atoi(av[3]);
    args->shared->nb_refills = atoi(av[4]);
    args->shared->refills_left = args->shared->nb_refills;
    args->shared->servings_left = args->shared->pot_size;
    args->shared->total_fights = args->nb_villagers * args->nb_fights;
    return args;
}

static args_t *init_villagers(args_t *args)
{
    args->villagers = malloc(sizeof(villager_t) * args->nb_villagers);
    if (!args->villagers) {
        perror("malloc");
        free(args->shared);
        free(args);
        return NULL;
    }
    return args;
}

static args_t *init_semaphore(args_t *args)
{
    sem_init(&args->shared->pot_empty, 0, 0);
    sem_init(&args->shared->pot_full, 0, 0);
    pthread_mutex_init(&args->shared->mutex, NULL);
    pthread_mutex_init(&args->shared->print_mutex, NULL);
    return args;
}

static int error_handling(char **av, args_t *args)
{
    for (int i = 1; i <= 4; i++) {
        if (atoi(av[i]) <= 0) {
            printf("Error: Invalid argument %s.\n", av[i]);
            fflush(stdout);
            free(args->shared);
            free(args);
            return 84;
        }
    }
    return 0;
}

static int verify_malloc(args_t *args)
{
    if (!args) {
        perror("malloc");
        return 84;
    }
    args->shared = malloc(sizeof(shared_data_t));
    if (!args->shared) {
        perror("malloc");
        free(args);
        return 84;
    }
    return 0;
}

int parse(char **av)
{
    args_t *args = malloc(sizeof(args_t));

    if (verify_malloc(args) == 84)
        return 84;
    if (error_handling(av, args) == 84)
        return 84;
    args = init_struct(args, av);
    args = init_villagers(args);
    if (args == NULL)
        return 84;
    args = init_semaphore(args);
    panoramix(args);
    free(args->villagers);
    free(args->shared);
    free(args);
    return (0);
}
