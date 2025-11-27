#ifndef GAME_H
#define GAME_H

#include "player.h"

// Struct for enemy definition
typedef struct Enemy {
    char name[50];
    int hp;
    int attack;
    int defense;
    int maxHP;
    char asciiFile[100];
} Enemy;

// ---------- Utility Functions ----------
int rollChance(int percent);
void printHealthBar(int current, int max, const char *color);
void printEnemyASCII(const char *filename, int offset);
void openInventory(Player *player);

// ---------- Display Functions ----------
void displayBattleScreen(Player *player, Enemy *enemy, int offset);

// ---------- Battle Logic ----------
void checkEnemyMercy(Player *player, Enemy *enemy);
int playerTurn(Player *player, Enemy *enemy);
void enemyTurn(Player *player, Enemy *enemy);

// ---------- Main Battle Entry Point ----------
void battle(Player *player);

#endif
