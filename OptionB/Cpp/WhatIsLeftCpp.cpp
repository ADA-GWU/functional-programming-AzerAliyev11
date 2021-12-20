#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

vector<long long int> v, vcopy;

int main()
{
	long long int n;
	cin >> n;

	for (long long int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}

	long long int count = 1;

	while (v.size() != 1)
	{
		if (count % 3 == 1)
		{
			for (long long int i = 0; i < v.size(); i++)
			{
				if (i == 0 || i % 2 == 0)
				{
					vcopy.push_back(v[i]);
				}
			}
		}
		else if (count % 3 == 2)
		{
			for (long long int i = 0; i < v.size(); i++)
			{
				if (i % 2 != 0)
				{
					vcopy.push_back(v[i]);
				}
			}
		}
		else
		{
			for (long long int i = 0; i < v.size(); i++)
			{
				if ((i+1) % 3 != 0)
				{
					vcopy.push_back(v[i]);
				}
			}
		}
		if (vcopy.size() != 0)
		{
			v = vcopy;
			vcopy.clear();
		}
		count++;
	}

	if (v.size() != 0)
	{
		cout << v[0] << endl;
	}

	system("Pause");
}