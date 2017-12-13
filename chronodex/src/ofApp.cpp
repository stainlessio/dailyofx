#include "ofApp.h"
#include "constructors.h"

void ofApp::setup()
{
  ofEnableSmoothing();
  ofBackground(240,240,240);
  section = new_section(
    { 0.0f, 90.0f },
    ofColor::powderBlue,
    "test");
}

void ofApp::update()
{
  section->update();
}

void ofApp::draw()
{
  ofPushMatrix();
  // Center Drawing
  ofTranslate(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f, 0);
    section->draw();
  ofPopMatrix();
}

void ofApp::exit()
{
}

void ofApp::keyPressed(ofKeyEventArgs& key)
{
}

void ofApp::keyReleased(ofKeyEventArgs& key)
{
}

void ofApp::mouseMoved(ofMouseEventArgs& mouse)
{
  float x = mouse.x;
  float y = mouse.y;
  float startAngle = ofMap(x, 0, ofGetWidth(), 0, 360);
  float length = ofMap(y, 0, ofGetHeight(), 0, 360);
  SectionSpecification spec {startAngle, length};
  section->specification(spec);
}

void ofApp::mousePressed(int x, int y, int button)
{

}

void ofApp::mouseDragged(int x, int y, int button)
{
}

void ofApp::mouseReleased(ofMouseEventArgs& mouse)
{
}

void ofApp::mouseScrolled(ofMouseEventArgs& mouse)
{
}

void ofApp::mouseEntered(ofMouseEventArgs& mouse)
{
}

void ofApp::mouseExited(ofMouseEventArgs& mouse)
{
}

void ofApp::touchDown(ofTouchEventArgs& touch)
{
}

void ofApp::touchMoved(ofTouchEventArgs& touch)
{
}

void ofApp::touchUp(ofTouchEventArgs& touch)
{
}

void ofApp::touchDoubleTap(ofTouchEventArgs& touch)
{
}

void ofApp::touchCancelled(ofTouchEventArgs& touch)
{
}

void ofApp::windowResized(ofResizeEventArgs& window)
{
}

void ofApp::dragged(ofDragInfo& dragged)
{
}

void ofApp::messageReceived(ofMessage& message)
{
}
