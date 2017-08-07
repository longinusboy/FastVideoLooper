#include "ofMain.h"
#include "playerApp.h"
#include <stdio.h>
#include <signal.h>

void interrupt_handler(int param) {
	exit(0);
}

int main()
{
	signal(SIGINT, interrupt_handler);
	try{
		ofSetupOpenGL(1024, 768, OF_FULLSCREEN);
		ofRunApp( new playerApp());
		return EXIT_SUCCESS;
	}catch(const std::exception&) {
		return EXIT_FAILURE;
	}
}
