#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>


void *addInFile(int a, char *name){	
	if (a == 1){
		std::ofstream fos(name);
		fos << "Two roads diverged in a yellow wood," << std::endl;
		fos << "And sorry I could not travel both" << std::endl;
		fos.close();
	}
	if (a == 2){
		std::ofstream fos(name);
		fos << "And be one traveler, long I stood" << std::endl;
		fos << "And looked down one as far as I could" << std::endl;
		fos << "To where it bent in the undergrowth." << std::endl;
		fos.close();
	}
}

void readFile(char *name){
	std::string word;
	std::ifstream fis(name);
	while (!fis.eof()){
		getline(fis,word);		
		std::cout << word  << std::endl;
	}
	fis.close();
}

bool wordInFile(std::string word, char *name){
	char s;
	int i = 0;
	const char *arr = word.c_str();
	std::ifstream fis(name);
	while(!fis.eof()){
		fis.get(s);
		if (s == *(arr + i)){
			i++;
		}
		else {
			i = 0;
			if(*arr == s){
				i++;
			}
		}
		if (i == strlen(arr)){
			return true;
		}
	}
	fis.close();
	return false;
}	

void gluingFiles(char *name1,char *name2){
	std::ifstream fis(name1);
	std::ofstream fos(name2, std::ofstream::app);
	char word;
	while(!fis.eof()){
		fis.get(word);
		fos << word;
	}
	fis.close();
	fos.close();
}

int memSize(char *name){
	char s;
	int c = 0;
	std::ifstream fis(name);
	while(fis.get(s) && !fis.eof()){
		c++;
	}
	fis.close();
	return c; 
}

void gluingFiles2(char *name1,char *name2){
	std::ifstream fis(name1);
	std::ofstream fos(name2, std::ofstream::app);
	char word;
	char *arr = (char*) calloc(memSize(name1),sizeof(char));
	int c = 0;
	while(fis.get(word) && !fis.eof()){
		*(arr + c) = word;
		c++;
	}
	fos << arr;
	delete arr;
	fis.close();
	fos.close();		
}


int main(int argc, char *argv[]){	
	
	int a = 1, b = 2;
	char *name1 = "text1.txt";
	char *name2 = "text2.txt";
	char *name3 = "text3.txt";
	std::string word = "looked";
	addInFile(a,name1);
	addInFile(b,name2);
	gluingFiles(name1, name3);
	gluingFiles2(name2, name3);
	std::cout <<  wordInFile(word,name3) << std::endl;

	return 0;
}
