@ECHO OFF
REM Build ZeitGeist and the testbed

ECHO "Building Everything..."

PUSHD engine
CALL build.bat
POPD
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit) ELSE (ECHO "ZeitGeist engine initialized...")

PUSHD testbed
CALL build.bat
POPD
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit) ELSE (ECHO "ZeitGeist tester initialized...")


ECHO "ZeitGeist building completed successfully."