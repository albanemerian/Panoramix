/*
** EPITECH PROJECT, 2025
** B-CCP-400-NAN-4-1-panoramix-albane.merian
** File description:
** test_helper
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std_help(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(helper, display_usage, .init = redirect_all_std_help)
{
    helper();
    cr_assert_stdout_eq_str(
        "USAGE\n"
        "\t./panoramix -n <number_of_villagers> -p <pot_size>"
        "-f <number_of_fights> -r <number_of_refills>\n"
        "\n"
        "DESCRIPTION\n"
        "\t-n number_of_villagers: number of villagers (must be > 0)\n"
        "\t-p pot_size: size of the potion (must be > 0)\n"
        "\t-f number_of_fights: number of fights (must be > 0)\n"
        "\t-r number_of_refills: number of refills (must be > 0)\n"
    );
}
