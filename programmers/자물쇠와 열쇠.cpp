#include <string>
#include <vector>


using namespace std;

vector<vector<int>> change(vector<vector<int>> key, int i){
    int n = key.size();
    vector<vector<int>> newkey(n, vector<int> (n,0));
    
    if(i==0) return key;
    else if(i==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(key[i][j]){
                    newkey[j][n-i-1] = 1;
                }
            }
        }
    }
    else if(i==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(key[i][j]){
                    newkey[n-i-1][n-j-1] = 1;
                }
            }
        }
    }
    else if(i==3){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(key[i][j]){
                    newkey[n-j-1][i] = 1;
                }
            }
        }
    }
    return newkey;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    bool flag = true;
    
    for(int n=0;n<4;n++){
        vector<vector<int>> newkey = change(key, n);
        int size = lock.size();
        
        for(int row = -size+1; row<size;row++){
            for(int col = -size +1 ; col<size;col++){
                flag = true;
                int cc = 0;
                for(int i=0;i<lock.size();i++){
                    for(int j=0;j<lock.size();j++){
                        
                        if(i+row < 0 || i+row >= key.size() || j+col <0 || j+col >= key.size()){
                            if(lock[i][j]!=1){
                                flag = false;
                                break;
                            }
                        }
                        else if(lock[i][j] + newkey[i+row][j+col] != 1){
                            flag = false;
                            break;
                        } 
                    }
                    if(!flag) break;
                }

                if(flag) {
                    answer = true;
                    return answer;
                }
            }
            
        }
        
    }
    
    return answer;
}
