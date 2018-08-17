#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
//#include <tuple>

using namespace std;
class StoreInfo {
public:
	int x_pos;
	int y_pos;
	int coupon;
	char storeName[10];
	int dist;
	StoreInfo(int x, int y, int coup, char* name, int dist)
	{
		this->x_pos = x;
		this->y_pos = y;
		this->coupon = coup;
		strcpy(storeName, name);
		this->dist = dist;
	}
	//���� ���� ���ϴ� Operator overloading 
	bool operator <(const StoreInfo &st) const
	{
		if (this->dist == st.dist)
		{	//�Ÿ��� ������� 
			if (this->coupon == st.coupon)
			{	//���������� �������  
				return this->storeName > st.storeName;// �̸� ������ ������������ 
			}

			return this->coupon > st.coupon; //���� ������ �������� ���� 
		}

		return this->dist < st.dist; //�Ÿ� ������ �������� ���� 
	}
	
};
vector<StoreInfo> stList;
int usr_x, usr_y, nstore;
//bool cmp(const StoreInfo &lst, const StoreInfo& rst)
//{
//	return tie(lst.dist, lst.coupon, lst.storeName) < tie(rst.dist, rst.coupon, rst.storeName);
//}

//��Ŭ����� ���Ͻ�(����x, ����y, ����x, ����y) 
int distCalu(int src_x, int src_y, int dst_x, int dst_y)
{
	return (int)sqrt(pow(dst_x - src_x, 2.0) + pow(dst_y - dst_x, 2.0));
}

//����ź ���Ͻ�
int distCalm(int src_x, int src_y, int dst_x, int dst_y)
{
	return abs(dst_x - src_x) + abs(dst_y - src_y);
}

int main(void)
{
	scanf("%d %d %d", &usr_x, &usr_y, &nstore);

	for (int i = 0; i<nstore; i++)
	{
		char name[20]={0,};
		int x, y, coup;
		int distance;
		//scanf("%d %d %s %d", &x, &y, name, &coup);
		cin>>x>>y>>name>>coup;
		distance = distCalm(usr_x, usr_y, x, y);
		distance = (int)(((double)(distance) / 100.0)*100.0); // 100�̸� ����
		//printf("%d\n", distance);
		stList.push_back(StoreInfo(x,y,coup, name, distance));
	}

	sort(stList.begin(), stList.end());

	for (int i = 0; i<stList.size(); i++)
	{
//		printf("num : %d\n ", i + 1);
//		printf("pos : %d %d\n", stList[i].x_pos, stList[i].y_pos);
//		printf("dist : %d\n", stList[i].dist);
//		printf("name : %s\n", stList[i].storeName);
//		printf("coup : %d\n", stList[i].coupon);
	
		//x, y��ǥ, ���� �̸� , ��������
		printf("%d %d %s %d\n", stList[i].x_pos, stList[i].y_pos, 
								stList[i].storeName,stList[i].coupon); 
	}

	return 0;
}
