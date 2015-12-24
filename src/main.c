#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void error_callback(int error, const char* description) {
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

void print_glfw_version() {
    int major;
    int minor;
    int rev;
    glfwGetVersion(&major, &minor, &rev);
    printf("GLFW Version %d.%d.%d\n", major, minor, rev);
    /*printf("VERSION: %s\n", glfwGetVersionString());*/
}

void print_monitor_specs() {
    int width;
    int height;
    glfwGetMonitorPhysicalSize(glfwGetPrimaryMonitor(), &width, &height);
    printf("Monitor specs: (%d x %d)\n", width, height);
}

int main(int argc, char **argv) {
    GLFWwindow* window;
    int fullscreen = 0;
    int do_print_monitor_specs = 0;
    int i;

    for (i = 1; i < argc; ++i) {
        if (strncmp(argv[i], "--version", strlen("--version")) == 0) {
            print_glfw_version();
            exit(0);
        }
        else if (strncmp(argv[i], "-v", strlen("-v")) == 0) {
            print_glfw_version();
            exit(0);
        }
        else if (strncmp(argv[i], "--fullscreen", strlen("--fullscreen")) == 0) {
            fullscreen = 1;
        }
        else if (strncmp(argv[i], "--monitor", strlen("--monitor")) == 0) {
            do_print_monitor_specs = 1;
        }
        else if (strncmp(argv[i], "-m", strlen("-m")) == 0) {
            do_print_monitor_specs = 1;
        }
    }

    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) exit(EXIT_FAILURE);
    if (do_print_monitor_specs) print_monitor_specs();
    if (fullscreen)
        window = glfwCreateWindow(640, 480, "Example", glfwGetPrimaryMonitor(), NULL);
    else
        window = glfwCreateWindow(640, 480, "Simple Example", NULL, NULL);

    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window)) {
        float ratio;
        int width;
        int height;

        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();
        glRotatef((float) glfwGetTime() * 50.f, 0.f, 0.f, 1.f);

        glBegin(GL_TRIANGLES);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.6f, -0.4f, 0.f);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(0.6f, -0.4f, 0.f);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(0.f, 0.6f, 0.f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return EXIT_SUCCESS;
}
