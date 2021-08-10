3#include <stdio.h>
#include<stdlib.h>
int main()
{
    int n, m, i, j, k;
    int alloc[10][10];
    int max[10][10];
    int avail[10];
    int f[10], ans[10], ind = 0;

    printf("number of process ");
    scanf("%d",&n);

    printf("number of resources ");
    scanf("%d",&m);

    printf(" Allocation matrix\n");
    for(i=0;i<n;i++)
    {
    	for(j=0;j<m;j++)
    	{
	    scanf("%d",&alloc[i][j]);
    	}
    }

    printf(" max matrix\n");
    for(i=0;i<n;i++)
    {
    	for(j=0;j<m;j++)
    	{
    		scanf("%d",&max[i][j]);
    	}
    }
    printf("available resources\n");
    for(i=0;i<m;i++)
    {
    	scanf("%d",&avail[i]);
    }

    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[10][10];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {

                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    printf("Following is the SAFE Sequence\n");
    for (i = 0; i<n-1; i++)
        printf(" P%d ->", ans[i]);
    printf(" P%d", ans[n-1]);
    return 0;

}
