#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int Z = 0, P = 95, S = 2800, H = 3000, E = H - S;
    int Y = 3, A = H / Y, I = 5, Q = 1;
    int D = 0;
    int D1 = 0, P1 = 0;
    float L; // declare L here

    while (Z < 10) {
        printf("\nHAMURABI:  I BEG TO REPORT TO YOU,\n");
        printf("IN YEAR %d, %d PEOPLE STARVED, %d CAME TO THE CITY,\n", Z, D, I);
        P += I;
        if (Q > 0) {
            P = P / 2;
            printf("A HORRIBLE PLAGUE STRUCK! HALF THE PEOPLE DIED.\n");
        }
        printf("POPULATION IS NOW %d\n", P);
        printf("THE CITY NOW OWNS %d ACRES.\n", A);
        printf("YOU HARVESTED %d BUSHELS PER ACRE.\n", Y);
        printf("THE RATS ATE %d BUSHELS.\n", E);
        printf("YOU NOW HAVE %d BUSHELS IN STORE.\n\n", S);

        if (Z == 10) break;

        int landPrice = rand() % 10 + 17;
        Y = landPrice + 17;
        printf("LAND IS TRADING AT %d BUSHELS PER ACRE.\n", Y);

        int acresToBuy;
        printf("HOW MANY ACRES DO YOU WISH TO BUY? ");
        scanf("%d", &acresToBuy);
        if (acresToBuy < 0) exit(0);
        if (landPrice * acresToBuy > S) {
            printf("HAMURABI: THINK AGAIN. YOU HAVE ONLY %d BUSHELS OF GRAIN. NOW THEN.\n", S);
            continue;
        }
        A += acresToBuy;
        S -= landPrice * acresToBuy;

        int grainForPeople;
        printf("HOW MANY BUSHELS DO YOU WISH TO FEED YOUR PEOPLE? ");
        scanf("%d", &grainForPeople);
        if (grainForPeople < 0) exit(0);
        if (grainForPeople > S) {
            printf("HAMURABI: THINK AGAIN. YOU HAVE ONLY %d BUSHELS OF GRAIN. NOW THEN.\n", S);
            continue;
        }
        S -= grainForPeople;

        int acresToPlant;
        printf("HOW MANY ACRES DO YOU WISH TO PLANT WITH SEED? ");
        scanf("%d", &acresToPlant);
        if (acresToPlant == 0) continue;
        if (acresToPlant < 0) exit(0);
        if (acresToPlant > A) {
            printf("HAMURABI: THINK AGAIN. YOU OWN ONLY %d ACRES. NOW THEN.\n", A);
            continue;
        }
        if (acresToPlant / 2 > S) {
            printf("HAMURABI: THINK AGAIN. YOU HAVE ONLY %d BUSHELS OF GRAIN. NOW THEN.\n", S);
            continue;
        }
        if (acresToPlant < 10 * P) {
            printf("BUT YOU HAVE ONLY %d PEOPLE TO TEND THE FIELDS! NOW THEN.\n", P);
            continue;
        }
        S -= acresToPlant / 2;

        int harvest = rand() % 5 + 1;
        if (harvest % 2 == 0) {
            E = S / harvest;
        }
        S = S - E + acresToPlant * Y;

        int immigrants = grainForPeople / 20;
        if (P < immigrants) {
            D = P - immigrants;
            if (D > 0.45 * P) {
                P1 = ((Z - 1) * P1 + D * 100 / P) / Z;
                P = immigrants;
                D1 += D;
                continue;
            }
        }
        else {
            printf("YOU STARVED %d PEOPLE IN ONE YEAR!!!\n", D);
            printf("DUE TO THIS EXTREME MISMANAGEMENT YOU HAVE NOT ONLY\n");
            printf("BEEN IMPEACHED AND THROWN OUT OF OFFICE BUT YOU HAVE\n");
            printf("ALSO BEEN DECLARED NATIONAL FINK!!!!\n");
            break;
        }
        Z++;
    }

    if (Z == 10) {
        printf("IN YOUR 10-YEAR TERM OF OFFICE, %d PERCENT OF THE\n", P1);
        printf("POPULATION STARVED PER YEAR ON THE AVERAGE, I.E. A TOTAL OF %d PEOPLE DIED!!\n", D1);
        L = (float)A / P; // calculate L here
        printf("YOU STARTED WITH 10 ACRES PER PERSON AND ENDED WITH %f ACRES PER PERSON.\n\n", L);
    }

    if (P1 > 33 || L < 7) {
        printf("YOUR HEAVY-HANDED PERFORMANCE SMACKS OF NERO AND IVAN IV.\n");
        printf("THE PEOPLE (REMAINING) FIND YOU AN UNPLEASANT RULER, AND,\n");
        printf("FRANKLY, HATE YOUR GUTS!!\n");
    }
    else if (P1 > 10 || L < 9) {
        printf("YOUR PERFORMANCE COULD HAVE BEEN SOMEWHAT BETTER, BUT\n");
        printf("REALLY WASN'T TOO BAD AT ALL. %d PEOPLE WOULD DEARLY LIKE TO SEE YOU ASSASSINATED BUT WE ALL HAVE OUR TRIVIAL PROBLEMS.\n", (int)(P * 0.8 * rand() / (RAND_MAX + 1.0)));
    }
    else {
        printf("A FANTASTIC PERFORMANCE!!! CHARLEMANGE, DISRAELI, AND\n");
        printf("JEFFERSON COMBINED COULD NOT HAVE DONE BETTER!\n");
    }

    return 0;
}
