@ECHO OFF

CLS

PUSHD Engine
ECHO Building Engine
CALL Build.bat
POPD

PUSHD Sandbox
ECHO Building Test
CALL Build.bat
POPD

