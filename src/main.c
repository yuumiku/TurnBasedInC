#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "list.h"
#include "game.h"
#include <time.h>

int main() {
    srand(time(NULL));
    Player *players = NULL;
    int choice;

    do {
        printf("\n=== PLAYER MENU ===\n");
        printf("1. Create Player\n");
        printf("2. Choose a Player\n");
        printf("3. Update Player\n");
        printf("4. Delete Player\n");
        printf("5. Show All Players\n");
        printf("0. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {   // handle invalid input
            printf("Invalid input. Try again.\n");
            while (getchar() != '\n');      // clear invalid input
            continue;
        }


        switch (choice) {
            case 1:
                players = addPlayer(players, createPlayer(players)); // pass head
                break;
            case 2: {
                Player *currentPlayer = choosePlayer(players);
                if (currentPlayer != NULL) {
                    #ifdef __linux__
                        system("clear");
                    #endif
                    #ifdef _WIN32
                        system("cls");
                    #endif
                    battle(currentPlayer);
                }
                break;
            }
            case 3:
                updatePlayer(players);
                break;
            case 4:
                players = deletePlayer(players);
                break;
            case 5:
                displayAllPlayers(players);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
