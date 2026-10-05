@echo off
g++ -Wall -std=c++17 -c GameEngine.cpp -o GameEngine.o
if errorlevel 1 exit /b 1
g++ -Wall -std=c++17 -c Renderer.cpp -o Renderer.o
if errorlevel 1 exit /b 1
g++ -Wall -std=c++17 -c Listener.cpp -o Listener.o
if errorlevel 1 exit /b 1
g++ -Wall -std=c++17 -c main.cpp -o main.o
if errorlevel 1 exit /b 1
g++ GameEngine.o Renderer.o Listener.o main.o -o tictactoe.exe
if errorlevel 1 exit /b 1
echo Build terminat.
