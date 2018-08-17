import java.util.*;

class StoreInfo implements Comparable<StoreInfo>
{
	public int x_pos;
	public int y_pos;
	public int coupon;
	public String storeName;
	public int dist;

	public StoreInfo(int x, int y, int coup, String name, int dist)
	{
		this.x_pos = x;
		this.y_pos = y;
		this.coupon = coup;
		this.storeName = name;
		this.dist = dist;
	}

	public int compareTo(StoreInfo st)
	{
		if(this.dist == st.dist)
		{
			if(this.coupon==st.coupon)
			{
				return this.storeName.compareTo(st.storeName);
			}
			else
				return st.coupon-this.coupon;
		}
		else
			return this.dist - st.dist;
	}
}

class LinePlus02
{
	public static int distCal(int src_x, int src_y, int dst_x, int dst_y)
	{
		return Math.abs(dst_x - src_x) + Math.abs(dst_y-src_y);
	}
	
	public static void main(String[] args)
	{
		ArrayList<StoreInfo> stList = new ArrayList<StoreInfo>();
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		StringTokenizer tok1 = new StringTokenizer(str);

		int usr_x = Integer.parseInt(tok1.nextToken(" "));
		int usr_y = Integer.parseInt(tok1.nextToken(" "));
		int nstore = Integer.parseInt(tok1.nextToken(" "));

		for(int i=0; i<nstore; i++)
		{
			String name;
			int x, y, coup;
			int distance;

			str = sc.nextLine();

			StringTokenizer tok2 = new StringTokenizer(str);
			x = Integer.parseInt(tok2.nextToken(" "));
			y = Integer.parseInt(tok2.nextToken(" "));
			name = tok2.nextToken(" ");
			coup = Integer.parseInt(tok2.nextToken(" "));

			distance = distCal(usr_x, usr_y, x,y);
			distance = (int)(((double)(distance)/100.0)*100.0); //100미만 절삭

			stList.add(new StoreInfo(x,y,coup,name, distance));

		}

		Collections.sort(stList);

		for(int i=0; i<stList.size(); i++)
		{
			StoreInfo res = stList.get(i);
			System.out.println(res.x_pos+" "+res.y_pos+" "
				+res.storeName+" "+res.coupon);	
		}
	}
}