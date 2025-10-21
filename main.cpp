/* it just gonna be like an standard for us untill we build the whole system

it is moving from A to B
*/

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

// Grid size
const int ROWS = 5;
const int COLS = 5;

// Symbols
const char INTERSECTION = 'O';
const char HORIZONTAL_ROAD = '-';
const char VERTICAL_ROAD = '|';
const char VEHICLE = 'V';
const char EMPTY = ' ';

// Grid
char grid[ROWS * 2 - 1][COLS * 2 - 1];

// Initialize ASCII grid
void initializeGrid()
{
    for (int i = 0; i < ROWS * 2 - 1; ++i)
    {
        for (int j = 0; j < COLS * 2 - 1; ++j)
        {
            if (i % 2 == 0 && j % 2 == 0)
                grid[i][j] = INTERSECTION;
            else if (i % 2 == 0)
                grid[i][j] = HORIZONTAL_ROAD;
            else if (j % 2 == 0)
                grid[i][j] = VERTICAL_ROAD;
            else
                grid[i][j] = EMPTY;
        }
    }
}

// Print grid
void printGrid()
{
    for (int i = 0; i < ROWS * 2 - 1; ++i)
    {
        for (int j = 0; j < COLS * 2 - 1; ++j)
        {
            std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }
}

// Move vehicle from (startRow, startCol) to (endRow, endCol)
void moveVehicle(int startRow, int startCol, int endRow, int endCol)
{
    int r = startRow;
    int c = startCol;

    while (r != endRow || c != endCol)
    {
        grid[r][c] = VEHICLE;
        system("cls"); // use "clear" on Linux/macOS
        printGrid();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        // Restore the previous symbol
        grid[r][c] = (r % 2 == 0 && c % 2 == 0) ? INTERSECTION : (r % 2 == 0) ? HORIZONTAL_ROAD
                                                                              : VERTICAL_ROAD;

        // Move horizontally first
        if (c < endCol)
            c++;
        else if (c > endCol)
            c--;

        // Move vertically
        else if (r < endRow)
            r++;
        else if (r > endRow)
            r--;
    }

    // Final position
    grid[endRow][endCol] = VEHICLE;
    system("cls");
    printGrid();
}

int main()
{
    initializeGrid();

    // Example: move from top-left intersection to bottom-right intersection
    int startRow = 0;
    int startCol = 0;
    int endRow = (ROWS - 1) * 2;
    int endCol = (COLS - 1) * 2;

    moveVehicle(startRow, startCol, endRow, endCol);

    return 0;
}
