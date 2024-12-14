//
// Created by tianyao on 24-12-14.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

const char start[4]="ul(";
const char ins[10]="'t()";
bool isnum(char a) {
    return (a>='0'&&a<='9');
}
int multi(FILE *fp) {
    for(int i=0;i<3;i++) {
        if(fgetc(fp)!=start[i]) return 0;
    }
    char X[8]="";
    char Y[8]="";
    int i=0,j=0;
    char ch=fgetc(fp);
    while(ch!=',') {
        if(!isnum(ch)) {
            return 0;
        }
        X[i++]=ch;
        ch=fgetc(fp);
    }
    ch=fgetc(fp);
    while(ch!=')') {
        if(!isnum(ch)){
            return 0;
        }
        Y[j++]=ch;
        ch=fgetc(fp);
    }
    int x=atoi(X),y=atoi(Y);
    return x*y;
}
int do_or_dont(FILE *fp) {
    if(fgetc(fp)!='o') {
        return 0;
    }
    else {
        char ch=fgetc(fp);
        if(ch=='(') {
            if(fgetc(fp)==')') return 1;
            else return 0;
        }
        else if(ch=='n') {
            for(int i=0;i<4;i++) {
                if(fgetc(fp)!=ins[i]) return 0;
            }
            return -1;
        }
        else return 0;
    }
}
int main() {
    FILE *fp=fopen("D:\\CLionProjects\\advent-of-code\\day3\\day3-input","r");
    long long sum = 0;
    bool end = 0;
    bool instruction = 1;
    while(!end) {
        char ch=fgetc(fp);
        if(ch==EOF) end = 1;
        else if(ch=='d') {
            int temp=do_or_dont(fp);
            if(temp==1) instruction=1;
            else if(temp==-1) instruction=0;
        }
        else if(ch=='m'&&instruction) {
            sum+=multi(fp);
        }
    }
    printf("%lld",sum);
    fclose(fp);
    return 0;
}