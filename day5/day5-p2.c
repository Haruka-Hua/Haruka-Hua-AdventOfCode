//
// Created by tianyao on 24-12-23.
//
//
// Created by tianyao on 24-12-23.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct RuleNode {
    int former;
    int later;
    struct RuleNode *next;
};
typedef struct RuleNode node;
node *rh=NULL, *rt=NULL;

void AddRule(char *str) {
    node *p=(node *)malloc(sizeof(node));
    p->former=atoi(strtok(str,"|"));
    p->later=atoi(strtok(NULL,"|"));
    p->next=NULL;
    if(rh==NULL) {
        rh=p;
        rt=p;
    }
    else {
        rt->next=p;
        rt=p;
    }
}
int cmp(const void *px,const void *py) {
    const int x=*((int *)px);
    const int y=*((int *)py);
    node *current=rh;
    while(current!=NULL) {
        if(current->former==x && current->later==y) {
            return 1;
        }
        else if(current->later==x && current->former==y) {
            return -1;
        }
        current = current->next;
    }
    return 0;
}
bool Right(int *update,int i) {
    for(int j=0;j<i-1;j++) {
        if(cmp(&update[j],&update[j+1])<1) {
            return 0;
        }
    }
    return 1;
}
int Update(char *str) {
    int update[32];
    int i=0;
    char *token=strtok(str,",");
    while(token) {
        update[i]=atoi(token);
        i++;
        token=strtok(NULL,",");
    }
    if(Right(update,i)) return 0;
    else {
        qsort(update,i,sizeof(int),cmp);
        return update[i/2];
    }

}
void Del() {
    while(rh!=NULL) {
        node *temp=rh;
        rh=rh->next;
        free(temp);
    }
}
int main() {
    FILE *fp=fopen("D:\\CLionProjects\\advent-of-code\\"
                   "day5\\day5-input","r");
    char str[200];
    int sum=0;
    fscanf(fp,"%s",str);
    while(strchr(str,'|')!=NULL) {
        AddRule(str);
        fscanf(fp,"%s",str);
    }
    do {
        sum+=Update(str);
    }while(fscanf(fp,"%s",str)!=EOF);
    printf("%d",sum);
    fclose(fp);
    Del();
    return 0;
}