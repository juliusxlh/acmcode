#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

struct point{
    int x;
    int y;
};

char f[10][15];
point h[200];
point way[4]={{1,0},{0,1},{-1,0},{0,-1}};
bool flag[10][15];
int st,ed,sum,score=0;

void check(int i,int j,int x,int y,int mode,char c){
    if (x>=10||x<0||y>=15||y<0) return;
    if (c!=f[x][y]) return;
    if (mode==0&&!flag[x][y]) return;
    flag[x][y]=false;
    ed++;
    h[ed].x=x;
    h[ed].y=y;
    if (mode) f[x][y]=0;
    return;
}

void swap(int i,int st,int ed){
    char c=f[st][i];
    f[st][i]=f[ed][i];
    f[ed][i]=c;
}

void swaplist(int x,int y){
    char c;
    for (int i=0;i!=10;i++){
        c=f[i][x];
        f[i][x]=f[i][y];
        f[i][y]=c;
    }
}

int main()
{
    freopen("poj.in","r",stdin);
    freopen("poj.out","w",stdout);
    int cs,csorder=0,left;
    cin>>cs;
    while (cs--){
        int order=0;
        left=150;
        csorder++;
        score=0;
        printf("Game %d:\n\n",csorder);
        for (int i=9;i>=0;i--){
            for (int j=0;j!=15;j++) {
                while (cin>>f[i][j],(f[i][j]!='R'&&f[i][j]!='G'&&f[i][j]!='B')){

                }
            }
        }
        while (true){
            order++;
            memset(flag,true,sizeof(flag));
            int sx=0;
            int sy=0;
            sum=0;
            for (int j=0;j!=15;j++){
                for (int i=0;i!=10;i++){
                    if (f[i][j]&&flag[i][j]){
                        h[0].x=i;
                        h[0].y=j;
                        flag[i][j]=false;
                        st=0;
                        ed=0;
                        while (st<=ed){
                            for (int k=0;k!=4;k++){
                                check(i,j,h[st].x+way[k].x,h[st].y+way[k].y,0,f[i][j]);
                            }
                            st++;
                        }
                        if (ed+1>sum){
                            sum=ed+1;
                            sx=i;
                            sy=j;
                        }
                    }
                }

            }
            if (sum<=1){
                if (left==0) score+=1000;
                printf("Final score: %d, with %d balls remaining.\n\n",score,left);
                break;
            }
            printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",order,sx+1,sy+1,sum,f[sx][sy],(sum-2)*(sum-2));
            score+=(sum-2)*(sum-2);
            left-=sum;
            st=0;
            ed=0;
            h[0].x=sx;
            h[0].y=sy;
            char c=f[sx][sy];
            f[sx][sy]=0;
            while (st<=ed){
                for (int i=0;i!=4;i++){
                    check(sx,sy,h[st].x+way[i].x,h[st].y+way[i].y,1,c);
                }
                st++;
            }
            for (int j=0;j!=15;j++){
                for (int i=0;i!=10;i++){
                    if (f[i][j]==0){
                        int k=i+1;
                        while (k!=10&&f[k][j]==0){
                            k++;
                        }
                        if (k==10) break;
                        swap(j,i,k);
                    }
                }
            }
            for (int i=0;i!=15;i++){
                if (f[0][i]==0){
                    int j=i+1;
                    while (j!=15&&f[0][j]==0) {
                        j++;
                    }
                    if (j==15) break;
                    swaplist(i,j);
                }
            }
        }
    }
    fclose(stdout);
    fclose(stdin);
}