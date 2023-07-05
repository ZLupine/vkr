#include "MAZE.h"

//Константы стена, проход, вход и выход
const int wall = 0, pass = 1, start = 2, finish = 3;

//Подпрограмма для нахождения соседних клеток со стоимостью 1
//в динамическом массиве А высотой height и шириной width
int Neighbor(int** A, int x, int y, int width, int height)
{
    int k = 0;
    if (x != width - 2 && A[y][x + 2] == 1)
        k++;
    if (x != 1 && A[y][x - 2] == 1)
        k++;
    if (y != height - 2 && A[y + 2][x] == 1)
        k++;
    if (y != 1 && A[y - 2][x] == 1)
        k++;
    return k;
}

//Подпрограмма для нахождения общей стоимость массива А
//высотой height и шириной width
int ALLNeighbors(int** A, int width, int height)
{
    int k = 0;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            k += A[i][j];
    return k;
}

//Подпрограмма для определения, находится ли  крот
//по координатам x и y в тупике в динамическом массиве maze
//шириной width и высотой height
bool deadend(int x, int y, int** maze, int height, int width)
{
    int a = 0;

    if (x != 1)
    {
        if (maze[y][x - 2] == pass)
            a += 1;
    }
    else a += 1;

    if (y != 1)
    {
        if (maze[y - 2][x] == pass)
            a += 1;
    }
    else a += 1;

    if (x != width - 2)
    {
        if (maze[y][x + 2] == pass)
            a += 1;
    }
    else a += 1;

    if (y != height - 2)
    {
        if (maze[y + 2][x] == pass)
            a += 1;
    }
    else a += 1;

    if (a == 4)
        return 1;
    else
        return 0;
}


//Подпрограмма для определения, есть ли не
//посещённые чётные клетки в динамическом массиве maze
//шириной width и высотой height
int ended(int** &maze, int height, int width)
{
    int n=0;
    for (int i=1; i<height; i+=2)
        for (int j=1; j<width; j+=2)
            if (maze[i][j]==wall)
                n++;
    return n;
}

//Подпрограмма для генерации лабиринта первым
//алгоритмом в динамическом массиве maze шириной 
//width и высотой height
void maze1(int** maze, int height, int width)
{   int x, y, c, a;
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            maze[i][j] = wall;

    x = 3;
    y = 3;
    a = 0;            
    while(ended(maze, height, width))
    {   maze[y][x] = pass;
        a++;
        while(1)          
        {   c = rand()%4; 
            switch(c)     
            {   case 0:
                    if(y != 1)
                        if(maze[y-2][x] == wall)  // Вверх
                        {   maze[y-1][x] = pass;
                            maze[y-2][x] = pass;
                            y-=2;
                        }
                case 1:
                    if(y != height-2)
                        if(maze[y+2][x] == wall)  // Вниз
                        {   maze[y+1][x] = pass;
                            maze[y+2][x] = pass;
                            y+=2;
                        }
                case 2:
                    if(x != 1)
                        if(maze[y][x-2] == wall)  // Налево
                        {   maze[y][x-1] = pass;
                            maze[y][x-2] = pass;
                            x-=2;
                        }
                case 3:
                    if(x != width-2)
                        if(maze[y][x+2] == wall)  // Направо
                        {   maze[y][x+1] = pass;
                            maze[y][x+2] = pass;
                            x+=2;
                        }
            }
            if(deadend(x,y,maze,height,width))
                break;
        }

        if(deadend(x,y,maze,height,width)) 
            do
            {   x = 2*(rand()%((width-1)/2))+1;
                y = 2*(rand()%((height-1)/2))+1;
            }
            while(maze[y][x] != pass);
    }
}


//Подпрограмма для генерации случайного лабиринта
//в динамическом массиве maze шириной width
//и высотой height
void mazer(int** maze, int height, int width)
{
    int c;
    srand(time(NULL));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 ||
                j == 0 || j == width - 1)
            {
                maze[i][j] = wall;
            }
            else
            {
                maze[i][j] = pass;
            }
        }
    }
    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            c = rand() % 2;
            if (i == 1 && j == 1 ||
                i == 1 && j == width - 2 ||
                i == height - 2 && j == 1 ||
                i == height - 2 && j == width - 2)
                maze[i][j] = pass;
            else if (i == 1)
            {
                if (maze[i][j - 1] == wall)
                    maze[i][j] = pass;
                else maze[i][j] = c;
            }
            else
            {
                if (maze[i][j - 1] == pass &&
                    maze[i - 1][j - 1] == pass &&
                    maze[i - 1][j] == pass)
                    maze[i][j] = wall;
                else if (maze[i - 1][j] == wall && (maze[i][j - 1] == wall &&
                    maze[i - 1][j - 1] == wall || maze[i][j + 1] == wall &&
                    maze[i - 1][j + 1] == wall))
                    maze[i][j] = pass;
                else if (maze[i-1][j]==pass && (maze[i-1][j-1]==wall && 
                    maze[i][j-1]==pass || maze[i-1][j+1]==wall))
                {
                    maze[i][j] == pass;
                }
                else if (i != height - 2)
                    maze[i][j] = c;
                else if (maze[i][j - 1] == wall)
                    maze[i][j] = pass;
                else
                    maze[i][j] = c;
            }
        }
    }
}


//Подпрограмма для генерации случайного лабиринта
//в динамическом массиве maze шириной width
//и высотой height с помощью динамического 
//массива стоимости A
void maze2(int** maze, int** A, int height, int width)
{
    int x, y, c;
    srand(time(NULL));
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((i % 2 != 0 && j % 2 != 0) && (i < height - 1 && j < width - 1))
            {
                maze[i][j] = pass;
                A[i][j] = 1;
            }
            else
            {
                maze[i][j] = wall;
                A[i][j] = 0;
            }
        }
    }
    x = 2 * (rand() % ((width - 1) / 2)) + 1;
    y = 2 * (rand() % ((height - 1) / 2)) + 1;
    A[y][x] = 0;
    while (ALLNeighbors(A, width, height) != 0)
    {
        c = rand() % 4;
        switch (c)
        {
        case 0:
        {
            if (y != 1 && A[y - 2][x] == 1)
            {
                maze[y - 1][x] = pass;
                y = y - 2;
            }
        }
        break;
        case 1:
        {
            if (x != 1 && A[y][x - 2] == 1)
            {
                maze[y][x - 1] = pass;
                x = x - 2;
            }
        }
        break;
        case 2:
        {
            if (y != height - 2 && A[y + 2][x] == 1)
            {
                maze[y + 1][x] = pass;
                y = y + 2;
            }
        }
        break;
        case 3:
        {
            if (x != width - 2 && A[y][x + 2] == 1)
            {
                maze[y][x + 1] = pass;
                x = x + 2;
            }
        }
        break;

        }

        A[y][x] = 0;
        if (Neighbor(A, x, y, width, height) == 0)
        {
            while (1)
            {
                x = 2 * (rand() % ((width - 1) / 2)) + 1;
                y = 2 * (rand() % ((height - 1) / 2)) + 1;
                if (Neighbor(A, x, y, width, height) != 0 && A[y][x] == 0)
                    break;
                else if (ALLNeighbors(A, width, height) == 0)
                    break;
            }
        }
    }
}


//Подпрограмма для генерации стартового поля
//лабиринта в динамическом массиве maze
//шириной width и высотой height
void mazeu(int** maze, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == height - 1 ||
                j == 0 || j == width - 1)
            {
                maze[i][j] = wall;
            }
            else
            {
                maze[i][j] = pass;
            }
        }
    }
}

//Подпрограмма для конвертирования переменной
//s управляемого типа String^ в переменную os
//типа string
std::string& Convert_String_To_string(String^ s, std::string& os)
{
    using namespace Runtime::InteropServices;
    const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
    return os;
}
