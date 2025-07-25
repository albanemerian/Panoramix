/*
** EPITECH PROJECT, 2025
** B-CCP-400-NAN-4-1-panoramix-albane.merian
** File description:
** main
*/

#include "include/my.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static void check_helper(char **av)
{
    for (int i = 1; av[i] != NULL; i++) {
        if (strcmp(av[i], "-h") == 0 || strcmp(av[i], "--help") == 0) {
            helper();
            exit(0);
        }
    }
}

int main(int ac, char **av)
{
    check_helper(av);
    if (ac != 5) {
        printf("Error: Invalid number of arguments.\n");
        exit(84);
    }
    if (parse(av) == 84)
        exit(84);
}
