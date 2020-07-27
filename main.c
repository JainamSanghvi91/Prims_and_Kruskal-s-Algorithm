// Prim's and Kruskal's Algorithm:

#include <stdio.h>

int visited[10] ={0};
int parent[10] = {0};
int find(int);
int ans(int,int);

void PrimAlgo()
{
    int i,j,n,times=1,x,y,a,b;
    printf("\n Enter the number of nodes:");
    scanf("%d",&n);
    int pa[n][n],min,mincost=0;
    printf("\nAdjacentry Matrix of :\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&pa[i][j]);
            if(pa[i][j] == 0)
                pa[i][j] = 100;
        }
    visited[1] = 1;
    printf("\n");
    while(times < n)
    {
        for(i=1,min=100;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(pa[i][j] < min)
                    if(visited[i] != 0)
                    {
                        min = pa[i][j];
                        x=a=i;
                        y=b=j;
                    }
            }
                if(visited[a] == 0 || visited[b] == 0)
                {
                    printf("\n Edge %d:(%d %d) cost: %d",times++,x,y,min);
                    mincost+=min;
                    visited[y]=1;
                }
                //This makes the reverse link not to come again.
                pa[a][b] = pa[b][a] = 100;
    }
    printf("\n The minimum cost is: %d",mincost);    
}

void KruskalAlgo()
{
    int v,i,j,times=1,a,b,u,w,c;
    printf("\nEnter the no. of vertices:");
	scanf("%d",&v);
	int ka[v][v],min,mincost=0;
	printf("\nEnter the cost adjacency matrix:\n");
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			scanf("%d",&ka[i][j]);
			//If the cost is zero then we just make it some random number.
			if(ka[i][j]==0)
				ka[i][j]=100;
		}
	}
	printf("The edges of Minimum Cost Spanning Tree are\n");
    while(times < v)
    {
        for(i=1;i<=v;i++)
		{
		    min = 100;
			for(j=1;j <= v;j++)
			{
				if(ka[i][j] < min)
				{
					min=ka[i][j];
					a=u=i;
					b=c=j;
				}
			}
        }
        u = find(u);
        c = find(c);
        
        if(ans(u,c))
        {
            printf("%d edge (%d,%d) =%d\n",times++,a,b,min);
			mincost +=min;
        }
        //This makes the reverse link not to come again.
        ka[a][b] = ka[b][a] = 100;
    }
        printf("\n Minimum cost of Spanning Tree: %d ",mincost);
}

int find(int w)
{
    while(parent[w])
    w = parent[w];
    return w;
}

int ans(int x,int y)
{
    if(x!=y)
    {
        parent[y]=x;
        return 1;
    }
    return 0;
}


void main()
{
    int choice,flag=1;
    
    while(flag == 1)
    {
        printf("Enter the choice as 1.Prim's 2. Kruskal's 3. Exit:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                PrimAlgo();
                break;
            case 2:
                KruskalAlgo();
                break;
            
            default:
                flag = 0;
                return;
        }
    }
}

