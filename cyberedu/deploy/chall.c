#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void emergency_eject() {
    printf("\n[ATC] Emergency procedure accepted...\n");
    printf("[ATC] Deploying maintenance shell...\n");
    system("/bin/sh");
}

int cockpit_console() {
    char callsign[128];

    printf("=====================================\n");
    printf("   COSPAS-SARSAT MAINTENANCE TERMINAL\n");
    printf("=====================================\n");
    printf("Flight recorder access granted.\n");
    printf("Enter pilot log entry:\n");
    printf("> ");
    fflush(stdout);

    read(STDIN_FILENO, callsign, 256);

    printf("\n[LOG] Entry received. Tower out.\n");
    return 0;
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    cockpit_console();
    return EXIT_SUCCESS;
}