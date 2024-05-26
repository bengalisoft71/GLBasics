#ifndef OPENGL_BASE_WINDOW_H
#define OPENGL_BASE_WINDOW_H

#include<GLFW/glfw3.h>

struct GLInfo {
    int major_version;
    int minor_version;
};

GLInfo createGLInfo(int major,int minor);

class GLWindow {
public:
    GLFWwindow *m_Window;
public:
    GLWindow() { m_Window = NULL; }
    int createWindow(int width,int height,const char *title,GLInfo info);
    int isWindowClosed();
    void pollEvents();
    void swapBuffers();
};

#endif