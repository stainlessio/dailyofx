#pragma once

#include "ofMain.h"
#include "interfaces.h"

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
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
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
    ILabel *label;
};
