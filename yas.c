#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARY "./test.yex"

int main() {

    unsigned buff[] = {0x02000028, 0x02100002, 0x03201000, 0x00000000};
    FILE *fp;
    fp = fopen(BINARY, "wb");
    fwrite(buff, sizeof(buff), 1, fp);
    fclose(fp);

    return 0;
}
