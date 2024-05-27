#include<base/glwindow.h>
#include<glad/glad.h>
#include<cstdio>


int main() {
    GLInfo glinfo = createGLInfo(3,3);
    GLWindow window;
    if(!window.createWindow(800,800,"HelloWindow", glinfo)){
        printf("Window creation failed\n");
    }else{
        printf("Window creation success\n");
    }
    while (!window.isWindowClosed())
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(184.0f/255.0f, 213.0f/255.0f, 238.0f/255.0f, 1.0f);
        /* Swap front and back buffers */
        window.swapBuffers();

        /* Poll for and process events */
        window.pollEvents();
    }
    return 0;
}