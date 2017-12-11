#include "ofApp.h"

int main()
{
  ofGLFWWindowSettings settings;
  settings.height = 1080 / 2;
  settings.width = settings.height * 2;

  auto window = ofCreateWindow(settings);
  auto app = make_shared<ofApp>();
  ofRunApp(window, app);

  return ofRunMainLoop();
}
