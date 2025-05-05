#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <fstream>
using namespace std;
void decasing(string& s1)
{
	for (int i = 0;i < s1.length();i++)
	{
		if (s1[i] >= 'A' && s1[i] < 'a')
		{
			s1[i] = s1[i] + 'a' - 'A';
		}
	}
}
map <string, int> harta;
class Mcompare
{
public:
	bool operator()(string& s1, string& s2)
	{
		if (harta[s1] == harta[s2])
		{
			return s2 < s1;
		}
		return harta[s1] < harta[s2];
	}

};
int main()
{
	string s1;
	ifstream f1("test.txt");
	getline(f1, s1);
	for (int i = 0;i < s1.length();i++)
	{	
		string cuvant;
		while (s1[i] != ' ' && s1[i] != '?' && s1[i] != ',' && s1[i] != '!' && s1[i] != '.' && i <= s1.length())
		{
			cuvant.push_back(s1[i]);
			i++;
		}
		if (s1[i] == ' ' || s1[i] == '?' || s1[i] == ',' || s1[i] == '!' || s1[i] == '.')
		{
			decasing(cuvant);
			if(cuvant.size()>0)
			harta[cuvant]++;
		}
			
	}
	priority_queue <string, vector <string>, Mcompare> coada;
	map <string, int>::iterator it;
	for (it = harta.begin();it != harta.end();++it)
	{
		coada.push(it->first);
	}
	while (!coada.empty())
	{
		cout << coada.top() << "=>" << harta[coada.top()] << endl;
		coada.pop();
	}
	return 0;

	

}