#ifndef LIST_H
#define LIST_H

#include "player.h"

Player* addPlayer(Player *head, Player *newPlayer);
Player* deletePlayer(Player *head);
void displayAllPlayers(Player *head);

#endif

