#include "base/GLWindow.h"
#include<glad/glad.h>
#include<cstdio>

GLInfo createGLInfo(int major, int minor)
{
    GLInfo info = {0};
    info.major_version = major;
    info.minor_version = minor;
    return info;
}

int GLWindow::createWindow(int width, int height, const char *title, GLInfo info)
{   
    if(info.major_version > 4 && info.minor_version > 6) {
        printf("Unable to determine opengl version: %d.%d\n", info.major_version,info.minor_version);
        return 0;
    }
    if(info.major_version < 3 && info.minor_version < 3) {
        printf("Minimum supported opengl version: %d.%d\n", 3,3);
        return 0;
    }
    if(!glfwInit()) {
        printf("GLFW init failed\n");
        return 0;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,info.major_version);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,info.minor_version);
    m_Window = glfwCreateWindow(width,height,title,NULL,NULL);
    if(m_Window == NULL){
        printf("GLFW window creation failed\n");
        glfwTerminate();
        return 0;
    }
    glfwMakeContextCurrent(m_Window);
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        printf("OpenGL context creation failed\n");
        glfwTerminate();
        return 0;
    }
    glViewport(0,0,width,height);
    return 1;
}

int GLWindow::isWindowClosed()
{
    if(!glfwWindowShouldClose(m_Window)){
        return 0;
    }
    return 1;
}

void GLWindow::pollEvents()
{
    glfwPollEvents();
}

void GLWindow::swapBuffers()
{
    glfwSwapBuffers(m_Window);
}