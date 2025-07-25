/*
** EPITECH PROJECT, 2025
** B-CCP-400-NAN-4-1-panoramix-albane.merian
** File description:
** panoramix
*/

#include "../include/my.h"
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

static void loop_in_villager(villager_t *data, shared_data_t *shared)
{
    pthread_mutex_lock(&shared->mutex);
    if (shared->servings_left == 0) {
        pthread_mutex_lock(&shared->print_mutex);
        refill(data->id);
        pthread_mutex_unlock(&shared->print_mutex);
        sem_post(&shared->pot_empty);
        pthread_mutex_unlock(&shared->mutex);
        sem_wait(&shared->pot_full);
        shared->servings_left--;
        pthread_mutex_lock(&shared->mutex);
    }
    pthread_mutex_lock(&shared->print_mutex);
    drink(data->id, shared->servings_left);
    pthread_mutex_unlock(&shared->print_mutex);
    shared->servings_left--;
    pthread_mutex_unlock(&shared->mutex);
    pthread_mutex_lock(&shared->print_mutex);
    fight(data->id, --data->nb_fights);
    pthread_mutex_unlock(&shared->print_mutex);
    usleep(10000);
}

void *villager_thread(void *arg)
{
    villager_t *data = (villager_t *)arg;
    shared_data_t *shared = data->shared;

    pthread_mutex_lock(&shared->print_mutex);
    battle(data->id);
    pthread_mutex_unlock(&shared->print_mutex);
    while (data->nb_fights > 0) {
        loop_in_villager(data, shared);
    }
    pthread_mutex_lock(&shared->print_mutex);
    sleep_villager(data->id);
    pthread_mutex_unlock(&shared->print_mutex);
    return NULL;
}

static int execute_druid(shared_data_t *shared)
{
    sem_wait(&shared->pot_empty);
    if (shared->refills_left <= 0)
        return 1;
    pthread_mutex_lock(&shared->print_mutex);
    brew_refill(shared->refills_left - 1);
    pthread_mutex_unlock(&shared->print_mutex);
    shared->servings_left = shared->pot_size;
    shared->refills_left--;
    sem_post(&shared->pot_full);
    usleep(50000);
    return 0;
}

void *druid_func(void *args)
{
    shared_data_t *shared = (shared_data_t *)args;

    pthread_mutex_lock(&shared->print_mutex);
    wake_up();
    pthread_mutex_unlock(&shared->print_mutex);
    while (shared->refills_left > 0) {
        if (execute_druid(shared) == 1)
            break;
    }
    pthread_mutex_lock(&shared->print_mutex);
    out_of_ingredients();
    pthread_mutex_unlock(&shared->print_mutex);
    return NULL;
}

void panoramix(args_t *args)
{
    pthread_t druid_thread;
    pthread_t villagers[args->nb_villagers];

    pthread_create(&druid_thread, NULL, druid_func, args->shared);
    usleep(10000);
    for (int i = 0; i < args->nb_villagers; i++) {
        args->villagers[i].id = i;
        args->villagers[i].nb_fights = args->nb_fights;
        args->villagers[i].shared = args->shared;
        pthread_create(&villagers[i], NULL,
            villager_thread, &args->villagers[i]);
    }
    for (int i = 0; i < args->nb_villagers; i++)
        pthread_join(villagers[i], NULL);
    if (args->shared->refills_left > 0)
        sem_post(&args->shared->pot_empty);
    pthread_join(druid_thread, NULL);
}
