SetLocal EnableDelayedExpansion

SET cFileNames=
FOR /R %%f in (*.cpp) do (
    SET cFileNames=!cFileNames! %%f
)

SET assembly=Sandbox
SET cFlags=-g -fdiagnostics-color=always
SET include=-ISource -I../Engine/Source -I../Engine/Vendor/GLFW/include -I../Engine/Vendor/glad/include
SET linker= -lEngine -L../Bin -lglfw3 
SET defines= -DCE_PLATFORM_WIN32

g++ %defines% %cFlags% %cFileNames% %include% %linker% -o../Bin/%assembly%.exe