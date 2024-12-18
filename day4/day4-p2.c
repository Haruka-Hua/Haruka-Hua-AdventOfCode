//
// Created by tianyao on 24-12-19.
//
#include<stdio.h>
#include<stdbool.h>
#define N 140
#define M 160
char map[M][M]={};
bool xmas(int i,int j) {
    int dia=0,anti_dia=0;
    if(map[i+1][j+1]=='M'&&map[i-1][j-1]=='S') dia=1;
    else if(map[i+1][j+1]=='S'&&map[i-1][j-1]=='M') dia=1;
    if(map[i-1][j+1]=='M'&&map[i+1][j-1]=='S') anti_dia=1;
    else if(map[i-1][j+1]=='S'&&map[i+1][j-1]=='M') anti_dia=1;
    return dia*anti_dia;
}
int main() {
    FILE *fp=fopen("D:\\CLionProjects\\advent-of-code\\day4\\day4-input","r");
    int sum=0;
    for(int i=11;i<11+N;i++) {
        fscanf(fp,"%s",&map[i][11]);
    }
    for(int i=11;i<11+N;i++) {
        for(int j=11;j<11+N;j++) {
            if(map[i][j]=='A') {
                if(xmas(i,j)) sum+=1;
                else continue;
            }
            else continue;
        }
    }
    printf("%d",sum);
    return 0;
}