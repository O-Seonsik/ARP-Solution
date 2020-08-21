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

    
    
	return 0;
}
