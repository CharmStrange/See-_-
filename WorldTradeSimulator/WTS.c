#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_ITEMS 4

typedef struct {
    char name[20];
    int prices[NUM_ITEMS];
} City;

typedef struct {
    char name[20];
    int base_price;
} Item;

typedef struct {
    char current_city[20];
    int capital;
    int cargo_capacity;
    int inventory[NUM_ITEMS];
} Player;

// Function prototypes
void initialize_game(City cities[], Item items[], Player *player);
void update_prices(City cities[], Item items[]);
void display_status(Player *player, City cities[], Item items[]);
void process_action(Player *player, City cities[], Item items[]);

int main() {
    City cities[NUM_CITIES] = {{"Tong"}, {"Delnya"}, {"Sipo"}, {"Belga"}, {"Tomadol"}};
    Item items[NUM_ITEMS] = {{"Item1", 10}, {"Item2", 20}, {"Item3", 30}, {"Item4", 40}};
    Player player;

    initialize_game(cities, items, &player);

    while (1) {
        update_prices(cities, items);
        display_status(&player, cities, items);
        process_action(&player, cities, items);
        
        // Add conditions to break the loop (e.g., a certain number of days, bankruptcy)
    }

    return 0;
}

void initialize_game(City cities[], Item items[], Player *player) {
    srand(time(0));
    player->capital = 1000;
    player->cargo_capacity = 15;
    strcpy(player->current_city, cities[0].name);
    for (int i = 0; i < NUM_ITEMS; i++) {
        player->inventory[i] = 0;
    }
}

void update_prices(City cities[], Item items[]) {
    for (int i = 0; i < NUM_CITIES; i++) {
        for (int j = 0; j < NUM_ITEMS; j++) {
            // Fluctuate prices randomly (example logic)
            cities[i].prices[j] = items[j].base_price + (rand() % 21 - 10);
        }
    }
}

void display_status(Player *player, City cities[], Item items[]) {
    printf("Current City: %s\n", player->current_city);
    printf("Capital: %d\n", player->capital);
    printf("Inventory:\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("  %s: %d\n", items[i].name, player->inventory[i]);
    }
    printf("Prices in current city:\n");
    for (int i = 0; i < NUM_ITEMS; i++) {
        printf("  %s: %d\n", items[i].name, cities[0].prices[i]); // Example: use first city
    }
}

void process_action(Player *player, City cities[], Item items[]) {
    // Example: buy first item
    if (player->capital >= cities[0].prices[0]) {
        player->capital -= cities[0].prices[0];
        player->inventory[0]++;
    }
}
