#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void make_zombie();

int main(int argc, char **argv) {
    int num_zombies = 16;

    if (argc == 2) {
        // Try to get number of zombies from argv[1]
        int num_zombies_from_args = atoi(argv[1]);
        if (num_zombies_from_args > 0) {
            num_zombies = num_zombies_from_args;
        }
    }

    for (int i = 0; i < num_zombies; i++) {
        make_zombie();
        printf("Zombie %d spawned\n", i);
    }

    printf("Hit enter to reap zombies and exit");
    getchar();
}

void make_zombie() {
    int pid = fork();
    assert(pid >= 0);

    if (pid > 0) {
        // We're in the parent -- do nothing
        return;
    }

    // Otherwise: we're in the child
    exit(0);
    // Not calling wait() -- we want zombies!
}
