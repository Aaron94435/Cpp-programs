#pragma once
#include <fstream>
#include <string>
#include <random>
using namespace std;
class FileFilter {
protected:
	virtual char transformation(char ch) = 0; //abstract member function
public:
	virtual ~FileFilter() {

	}
	void doFilter(ifstream& in, ofstream& out);
};
class EncryptedFile : public FileFilter {
private:
	std::string seed;
	std::minstd_rand0* generator;

public:
	virtual ~EncryptedFile() {
		delete generator;
	}
	EncryptedFile(const std::string& seed) {
		this->seed = seed;
		std::seed_seq generatorSeed(seed.begin(), seed.end());
		generator = new minstd_rand0(generatorSeed);
	}
	std::string getSeed() {
		return seed;
	}
protected:
	char transformation(char ch);
};
class DecryptedFile : public FileFilter {
private:
	EncryptedFile* file;
	std::minstd_rand0* generator;
public:
	virtual ~DecryptedFile() {
		delete file;
		delete generator;
	}
	DecryptedFile(EncryptedFile* file) {
		this->file = file;
		std::string seed = file->getSeed();
		std::seed_seq generatorSeed(seed.begin(), seed.end());
		generator = new std::minstd_rand0(generatorSeed);
	}
	char transformation(char ch);
};
class UpperCaseFile : public FileFilter {
public:
	virtual ~UpperCaseFile() {

	}
protected:
	char transformation(char ch) {
		return toupper(ch);
	}
};
class OriginalFile : public FileFilter {
public:
	virtual ~OriginalFile() {

	}
protected:
	char transformation(char ch) {
		return ch;
	}
};