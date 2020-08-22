#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

void usage(){
	printf("syntax : logparser <file location>\n");
	printf("exam : logparser /var/log/suricata/fast.log\n");
}


int main(int argc, char** argv)
{
	if(argc < 2){
	    usage();
	    return 1;
	}

	string read_line;
	ifstream fread;
	fread.open(argv[1]);
	if(!fread.is_open()) {
		printf("xx파일이 열리지 않음\n");
		exit(0);
	}

	while(!fread.eof()) { //한 줄씩 출력
		getline(fread, read_line);
		cout<<read_line<<endl;
	}
	fread.close();

    
    
	return 0;
}
