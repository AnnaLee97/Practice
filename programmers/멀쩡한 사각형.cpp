#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

using namespace std;

int getgcd(int a, int b){
    int div = 1;
    
    for(int i=2;i<=min(a, b);i++){
        if(a%i==0 && b%i==0) div = i;
    }
    return div;
}

long long count(int h, int w){
    int gcd = getgcd(h, w);
    long long a = min(h, w) / gcd;
    long long b = max(h, w) / gcd;
    
    return (a + b -1) * gcd;
}

long long solution(int w,int h) {
    long long answer = (long long)w * h;
    answer -= count(w, h);
    return answer;
}
