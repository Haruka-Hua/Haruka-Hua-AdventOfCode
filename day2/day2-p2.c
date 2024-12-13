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
bool Judge1(int *levels,int index) {
    const int sgn0=sgn(levels[0]-levels[1]);
    bool flag=true;
    for(int i=0;i<index-1;i++) {
        {
            if(abs(levels[i]-levels[i+1])>3||abs(levels[i]-levels[i+1])<1) {
                flag=false; break;
            }
            else if(sgn(levels[i]-levels[i+1])!=sgn0) {
                flag=false; break;
            }
        }
    }
    return flag;
}
bool Judge2(int *levels,int index,int dampener) {
    int *changed=(int *)malloc(20*sizeof(int));
    for(int i=0;i<dampener;i++) {
        changed[i]=levels[i];
    }
    for(int i=dampener;i<index-1;i++) {
        changed[i]=levels[i+1];
    }
    const int sgn0=sgn(changed[0]-changed[1]);
    bool flag=true;
    for(int i=0;i<index-2;i++) {
        {
            if(abs(changed[i]-changed[i+1])>3||abs(changed[i]-changed[i+1])<1) {
                flag=false; break;
            }
            else if(sgn(changed[i]-changed[i+1])!=sgn0) {
                flag=false; break;
            }
        }
    }
    free(changed);
    return flag;
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
    if(Judge1(levels,index)) {
        free(str); free(levels); return 1;
    }
    else {
        for(int i=0;i<index;i++) {
            if(Judge2(levels,index,i)) {
                free(str); free(levels); return 1;
            }
        }
        free(str); free(levels); return 0;
    }
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