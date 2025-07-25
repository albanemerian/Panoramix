/*
** EPITECH PROJECT, 2025
** B-CCP-400-NAN-4-1-panoramix-albane.merian
** File description:
** helper
*/

#include <stdio.h>
#include <stdlib.h>

void helper(void)
{
    printf("USAGE\n");
    printf("\t./panoramix -n <number_of_villagers> -p <pot_size>");
    printf("-f <number_of_fights> -r <number_of_refills>\n");
    printf("\n");
    printf("DESCRIPTION\n");
    printf("\t-n number_of_villagers: number of villagers (must be > 0)\n");
    printf("\t-p pot_size: size of the potion (must be > 0)\n");
    printf("\t-f number_of_fights: number of fights (must be > 0)\n");
    printf("\t-r number_of_refills: number of refills (must be > 0)\n");
    exit(0);
}
