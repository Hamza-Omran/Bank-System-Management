#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace func {

	double ReadNumber(string msg) {
		double Number;
		cout << endl << msg;
		cin >> Number;
		return Number;
	}

	int RandNumber(int from, int to)
	{
		return rand() % (to - from + 1) + from;
	}


	void AddArrayElement(int Number, int arr[100], int& arrLength) {
		//its a new element so we need to add the length by 1 
		arrLength++;
		arr[arrLength - 1] = Number;
	}

	void InputUserNumbersInArray(int arr[100], int x, int& arrLength)
	{
		for (int i = 0; i < x; i++) {
			AddArrayElement(RandNumber(-100, 100), arr, arrLength);
		}
	}


	bool IsNumberInArray(int arr, int arr2[10], int& arrLength2) {

		for (int i = 0; i < arrLength2; i++)
		{
			if (arr == arr2[i]) {
				return true;
			}

		}
		return false;
	}
	void CopyArray(int arr[100], int arr2[100], int arrLength, int& arrLength2)
	{

		for (int i = 0; i < arrLength; i++)
			if (!IsNumberInArray(arr[i], arr2, arrLength2)) {
				AddArrayElement(arr[i], arr2, arrLength2);
			}
	}

	int CountOdd(int arr[100], int& length) {
		int count = 0;
		for (int i = 0; i < length; i++) {
			if (arr[i] >= 0)
				count++;
		}
		return count;
	}

	void PrintArray(int arr[100], int arrLength) {
		for (int i = 0; i < arrLength; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	bool IsPalindrome(int arr[100], int& length) {

		for (int i = 0, j = length - 1; i <= length / 2, j >= length / 2; i++, j--) {
			if (arr[i] != arr[j])
				return false;
		}
		return true;
	}
	void PrintIsPalindrome(int arr[100], int& length) {
		if (IsPalindrome(arr, length))
			cout << "palindrome.";
		else
			cout << "not palindrome.";
	}

	short indexoffirstletter(string s1) {
		bool firstletter = true;
		for (int i = 0; i < s1.length(); i++) {

			if ((s1[i] != ' ') && firstletter)
			{
				s1[i] = (char)"";
			}
			firstletter = (s1[i] == ' ' ? true : false);
		}
		return -1;
	}

	string readstring(string s2) {
		string x;
		cout << s2 << "\n";
		getline(cin >> ws, x);
		return x;
	}

	char invertcharz(char a) {
		return (isupper(a)) ? tolower(a) : toupper(a);
	}



	char readchar(string s1) {
		char a;
		cout << s1 << "\n";
		cin >> a;
		return a;
	}
	short printnumberofwords(string s1) {
		string delim = " ";
		short pos = 0;
		string word;
		short counter = 0;
		while ((pos = s1.find(delim)) != string::npos) {
			word = s1.substr(0, pos);
			if (word != "") {
				counter++;
			}
			s1.erase(0, pos + delim.length());
		}
		if (s1 != "") {
			counter++;
		}
		return counter;
	}

	

	vector<string> wordsinstring(string s1, string delim) {
		short pos = 0;
		vector<string> vec = {};
		string word;
		short counter = 0;
		while ((pos = s1.find(delim)) != string::npos) {
			word = s1.substr(0, pos);
			if (word != "") {
				vec.push_back(word);
			}
			s1.erase(0, pos + delim.length());
		}
		if (s1 != "") {
			vec.push_back(s1);
		}
		return vec;
	}


	void printvectors(vector<string> nums) {
		for (string& x : nums) {
			cout << x << endl;
		}
	}



	string TrimLeft(string S1) {
		for (short i = 0; i < S1.length(); i++) {
			if (S1[i] != ' ') {
				return S1.substr(i, S1.length() - i);
			}
		} return "";
	}

	string TrimRight(string S1) {
		for (short i = S1.length() - 1; i >= 0; i--) {
			if (S1[i] != ' ') {
				return S1.substr(0, i + 1);
			}
		} return "";
	}

	string Trim(string S1) {
		return (TrimLeft(TrimRight(S1)));
	}

	string Join(vector<string> vec, string delim) {
		string s1 = "";
		for (string& word : vec) {
			s1 += word + delim;
		}
		return s1.substr(0, s1.length() - delim.length());

	}

	string Join(string arr[5], string delim, int length) {
		string s1 = "";
		for (int i = 0; i < length; i++) {
			s1 += arr[i] + delim;
		}
		return s1.substr(0, s1.length() - delim.length());

	}
	string stringreversed(string s1) {
		vector<string> vec = wordsinstring(s1, " ");

		string s2 = "";
		for (int i = vec.size() - 1; i < vec.size(); i--) {
			s2 += vec.at(i) + " ";
		}
		return s2.substr(0, s1.length() - 1);
	}

	enum encase { match = 1, notmatch = 2 };

	string lowerword(string s1) {
		for (int i = 0; i < s1.length(); i++) {
			s1[i] = tolower(s1[i]);
		}
		return s1;
	}

	string removepunct(string s1) {
		for (int i = 0; i < s1.length(); i++) {
			if (ispunct(s1[i]))
				s1[i] = 0;
		}
		return s1;
	}

	string replace_word(string s1, string oldrep, string newrep, encase x = encase::notmatch) {
		vector<string> vec = wordsinstring(s1, " ");

		for (string& i : vec) {
			if (i == oldrep && x == encase::match)
				i = newrep;
			else if (lowerword(i) == lowerword(oldrep) && x == encase::notmatch)
				i = newrep;
		}

		return Join(vec, " ");
	}



	string replaceword(string s1, string oldrep, string newrep) {
		int pos = s1.find(oldrep);

		while (pos != string::npos) {
			s1.replace(pos, oldrep.length(), newrep);
			pos = s1.find(oldrep);
		}
		return s1;
	}

}

