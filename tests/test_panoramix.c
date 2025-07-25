/*
** EPITECH PROJECT, 2025
** B-CCP-400-NAN-4-1-panoramix-albane.merian
** File description:
** test_panoramix
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

Test(panoramix, valid_execution)
{
    args_t args = {
        .nb_villagers = 2,
        .nb_fights = 3,
        .shared = malloc(sizeof(shared_data_t))
    };
    args.shared->pot_size = 5;
    args.shared->nb_refills = 2;
    args.shared->refills_left = 2;
    args.shared->servings_left = 5;
    args.shared->total_fights = 6;
    args.villagers = malloc(sizeof(villager_t) * args.nb_villagers);

    panoramix(&args);

    free(args.villagers);
    free(args.shared);
    cr_assert(1); // Ensure no crash
}
