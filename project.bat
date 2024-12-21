@echo off
setlocal enabledelayedexpansion

@REM Global Constants
set CLEAN=0
set BUILD=0
set BUILD_DIR=build
set ROOT_DIR=.
set CLI_APP_NAME=%~nx0

@REM Argument Counter
set arg_c=0

@REM Parse arguments
for %%A in (%*) do set /a arg_c+=1

if %arg_c% lss 1 goto :display_help
if %arg_c% gtr 3 goto :error_invalid_args

:parse_args
if "%~1"=="" goto :end_parse_args

if "%~1"=="--help" (
    goto :display_help
)
if "%~1"=="--clean" (
    set CLEAN=1
    shift
    goto :parse_args
)
if "%~1"=="--build" (
    set BUILD=1
    shift
    goto :parse_args
)
if not "%~1"=="" (
    set BUILD_DIR=%~1
    shift
    goto :parse_args
)
goto :error_invalid_args

:end_parse_args

if %BUILD%==0 if %CLEAN%==0 goto :error_invalid_args
if "%BUILD_DIR%"=="" set BUILD_DIR=build

@REM Handle Cleaning
if %CLEAN%==1 (
    if exist "%BUILD_DIR%" (
        echo ^::: Cleaning build directory: '%BUILD_DIR%'
        rmdir /s /q "%BUILD_DIR%"
        if errorlevel 1 (
            echo ^::: Cleaning failed: Cannot delete '%BUILD_DIR%'
            exit /b 1
        )
    ) else (
        echo ^::: Cleaning skipped: Build directory does not exist '%BUILD_DIR%'
    )
)

@REM Handle Building
if %BUILD%==1 (
    echo ^::: Configuring project in '%BUILD_DIR%'
    cmake -S "%ROOT_DIR%" -B "%BUILD_DIR%"
    if errorlevel 1 (
        echo ^::: Configuration failed
        exit /b 1
    )

    echo ^::: Building project in '%BUILD_DIR%'
    cmake --build "%BUILD_DIR%"
    if errorlevel 1 (
        echo ^::: Build failed
        exit /b 1
    )
)

goto :success

:display_help
echo ^::: Usage:
echo    %CLI_APP_NAME% --clean ^[^<build-dir^>^]
echo    %CLI_APP_NAME% --build ^[^<build-dir^>^]
echo    %CLI_APP_NAME% --clean --build ^[^<build-dir^>^]
exit /b 0

:error_invalid_args
echo ^::: Error: Invalid or unknown arguments: '%*'
echo ^::: Use '--help' for usage information.
exit /b 1

:success
echo ^::: Operation completed successfully.
exit /b 0
