REM Build script for the Zeit Geist engine. Will be replaced with cmake in the future
@ECHO OFF   
REM Force variables to wait till execution time to give their values
SetLocal EnableDelayedExpansion

REM Get a list of all the .c files
SET cFilenames=
FOR /R %%f in (*.c) do (
    SET cFilenames=!cFilenames! %%f
)

ECHO "Files:" %cFilenames%

SET assembly=engine
SET compilerFlags=-g -shared -Wvarargs -Wall -Werror
REM -Wall -Werror
SET includeFlags=-Isrc -I%VULKAN_SDK%/Include
SET linkerFlags=-luser32 -lvulkan-1 -L%VULKAN_SDK%/Lib
SET defines=-D_DEBUG -DZEXPORT -D_CRT_SECURE_NO_WARNINGS

ECHO "Building ZeitGeist %assembly%%.."
clang %cFilenames% %compilerFlags% -o ../bin/%assembly%.dll %defines% %includeFlags% %linkerFlags%

