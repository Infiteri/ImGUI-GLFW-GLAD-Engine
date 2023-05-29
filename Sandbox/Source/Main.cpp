#include <ClientCore.h>

class Sandbox : public Core::Application
{
};

Core::Application *Core::CreateApplication()
{
    return new Sandbox();
}