SetLocal EnableDelayedExpansion

cd Source
SET cFileNames=
FOR /R %%f in (*.cpp) do (
    SET cFileNames=!cFileNames! %%f
)
cd ..

SET assembly=Engine
SET cFlags=-g -fdiagnostics-color=always -shared 
SET include=-ISource  -IVendor/glad/include -IVendor/GLFW/include -IVendor/ImGUI
SET linker= -lglfw3  -L../Bin 
SET defines= -DCE_BUILD_DLL -DCE_PLATFORM_WIN32

SET ImGUIFiles=Vendor/ImGUI/imgui.cpp Vendor/ImGUI/imgui_draw.cpp Vendor/ImGUI/imgui_tables.cpp Vendor/ImGUI/imgui_demo.cpp Vendor/ImGUI/imgui_widgets.cpp Vendor/ImGUI/backends/imgui_impl_glfw.cpp Vendor/ImGUI/backends/imgui_impl_opengl3.cpp

@REM Builds
@REM gcc -g -IVendor/glad/include -shared Vendor/glad/src/glad.c -o ../Bin/glad.o
@REM g++ -g -shared %ImGUIFiles%  -IVendor/ImGUI -IVendor/GLFW/include -lglfw3 -L../Bin -o ../Bin/ImGUI.o

g++ %defines% %cFlags% ../Bin/ImGUI.o %cFileNames% Vendor/glad/src/glad.c %include% %linker% -o../Bin/%assembly%.dll