//Hunter Reinhart CWID:11886420
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#define maxIN 80

int recent = -1;
char *history[10];
int size = 0;

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
char *rHist(int index){
    if(size - index > -1 && size - index < 10){
        return history[(index -1) % 10];
    }
    return NULL;
}

void addCmd(char *cmd){
    size++;
    recent++;
    recent %= 10;
    strcpy(history[recent],cmd);
}
void printHist(){
    if(size < 1){
        printf("No commands in history.\n");
    }
    else{
        int index = recent;
        int maxIndex = {(size < 10) ? size : 10};
        for(int i = 0; i < maxIndex; i++){
            printf("%d %s", size-i,history[index]);
            index--;
            if(index < 0){
                index = 9;
            }
        }
    }
}
bool execCmd(char *historyBuffer, char *cmd, char **args){
    if(cmd == NULL){return true;}
    else if(strcmp(cmd, "exit") == 0){
        return true;
    }
    else if(strcmp(cmd, "history") == 0){
        printHist();
        return true;
    }
    else if(cmd[0] == '!'){
        char *temp;
        if(cmd[1] == '1'){
            temp = rHist(size);
            if(temp == NULL){
                printf("No commands in history.\n");
                return true;
            }
        }else{
            return false;
        }
        strcpy(cmd, temp);
        strcpy(historyBuffer, cmd);
        printf("%s", historyBuffer);
        parseFunc(args, cmd);
        return false;
    }
    return false;
}
int main() {
    char *argus[maxIN/2 + 1]; // String Arr
    char readIN[maxIN+1]; // Buffer
    char historyTemp[maxIN+1];
    int go = 1;

    for(int i = 0; i < 10; i++){
        history[i] = (char *)malloc(maxIN + 1);
    }
    while (go) {
    printf("Reinhart_%d>", getpid());
    fflush(stdout);
    fgets(readIN, maxIN + 1, stdin);
    strcpy(historyTemp, readIN);
    bool synchEx = parseFunc(argus, readIN);
    
    if(execCmd(historyTemp, argus[0], argus)){
        continue;
    }
    addCmd(historyTemp);
    pid_t id = fork();
    if(id == 0){
        execvp(argus[0], argus);
        exit(1);
    }
    else{
        if(synchEx){
            wait(NULL);
        }
    }
}
    return 0;
}
