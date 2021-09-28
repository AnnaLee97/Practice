#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int row=0, col=0;
    
    for(int i=0;i<sizes.size();i++){
        sort(sizes[i].begin(), sizes[i].end());
        if(row < sizes[i][0]) row = sizes[i][0];
        if(col < sizes[i][1]) col = sizes[i][1];
    }
    
    return row*col;
}
