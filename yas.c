#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BINARY "./test.yex"
unsigned bytecode_buff[] = {0x02000028, 0x02100002, 0x03201000, 0x00000000};

int parse_line(char *line, unsigned buff[]) {
    char *instr = NULL;
    char *cmd = NULL;
    char *reg = NULL;
    char *arg1, *arg2, *arg3 = NULL;
    char *ls_reg = NULL;
    char *op_regs = NULL;
    char *val = NULL;

    if (strchr("!", *line)) {
        cmd = strtok(line, "!");
        printf("COMMAND : %s", cmd);
    }

    if (line[0] == '\t' || line[0] == ' ') {
        int i = 0;
        while (i < sizeof(line)/sizeof(char*)) {
            instr = strtok(line, " ");
            printf("INSTR : %s\n", instr);
            arg1 = strtok(NULL, " ");
            printf("ARG1 : %s\n", arg1);
            arg2 = strtok(NULL, " ");
            printf("ARG2 : %s\n", arg2);
            arg3 = strtok(NULL, " ");
            printf("ARG3 : %s\n", arg3);
            i++;
        }
    }

    return 0;
}

int parse_file(char* source) {
    FILE *fp = fopen(source, "r");
    char line[128];
    /*char *l = NULL;*/

    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
        /*l = &line[0];*/
        parse_line(line, bytecode_buff);
    }
    return 0;
}

int generate_bin(unsigned buff[], char* name) {
    FILE *fp;
    fp = fopen(name, "wb");
    fwrite(buff, sizeof(buff), 1, fp);
    fclose(fp);
}

int main(int argc, char* argv[]) {
    parse_file(argv[1]);        // this is the assembly source
    generate_bin(bytecode_buff, BINARY);
    return 0;
}
