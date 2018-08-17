#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>

//#define BUFSIZ 200

using namespace std;

vector<string> res;
/*
 * Time complexity: TODO
 * Space complexity: TODO
 */
string intToString(int n)
{

	stringstream s;
	s << n;
	//cout<<s.str()<<endl;
	return s.str();

}



int main(int argc, const char *argv[]) {
    int T;
    //scanf("%d\n", &T);
	cin>>T;
	 
    for (int i = 0; i < T; ++i) {
        char buf[BUFSIZ];
        //scanf("%s\n", buf);
        cin>>buf;
        
        char fst = buf[0];
        char tmp[10]={0,};
        string tres="";
        int cnt=1;
        for(int j=1; j<strlen(buf); j++)
        {
        	if(buf[j]==fst)
        	{
        		cnt++;
        		if(j<strlen(buf)-1)
        			continue;
        		else
        		{
        			tres+=intToString(cnt);
        			tres+=fst;
				}
			}
			else if(buf[j]!=fst)
			{
				tres+=intToString(cnt);
				//tres += std::to_string(cnt);
				tres+=fst;
				fst = buf[j];
				cnt=1;
				
				if(j==strlen(buf)-1)
				{
					tres+=intToString(cnt);
					tres+=fst;
				}
			}
		}
		res.push_back(tres);        
    }
    
    for(int j=0; j<T; j++)
    {
    	//printf("%s\n", res[i]);
    	cout<<res[j]<<"\n";
	}

    return 0;
}

