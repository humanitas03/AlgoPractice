#include <cstdio>

#define MAX_N 10001
using namespace std;
long long dp1[MAX_N][MAX_N];
//long long dp2[MAX_N][MAX_N];

int main(int argc, const char *argv[]) 
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
	 {
    	
		for(int i=0; i<MAX_N; i++)
    	{
    		for(int j=0; j<MAX_N; j++)
    		{
    			dp1[i][j] = 0LL;
    			//dp2[i][j] = 0LL;
			}
		}
		
        int n, k, m;
        scanf("%d %d %d", &n, &k, &m);
        
        int r = k-m;
       	
		for (int i = 1; i <= n; i++)
   	 	{
   	 		//base case input 
        	dp1[1][i] = (long)i;
        	//dp2[1][i] = (long)i;
    	} //end base loop
    	        
        for (int i = 2; i <= m; i++)
	    {
	        for (int j = i; j <= n; j++)
	        {
	            for (int l = j-1; l >= i-1; l--) {
	                dp1[i][j] += (dp1[i - 1][l]);
	               // printf("%lld\n", dp1[i][j]);
	            }
	        } // end m inner loop
	        
//	        for (int j = i; j <= r; j++)
//	        {
//	            for (int l = j-1; l >= i-1; l--) {
//	                dp2[i][j] += dp2[i - 1][l] % 1003001;
//	            }
//	        }
	    }//end m loop
	    
	    printf("%lld \n", 
				(dp1[m][n]%1003001LL+dp1[r][n]%1003001LL)% 1003001LL);
    }// end Test loop
	
    return 0;
}

