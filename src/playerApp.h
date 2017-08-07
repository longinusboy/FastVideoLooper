#pragma once

#include "ofMain.h"
#include "ofxOMXPlayer.h"

class playerApp : public ofBaseApp {

	public:
		void setup();
		ofxOMXPlayer omxPlayer;
};

