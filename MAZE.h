#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <string>

using namespace System;

int Neighbor(int** A, int x, int y, int width, int height);
int ALLNeighbors(int** A, int width, int height);
int ended(int** &maze, int height, int width);
bool deadend(int x, int y, int** maze, int height, int width);
void maze1(int** maze, int height, int width);
void maze2(int** maze, int** A, int height, int width);
void mazer(int** maze, int height, int width);
void mazeu(int** maze, int height, int width);

std::string& Convert_String_To_string(String^ s, std::string& os);