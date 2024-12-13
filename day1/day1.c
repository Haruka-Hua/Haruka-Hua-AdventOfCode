#include <stdio.h>
#include <stdlib.h>
#define N 1005
int list1[N]={};
int list2[N]={};
int cmpint(const void *arg1, const void *arg2) {
    int a1=*(int *)arg1;
    int a2=*(int *)arg2;
    if(a1==a2) return 0;
    else if(a1<a2) return -1;
    else return 1;
}
int same(int n,int num) {
    int cnt=0;
    for(int i=0;i<num;i++) {
        if(list2[i]==n) cnt++;
    }
    return cnt;
}
long long similarity(int num) {
    long long simi=0;
    for(int i=0;i<num;i++) {
        simi+=list1[i]*same(list1[i],num);
    }
    return simi;
}
int main(void) {
    FILE *fp = fopen("D:\\CLionProjects\\"
          "advent-of-code\\day1\\day1input","r");
    int index=0;
    while(fscanf(fp,"%d %d",&list1[index],&list2[index])!=EOF) {
        index++;
    }
    qsort(list1,index,sizeof(int),cmpint);
    qsort(list2,index,sizeof(int),cmpint);
    long long sum=0;
    int num=index;
    while(index--) {
        sum+=abs(list1[index]-list2[index]);
    }
    printf("%lld\n",sum);
    printf("%lld\n",similarity(num));
    fclose(fp);
    return 0;
}
