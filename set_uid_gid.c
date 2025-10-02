#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    // Set the UID to 0 (root user)
    if (setuid(0) != 0) {
        perror("setuid failed");
        return 1;
    }

    // Set the GID to 0 (root group)
    if (setgid(0) != 0) {
        perror("setgid failed");
        return 1;
    }

    printf("UID and GID set to 0 (root).\n");

    // Execute the shell
    execl("/bin/sh", "sh", NULL);

    return 0;
}
