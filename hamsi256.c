#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "sph_hamsi.h"

#define HASH_SIZE 32
#define HEX_SIZE  (HASH_SIZE * 2 + 1)

void to_hex(const unsigned char *hash, size_t hash_len,
            char *hex, size_t hex_size) {
    for (size_t i = 0; i < hash_len && (i * 2 + 2) < hex_size; i++) {
        snprintf(hex + i * 2, 3, "%02x", hash[i]);
    }
    hex[hash_len * 2] = '\0';
}

int test_hamsi256(const char *msg, const char *expected_hex) {
    sph_hamsi256_context ctx;
    unsigned char hash[HASH_SIZE];
    char calculated_hex[HEX_SIZE];

    sph_hamsi256_init(&ctx);
    sph_hamsi256(&ctx, (const void *)msg, (size_t)strlen(msg));
    sph_hamsi256_close(&ctx, hash);

    to_hex(hash, HASH_SIZE, calculated_hex, HEX_SIZE);

    printf("\nMessage   : \"%s\"\n", msg);
    printf("Calculated: %s\n", calculated_hex);
    printf("Expected  : %s\n", expected_hex);

    if (strcmp(calculated_hex, expected_hex) == 0) {
        printf("Result    : PASSED\n");
        return 1;
    } else {
        printf("Result    : FAILED\n");
        return 0;
    }
}

int main(void) {
    int passed = 0;
    int total  = 0;

    printf("=============================================\n");
    printf(" Hamsi-256 Official Implementation Test\n");
    printf(" Student: Muhammed Baran ATMANOGLU\n");
    printf(" Source : https://ehash.isec.tugraz.at/wiki/Hamsi\n");
    printf("=============================================\n");

    total++;
    passed += test_hamsi256(
        "",
        "6e52264c76063b7f149f2ddd4d4f7bcf77d76000c0a44f4d955dd6f4cfbf25de"
    );

    total++;
    passed += test_hamsi256(
        "abc",
        "7f90f47cd4c1f0a071b41ed5ac300ef4efc68c9925a055ede2f3549046c2461d"
    );

    total++;
    passed += test_hamsi256(
        "message digest",
        "e340566d8a272adc51cc7932e8816a4d270f0df5f10ca345bd3d03ca93fdd5bb"
    );

    printf("\n=============================================\n");
    printf("Total : %d\n", total);
    printf("Passed: %d\n", passed);
    printf("Failed: %d\n", total - passed);
    printf("=============================================\n");

    return (passed == total) ? 0 : 1;
}