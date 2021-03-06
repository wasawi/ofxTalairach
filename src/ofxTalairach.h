// =============================================================================
//
// Copyright (c) 2014 Carles Gutierrez <http://carlesgutierrez.wordpress.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================
#pragma once

#include "ofMain.h"
#define MARGINTEXT 22

class ofxTalairach
{
public:
	
    ofxTalairach();
	~ofxTalairach();
	
	void setup();
	void update();

	void keyReleased(int key);
	
	//Drawers
	void drawDebug(int x, int y);
	void drawRequestProbMap(int x, int y);
	void drawRequestedLabels(int x, int y);
	
	//Getters
	float getStructuralProbMap(ofVec3f pos);
	vector<string> getLabelsArroundCube(ofVec3f pos, int _cubeSize);
	
	//Utils 
	inline bool existsFile (const std::string& name) {
		return ( access( name.c_str(), F_OK ) != -1 );
	}
	
private:	
	//Connecting
	void connectT();
	bool bConnected;
	
	//Request
	void requestTL(string commandline);//(1) Structural Probability Maps, 
	string readBuffer4Label(char _buffer[]);
	//...//(2) Talairach label, 
	float requestSPM(string commandline);//(3) Talairach labels within a cube range
	float readBuffer4Caudate(char _buffer[]);
	//...//(4) Talairach gray matter labels.
	
	ofVec3f point3d;
	int cubeSize;
	float probMap;
	string commnadline;
		
	vector<string> vectorLabels;
};

