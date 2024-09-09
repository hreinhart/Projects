//Hunter Reinhart CWID:11886420
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#define maxIN 80

bool parseFunc(char **argus, char *line) {
    bool synchEx = true, EOL = false;
    char *tmp = strtok(line, "\r\a\t \n");
    for (int i = 0; i < maxIN / 2 + 1; i++) {
        argus[i] = tmp;
        if (EOL) {break;}
        tmp = strtok(NULL, "\r\a\t \n");
        if (strcmp(argus[i], "&") == 0) {
            argus[i] = NULL;
            i--;
            synchEx = false;}
        if (tmp == NULL) {EOL = true;}
    }
    return synchEx;
}

int main() {
    char *argus[maxIN/2 + 1]; // String Arr
    char readIN[maxIN+1]; // Buffer
    int go = 1;

    while (go) {
    printf("Reinhart_%d>", getpid());
    fflush(stdout);
    fgets(readIN, maxIN + 1, stdin);
    bool synchEx = parseFunc(argus, readIN);
        // exit
    if (strcmp(argus[0], "exit") == 0) {
        go = 0;
        continue;} 
    else if (argus[0] == NULL){
        continue;}
        pid_t id = fork();
    if (id == 0) { // Child
        execvp(argus[0], argus);
        exit(1);}
    else { // Parent
        if (synchEx) {wait(NULL);}
        }
    }

    return 0;
}