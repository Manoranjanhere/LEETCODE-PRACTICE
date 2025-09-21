class Spreadsheet {
public:
    vector<vector<int>>st;
    Spreadsheet(int rows) {
        st.resize(rows+1,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int c = (cell[0]-'A');
        int r = stoi(cell.substr(1));
        st[r][c]=value;
    }
    
    void resetCell(string cell) {
        int c = (cell[0]-'A');
        int r = stoi(cell.substr(1));
        st[r][c]=0;
    }
    
    int getValue(string formula) {
        int plus = formula.find('+');
        int vala,valb;
        if(isalpha(formula[1]))
        {
            int cola= formula[1]-'A';
            int rowa=stoi(formula.substr(2,plus));
            vala= st[rowa][cola];
        }
        else
        {
            vala=stoi(formula.substr(1,plus));
        }
        if(isalpha(formula[plus+1]))
        {
            int colb= formula[plus+1]-'A';
            int rowb=stoi(formula.substr(plus+2));
            valb= st[rowb][colb];
        }
        else
        {
            valb=stoi(formula.substr(plus+1));
        }
        return vala+valb;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */