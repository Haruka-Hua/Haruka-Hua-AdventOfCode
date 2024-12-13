//
// Created by tianyao on 24-12-13.
//
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
bool end = 0;
int sgn(int a) {
    if(a==0) return 0;
    else if(a>0) return 1;
    else return -1;
}
int safe(FILE *fp) {
    //input;
    char *str=(char *)malloc(1024);
    char *ps=str;
    do {
        *ps=fgetc(fp);
        ps++;
    }while(*(ps-1)!='\n'&&*(ps-1)!=EOF);
    if(*(ps-1)==EOF) end=1;
    int *levels=(int *)malloc(20*sizeof(int));
    levels[0]=atoi(strtok(str," "));
    int index=1;
    char *p=strtok(NULL," ");
    while(p!=NULL) {
        levels[index]=atoi(p);
        p=strtok(NULL," ");
        index++;
    }
    //judge;
    const int sgn0=sgn(levels[0]-levels[1]);
    for(int i=0;i<index-1;i++) {
        {
            if(abs(levels[i]-levels[i+1])>3||abs(levels[i]-levels[i+1])<1) {
                free(str); free(levels); return 0;
            }
            else if(sgn(levels[i]-levels[i+1])!=sgn0) {
                free(str); free(levels); return 0;
            }
        }
    }
    free(str); free(levels); return 1;
}

int main() {
    int cnt=0;
    FILE *fp=fopen("D:\\CLionProjects\\advent-of-code\\day2\\day2-input","r");
    while(!end) {
        cnt+=safe(fp);
    }
    printf("%d",cnt);
    fclose(fp);
    return 0;
}