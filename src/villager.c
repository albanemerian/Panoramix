/*
** EPITECH PROJECT, 2025
** B-CCP-400-NAN-4-1-panoramix-albane.merian
** File description:
** battle
*/

#include <stdio.h>
#include <stdlib.h>

void battle(int id)
{
    printf("Villager %d: Going into battle!\n", id);
    fflush(stdout);
}

void drink(int id, int nb_servings_left)
{
    printf("Villager %d: I need a drink... I see", id);
    printf(" %d servings left.\n", nb_servings_left);
    fflush(stdout);
}

void refill(int id)
{
    printf("Villager %d: Hey Pano wake up! We need more potion.\n", id);
    fflush(stdout);
}

void fight(int id, int fights_left)
{
    printf("Villager %d: Take that roman scum!", id);
    printf(" Only %d left.\n", fights_left);
    fflush(stdout);
}

void sleep_villager(int id)
{
    printf("Villager %d: I'm going to sleep now.\n", id);
    fflush(stdout);
}
