#include <iostream>
#include <ctime>

using namespace std;

void Create(int** a, const int HIGH, const int LOW, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            a[i][j] = LOW + rand() % (HIGH - LOW + 1);
    }
}
void Print(int** a, const int rowCount, const int colCount)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

void Change(int** a, int& imax, int& jmax, int& i, int& j, const int colCount)
{
    int tmp = 0;
    tmp = a[imax][jmax];
    a[imax][jmax] = a[i][i];
    a[i][i] = tmp;
}


void Replace(int** a, const int rowCount, const int colCount, int& max, int& imax, int& jmax)
{
    for (int i = 0; i < rowCount; i++)
    {
        int max = a[i][0];
        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] >= max)
            {
                max = a[i][j];
                jmax = j;
                imax = i;
                
            }
            if (j == (colCount - 1))
            {
                cout << "a[" << imax << "][" << jmax << "] = " << max << endl;

                if (a[i][i] != a[imax][jmax])
                {
                  Change(a, imax, jmax, i, j, colCount);
                }
            }
        }
    }
}
int Max(int** a, const int rowCount, const int colCount, int& max, int& imax_1, int& jmax_1)
{
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            if (a[i][j] >= max )
            {
                max = a[i][j];
                jmax_1 = j;
                imax_1 = i;
            }
        }
    }
    return max;
}



int main()
{
    srand(time(NULL));

    const int HIGH = 100;
    const int LOW = 1;
    int rowCount;
    int colCount;
    cout << "Enter the matrix size: "; cin >> rowCount;
    colCount = rowCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];


    Create(a, HIGH, LOW, rowCount, colCount);
    Print(a, rowCount, colCount);
    int max = a[0][0];
    int imax = 0;
    int jmax = 0;
    Replace(a, rowCount, colCount, max, imax, jmax);

    Print(a, rowCount, colCount);


    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[]a;


    system("pause");
    return 0;

}