#include<iostream>
using namespace std;
int main(){
    int N, now, next;
    int count=0;
    scanf("%d",&N);
    
    now = N;
    do{    
        next = (now%10)*10 + ((now/10+now%10))%10;
        now = next;
        count++;
    }while(N != now);

    printf("%d\n",count);
    return 0;
}