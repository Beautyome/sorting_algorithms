#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Enumeration of the suits of card
 * @SPADE: Spades suit
 * @HEART: Hearts suit
 * @CLUB: Clubs suit
 * @DIAMOND: Diamonds suit
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing the cards
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the cards
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of cards
 *
 * @card: Pointer to the nodeof the cards
 * @prev: Pointer to the prev node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
