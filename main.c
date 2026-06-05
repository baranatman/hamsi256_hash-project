#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "sph_hamsi.h"

static void to_hex(const unsigned char *hash, size_t len)
{
    for (size_t i = 0; i < len; i++)
        printf("%02x", hash[i]);
    printf("\n");
}

static int hash_buffer(const unsigned char *data, size_t len, int size)
{
    if (size == 256) {
        sph_hamsi256_context ctx;
        unsigned char out[32];

        sph_hamsi256_init(&ctx);
        sph_hamsi256(&ctx, data, len);
        sph_hamsi256_close(&ctx, out);

        to_hex(out, 32);
        return 0;
    }

    if (size == 512) {
        sph_hamsi512_context ctx;
        unsigned char out[64];

        sph_hamsi512_init(&ctx);
        sph_hamsi512(&ctx, data, len);
        sph_hamsi512_close(&ctx, out);

        to_hex(out, 64);
        return 0;
    }

    fprintf(stderr, "Hata: -size sadece 256 veya 512 olabilir.\n");
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc != 6) {
        fprintf(stderr,
            "Kullanim: %s -size <256|512> -split <N> <dosya>\n", argv[0]);
        return 1;
    }

    int size = 0, split = 0;
    const char *filename = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-size") == 0 && i + 1 < argc)
            size = atoi(argv[++i]);
        else if (strcmp(argv[i], "-split") == 0 && i + 1 < argc)
            split = atoi(argv[++i]);
        else
            filename = argv[i];
    }

    if ((size != 256 && size != 512) || split <= 0 || !filename) {
        fprintf(stderr, "Hata: Gecersiz parametre.\n");
        return 1;
    }

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Hata: Dosya acilamadi: %s\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (file_size < 0) {
        fprintf(stderr, "Hata: Dosya boyutu okunamadi.\n");
        fclose(fp);
        return 1;
    }

    unsigned char *buffer = malloc((size_t)file_size);

    if (!buffer) {
        fprintf(stderr, "Hata: Bellek ayrilamadi.\n");
        fclose(fp);
        return 1;
    }

    if (fread(buffer, 1, (size_t)file_size, fp) != (size_t)file_size) {
        fprintf(stderr, "Hata: Dosya okunamadi.\n");
        free(buffer);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    size_t part_size = (size_t)file_size / split;
    size_t remainder = (size_t)file_size % split;
    size_t offset = 0;

    for (int i = 0; i < split; i++) {

        size_t current =
            part_size + (i == split - 1 ? remainder : 0);

        hash_buffer(buffer + offset, current, size);

        offset += current;
    }

    free(buffer);

    return 0;
}