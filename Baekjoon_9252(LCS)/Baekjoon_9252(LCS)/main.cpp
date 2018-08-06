#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool isLeft(int **maxLength, int X, int Y)
{
	if (maxLength[X][Y] == maxLength[X][Y - 1])
	{
		return true;
	}
	return false;
}

bool isTop(int **maxLength, int X, int Y)
{
	if (maxLength[X][Y] == maxLength[X-1][Y])
	{
		return true;
	}
	return false;
}

int main()
{
	string firstString;
	string secondString;
	
	//input firstString, secondString
	getline(cin, firstString, '\n');
	getline(cin, secondString, '\n');

	/*vector<vector<int>> maxLength(firstString.size()+1, vector<int>(secondString.size()+1, 0));*/

	int **maxLength = new int *[firstString.size() + 1];
	for (int i = 0; i <= firstString.size(); i++)
	{
		maxLength[i] = new int[secondString.size() + 1];
	}

	for (int i = 0; i <= firstString.size(); i++)
	{
		for (int j = 0; j <= secondString.size(); j++)
		{
			maxLength[i][j] = 0;
		}
	}

		
	for (int i = 1; i <= firstString.size(); i++)
	{
		for (int j = 1; j <= secondString.size(); j++)
		{
			if (firstString.at(i-1) == secondString.at(j-1))
			{
				maxLength[i][j] = maxLength[i - 1][j - 1] + 1;
				//cout << maxString[i][j] << endl;
			}
			else
			{
				maxLength[i][j] = fmax(maxLength[i - 1][j], maxLength[i][j - 1]);
			}
		}

	}

	cout << maxLength[firstString.size()][secondString.size()] << endl;
	
	int X = firstString.size();
	int Y = secondString.size();
	int temp = maxLength[firstString.size()][secondString.size()];
	string resString = "";
	while (temp != 0)
	{
		if (!isLeft(maxLength, X, Y) && !isTop(maxLength, X, Y))
		{
			temp = maxLength[X - 1][Y - 1];
			resString += firstString.at(X - 1); //because maxLength size is bigger than firstString size
			X -= 1;
			Y -= 1;
		}
		else if (isLeft(maxLength, X, Y))
		{
			temp = maxLength[X][Y - 1];
			Y -= 1;
		}
		else if (isTop(maxLength, X, Y))
		{
			temp = maxLength[X - 1][Y];
			X -= 1;
		}
	}
	reverse(resString.begin(), resString.end());
	cout << resString << endl;
	for (int i = 0; i <= firstString.size(); i++)
	{
		delete[] maxLength[i];
	}

	system("pause");
	return 0;
}