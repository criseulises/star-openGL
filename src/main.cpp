#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    // Update the viewport to match the new window size
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (width > height) {
        float aspect = (float)width / height;
        glOrtho(-aspect, aspect, -1.0f, 1.0f, -1.0f, 1.0f);
    } else {
        float aspect = (float)height / width;
        glOrtho(-1.0f, 1.0f, -aspect, aspect, -1.0f, 1.0f);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(void) {
    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Star", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    framebuffer_size_callback(window, width, height);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.5f, 0.0f, 0.5f, 1.0f);

        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 0.0f);

        // FIRST TRIANGLE
        glVertex2f(-0.5f, 0.4f);
        glVertex2f(0.0f, -0.7f);
        glVertex2f(0.5f, 0.4f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.4f);
        glVertex2f(0.0f, 0.7f);
        glVertex2f(0.5f, -0.4f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}