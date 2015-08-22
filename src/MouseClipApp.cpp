
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

// use CGDisplayHideCursor
// use CGWarpMouseCursorPosition
#include <ApplicationServices/ApplicationServices.h>

using namespace ci;
using namespace ci::app;
using namespace std;

class MouseClipApp : public AppNative {
private:
  CGPoint pos;

public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void MouseClipApp::setup() {
  pos.x = getWindowWidth() / 2;
  pos.y = getWindowHeight() / 2;
  
  // カーソル非表示
  // hideCursor();              -> Cinder Library
  // CGDisplayHideCursor(0);    -> ApplicationServices
}

void MouseClipApp::mouseDown(MouseEvent event) {
  // カーソル移動
  CGWarpMouseCursorPosition(pos);
}

void MouseClipApp::update() {}

void MouseClipApp::draw() {
	gl::clear(Color(0, 0, 0));
}

CINDER_APP_NATIVE(MouseClipApp, RendererGl)
