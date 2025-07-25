# Project Detail
PANORAMIX

### 🧪 Preliminaries

    Binary name: panoramix

    Language: C

    Compilation: via Makefile (must include re, clean, and fclean rules)

### 📜 Context

The year is 50 BC. Gaul is entirely occupied by the Romans... Well, almost.
One small village of indomitable Gauls still holds out. Life isn't easy for the Roman soldiers stationed in Totorum, Aquarium, Laudanum, and Compendium!

In this village, the druid prepares a magic potion that gives the villagers strength to beat up the Romans. Each villager needs to drink from the potion before fighting. When the pot is empty, they must wake the druid to refill it.

### 🎯 Project Goals

This project focuses on threads, mutexes, and semaphores programming in C.
You must simulate the behavior of villagers drinking, fighting, and asking the druid for more potion, respecting thread synchronization.

### 🛠️ How to Use
```
./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>
```
Arguments:

    nb_villagers (int > 0) — number of villagers

    pot_size (int > 0) — number of servings the pot can hold

    nb_fights (int > 0) — number of fights each villager will perform

    nb_refills (int > 0) — number of times the druid can refill the pot

Example:
```
./panoramix 3 5 3 1
```
📋 Rules

    Each villager and the druid must run in their own thread.

    The cooking pot starts full.

    Villagers drink before each fight.

    If the pot is empty, villagers must wake up the druid.

    The druid refills the pot until he runs out of ingredients.

    The program must exit gracefully when all villagers have finished fighting.

    If inputs are invalid (≤ 0), the program prints an error and exits with status 84.

### 👨‍🌾 Villager Behavior

Each villager:

    Starts by announcing their entrance into battle.

    Drinks a potion before each fight.

    Asks the druid for a refill if the pot is empty.

    Fights (nb_fights times), then goes to sleep.

Output examples:
```
Villager <id>: Going into battle!
Villager <id>: I need a drink... I see <nb_servings_left> servings left.
Villager <id>: Hey Pano wake up! We need more potion.
Villager <id>: Take that roman scum! Only <fights> left.
Villager <id>: I'm going to sleep now.
```
### 🧙 Druid Behavior

The druid:

    Waits to be called by a villager.

    Refills the pot up to nb_refills times.

    Announces when he runs out of ingredients and stops.

Output examples:

Druid: I'm ready... but sleepy...
Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make <refills> more refills after this one.
Druid: I'm out of viscum. I'm going back to... zZz

### 🧵 Threads & Synchronization

    Semaphores are used to signal between villagers and the druid.

    Mutexes protect access to shared resources like the pot's servings.

    Threads are used for each villager and the druid independently.
## Compilation :
    - make / make re
    - make clean / make fclean
    - make coding


## Coding Style :

    The Cpp code needs to ablige to a specified coding styke,
    to check if the code is complient with the norm execut
    the make coding command or the ./styleChecker.sh.
    To understand the errors and how to fix them please
    refers to the coding-cpp.txt.


## Doxygen :

    The basic documentation fo the project is generated using the
    doxygen, to run the doxygen executable, please make sure you
    installed the pdf-latex librairie.


## Commit norm :

<Gitmoji> : [Element / Module] : [MESSAGE]

Gitmoji = The emoji approriate for the current modification.
[Element / Module] = The elemenet you applied the modification.
[MESSAGE] = A detail message of what you did.


Gitmojies:

    Code feature :
        - :sparkles: (✨): Introduce new features
        - :recycle: (♻️): Refactor / update code
        - :bug: (🐛): Fix a bug
        - :poop: (💩) : Remove Coding style or temporary fix
        - :rotating_light: (🚨) : Fix Compiling Warning
        - :fire: (🔥): Remove code or files

    Test feature :
        - :white_check_mark: (✅): Add, update, or pass tests

    Architecture :
        - :see_no_evil: (🙈): Add or update .gitignore files
        - :construction_worker: (👷): Add or update CI build system
        - :building_construction: (🏗️) : Make Architectural changes
        - :memo: (📝) : Add or update documentation

    ...
### Pull Request
    - :tada: (🎉): This Gitmoji must be used for each PR created!
    - :lipstick: (💄): This Gitmoji must be used for each PR merged!
    - :rewind: (⏪️): This Gitmoji must be used for each revert done!



## Git-Cli :

- Changer message de commit, avant qu'il soit push :
    ```bash
    git commit --amend -m "New commit message"
    ```

- Changer le message de commit, si il a deja été push :
    ```bash
    git commit --amend -m "New commit message"
    git push --force
    ```

- Un-add un ficher add par erreur qui est pas encore push:
    ```bash
    git restore --staged <file>
    ```

- Un-add un fichier qui a été commit :
    ```bash
    git reset --soft HEAD~1
    git restore --staged fichier-a-retirer.txt
    git commit -m "Nouveau message de commit (sans le fichier)"
    ```

## NOTE 

| Category                         | Percentage | Tests | Crash |
|----------------------------------|------------|-------|-------|
| 01 - Usage of required functions | 100%       | 3/3   | x     |
| 02 - Error handling              | 100%       | 6/6   | x     |
| 03 - Working as intended         | 100%       | 8/8   | x     |
| End scores                       | 100%       | 17/17 | x     |


Grade A Médailles

