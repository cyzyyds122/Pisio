#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
string doing;
string ms;
//pisio_main_code:

string typemain(string mou)
{
    if ((mou[0] == '\'')||(mou[mou.size()-1] == '\''))
    {
    	string s(1,mou[1]);
    	return s;
    }
    if ((mou[mou.size()-1] == '\"')||(mou[0] == '\"'))
    {
        return mou.substr(1,mou.size()-2);
    }
    return "";

}

//pisio_system_code:

void println(string m)
{
    cout << m << endl;
}
void print(string m)
{
    cout << m;
}

int coderun(string code)
{
    string cstr;
    int n = 0;
	for(int i = 0;i < code.size();i++)
	{
		cstr+=code[i];//code
        if ((cstr=="{")&&(doing=="runs"))//run main{}
        {
            doing="   ";
            return 0;
        }
        if ((code[i] == ' ')||(code[i] == '('))
        {
            doing = cstr.substr(n,i-n);
            if (doing=="runs")
            {
                return 0;
            }
            n = i+1;
        }
        if ((code[i] == ';')||(code[i] == ':'))
        {
            if (doing=="println")
            {
                println(typemain(ms));
            }
            if (doing=="print")
            {
                print(typemain(ms));
            }
            return 0;
        }
        if ((code[i] == ')')||(code[i] == '~'))
        {
            ms=cstr.substr(n,i-n);
        }
        if (cstr == "}")//over{}
        {
            return 0;
        }
	}
    return 0;
}
int main()
{
	string address;
	cin >> address;
	fstream fin(address,ios::in);
		if(!fin)
		{
			cerr << "can not open file" << endl;
			return -1;
		}
	ifstream infile(address, ios::in);
    if (!infile.fail())
    {
        while (!infile.eof())
        {
            string codestr;
            getline(infile, codestr);
        }
    }
    ifstream afile(address, ios::in);
    if (!afile.fail())
    {
        while (!afile.eof())
        {
            string code;
            getline(afile, code);
			coderun(code);
        }
    }
	getchar();getchar();
	afile.close();
	infile.close();
    fin.close();
	return 0;
}