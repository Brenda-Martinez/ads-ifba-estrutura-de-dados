#include <stdio.h>

int main(){
int *pont;
for(int i = 0; i < 5; i++){
    pont = i * 10;
    printf("%d\n", pont);
}
}
