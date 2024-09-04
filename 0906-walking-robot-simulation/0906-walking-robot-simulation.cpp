class Solution {
private:
    string solve(string dir, int val){
        if(val == -1){ // turn right
            if(dir == "+y"){ dir = "+x"; }
            else if(dir == "+x"){ dir = "-y"; }
            else if(dir == "-y"){ dir = "-x"; }
            else if(dir == "-x"){ dir = "+y"; }
        } 
        else if(val == -2){ // turn left
            if(dir == "+y"){ dir = "-x"; }
            else if(dir == "-x"){ dir = "-y"; }
            else if(dir == "-y"){ dir = "+x"; }
            else if(dir == "+x"){ dir = "+y"; }
        }

        return dir;
    }
    // convert two point into single hash value
    int convert_hash(int x,int y){
        int hash_multiplier = 60001;
        return x+y*hash_multiplier;
    }

public:
    int robotSim(vector<int>& c, vector<vector<int>>& obs) {
        int mx = 0;
        int x = 0, y = 0;
        string dir = "+y"; // initial direction

        // set<pair<int, int>> st;
        unordered_set<int> st;
        for(auto &val : obs){
            st.insert(convert_hash(val[0], val[1]));
        }

        for(auto &val : c){
            if(val == -1 or val == -2){
                dir = solve(dir, val);
                continue;
            }

            if(dir == "+y"){
                for(int i = 0; i < val; i++){
                    if(st.find(convert_hash(x, y + 1)) != st.end()){
                        break;
                    }
                    y++;
                }
            } 
            else if(dir == "-y"){
                for(int i = 0; i < val; i++){
                    if(st.find(convert_hash(x, y - 1)) != st.end()){
                        break;
                    }
                    y--;
                }
            } 
            else if(dir == "+x"){
                for(int i = 0; i < val; i++){
                    if(st.find(convert_hash(x + 1, y)) != st.end()){
                        break;
                    }
                    x++;
                }
            } 
            else if(dir == "-x"){
                for(int i = 0; i < val; i++){
                    if(st.find(convert_hash(x - 1, y)) != st.end()){
                        break;
                    }
                    x--;
                }
            }
            mx = max(mx, x*x + y*y);
        }

        return mx;
    }
};