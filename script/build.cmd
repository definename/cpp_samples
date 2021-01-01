@echo off

set GENERATOR="%1"
set LIBTYPE="%2"
set CRTTYPE="%3"
set BUILDTYPE_INTERNAL="%4"

if %BUILDTYPE_INTERNAL% == "" goto :error_param_buildtype
set ARCHITECTURE_INTERNAL=""

:: Determine CMake generator.
if %GENERATOR% == "" goto :error_param_generator
set GENERATOR_INTERNAL=""
if %GENERATOR% == "vc10-x86" set GENERATOR_INTERNAL="Visual Studio 10 2010"
if %GENERATOR% == "vc10-x64" set GENERATOR_INTERNAL="Visual Studio 10 2010 Win64"
if %GENERATOR% == "vc11-x86" set GENERATOR_INTERNAL="Visual Studio 11 2012"
if %GENERATOR% == "vc11-x64" set GENERATOR_INTERNAL="Visual Studio 11 2012 Win64"
if %GENERATOR% == "vc12-x86" set GENERATOR_INTERNAL="Visual Studio 12 2013"
if %GENERATOR% == "vc12-x64" set GENERATOR_INTERNAL="Visual Studio 12 2013 Win64"
if %GENERATOR% == "vc14-x86" set GENERATOR_INTERNAL="Visual Studio 14 2015"
if %GENERATOR% == "vc14-x64" set GENERATOR_INTERNAL="Visual Studio 14 2015 Win64"
if %GENERATOR% == "vc15-x86" set GENERATOR_INTERNAL="Visual Studio 15 2017"
if %GENERATOR% == "vc15-x64" set GENERATOR_INTERNAL="Visual Studio 15 2017 Win64"
if %GENERATOR% == "vc16-x86" (
    set GENERATOR_INTERNAL="Visual Studio 16 2019"
    set ARCHITECTURE_INTERNAL=-A Win32
)
if %GENERATOR% == "vc16-x64" (
    set GENERATOR_INTERNAL="Visual Studio 16 2019"
    set ARCHITECTURE_INTERNAL=-A x64
)
if %GENERATOR_INTERNAL% == "" goto :error_param_generator

:: Determine library type.
if %LIBTYPE% == "" goto :error_param_libtype
set LIBTYPE_INTERNAL=""
if %LIBTYPE% == "shared" set LIBTYPE_INTERNAL="shared"
if %LIBTYPE% == "static" set LIBTYPE_INTERNAL="static"
if %LIBTYPE_INTERNAL% == "" goto :error_param_libtype

:: Determine CRT type.
if %CRTTYPE% == "" goto :error_param_crttype
set CRTTYPE_INTERNAL=""
if %CRTTYPE% == "md" set CRTTYPE_INTERNAL="md"
if %CRTTYPE% == "mt" set CRTTYPE_INTERNAL="mt"
if %CRTTYPE_INTERNAL% == "" goto :error_param_crttype

:: Check for conflicting CRT and library type.
if %LIBTYPE_INTERNAL% == "shared" if %CRTTYPE_INTERNAL% == "mt" goto :error_crttype_conflict

:: Compose CMake parameters string.
set CMAKE_PARAMS_INTERNAL=%BUILDTYPE_INTERNAL%
if %LIBTYPE_INTERNAL% == "shared" set CMAKE_PARAMS_INTERNAL=-DBUILD_SHARED_LIBS=ON
if %LIBTYPE_INTERNAL% == "static" set CMAKE_PARAMS_INTERNAL=-DBUILD_SHARED_LIBS=OFF

if %CRTTYPE_INTERNAL% == "mt" set CMAKE_PARAMS_INTERNAL=%CMAKE_PARAMS_INTERNAL% -DBUILD_WITH_STATIC_CRT=ON
if %CRTTYPE_INTERNAL% == "md" set CMAKE_PARAMS_INTERNAL=%CMAKE_PARAMS_INTERNAL% -DBUILD_WITH_STATIC_CRT=OFF

if %BUILDTYPE_INTERNAL% == "debug" set CMAKE_PARAMS_INTERNAL=%CMAKE_PARAMS_INTERNAL% -DCMAKE_CONFIGURATION_TYPES=Debug
if %BUILDTYPE_INTERNAL% == "release" set CMAKE_PARAMS_INTERNAL=%CMAKE_PARAMS_INTERNAL% -DCMAKE_CONFIGURATION_TYPES=Release

:: Create build directory.
set BUILD_DIR=..\build\%GENERATOR%-%BUILDTYPE_INTERNAL%
echo -- CMake build directory: %BUILD_DIR%
mkdir %BUILD_DIR%
pushd %BUILD_DIR%

:: Run CMake.
set CMAKE_COMMAND=-G %GENERATOR_INTERNAL% %CMAKE_PARAMS_INTERNAL% %ARCHITECTURE_INTERNAL% -S ../..
echo -- CMake command: %CMAKE_COMMAND%
cmake %CMAKE_COMMAND%
if errorlevel 1 goto :error_build

:: Exit
echo -- Build succeeded!
popd
goto :eof

:error_param_generator
echo ERROR: Build tool must be specified (vc10-x86,vc10-x64,vc11-*,vc12-*,vc14-*,vc15-*,vc16-*).
exit /b 1

:error_param_libtype
echo ERROR: Library type must be specified (shared, static).
exit /b 2

:error_param_crttype
echo ERROR: CRT type must be specified (md, mt).
exit /b 3

:error_param_buildtype
echo ERROR: Build type must be specified (debug, release).
exit /b 4

:error_build
echo ERROR: Failed to build project - see above and correct.
popd
exit /b 5