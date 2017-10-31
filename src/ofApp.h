#pragma once

#include "ofMain.h"
#include <random>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    float genRandom(int lowerBounds, int upperBounds);
    
    
    //fly population size
    int popSize = 100;
    
    //each fly contains 5 values
    int solutionSize = 2;
    
    //use disturbance threshold to disturb flies
    float disturbanceThresh = 0.1f;
    
    //target solution
    std::vector <float> targetSolution {400, 400};
    
    //empty vector for the fly population
    
    std::vector <float> fly; //holds values for each fly
    std::vector <std::vector <float>> population; //vector to hold whole population
    
    std::vector <float> fitness;
    
    //set upper and lower bounds of data space
    float lowerBounds = 0.0f;
    float upperBounds = 800.0f;
    
    //iterations/generations
    int totalIterations = 100;
    
    int fittestInSwarm;

    
    
    
		
};
