#include <stdio.h>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <cstring>

using namespace std;

void usage(){
	printf("syntax : logparser <file location>\n");
	printf("exam : logparser /var/log/suricata/fast.log\n");
}

int line_count = 0, fileLen = -1;

int statusObserver(char* path){
    string read_line;
    ifstream fread;
    fread.open(path);
    while(!fread.is_open()) {
        printf("can not open %s\n", path);
        return 1;
    }

    int i=0;
    while(!fread.eof()) {
        i++;
        getline(fread, read_line);
        if(fileLen < i){
            fileLen++;
//            cout << read_line << endl;
        
            printf("Time: ");
            int j = 0;
            for(j = 0; j < 19; j++) printf("%c", read_line[j]);
            
            int spaceCnt = 0;
            printf("\nMsg: ");
            while(true){
                j++;
                if(read_line[j] == ' ' ){
                    spaceCnt++;
                }
                if(spaceCnt == 5){
                    while(true){
                        j++;
                        if(read_line[j] == '[') break;
                        printf("%c", read_line[j]);
                    }
                    printf("\n");
                    break;
                }
            }
            printf("\n");
        }
    }
    
    fread.close();
    
    return 0;
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
    int line_count = 0, fileLen=0;

	if(!fread.is_open()) {
		printf("can not open %s\n", argv[1]);
		exit(0);
	}

	while(!fread.eof()) { 
        fileLen++;
		getline(fread, read_line);
	}
    fileLen -= 1;
	fread.close();
    
    while(true){
        sleep(1);
        statusObserver(argv[1]);
    }
	return 0;
}
