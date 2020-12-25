@echo off
REM COMMENT PREVIOUS LINE FOR DEBUGGING PERSPECTIVE

REM ***********************************************
REM @file Makefile.bat
REM @author XAVIER DUPUIS (xavier0978@hotmail.fr)
REM @brief 
REM @version 0.1
REM @date 2020-12-12
REM 
REM @copyright Copyright (c) 2020
REM ***********************************************

setLocal EnableDelayedExpansion 
cls
title Makefile
echo === MAKEFILE BEGIN ===
echo.

REM COMPILER AND FLAGS
set CC=g++
set CCFLAGS=-std=c++17
set CFLAGS=-W -Wall -ansi -pedantic
set LDFLAGS=-lm

REM LOCAL DIRECTORIES AND FILES
set SRC_DIR=src
set BIN_DIR=bin
set BUILD_DIR=build
set TEST_DIR=test
set MAIN=main
set SRCFILESEXT=*.cpp *.c
set EXEC=program.exe

REM GET OPTION
set option=%1
echo    make %option%
echo.

REM DISPATCHING
IF [%option%]==[]       (call :MAKE)
IF [%option%]==[make]   (call :MAKE)
IF [%option%]==[help]   (call :HELP)
IF [%option%]==[start]  (call :START)
IF [%option%]==[run]    (call :MAKE && call :RUN)
IF [%option%]==[test]   (call :TEST && call :RUNTESTS)
IF [%option%]==[clean]  (call :CLEAN)
goto END

REM **** RULES ****
:HELP
echo *********************************************************************
echo ** ./Makefile.bat [tag]                                            **
echo **     [no_tag] : Executes MAKE rule (compile and link)            **
echo **     make     : Executes MAKE rule (compile and link)            **
echo **     help     : Displays help informations                       **
echo **     start    : Executes MAKE rule and start in single window    **
echo **     run      : Executes MAKE rule and run executable in console **
echo **     test     : Executes MAKE rule and run test file in console  **
echo **     clean    : Delete /bin and /build directories               **
echo *********************************************************************
goto :EOF

:MAKE
IF NOT exist %SRC_DIR%   (echo No file to Compile && goto :EOF)
IF NOT exist %BIN_DIR%   (md %BIN_DIR%)
IF NOT exist %BUILD_DIR% (md %BUILD_DIR%)
cd %SRC_DIR%
set DEPENDANCIES=
for %%f in (%SRCFILESEXT%) do (
    echo    COMPILING %%f INTO %%~nf.o
    %CC% -c %%f -o ../%BIN_DIR%/%%~nf.o %CFFLAGS% %CCFLAGS%
    if NOT [%%~nf]==[%MAIN%] (
        set DEPENDANCIES=!DEPENDANCIES!%BIN_DIR%/%%~nf.o 
    )
)
echo.
cd ..
echo    LINKING %BUILD_DIR%/%EXEC% FROM %BIN_DIR%/%MAIN%.o AND %DEPENDANCIES%
%CC% -o %BUILD_DIR%/%EXEC% %BIN_DIR%/%MAIN%.o %DEPENDANCIES% %LDFLAGS% %CCFLAGS%
echo.
goto :EOF

:START
start %BUILD_DIR%/%EXEC%
goto :EOF

:RUN
.\%BUILD_DIR%\%EXEC%
goto :EOF

:RUNTESTS
.\%TEST_DIR%\%BUILD_DIR%\%EXEC%
goto :EOF

:TEST
IF NOT exist %TEST_DIR%   (echo No testing directory && goto :EOF)
cd %TEST_DIR%
IF NOT exist %BIN_DIR%   (md %BIN_DIR%)
IF NOT exist %BUILD_DIR% (md %BUILD_DIR%)
cd ../%SRC_DIR%
set DEPENDANCIES=
for %%f in (%SRCFILESEXT%) do (
    echo    COMPILING %%f INTO %%~nf.o
    %CC% -c %%f -o ../%TEST_DIR%/%BIN_DIR%/%%~nf.o %CFFLAGS% %CCFLAGS%
    if NOT [%%~nf]==[%MAIN%] (
        set DEPENDANCIES=!DEPENDANCIES!%BIN_DIR%/%%~nf.o 
    )
)
echo.
cd ../%TEST_DIR%/%SRC_DIR%
set TESTDEPENDANCIES=
for %%f in (%SRCFILESEXT%) do (
    echo    COMPILING %%f INTO %%~nf.o
    %CC% -c %%f -o ../%BIN_DIR%/%%~nf.o %CFFLAGS% %CCFLAGS%
    if NOT [%%~nf]==[%MAIN%] (
        set TESTDEPENDANCIES=!TESTDEPENDANCIES!%BIN_DIR%/%%~nf.o 
    )
)
echo.
cd ..
echo    LINKING %BUILD_DIR%/%EXEC% FROM %BIN_DIR%/%MAIN%.o AND %DEPENDANCIES%
%CC% -o %BUILD_DIR%/%EXEC% %BIN_DIR%/%MAIN%.o %DEPENDANCIES% %TESTDEPENDANCIES% %LDFLAGS% %CCFLAGS%
echo.
cd ..
goto :EOF

:CLEAN
IF exist %BIN_DIR%   (rmdir %BIN_DIR% /q /s)
IF exist %BUILD_DIR% (rmdir %BUILD_DIR% /q /s)
cd %TEST_DIR%
IF exist %BIN_DIR%   (rmdir %BIN_DIR% /q /s)
IF exist %BUILD_DIR% (rmdir %BUILD_DIR% /q /s)
goto :EOF

:END
echo ===  MAKEFILE END  === 