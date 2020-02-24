#include<iostream>

using namespace std;

int KMP(string s1, string s2);
bool KMP2(string s1, string s2);


int main()
{
	string s1 = "adadffadad";
	string s2 = "ffd";

	cout << s1 << endl;
	cout << s2 << endl;
	auto result = KMP2(s1, s2);

	
	return 1;
}


void getNext(string s, int * next1) //传入一个模式串s 和一个next数组
{
	
	next1[0] = -1;
	int i = 0, j = -1;

	while (i < s.length())
	{
		if ((j == -1) || (s[i] == s[j]))
		{
			++i;							//注意i是一直增加的
			++j;
			next1[i] = j;
			
		}
		else
		{
			j = next1[j];

		}
	}
}





int KMP(string s1, string s2)  //s1为主串  s2为模式串
{
	int size = s2.length();
	int* next = new int[size];
	getNext(s2, next);
	int k = -1;
	cout << s1.length();
	for (int i = 0; i < s1.length(); i++)
	{
		if (k > -1 && s2[k + 1] != s1[i])		//主串和模式串不相同，就把k回溯，
		{
			k = next[k];
		}
		if (s2[k + 1] == s1[i])
			k = k + 1;
		if (k == s2.length() - 1)
		{
			cout << "匹配成功" << endl;
			return i - k;
		}
	}
	cout << "匹配失败" << endl;
	return -1;
}





bool KMP2(string s1, string s2)    //s1代表主串  s2代表模式串
{
	//int len2 = s2.length();
	int * next2 = new int ;

	getNext(s2, next2);

	int i = 0, j = 0;           
	while (j < s1.length()) {
		if (s2[i] == s1[j]) {
			i++;
			j++;
			if (i == s2.length())
			{
				cout << "匹配成功" << endl;
				return 1;
			}
		}
		else {
			i = next2[i];
			if (i == -1) {
				j++; i++;
			}
		}
	}
	cout << "匹配失败" << endl;
	return 0;
}
