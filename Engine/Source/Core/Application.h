#include "Core.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Core
{
    class CORE_API Application
    {
    public:
        Application();
        ~Application();

        GLFWwindow *window;

        void Run();
    };

    Application *CreateApplication();

} // namespace Core
