#include <iostream>
using namespace std;

int main()
{
	char firstStr[1024], secondStr[1024], thirdStr[1024];

	cout << "Enter first string: ";
	cin >> firstStr;

	cout << "Enter second string: ";
	cin >> secondStr;

	cout << "Enter third string: ";
	cin >> thirdStr;

	int length_FirstStr = 0;
	int length_SecondStr = 0;
	int length_ThirdStr = 0;

	for (;; length_FirstStr++)
	{
		if (firstStr[length_FirstStr] == '\0')
		{
			break;
		}
	}

	for (;; length_SecondStr++)
	{
		if (secondStr[length_SecondStr] == '\0')
		{
			break;
		}
	}

	for (;; length_ThirdStr++)
	{
		if (thirdStr[length_ThirdStr] == '\0')
		{
			break;
		}
	}

	int i = 0;
	int j = 0;
	int zap = -1;

	for (i; i <= length_FirstStr; i++)
	{
		if (firstStr[i] == secondStr[j])
		{
			if (zap == -1)
			{
				zap = i;
			}
			j++;
			if (j == length_SecondStr)
			{
				break;
			}
			else
			{
				if (zap != -1)
				{
					if (length_FirstStr - i < length_SecondStr && j != length_SecondStr)
					{
						zap = -1;
						break;
					}
					else
					{
						zap = -1;
					}
					i--;
				}
			}
			j = 0;
		}
	}
	if (zap != -1)
	{
		cout << "First entry = " << zap << '\n';
		i = zap;
		if (length_SecondStr == length_ThirdStr)
		{
			j = 0;
			while (thirdStr[j] != '\0')
			{
				firstStr[i] = thirdStr[j];
				i++;
				j++;
			}
			cout << "String after paste: " << firstStr;
		}
		if (length_SecondStr > length_ThirdStr)
		{
			int z = 0;
			j = i;
			while (length_SecondStr - length_ThirdStr - z > 0)
			{
				while (firstStr[j] != '\0')
				{
					firstStr[j] = firstStr[j+1];
					j++;
				}
				j = i;
				z++;
			}
			j = 0;
			while (thirdStr[j] != '\0')
			{
				firstStr[i] = thirdStr[j];
				i++;
				j++;
			}
			cout << "String after paste:\n" << firstStr;
		}
		if (length_SecondStr < length_ThirdStr)
		{
			int z = 0;
			while (length_ThirdStr - length_SecondStr - z != 0)
			{
				for (j = length_FirstStr; j >= i; j--)
				{
					firstStr[j + 1 + z] = firstStr[j + z];
				}
				z++;
			}
			j = 0;
			while (thirdStr[j] != '\0')
			{
				firstStr[i] = thirdStr[j];
				i++;
				j++;
			}
			cout << "String after paste:\n" << firstStr;
		}
	}
	else
	{
		cout << firstStr;
	}
}