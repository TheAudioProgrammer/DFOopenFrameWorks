#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowShape (800, 800);
    
    //make flies and give them a random position
    for (int i = 0; i < popSize; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            float randNum = lowerBounds + ofRandom(0.0f, 1.0f) * (upperBounds - lowerBounds);
            fly.push_back(randNum);
        }
        population.push_back(fly);
        fly.clear();
    }
}


//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetFrameRate(5);
    
    //generations/iterations
    for (int iterations = 0; iterations < totalIterations; iterations++)
    {
        ofBackground(0);
        
        //sample target solution
        ofSetColor(255);
        ofFill();
        ofDrawEllipse(targetSolution[0], targetSolution[1], 50, 50);
        
        //draw and update flies
        for (int i = 0; i < population.size(); i++)
        {
            for (int j = 1; j < 2; j++)
            {
                ofSetColor(255, 0, 0);
                ofFill();
                ofDrawEllipse(population[i][j - 1], population[i][j], 5, 5);
            }
        }
        
        fitness.clear();        //each iteration we must clear fitnesses and reload
        
        //calculate fitnesses for each fly
        for (int i = 0; i < population.size(); i++)
        {
            float temp = 0;
            
            for (int j = 0; j < targetSolution.size(); j++)
            {
                //euclidean distance square result of differences
                
                float fitness = pow (targetSolution[j] - population[i][j], 2);
                temp = fitness + temp;          //temp stores fitnesses until solution size
                
                if (j == targetSolution.size() - 1)
                {
                    temp = sqrt(temp);      //square root of sum
                }
            }
            //push distances into vector
            fitness.push_back(temp);
        }
        
        //find index of fly with best fitness (closest to ideal solution)
        auto result = std::min_element(std::begin(fitness), std::end(fitness));
        fittestInSwarm = (int)(result - fitness.begin());
        
        
        for (int i = 0; i < fitness.size(); i++)
        {
            int leftFly;
            int rightFly;
            
            if (i == 0)
            {
                leftFly = (int)fitness.size() - 1;
            }
            else
            {
                //compare left and right fly and find more fit
                leftFly = i - 1;
            }
            
            //if last fly, right fly is first fly
            if (i == fitness.size() - 1)
            {
                rightFly = 0;
            }
            else
            {
                rightFly = i + 1;
            }
            
            //find fittest neighbor
            int bestNeighbor = 0;
            
            if (fitness[leftFly] < fitness[rightFly])
            {
                bestNeighbor = leftFly;
                
            }
            else if (fitness[leftFly] > fitness[rightFly])
            {
                bestNeighbor = rightFly;
            }
            
                //update all fly positions
            
                //random dice throw to sometimes redistribute fly
                float threshold = ofRandom(0.0f, 1.0f);
                
                if (threshold < disturbanceThresh)
                {
                    for (int j = 0; j < solutionSize; j++)
                    {
                        //randomly scatter fly
                        float randNum = lowerBounds + ofRandom(0.0f, 1.0f) * (upperBounds - lowerBounds);
                    
                        population[i][j] = randNum;
                    }
                }
                else
                {
                    for (int j = 0; j < solutionSize; j++)
                    {
                        //update position
                        population[i][j] = population[bestNeighbor][j] + ofRandom(0.0, 1.0) * (population[fittestInSwarm][j] - population[bestNeighbor][j]);
                    }
                }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
