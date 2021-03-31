
#include <iostream>
using std::cout;
using std::endl;

int grid[9][9] = {{7, 8, 0, 4, 0, 0, 1, 2, 0},
                  {6, 0, 0, 0, 7, 5, 0, 0, 9},
                  {0, 0, 0, 6, 0, 1, 0, 7, 8},
                  {0, 0, 7, 0, 4, 0, 2, 6, 0},
                  {0, 0, 1, 0, 5, 0, 9, 3, 0},
                  {9, 0, 4, 0, 6, 0, 0, 0, 5},
                  {0, 7, 0, 3, 0, 0, 0, 1, 2},
                  {1, 2, 0, 0, 0, 7, 4, 0, 0},
                  {0, 4, 9, 2, 0, 6, 0, 0, 7} };

void display()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if ((grid[row][i] == num) || (grid[i][col] == num))
        {
            return(false);
        }
    }
    int xo = (row / 3) * 3;
    int yo = (col / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[xo + i][yo + j] == num)
            {
                return(false);
            }
        }
    }
    return(true);
}

bool solve()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == 0)
            {
                for (int n = 1; n < 10; n++)
                {
                    if (isSafe(i, j, n))
                    {
                        grid[i][j] = n;
                        if (solve())
                        {
                            return(true);
                        }
                        grid[i][j] = 0;
                    }
                }
                return(false);
            }
        }
    }
    return(true);
}
int main()
{
    display();
    cout << endl;
    cout << endl;
    solve();
    cout << endl;
    cout << endl;
    display();

    return(0);
}


