#include <cstdio>

using namespace std;


int main(){
    int n;
    int sum=0;
    char c;
    
    scanf("%d\n",&n);
    
    for(int i=0;i<n;i++){
        scanf("%c", &c);
        sum+= c-'0';
    }
    printf("%d\n", sum);
    
    return 0;
}
