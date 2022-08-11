#include <fstream>
#include <iostream>
#include <string>
#include "file_encryption.h"
int main() {
	std::string seed;
	cout << "Enter a seed: ";
	std::getline(std::cin, seed);
	std::ifstream in;
	in.open("inputfile.txt");
	std::ofstream out;
	out.open("encrypted.txt");
	EncryptedFile* e = new EncryptedFile(seed);
	e->doFilter(in, out);
	in.close();
	out.close();
	in.open("encrypted.txt");
	out.open("decrypted.txt"); //should be the same as inputfile.txt
	DecryptedFile* d = new DecryptedFile(e);
	d->doFilter(in, out);
	in.close();
	out.close();
	return 0;
}