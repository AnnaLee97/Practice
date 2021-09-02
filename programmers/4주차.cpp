#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    vector<string> job(5);
    int max = 0, cal=0, maxi = -1, val = 0;
    vector<map<string, int>> score(5);
    string temp;
    
    for(int i=0; i<table.size(); i++){
        istringstream ss(table[i]);
        ss >> temp;
        job[i] = temp;
        for(int j=0; j<5; j++){
            ss >> temp;
            score[i][temp] = 5-j;
        }
    }
   
    for(int i=0; i<5; i++){
        cal = 0; 
        for(int j=0; j<languages.size(); j++){
            val = 0;
            if(score[i].find(languages[j]) != score[i].end()){
                val = score[i][languages[j]];
             }
            cal += preference[j] * val;
        }
        
        if((max < cal) || (max == cal && job[maxi] > job[i])){
            max = cal;
            maxi = i;
        } 
    }
    
    
    return job[maxi];
}
