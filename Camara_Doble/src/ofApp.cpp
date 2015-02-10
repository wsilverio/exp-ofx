#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    camWidth    = 640;
    camHeight   = 360;

    ofSetWindowTitle("Cámara doble");

    ofSetWindowPosition(
        ((ofGetScreenWidth() - ofGetWidth())/2),
        ((ofGetScreenHeight() - ofGetHeight())/2)
    );

    vector<ofVideoDevice> devices = cam[0].listDevices();

    cout << endl;
    for(int i = 0; i < devices.size(); i++){
        cout << devices[i].id << ": " << devices[i].deviceName << ": " << devices[i].hardwareName; 
        if( devices[i].bAvailable ) cout << endl;
        else cout << " - indisponível " << endl;
    }
    cout << endl;

    if(devices.size() < 2){
        ofLogError() << "erro ao localizar 2 câmeras válidas.\nVerifique a conexão.";
        ofExit();
    }

    for(int i = 0; i < 2; i++){
        cam[i].setDeviceID(i);
        cam[i].setDesiredFrameRate(60);
        cam[i].initGrabber(camWidth,camHeight);
    }

}

//--------------------------------------------------------------
void ofApp::update(){

    cam[0].update();
    cam[1].update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam[0].draw(0,0);
    cam[1].draw(ofGetWidth()/2,0);
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
