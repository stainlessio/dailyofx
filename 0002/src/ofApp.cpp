#include "ofApp.h"

class FilledShape : public Shape {
  public:
    FilledShape(ofColor color)
      : color(color)
    {
      createShape();
    }

    void resetShape() override {
      createShape();
    }

    void createShape()
    {
      speed = ofRandomuf() * 15.0;
      shape.set(ofRandomuf() * 25.0, ofRandomHeight(), ofRandomWidth(), ofRandomuf() * 25.0);
      shape.x = -shape.width;
    }

    bool isAlive() override {
      return shape.getLeft() < ofGetWidth();
    }

    void update() override {
      shape.setPosition(shape.getLeft() + speed, shape.getTop());
    }

    void draw() override {
      ofSetColor(color);
      ofDrawRectangle(shape);
    }

  private:
    ofColor color;
    ofRectangle shape;
    float speed;
};

void ofApp::setup()
{
  ofEnableSmoothing();
  ofBackground(240,240,240);
  for (int i=0; i<100; i++) {
    shapes.push_back( new FilledShape( ofColor( 15, 15, 15, 25.0*ofRandomf() + 25.0 )));
  }
}

void ofApp::update()
{
  for(auto& shape : shapes) {
    shape->update();
    if (!shape->isAlive()) {
      shape->resetShape();
    }
  }
}

void ofApp::draw()
{
  ofEnableAlphaBlending();
  ofClear(240, 240, 240);
  for(auto& shape: shapes) {
    shape->draw();
  }
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
}

void ofApp::mouseDragged(ofMouseEventArgs& mouse)
{
}

void ofApp::mousePressed(ofMouseEventArgs& mouse)
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
