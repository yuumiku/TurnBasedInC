#ifndef PLAYER_H
#define PLAYER_H

typedef struct Player {
    char name[50];
    int level;
    int hp;
    int maxHP;
    int attack;
    int defense;
    int score;
    int magic;
    int maxMagic;
    int healPotions;
    int defensePotions;
    int attackPotions;
    int magicPotions;

    struct Player *next;
} Player;



Player* createPlayer();
Player* choosePlayer(Player *head);
void updatePlayer(Player *head);
void displayPlayer(Player *p);

#endif

