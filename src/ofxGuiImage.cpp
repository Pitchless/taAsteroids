/*
 * ofxGuiImage.cpp
 *
 *  Created on: 23 Jun 2012
 *      Author: mda
 */

#include "ofxGuiImage.h"

ofxGuiImage * ofxGuiImage::setup(string _name, ofImage* _imgPtr, bool _showName, float width ) {
	name     = _name;
	showName = _showName;
	b.width  = width;
	b.height = _imgPtr->height*(width/_imgPtr->width);
	if (showName)
	    b.height += defaultHeight;
	imgPtr   = _imgPtr;
	return this;
}

ofxGuiImage * ofxGuiImage::setup(string _name, ofImage* _imgPtr, bool _showName, float width, float height ) {
	name     = _name;
	showName = _showName;
	b.width  = width;
	b.height = height;
	imgPtr   = _imgPtr;
	return this;
}


void ofxGuiImage::mouseMoved(ofMouseEventArgs & args){
}

void ofxGuiImage::mousePressed(ofMouseEventArgs & args){
}

void ofxGuiImage::mouseDragged(ofMouseEventArgs & args){
}

void ofxGuiImage::mouseReleased(ofMouseEventArgs & args){
}

void ofxGuiImage::saveToXml(ofxXmlSettings& xml) {
    // Nothing to save for an image
}

void ofxGuiImage::loadFromXml(ofxXmlSettings& xml) {
    // Nothing to save for an image
}

void ofxGuiImage::draw(){
	currentFrame = ofGetFrameNum();

	ofPushStyle();
	ofPushMatrix();

	ofSetColor(backgroundColor);
	ofRect(b);

	ofTranslate(b.x, b.y);
	ofSetColor(ofColor::white);
	float h = b.height-2*textPadding;
	if (showName)
	    h -= defaultHeight;
	imgPtr->draw(textPadding, textPadding, b.width-2*textPadding, h);

	if (showName) {
        ofSetColor(textColor);
        ofDrawBitmapString(name, textPadding, b.height-textPadding);
	}

	ofPopMatrix();
	ofPopStyle();
}

//ofImage ofxGuiImage::operator=(ofImage v){
//	value = v;
//	return v;
//}
//
//ofxGuiImage::operator ofImage & (){
//	return value;
//}

void ofxGuiImage::setValue(float mx, float my, bool bCheck){
}
