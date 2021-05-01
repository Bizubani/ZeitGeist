@ECHO OFF
REM Build ZeitGeist and the testbed

ECHO "Building Everything..."

PUSHD engine
CALL build.bat
POPD
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit) 

PUSHD testbed
CALL build.bat
POPD
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit) 

ECHO "ZeitGeist building completed successfully."