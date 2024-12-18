//
// Created by tianyao on 24-12-19.
//
#include<stdio.h>
#include<stdbool.h>
#define N 140
#define M 160
char map[M][M]={};
const char xmas[]="XMAS";
const int vectors[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
bool walk(int i,int j,int k) {
    for(int x=0;x<4;x++) {
        if(map[i][j]!=xmas[x]) return 0;
        i+=vectors[k][0];
        j+=vectors[k][1];
    }
    return 1;
}
int count(int i,int j) {
    int cnt=0;
    for(int k=0;k<8;k++) {
        if(walk(i,j,k)) cnt++;
        else continue;
    }
    return cnt;
}
int main() {
    FILE *fp=fopen("D:\\CLionProjects\\advent-of-code\\day4\\day4-input","r");
    int sum=0;
    for(int i=11;i<11+N;i++) {
        fscanf(fp,"%s",&map[i][11]);
    }
    for(int i=11;i<11+N;i++) {
        for(int j=11;j<11+N;j++) {
            if(map[i][j]=='X') {
                sum+=count(i,j);
            }
            else continue;
        }
    }
    printf("%d",sum);
    return 0;
}