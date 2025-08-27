class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        int ans =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    bool istwo=true;
                    bool turnallow=true;
                    //leftup
                    ans=max(ans,1);
                    solveleftup(i-1,j-1,ans,grid,istwo,turnallow);
                    //rightup
                    solverightup(i-1,j+1,ans,grid,istwo,turnallow);
                    //leftdown
                    solveleftdown(i+1,j-1,ans,grid,istwo,turnallow);
                    //rightdown
                    solverightdown(i+1,j+1,ans,grid,istwo,turnallow);
                }
            }
        }
        return ans;
    }
        void solveleftup(int i,int j,int& ans,vector<vector<int>>& grid,bool istwo,bool turnallow)
        {
                    int c1=1;
                    int c2=0;
                    while(i>=0&&j>=0&&grid[i][j]!=1)
                    {
                        if(grid[i][j]==2)
                        {
                            if(!istwo)
                            {
                                break;
                            }
                        }
                        else if(grid[i][j]==0)
                        {
                            if(istwo)
                            {
                                break;
                            }
                        }
                        
                            istwo=!istwo;
                            c1++;
                            ans=max(ans,c1);
                            if(turnallow)
                            {
                                solverightup(i-1,j+1,c2,grid,istwo,false);
                                ans=max(ans,c1+c2-1);
                                c2=0;
                            }
                        
                        i--;
                        j--;
                    }
        }
        void solverightdown(int i,int j,int& ans,vector<vector<int>>& grid,bool istwo,bool turnallow)
        {
                    int c1=1;
                    int c2=0;
                    while(i<grid.size()&&j<grid[0].size()&&grid[i][j]!=1)
                    {
                        if(grid[i][j]==2)
                        {
                            if(!istwo)
                            {
                                break;
                            }
                        }
                        else if(grid[i][j]==0)
                        {
                            if(istwo)
                            {
                                break;
                            }
                        }
                        
                            istwo=!istwo;
                            c1++;
                            ans=max(ans,c1);
                            if(turnallow)
                            {
                                solveleftdown(i+1,j-1,c2,grid,istwo,false);
                                ans=max(ans,c1+c2-1);
                                c2=0;
                            }
                        
                        i++;
                        j++;
                    }
        }
        void solverightup(int i,int j,int& ans,vector<vector<int>>& grid,bool istwo,bool turnallow)
        {
                    int c1=1;
                    int c2=0;
                    while(i>=0&&j<grid[0].size()&&grid[i][j]!=1)
                    {
                        if(grid[i][j]==2)
                        {
                            if(!istwo)
                            {
                                break;
                            }
                        }
                        else if(grid[i][j]==0)
                        {
                            if(istwo)
                            {
                                break;
                            }
                        }
                        
                            istwo=!istwo;
                            c1++;
                            ans=max(ans,c1);
                            if(turnallow)
                            {
                                solverightdown(i+1,j+1,c2,grid,istwo,false);
                                ans=max(ans,c1+c2-1);
                                c2=0;
                            }
                        
                        i--;
                        j++;
                    }
        }
        void solveleftdown(int i,int j,int& ans,vector<vector<int>>& grid,bool istwo,bool turnallow)
        {
                    int c1=1;
                    int c2=0;
                    while(i<grid.size()&&j>=0&&grid[i][j]!=1)
                    {
                        if(grid[i][j]==2)
                        {
                            if(!istwo)
                            {
                                break;
                            }
                        }
                        else if(grid[i][j]==0)
                        {
                            if(istwo)
                            {
                                break;
                            }
                        }
                        
                            istwo=!istwo;
                            c1++;
                            ans=max(ans,c1);
                            if(turnallow)
                            {
                                solveleftup(i-1,j-1,c2,grid,istwo,false);
                                ans=max(ans,c1+c2-1);
                                c2=0;
                            }
                        
                        i++;
                        j--;
                    }
    }
};