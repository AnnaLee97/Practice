#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
    string input;
    cin >> input;
    
    int sum=0;
    
    string temp="";
    int flag = 1;
    for(int i=0;i<input.length();i++){
        if(input[i]!='+' && input[i]!='-'){
            temp+=input[i];
        }
        else{
            sum += flag * atoi(temp.c_str());
          
            if(input[i] == '-'){
                    flag = -1;
            }
            temp = "";
        }
    }
    sum += flag * atoi(temp.c_str());
    
    cout << sum <<"\n";
    
    return 0;
}
