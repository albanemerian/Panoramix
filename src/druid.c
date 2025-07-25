/*
** EPITECH PROJECT, 2025
** B-CCP-400-NAN-4-1-panoramix-albane.merian
** File description:
** druid
*/

#include <stdio.h>
#include <stdlib.h>


void wake_up(void)
{
    printf("Druid: I'm ready... but sleepy...\n");
    fflush(stdout);
}

void brew_refill(int refill)
{
    printf("Druid: Ah! Yes, yes, I'm awake! Working on it! ");
    printf("Beware I can only make %d more refills after this one.\n", refill);
    fflush(stdout);
}

void out_of_ingredients(void)
{
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    fflush(stdout);
}
