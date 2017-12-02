#pragma once

#include "ofMain.h"

class Shape {
  public:
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void resetShape() = 0;
};

class ofApp : public ofBaseApp
{
  public:
    void setup();
    void update();
    void draw();
    void exit();

    void keyPressed( ofKeyEventArgs& );
    void keyReleased( ofKeyEventArgs& );

    void mouseMoved( ofMouseEventArgs& );
    void mouseDragged( ofMouseEventArgs& );
    void mousePressed( ofMouseEventArgs& );
    void mouseReleased( ofMouseEventArgs& );
    void mouseScrolled( ofMouseEventArgs& );
    void mouseEntered( ofMouseEventArgs& );
    void mouseExited( ofMouseEventArgs& );

    void touchDown( ofTouchEventArgs& );
    void touchMoved( ofTouchEventArgs& );
    void touchUp( ofTouchEventArgs& );
    void touchDoubleTap( ofTouchEventArgs& );
    void touchCancelled( ofTouchEventArgs& );

    void windowResized( ofResizeEventArgs& );
    void dragged( ofDragInfo& );
    void messageReceived( ofMessage& );



  private:
    std::vector<Shape*> shapes;
};
