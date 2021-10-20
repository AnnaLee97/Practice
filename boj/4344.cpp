#include <iostream>
#include <vector>

using namespace std;

int main(){
    int c;
    int n;
    
    cin >> c;
    
    cout.setf(ios::fixed);
    cout.precision(3);
    
    for(int i=0;i<c;i++){
        cin >> n;
        vector<int> scores(n);
        double avg = 0;
        int count = 0;
        for(int j=0;j<n;j++){
            cin >> scores[j];
            avg += scores[j];
        }
        avg /= n;
        
        for(int j=0;j<n;j++){
            if(scores[j] > avg) count++;
        }
        avg = (double)count*100/n ;
        
        cout << avg;
        cout <<"%\n";
    }
    
    return 0;
}
