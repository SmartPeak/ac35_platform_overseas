::##########################################################################
::# Shanghai Basewin Technology Co.,Ltd.
::# All Rights Reserved 2019
::##########################################################################
:: environment£º
:: - Cygwin64 (with CMake)
:: - ARMCT5.01 (Or RVCT)

@echo off
@echo --------------------------------------
@echo ENV Setup
@echo --------------------------------------
@set SRC_ROOT=%~dp0

@set CYGPATH=D:\tools\cygwin\bin\cygpath.exe
@set TOOLCHAIN_ROOT_PATH=/cygdrive/D/tools/ARMCT5.01/94
@set path=D:\tools\cygwin\bin;D:\tools\ARMCT5.01\94\bin;%SRC_ROOT%tools;%path%

:: Enter the application name here
@echo --------------------------------------
@echo Default APP Name£º showAPP
@echo Please modify APP_NAME in envsetup.cmd
@echo --------------------------------------
@set APP_NAME=showAPP

