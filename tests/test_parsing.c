/*
** EPITECH PROJECT, 2025
** B-CCP-400-NAN-4-1-panoramix-albane.merian
** File description:
** test_parsing
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std_parse(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(parse, invalid_arguments, .init = redirect_all_std_parse)
{
    char *av[] = {"./panoramix", "-1", "10", "5", "3", NULL};

    cr_assert_eq(parse(av), 84);
    cr_assert_stdout_eq_str("Error: Invalid argument -1.\n");
}

Test(parse, valid_arguments, .init = redirect_all_std_parse)
{
    char *av[] = {"./panoramix", "3", "5", "3", "1", NULL};
    parse(av);
}
