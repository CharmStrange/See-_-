#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h> // usleep 함수 사용

#define EULER_NUMBER 2.71828
#define EULER_NUMBER_F 2.71828182846
#define EULER_NUMBER_L 2.71828182845904523536

#define MAP_SIZE 5 // 맵 크기 확장
#define MAX_FISH_TYPES 5 // 물고기 종류 확장
#define MAX_ITEMS 5 // 아이템 종류 확장

// 물고기 종류 정의
typedef enum {
    NONE_FISH = 0,
    SALMON,
    TROUT,
    CARP,
    TUNA,
    SHARK
} FishType;

// 아이템 종류 정의
typedef enum {
    NONE_ITEM = 0,
    ROD_BASIC,
    ROD_ADVANCED,
    BAIT_WORM,
    BAIT_LURE,
    NET
} ItemType;

// 플레이어 상태 구조체
typedef struct {
    int level;
    int experience;
    int gold;
    ItemType inventory[MAX_ITEMS];
    int inventoryCount;
} Player;

// 낚시터 구조체
typedef struct Spot {
    unsigned char status;
    struct Spot *ptr;
    FishType fish;
    ItemType item;
} Spot;

// 전역 변수
Player player;
Spot Pixels[MAP_SIZE][MAP_SIZE];
int fishes = 0;

// SlowPrint 함수
void slowPrint(const char *str, unsigned int delay) {
    for (int i = 0; str[i] != '\0'; i++) {
        putchar(str[i]);
        fflush(stdout); // 버퍼 비우기
        usleep(delay); // 마이크로초 단위로 지연
    }
    printf("\n");
}

// 시그모이드 함수 (double, float, long double)
double sigmoid(double n) {
    return (1 / (1 + pow(EULER_NUMBER, -n)));
}

float sigmoidf(float n) {
    return (1 / (1 + powf(EULER_NUMBER_F, -n)));
}

long double sigmoidl(long double n) {
    return (1 / (1 + powl(EULER_NUMBER_L, -n)));
}

// 맵 초기화 함수
void initializeMap() {
    for (int r = 0; r < MAP_SIZE; r++) {
        for (int c = 0; c < MAP_SIZE; c++) {
            Pixels[r][c] = (Spot){0, NULL, NONE_FISH, NONE_ITEM};
        }
    }
    slowPrint("\nFishing spots successfully created!", 10000);
}

// 플레이어 초기화 함수
void initializePlayer() {
    player.level = 1;
    player.experience = 0;
    player.gold = 100;
    player.inventoryCount = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        player.inventory[i] = NONE_ITEM;
    }
    slowPrint("Player initialized.", 10000);
}

// 맵 속성 출력 함수
void printMapAttributes() {
    slowPrint("\nMap Attributes:", 10000);
    for (int r = 0; r < MAP_SIZE; r++) {
        for (int c = 0; c < MAP_SIZE; c++) {
            printf("/ %p ", &Pixels[r][c]);
            printf("[%d] ", sizeof(Pixels[r][c]));
        }
    }
    printf("\n");
}

// 맵 상태 설정 함수
void setMapState() {
    srand(time(NULL));
    for (int r = 0; r < MAP_SIZE; r++) {
        for (int c = 0; c < MAP_SIZE; c++) {
            Pixels[r][c].status = rand() % 255;
            Pixels[r][c].fish = rand() % MAX_FISH_TYPES;
            Pixels[r][c].item = rand() % MAX_ITEMS;
        }
    }

    // 맵 연결 (원형 연결)
    for (int r = 0; r < MAP_SIZE; r++) {
        for (int c = 0; c < MAP_SIZE; c++) {
            Pixels[r][c].ptr = &Pixels[(r + 1) % MAP_SIZE][c];
        }
    }
    slowPrint("Map state set.", 10000);
}

// 맵 상태 출력 함수
void printMapState() {
    slowPrint("\nCurrent Map State:", 10000);
    for (int r = 0; r < MAP_SIZE; r++) {
        for (int c = 0; c < MAP_SIZE; c++) {
            printf("Status: %d, Fish: %d, Item: %d\n", Pixels[r][c].status, Pixels[r][c].fish, Pixels[r][c].item);
            printf("[This %p] -> [%p]\n\n", &Pixels[r][c], Pixels[r][c].ptr);
        }
    }
}

// 낚시 함수
void fishing(int r, int c) {
    srand(time(NULL));
    int parameter1 = rand() % 127;
    int parameter2 = rand() % 127;
    double probability = sigmoid(parameter1 - parameter2);

    if (probability > 0.5) {
        Pixels[r][c].status--;
        fishes++;
        slowPrint("You caught a fish!", 50000);
        printf(" ~~ ><(((º> ~~~\n");

        // 물고기 종류에 따른 보상
        switch (Pixels[r][c].fish) {
            case SALMON:
                player.gold += 50;
                player.experience += 20;
                slowPrint("You earned 50 gold and 20 experience.", 30000);
                break;
            case TROUT:
                player.gold += 30;
                player.experience += 15;
                slowPrint("You earned 30 gold and 15 experience.", 30000);
                break;
            case CARP:
                player.gold += 20;
                player.experience += 10;
                slowPrint("You earned 20 gold and 10 experience.", 30000);
                break;
            case TUNA:
                player.gold += 70;
                player.experience += 30;
                slowPrint("You earned 70 gold and 30 experience.", 30000);
                break;
            case SHARK:
                player.gold += 100;
                player.experience += 50;
                slowPrint("You earned 100 gold and 50 experience.", 30000);
                break;
            default:
                player.gold += 10;
                player.experience += 5;
                slowPrint("You earned 10 gold and 5 experience.", 30000);
                break;
        }

        // 아이템 획득
        if (Pixels[r][c].item != NONE_ITEM && player.inventoryCount < MAX_ITEMS) {
            player.inventory[player.inventoryCount++] = Pixels[r][c].item;
            slowPrint("You found an item!", 30000);
        }

    } else {
        slowPrint("Nothing was caught...", 50000);
        printf("Probability: [%f]\n", probability);
    }
}

// 게임 시뮬레이션 함수
void simulateGame() {
    slowPrint("\nGame Simulation Started:", 50000);
    fishing(0, 0); // 예시로 (0, 0) 위치에서 낚시
    slowPrint("\nGame Simulation Ended.", 50000);
}

int main() {
    initializeMap();
    initializePlayer();
    setMapState();
    printMapState();
    simulateGame();
    printMapAttributes();

    printf("\nPlayer Level: %d, Experience: %d, Gold: %d\n", player.level, player.experience, player.gold);
    printf("Inventory Count: %d\n", player.inventoryCount);
    for (int i = 0; i < player.inventoryCount; i++) {
        printf("Item: %d\n", player.inventory[i]);
    }
    return 0;
}
