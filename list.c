#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

Player* addPlayer(Player *head, Player *newPlayer) {
    if (head == NULL) return newPlayer;

    Player *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newPlayer;
    return head;
}

Player* deletePlayer(Player *head) {
    if (head == NULL) {
        printf("No players to delete.\n");
        return NULL;
    }

    Player *temp = head;
    int i = 1;

    printf("\n--- Players List ---\n");
    while (temp != NULL) {
        printf("%d. %s (Level: %d, HP: %d)\n", i, temp->name, temp->level, temp->hp);
        temp = temp->next;
        i++;
    }

    int choice;
    printf("Enter the number of the player you want to delete: ");
    scanf("%d", &choice);
    getchar(); // remove leftover newline

    if (choice < 1 || choice >= i) {
        printf("Invalid choice.\n");
        return head;
    }


    temp = head;
    Player *prev = NULL;
    for (int j = 1; j < choice; j++) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    printf("Player '%s' deleted.\n", temp->name);
    free(temp);
    return head;
}

void displayAllPlayers(Player *head) {
    if (head == NULL) {
        printf("No players found.\n");
        return;
    }

    printf("\n=== PLAYER LIST ===\n");
    Player *temp = head;
    while (temp != NULL) {
        displayPlayer(temp);
        temp = temp->next;
    }
}

