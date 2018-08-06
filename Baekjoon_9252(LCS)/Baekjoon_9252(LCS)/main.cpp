#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	string firstString;
	string secondString;
	
	//input firstString, secondString
	getline(cin, firstString, '\n');
	getline(cin, secondString, '\n');

	//+1 => maxLength[0] = 0 not count
	//		maxLength[-][0] = 0 not count
	/*vector<vector<int>> maxLength(firstString.size()+1, vector<int>(secondString.size()+1, 0));
	vector<vector <string>> maxString(firstString.size() + 1, vector<string>(secondString.size() + 1, ""));*/

	int **maxLength = new int *[firstString.size() + 1];
	string **maxString = new string *[firstString.size() + 1];
	for (int i = 0; i <= firstString.size(); i++)
	{
		maxLength[i] = new int[secondString.size() + 1];
		maxString[i] = new string[secondString.size() + 1];
	}

	for (int i = 0; i <= firstString.size(); i++)
	{
		for (int j = 0; j <= secondString.size(); j++)
		{
			maxLength[i][j] = 0;
			maxString[i][j] = "";
		}
	}
		
	for (int i = 1; i <= firstString.size(); i++)
	{
		for (int j = 1; j <= secondString.size(); j++)
		{
			if (firstString.at(i-1) == secondString.at(j-1))
			{
				maxLength[i][j] = maxLength[i - 1][j - 1] + 1;
				maxString[i][j] = maxString[i - 1][j - 1] + firstString.at(i - 1);
				//cout << maxString[i][j] << endl;
			}
			else
			{
				maxLength[i][j] = fmax(maxLength[i - 1][j], maxLength[i][j - 1]);
				if (maxString[i - 1][j].length() > maxString[i][j - 1].length())
				{
					maxString[i][j] = maxString[i - 1][j];
				}
				else
				{
					maxString[i][j] = maxString[i][j - 1];
				}
			}
		}
	}
	for (int i = 0; i <= firstString.size(); i++)
	{
		for (int j = 0; j <= secondString.size(); j++)
		{
			cout << maxLength[i][j] << " ";
		}
		cout << endl;
	}

	cout << maxLength[firstString.size()][secondString.size()] << endl;
	cout << maxString[firstString.size()][secondString.size()] << endl;
	
	/*for (int i = 0; i <= firstString.size(); i++)
	{
		vector<int>().swap(maxLength[i]);
		vector<string>().swap(maxString[i]);
	}
	vector<vector<int>>().swap(maxLength);
	vector<vector<string>>().swap(maxString);*/
	//cout << maxLength.capacity() << endl;


	for (int i = 0; i <= firstString.size(); i++)
	{
		//free(maxLength[i]);
		//free(maxString[i]);
		delete[] maxString[i];
		delete[] maxLength[i];
	}

	system("pause");
	return 0;
}