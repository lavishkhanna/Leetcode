class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int m=board.size();
        if(m==0){
            return;
        }
        int n=board[0].size();

        vector<vector<char>> vis;

        for(int i=0;i<m;i++){
            vector<char>d;
            for(int j=0;j<n;j++){
                d.push_back('X');
            }
            vis.push_back(d);
        }

        for(int i=0;i<board.size();i++){
            if(i==0 || i==board.size()-1){
                for(int j=0;j<board[i].size();j++){
                    
                    if(board[i][j]=='O'){
                        pair<int,int>p={i,j};
                        q.push(p);
                        vis[i][j]='O';
                    }
                }
            }
            else{

                    
                    if(board[i][0]=='O'){
                        pair<int,int>p={i,0};
                        q.push(p);
                        vis[i][0]='O';
                    }


                    
                    if(board[i][board[i].size()-1]=='O'){
                        pair<int,int>p={i,board[i].size()-1};
                        q.push(p);
                        vis[i][board[i].size()-1]='O';
                    }

            }
        }

        while(!q.empty()){
            pair<int,int>p1=q.front();
            int x=p1.first;
            int y=p1.second;

            q.pop();

            vis[x][y]='O';

            int dr[] = {-1, 0, +1, 0}; 
            int dc[] = {0, +1, 0, -1};

            for(int i=0;i<4;i++){
                int nrow=x+dr[i];
                int ncol=y+dc[i];

                if( nrow >=0 && nrow <m && ncol >= 0 && ncol < n  && board[nrow][ncol]!='X' && vis[nrow][ncol]!='O'){
                    q.push( {nrow,ncol} );
                }
            }
        }

        for(int i=0;i<vis.size();i++){
            for(int j=0;j<vis[i].size();j++){
                if(vis[i][j]!='O'){
                    vis[i][j]='X';
                }
            }
        }

        board=vis;

    }
};