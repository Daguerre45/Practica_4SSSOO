#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void error(char* mensaje) {
    fprintf(stderr, "%s", mensaje);
    exit(1);
}

int main(int argc, char *argv[]) {
    int f;
    off_t pos;
    char c[1];
    strcpy(c, argv[3]);
    if (argc != 4) error("Error en los argumentos\n");
    if ((f = open(argv[1], O_RDWR, 0666)) < 0) error("Error en el origen\n");
    if (lseek(f, pos = atoi(argv[2]), SEEK_SET) < 0) error("Error en el posicionamiento\n");
    if (write(f, c, strlen(c)) < 0) error("Error de escritura\n");
    close(f);
    exit(0);
}
