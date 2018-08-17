import java.util.Scanner;
import java.util.ArrayList;

class LinePlus01
{
	public static final int BUFSIZ = 200;
	//public static 

	public static void main(String[] args)
	{
		int t;
		ArrayList<String> res = new ArrayList<String>();
		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();

		String flush = sc.nextLine();//개행문자 제거

		for(int i=0; i<t; i++)
		{
			char[] buf = new char[BUFSIZ];
			String str = sc.nextLine();
			
			int sLen = str.length();
			buf = str.toCharArray();

			//System.out.println(buf);

			char fst = buf[0];
			//char[] tmp = new char[10];

			String tres="";

			int cnt = 1;

			for(int j=1; j<sLen; j++)
			{
				//System.out.println(fst);

				if(buf[j]==fst)
				{
					cnt++;
					
					if(j<sLen-1)
						continue;
					else
					{
						tres += cnt;
						tres += Character.toString(fst);
					}
				}
				else if((buf[j]!=fst) || (j==sLen-1))
				{
					tres += cnt;
					tres += Character.toString(fst);
					fst = buf[j];
					cnt = 1;

					if(j==sLen-1)
					{
						tres+=cnt;
						tres+=Character.toString(fst);
					}
				}
			}

			//System.out.println(tres);
			res.add(tres);
		}

		for(int j=0; j<t; j++)
		{
			System.out.println(res.get(j));
		}
	}
}