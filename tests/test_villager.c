/*
** EPITECH PROJECT, 2025
** B-CCP-400-NAN-4-1-panoramix-albane.merian
** File description:
** test_villager
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(villager, battle, .init = redirect_all_std)
{
    battle(1);
    cr_assert_stdout_eq_str("Villager 1: Going into battle!\n");
}

Test(villager, drink, .init = redirect_all_std)
{
    drink(1, 3);
    cr_assert_stdout_eq_str("Villager 1: I need a drink... I see 3 servings left.\n");
}

Test(villager, refill, .init = redirect_all_std)
{
    refill(1);
    cr_assert_stdout_eq_str("Villager 1: Hey Pano wake up! We need more potion.\n");
}

Test(villager, fight, .init = redirect_all_std)
{
    fight(1, 2);
    cr_assert_stdout_eq_str("Villager 1: Take that roman scum! Only 2 left.\n");
}

Test(villager, sleep_villager, .init = redirect_all_std)
{
    sleep_villager(1);
    cr_assert_stdout_eq_str("Villager 1: I'm going to sleep now.\n");
}
