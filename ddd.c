#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define _CRT_SECURE_NO_WARNINGS

uint32_t binary_reading(char** asdf) {
    FILE* filefile;
    uint32_t switch1;;
    if ((filefile = fopen(asdf[0], "rb")) == NULL) {
        exit(1);
    }
    fread(&switch1, sizeof(uint32_t), 1, filefile);
    printf("Binary : 0x%08x\n", switch1);
    fclose(filefile);
    return switch1;
}

uint32_t change_int(uint32_t swap_int32) {
    uint32_t n1, n2, n3, n4;
    uint32_t ret;

    n1 = (0xff000000 & swap_int32) >> 24;
    n2 = (0x00ff0000 & swap_int32) >> 8;
    n3 = (0x0000ff00 & swap_int32) << 8;
    n4 = (0x000000ff & swap_int32) << 24;

    ret = n1 |
        n2 |
        n3 |
        n4;
    return ret;

}



int main(int argc, char** argv) {
    uint32_t temp1;
    uint32_t temp2;
    uint32_t result;

    temp1 = binary_reading(&argv[1]);
    temp2 = binary_reading(&argv[2]);

    temp1 = change_int(temp1);
    temp2 = change_int(temp2);

    printf("Binary1 : 0x%08x\n", temp1);
    printf("Binary2 : 0x%08x\n", temp2);

    result = temp1 + temp2;

    printf("result : 0x%08x\n", result);
    printf("result swap : 0x%08x\n", change_int(result));

    return 0;
}


