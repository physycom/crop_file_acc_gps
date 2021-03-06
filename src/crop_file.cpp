#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <boost/filesystem.hpp>

using namespace std;

vector<string> NomiFiles(bool togli_ext = true, string dir = "") {
	string comm = "dir \"" + dir + "\" /b /a-d";
	vector<string> res;
	FILE* pipe; 
	char buf[2048];
	if(NULL == (pipe = fopen(comm.c_str(), "r"))) return res;
	while(fgets(buf, 2048, pipe) != NULL) {
		string nomef = string(buf); 
		nomef.pop_back();
		if(togli_ext) {
			unsigned pospunto = nomef.find_last_of('.');
			if(pospunto != string::npos) nomef = nomef.substr(0, pospunto);
		};
		res.push_back(nomef);
	};
	fclose(pipe);
	return res;
}

void MakeFolder(const char * path) {
  if (!boost::filesystem::exists(path)) {
    boost::filesystem::create_directories(path);
  }
  else {
    std::string old = std::string(path) + "_old";
    boost::filesystem::rename(old, path);
    boost::filesystem::create_directories(path);
  }
};

int main(int nargs, char** args) {
	double ti, tf;
	cout << "dare gli estremi dell'intervallo: "; 
	cin >> ti >> tf;

	string folderin(args[1]);
	auto nomi = NomiFiles(true, folderin);

	string folderout = folderin + "\\crop";
	MakeFolder(folderout.c_str());

	for(string f : nomi) {
		ifstream ifi(folderin + "\\" + f + ".txt");
		ofstream ofi(folderout + "\\" + f + "_crop.txt");
		double t;
		string riga;
		while(getline(ifi, riga)) {
			istringstream istr(riga); istr >> t;
			if(t < ti) continue;
			if(t > tf) break;
			ofi << riga << endl;
		};
		ifi.close();
		ofi.close();
	};
}