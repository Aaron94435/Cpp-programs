#include "file_encryption.h"
void FileFilter::doFilter(std::ifstream& in, std::ofstream& out) {
	std::string str;
	while (getline(in, str)) {
		for (int i = 0; i < str.length(); i++) {
			str[i] = transformation(str[i]);
		}
		out << str << endl;
	}
}
char EncryptedFile::transformation(char ch) {
	char minchar = ' ';
	char maxchar = '~';
	int range = maxchar - minchar + 1;
	//int num = (*generator)() % range;
	//int minrange = ch - minchar;
	//int maxrange = maxchar - ch;
	//ch += (*generator)() % (maxrange + minrange + 1) - minrange;
	ch += (*generator)() % range - minchar;
	return ch;
}
char DecryptedFile::transformation(char ch) {
	char minchar = ' ';
	char maxchar = '~';
	int range = maxchar - minchar + 1;
	//int num = generator() % range;
	//int minrange = ch - minchar;
	//int maxrange = maxchar - ch;
	//ch -= (*generator)() % (maxrange + minrange + 1) - minrange;
	ch -=  (*generator)() % range - minchar;
	return ch;
}