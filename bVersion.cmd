
@echo off
@set default_ver=V0.09.2003

:: get version
@if "%1"=="" (
@set /p APP_VERSION="Please input ver (for:%default_ver%): "
) else (
@set APP_VERSION=%1
)

@if "%APP_VERSION%"=="" (
@set APP_VERSION=%default_ver%
)

@echo Version: %APP_VERSION%

