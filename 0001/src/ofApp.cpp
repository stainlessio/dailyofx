#include "ofApp.h"

class FilledShape : public Shape {
  public:
    FilledShape(ofColor color)
      : color(color)
    {
      createShape();
    }

    void resetShape() override {
      points.clear();
      createShape();
    }

    void createShape()
    {
      float widthPosition = ofGetWidth() + ofNoise( ofRandomWidth(), ofRandomHeight()),
            heightPosition = ofRandomHeight();
      origin.x = 0;
      origin.y = heightPosition;
      points.push_back( ofPoint( widthPosition / 2.0, heightPosition + ofRandomf() * 50.0));
      points.push_back( ofPoint( widthPosition, heightPosition + ofRandomf() * 150.0));
      points.push_back( ofPoint( widthPosition / 2.0 + ofRandomf() * 50.0, heightPosition));
      points.push_back( ofPoint( 0, heightPosition));
    }

    void update() override {
      updatePoint(origin);
      for(auto& point : points) {
        updatePoint( point );
      }
    }

    void updatePoint( ofPoint& point ) const
    {
      float xDelta = ofSignedNoise( point.x + ofRandomf(), point.y),
              yDelta = ofSignedNoise(point.y + ofRandomf(), point.x);

      point.x = ofClamp(point.x + 5.0 * sin(ofGetElapsedTimef()) * xDelta, 0, ofGetWidth());
      point.y = ofClamp(point.y + 2.5 * cos(ofGetElapsedTimef()) * yDelta, 0, ofGetHeight());
    }

    void draw() override {
//      ofSetColor(ofColor::red);
//      ofDrawCircle(0,0, 10.0);
      ofSetColor(color);
//      for(auto& point : points) {
//        ofDrawCircle(point.x, point.y, 10.0);
//      }
      ofSetPolyMode(OF_POLY_WINDING_NONZERO);
      ofBeginShape();
        ofVertex(origin);
        ofCurveVertices(points);
      ofEndShape(true);
    }

  private:
    ofColor color;
    std::vector<ofPoint> points;
    ofPoint origin;
};

void ofApp::setup()
{
  ofEnableSmoothing();
  ofBackground(240,240,240);
  for (int i=0; i<20; i++) {
    shapes.push_back( new FilledShape( ofColor( 15, 15, 15, 25.0*ofRandomf() + 25.0 )));
  }
}

void ofApp::update()
{
  for(auto& shape : shapes) {
    shape->update();
  }
}

void ofApp::draw()
{
  ofEnableAlphaBlending();
  ofClear(240, 240, 240);
  for(auto& shape: shapes) {
    shape->draw();
    if (ofRandomf() > 0.999) {
      shape->resetShape();
    }
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
