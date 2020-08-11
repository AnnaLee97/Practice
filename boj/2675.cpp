#include <cstdio>
#include <string>

using namespace std;

int main(){
    int T;
    string str;
    int r;
    char temp[22];
    scanf("%d\n", &T);
    for(int i=0;i<T;i++){
        scanf("%d %s", &r, temp);
        str = (string)temp;
        for(int j=0;j<str.length();j++){
            for(int k=0;k<r;k++){
                printf("%c", str[j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
