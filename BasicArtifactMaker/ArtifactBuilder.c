#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define SIZE 50
#define DELAY 30000  // microseconds for slow-print

typedef unsigned char UC;

// Type name table
char *type[21] = {
    "Epsilon", "Zeta", "Eta", "Theta",
    "Iota", "Kappa", "Lambda", "Mu",
    "Nu", "Xi", "Omicron", "Pi",
    "Rho", "Sigma", "Tau", "Upsilon",
    "Phi", "Chi", "Psi", "Omega", "End"
};

typedef struct Artifact {
    UC Alpha;
    UC Beta;
    UC Gamma;
    UC Delta;
    char signature;
} Artifact;

// Logging system (in-memory)
char* logs[100];
int log_index = 0;

// -------- Utility Functions --------
void slow_print(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        putchar(str[i]);
        fflush(stdout);
        usleep(DELAY);
    }
}

char* Buffer() {
    char* buffer = (char*)malloc(SIZE * sizeof(char));
    return buffer;
}

void log_command(const char* cmd) {
    logs[log_index] = strdup(cmd);
    log_index++;
}

void show_log() {
    for (int i = 0; i < log_index; i++) {
        printf("[%d] %s\n", i, logs[i]);
    }
}

// -------- Artifact Core Functions --------
Artifact Maker(UC Alpha, UC Beta, UC Gamma, UC Delta) {
    Artifact artifact = { Alpha, Beta, Gamma, Delta };
    artifact.signature = *type[0];  // Default signature
    return artifact;
}

void inspect_artifact(const Artifact* a) {
    printf("Alpha: %c\n", a->Alpha);
    printf("Beta: %c\n", a->Beta);
    printf("Gamma: %c\n", a->Gamma);
    printf("Delta: %c\n", a->Delta);
    printf("Signature: %c (%s)\n", a->signature, type[a->signature - 'A']);
}

void set_field(Artifact* a, const char* field, char value) {
    if (strcmp(field, "alpha") == 0) a->Alpha = value;
    else if (strcmp(field, "beta") == 0) a->Beta = value;
    else if (strcmp(field, "gamma") == 0) a->Gamma = value;
    else if (strcmp(field, "delta") == 0) a->Delta = value;
    else printf("Unknown field.\n");
}

void reset_artifact(Artifact* a) {
    a->Alpha = a->Beta = a->Gamma = a->Delta = ' ';
    a->signature = 'E';
}

// -------- Main Interface (REPL) --------
void repl() {
    char* input = Buffer();
    Artifact artifact = Maker('A', 'B', 'G', 'D');

    slow_print("Artifact System Booted. Type 'exit' to quit.\n\n");

    while (1) {
        printf(">> ");
        fgets(input, SIZE, stdin);

        input[strcspn(input, "\n")] = 0;  // Remove newline
        log_command(input);

        if (strcmp(input, "exit") == 0) {
            slow_print("Goodbye.\n");
            break;
        } else if (strcmp(input, "inspect") == 0) {
            inspect_artifact(&artifact);
        } else if (strncmp(input, "set", 3) == 0) {
            char field[10];
            char val;
            sscanf(input, "set %s %c", field, &val);
            set_field(&artifact, field, val);
        } else if (strcmp(input, "log") == 0) {
            show_log();
        } else if (strcmp(input, "reset") == 0) {
            reset_artifact(&artifact);
            slow_print("Artifact reset.\n");
        } else {
            printf("Unknown command: %s\n", input);
        }
    }

    // Free logs and buffer
    for (int i = 0; i < log_index; i++) free(logs[i]);
    free(input);
}

int main() {
    repl();
    return 0;
}
