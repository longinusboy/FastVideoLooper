#include "playerApp.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fstream>

#define VOLUME_DEFAULT 50
#define VOLUME_MIN 0
#define VOLUME_MAX 100

using namespace std;

const string filenameVolume = "/boot/volume.txt";
const string filenameAudioOutput = "/boot/audio_output.txt";
const string videoPath = "/root/video.mp4";

int volume;
bool useHdmiAudio = true;

void initVolume() {
	std::ifstream ifs(filenameVolume);
	if(ifs.fail()) {
		volume = VOLUME_DEFAULT;
	} else {
		string line;
		getline(ifs, line);
		stringstream ss;
		ss  << line;
		if((ss >> volume).fail())
			volume = VOLUME_DEFAULT;
	}
	ifs.close();
}

void initAudioOutput() {
	std::ifstream ifs(filenameAudioOutput);
	if(!ifs.fail()) {
		string line;
		string analogtag("1");
		getline(ifs, line);
		if(line.find(analogtag) != string::npos)
			useHdmiAudio = false;
	}
	ifs.close();
}

void playerApp::setup()
{
	struct stat fileInfo;

	if(stat(videoPath.c_str(), &fileInfo) != 0) {
		ofLog(OF_LOG_ERROR, "Unable to open video %s", videoPath.c_str());
		throw std::exception();
	}

	initVolume();
	initAudioOutput();

	ofxOMXPlayerSettings settings;
	settings.videoPath = videoPath;
	settings.useHDMIForAudio	= useHdmiAudio;
	settings.enableTexture		= false;
	settings.enableLooping		= true;
	settings.enableAudio		= true;
	settings.doFlipTexture		= true;
	settings.initialVolume		= (float)volume/(float)100;
	settings.directDisplayOptions.doFullScreen = true;
	omxPlayer.setup(settings);
}
