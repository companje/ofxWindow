#include "ofxWindow.h"

int titlebarHeight = 30;
int borderHeight = 8;

void ofxRemoveWindowBorders() {
#ifdef WIN32
  HWND hwnd = WindowFromDC(wglGetCurrentDC());

  LONG lStyle = GetWindowLong(hwnd, GWL_STYLE);
  lStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);
  SetWindowLong(hwnd, GWL_STYLE, lStyle);

  LONG lExStyle = GetWindowLong(hwnd, GWL_EXSTYLE);
  lExStyle &= ~(WS_EX_DLGMODALFRAME | WS_EX_CLIENTEDGE | WS_EX_STATICEDGE);
  SetWindowLong(hwnd, GWL_EXSTYLE, lExStyle);
  SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOOWNERZORDER);
#endif
}

void ofxWindowAlignLeft() {
  ofSetFullscreen(false);
  ofxRemoveWindowBorders();
  ofSetWindowShape(360, ofGetScreenHeight() - titlebarHeight - borderHeight);
  ofSetWindowPosition(0, titlebarHeight);
}

void ofxWindowAlignRight() {
  ofSetFullscreen(false);
  ofxRemoveWindowBorders();
  ofSetWindowShape(360, ofGetScreenHeight() - titlebarHeight - borderHeight);
  ofSetWindowPosition(ofGetScreenWidth() - 360, titlebarHeight);
}

void ofxWindowMaximize() {
  ofSetFullscreen(false);
  ofxRemoveWindowBorders();
  ofSetWindowShape(ofGetScreenWidth(), ofGetScreenHeight() - titlebarHeight - borderHeight);
  ofSetWindowPosition(0, titlebarHeight);
}

void ofxWindowAlignCenter(ofPoint offset) {
  ofSetFullscreen(false);
  ofxRemoveWindowBorders();
  ofSetWindowShape(ofGetScreenHeight(), ofGetScreenHeight() - titlebarHeight - borderHeight);
  ofSetWindowPosition(ofGetScreenWidth() / 2 - ofGetScreenHeight() / 2 + offset.x, titlebarHeight + offset.y);
}

