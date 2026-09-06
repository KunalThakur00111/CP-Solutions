class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<vector<vector<int>>>> dis(n+1,vector<vector<vector<int>>>(m+1,vector<vector<int>>(k+1,vector<int>(5,1e9))));
        pq.push({grid[0][0],0,0,0,0});
        dis[0][0][0][0]=grid[0][0];
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int cost=it[0];
            int i=it[1];
            int j=it[2];
            int dir=it[3];
            int total=it[4];
            if(i==n-1 && j==m-1){
                return cost;
            }
            int drow[]={+1,-1,0,0};
            int dcol[]={0,0,+1,-1};// 0 means down, 1 means up, 2 for left, 3 for right
            for(int l=0;l<4;l++){
                int r=i+drow[l];
                int c=j+dcol[l];
                if(r>=0 && c>=0 && r<n && c<m){
                    if(i==r){
                        if(j>c){
                            int nk=total;
                            if(dir!=3 && dir!=0) nk++;
                            if(nk<=k && dis[r][c][nk][3]>cost+grid[r][c]){
                                dis[r][c][nk][3]=cost+grid[r][c];
                                pq.push({dis[r][c][nk][3],r,c,3,nk});
                            }
                        }
                        else{
                            int nk=total;
                            if(dir!=4 && dir!=0) nk++;
                            if(nk<=k && dis[r][c][nk][4]>cost+grid[r][c]){
                                dis[r][c][nk][4]=cost+grid[r][c];
                                pq.push({dis[r][c][nk][4],r,c,4,nk});
                            }
                        }
                    }
                    else{
                        if(r>i){
                            int nk=total;
                            if(dir!=1 && dir!=0) nk++;
                            if(nk<=k && dis[r][c][nk][1]>cost+grid[r][c]){
                                dis[r][c][nk][1]=cost+grid[r][c];
                                pq.push({dis[r][c][nk][1],r,c,1,nk});
                            }
                        }
                        else{
                            int nk=total;
                            if(dir!=2 && dir!=0) nk++;
                            if(nk<=k && dis[r][c][nk][2]>cost+grid[r][c]){
                                dis[r][c][nk][2]=cost+grid[r][c];
                                pq.push({dis[r][c][nk][2],r,c,2,nk});
                            }
                        }
                    }
                }
            }
        }
        return -1;
    }
};