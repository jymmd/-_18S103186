#include<iostream>  
#include<string>  
#include<stdio.h>  
#include<math.h>  
#include<algorithm> 
#include<fstream> 
#include<vector>
using namespace std;
int min(int i, int j)
{
	if (i <j)return i;
	else return j;
}
int main()
{
	int n, a, b, c, d;
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> c >> d;
		int count = 0;
		int r = 0;
		count += d;
		count += b / 2;
		r = b % 2;
		if (a == c)count += a;
		else if (a > c)
		{
			count += c;
			a = a - c;
			if (r == 1)
			{
				if (a >= 2 && a < 6)
				{
					count += 1;
				}
				else if (a>6)
				{
					count += 1;
					a = a - 2;
					count + a / 4;
				}
			}
			else
			{
				count += a / 4;
			}
			cout << count << endl;

		}

	}
	return 0;
}
