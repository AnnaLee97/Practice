#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ppl {
    public:
        int weight;
        int ind;
        int w, l, n;
    
    ppl(int i, int we, int wi, int lo, int nu){
        ind = i;
        weight = we;
        w = wi;
        l = lo;
        n = nu;
    }
};

bool compare(ppl a, ppl b){
    double aw, bw;
    if((a.w) + (a.l) == 0) aw = 0;
    else aw = (double)(a.w)/(a.w + a.l);
    if((b.w)+(b.l) == 0) bw = 0;
    else bw = (double)(b.w)/(b.w+b.l);
    
    if(aw == bw){
        if(a.n == b.n){
            if(a.weight == b.weight){
                return a.ind < b.ind;
            }
            return a.weight > b.weight;
        }
        return a.n > b.n;
    }
    return aw > bw;
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<ppl> p;
    int w, l,n;
    
    for(int i=0;i<head2head.size();i++){
        w=0; l=0; n=0;
        for(int j=0;j<head2head[i].length();j++){
            if(head2head[i][j]=='W'){
                w++;
                if(weights[i] < weights[j]) n++;
            }
            else if(head2head[i][j]=='L') l++;
            
        }
        p.push_back(ppl(i+1,weights[i],w,l,n));
    }
    
    sort(p.begin(), p.end(), compare);
    
    for(int i=0;i<head2head.size();i++){
        answer.push_back(p[i].ind);
    }
    
    return answer;
}
