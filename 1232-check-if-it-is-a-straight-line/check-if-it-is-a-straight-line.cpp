class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        float m,c;
        int v=0;
        for(int i =0;i<coordinates.size();i++){  
            int k=coordinates[0][0];
            int t=coordinates[i][0];
            if(k==t)
              v++;
            
        }
        if(v==coordinates.size())
        return true;
        m=float(coordinates[0][1]-coordinates[1][1])/float(coordinates[0][0]-coordinates[1][0]);      
        for(int i=1;i<coordinates.size()-1;i++){                
            c=float(coordinates[i][1]-coordinates[i+1][1])/float(coordinates[i][0]-coordinates[i+1][0]);
            cout<<c<<" ";
            if(m==c){                    
             continue;
            }
            else{                
             return false;
            }
        }    
        return true;
     
    }
};