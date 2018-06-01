#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <vector>
using namespace std;

const int M = 90001; //myhash������ȡ�����

int snow[100005][6]; //�洢ѩ����Ϣ
vector<int> myhash[M]; //myhash�����д洢����snow������±�

bool isSame(int a, int b)//�ж�a��b�Ƿ�ͬ��
{
	for(int i=0;i<6;i++)
	{
		//˳ʱ��
		if((snow[a][0] == snow[b][i] &&
					snow[a][1] == snow[b][(i+1)%6] &&
					snow[a][2] == snow[b][(i+2)%6] &&
					snow[a][3] == snow[b][(i+3)%6] &&
					snow[a][4] == snow[b][(i+4)%6] &&
					snow[a][5] == snow[b][(i+5)%6])
				||   //��ʱ��
				(snow[a][0] == snow[b][i] &&
				 snow[a][1] == snow[b][(i+5)%6] &&
				 snow[a][2] == snow[b][(i+4)%6] &&
				 snow[a][3] == snow[b][(i+3)%6] &&
				 snow[a][4] == snow[b][(i+2)%6] &&
				 snow[a][5] == snow[b][(i+1)%6]))

			return true;
	}
	return false;
}

int main()
{
	freopen("h.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int ok = 0;
		int n;
		int i,j;
		cin>>n;
		for( i = 0; i < n; i++)
			for( j = 0; j < 6; j++)
				cin>>snow[i][j];

		int sum, key;
		for(i = 0; i < n; i++)
		{
			sum = 0;//���ѩ����������ĺ�
			for( j = 0; j < 6; j++)
				sum += snow[i][j];
			key = sum % M; //���key

			//�ж��Ƿ���myhash����myhash[key]�洢��ѩ����ͬ
			for(vector<int>::size_type j = 0; j < myhash[key].size(); j++)
			{
				if(isSame(myhash[key][j], i))//����ͬ
				{
					cout<<"Twin snowflakes found."<<endl;
					ok = 1;
					break;
				}
			}
			if (ok) {
				break;
			}
			myhash[key].push_back(i);//��û�ҵ���ͬ��
		}
		if (ok == 0)
			cout<<"No two snowflakes are alike."<<endl;
	}
	return 0;
}
