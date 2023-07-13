#include <stdint.h>
#include <stdio.h>

int main(int argc, char **argv) {
    FILE* file1 = fopen(argv[1], "rb");
    if (file1 == nullptr) {
        printf("file1 open error.\n");
        return 1;
    }
    FILE* file2 = fopen(argv[2], "rb");
    if (file2 == nullptr) {
        printf("file2 open error.\n");
        return 1;
    }

    unsigned char buf1[4];
    unsigned char buf2[4];

    size_t fd1 = fread(buf1, sizeof(unsigned char), 4, file1);
    uint32_t* p1 = reinterpret_cast<uint32_t*>(buf1);
    uint32_t n1 = *p1;
    n1=__builtin_bswap32(n1);

    size_t fd2 = fread(buf2, sizeof(unsigned char), 4, file2);
    uint32_t* p2 = reinterpret_cast<uint32_t*>(buf2);
    uint32_t n2 = *p2;
    n2=__builtin_bswap32(n2);


    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",n1, n1, n2, n2, n1+n2, n1+n2);

    fclose(file1);

    return 0;
}

