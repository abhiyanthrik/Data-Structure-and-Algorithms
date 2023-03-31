/*
Let's see something related to strings and get familier with them.
*/

#include <iostream>
using namespace std;

// Program to calculate the length of a string.
int strLen(char* str)
{
	int i = 0;
	while (str[i] != '\0') i++;
	return i;
}

// Converting a string intro lower-case string
void lowerCase(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 65) && str[i] <= 90)
			str[i] += 32;
		i++;
	}
}

// Converting a string into upper-case string
void upperCase(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a') && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

// Program to toggle upper case and lower cases in a string.
void toggleCase(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A') && str[i] <= 'Z')
			str[i] += 32;
		else if ((str[i] >= 'a') && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}

// Program to calculate Vowels, Consonants and number of words in a string
int* wordConsVow(char* arr)
{
	int i = 0, vowel = 0, cons = 0, words = 1;
	while (arr[i] != '\0')
	{
		if (arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U'
			|| arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			vowel++;
		else if (((arr[i] >= 'A') && arr[i] <= 'Z') || ((arr[i] >= 'a') && arr[i] <= 'z'))
			cons++;

		if (arr[i] == ' ' && arr[i - 1] != ' ')
			words++;
		i++;
	}
	int* a{ new int[3] {vowel, cons, words } };

	return a;
}

bool validityCheck(char* str)
{
	int i = 0, vowel = 0, cons = 0, words = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 65 && str[i] <= 90) &&
			!(str[i] >= 97 && str[i] <= 122) &&
			!(str[i] >= 48 && str[i] <= 57))
			return false;
		i++;
	}
	return true;
}

void reverseString(char* str)
{
	int i = 0, j = strLen(str)-1;
	char temp;
	while (i < j)
		temp = str[i], str[i] = str[j], str[j] = temp, i++, j--;
}

bool isPalindrome(char* str)
{
	lowerCase(str);
	int i = 0, j = strLen(str) - 1;
	while (i < j)
	{
		if (str[i] != str[j]) return false;
		i++, j--;
	}
	return true;

}

void duplicate(char* str)
{
	int i = 0, H = 0, x = 0;
	lowerCase(str);
	while (str[i] != '\0')
	{
		x = 1;
		x <<= (97 - str[i]);
		if (H & x)
		{
			cout << str[i] << " is repeated.\n";
		}
		else H |= x;
		i++;
	}
}

bool isAnagram(char* str1, char* str2)
{
	if (strLen(str1) != strLen(str2))
		return false;
	lowerCase(str1);
	lowerCase(str2);

	int arr[26]{ 0 };
	int i = 0, j = 0;

	while (str1[i] != '\0')
		arr[97 - str1[i]]++, i++;

	while (str2[j] != '\0')
	{
		arr[97 - str2[j]]--;
		if (arr[97 - str2[j]] < 0)
			return false;
		j++;
	}
	return true;
}

void permutations(char* str, int k)
{
	int i;
	static char res[10];
	static bool flags[10]{ 0 };

	if (str[k] == '\0') { res[k] = '\0'; cout << res << " "; }
	else
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			if (flags[i] == false)
			{
				flags[i] = true;
				res[k] = str[i];
				permutations(str, k + 1);
				flags[i] = false;
			}
		}
	}
}

void permutations2(char* str, int l, int h)
{
	int i;
	if ((l == h))
		cout << str << " ";
	else
	{
		for (i = l; i <= h; i++)
		{
			char temp = str[i];
			str[i] = str[l];
			str[l] = temp;
			permutations2(str, l + 1, h);
			temp = str[i];
			str[i] = str[l];
			str[l] = temp;
		}

	}

}


int main()
{
	cout << "Getting started with strings!\n";
	char s0[] = "Rohit";
	cout << "Length of the string is: " << strLen(s0) << endl;

	char s1[] = "StRIngggg";
	lowerCase(s1);
	cout << "All Characters converted to lower is: " << s1 << endl;

	char s2[] = "BeLla CiAoo";
	upperCase(s2);
	cout << "The upper string is: " << s2 << endl;

	char s3[] = "ToGgle THis MaNn...";
	cout << "Before toggle: " << s3 << endl;
	toggleCase(s3);
	cout << "After toggle: " << s3 << endl;

	char s4[] = "This sentance contains vowels, consonants and, words off course!";
	int* ar = wordConsVow(s4);
	cout << "The string is: " << s4 << endl;
	cout << "There are " << ar[0] << " vowels, " << ar[1] 
		 << " consonants, and " << ar[2] << " words in s4.\n";

	delete[] ar;
	ar = NULL;

	char s5[] = "This string is !nvalid";
	validityCheck(s5) ? cout << "String is valid.\n" : cout << "String is invalid.\n";

	cout << "Let's reverse the last string\n";
	reverseString(s5);
	cout << "The reversed string is: " << s5 << endl;

	char s6[] = "Madam";
	char s7[] = "damam";
	isPalindrome(s6) ? cout << "String is palindrome.\n" : cout << "String is not palindrome.\n";

	duplicate(s6);
	isAnagram(s6, s7) ? cout << "Strins are anagram.\n" : cout << "String are not anagram.\n";

	char s8[] = "ABC";
	cout << "permutations of 'ABC' are: \n";
	permutations2(s8, 0, strLen(s8) - 1); cout << endl;
}