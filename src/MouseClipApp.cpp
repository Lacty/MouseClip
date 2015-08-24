
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
  
  // CGDirectDisplayIDを取得
  Display display;

public:
  void setup();
  void mouseDown(MouseEvent event);
  void update();
  void draw();
};

void MouseClipApp::setup() {
  setWindowPos(0, 0);
  
  // カーソル非表示
  // hideCursor();              -> Cinder Library
  // CGDisplayHideCursor(0);    -> ApplicationServices
  
  u_int32_t wide = CGDisplayPixelsWide(display.getCgDirectDisplayId());
  u_int32_t high = CGDisplayPixelsHigh(display.getCgDirectDisplayId());
  console() << "モニターの横幅:" << wide << endl;
  console() << "モニターの縦幅:" << high << endl;
}

void MouseClipApp::mouseDown(MouseEvent event) {
  // カーソル移動
  // CGWarpMouseCursorPosition(pos);
  pos.x = 0;
  pos.y = 0;
  
  // CGWarpMouseCursorPositionと変わりなし
  CGDisplayMoveCursorToPoint(display.getCgDirectDisplayId(), pos);
}

void MouseClipApp::update() {}

void MouseClipApp::draw() {
	gl::clear(Color(0, 0, 0));
}

CINDER_APP_NATIVE(MouseClipApp, RendererGl)
