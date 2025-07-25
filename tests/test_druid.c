/*
** EPITECH PROJECT, 2025
** B-CCP-400-NAN-4-1-panoramix-albane.merian
** File description:
** test_druid
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std_druid(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(druid, wake_up, .init = redirect_all_std_druid)
{
    wake_up();
    cr_assert_stdout_eq_str("Druid: I'm ready... but sleepy...\n");
}

Test(druid, brew_refill, .init = redirect_all_std_druid)
{
    brew_refill(3);
    cr_assert_stdout_eq_str(
        "Druid: Ah! Yes, yes, I'm awake! Working on it! "
        "Beware I can only make 3 more refills after this one.\n"
    );
}

Test(druid, out_of_ingredients, .init = redirect_all_std_druid)
{
    out_of_ingredients();
   cr_assert_stdout_eq_str("Druid: I'm out of viscum. I'm going back to... zZz\n");
}
