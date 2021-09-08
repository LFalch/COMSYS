#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <assert.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    assert((argc & 1) == 1);
    for (int i = 1; i < argc; i += 2) {
        FILE *from = fopen(argv[i], "r");
        if (from == NULL) {
            perror("Could not open from-file");
            return 1;
        }
        int fd_to = open(argv[i + 1], O_CREAT | O_EXCL | O_WRONLY, 00664);
        if (fd_to == -1) {
            fclose(from);
            perror("Could not create a new to-file.");
            return 1;
        }

        char buffer[1024];
        for (;;) {
            int read = fread(buffer, sizeof(char), 1024, from);
            if (read == 0) {
                if (feof(from)) {
                    break;
                } else {
                    perror("Could not read from file");
                }
            }

            int written = 0;
            while (written < read) {
                int count = write(fd_to, &buffer[written], read-written);
                if (count == -1) {
                    perror("Could not write to file");
                    fclose(from);
                    close(fd_to);
                    return 1;
                }
                written += count;
            }
        }

        fclose(from);
        close(fd_to);
    }

    return 0;
}
