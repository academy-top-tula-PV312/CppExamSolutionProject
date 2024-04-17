#include <iostream>
#include <iomanip>

struct Item
{
    int row;
    int column;
};

int** MatrixCreate(int rows, int columns);
int** MatrixNaturalCreate(int rows, int columns);
void MatrixPrint(int** matrix, int rows, int columns);
void MatrixDelete(int** matrix, int rows);

Item MatrixMin(int** matrix, int rows, int columns);
Item MatrixMax(int** matrix, int rows, int columns);

unsigned long long BigRand(int digits);

void MatrixTransp(int** matrix, int rows);
void MatrixShaffl(int** matrix, int rows);

void BinaryNumber(int number);
void NumberToBase(int number, int base);

void ArraySortMerge(int* array, int size);

int main()
{
    srand(time(nullptr));

    /*int** matrix = MatrixCreate(5, 7);
    MatrixPrint(matrix, 5, 7);
    

    Item itemMin = MatrixMin(matrix, 5, 7);
    std::cout << "item = " << matrix[itemMin.row][itemMin.column]
                << ", row = " << itemMin.row
                << ", column = " << itemMin.column << "\n";

    MatrixDelete(matrix, 5);*/

    /*long long number = BigRand(15);
    std::cout << number << "\n";*/

    //int** matrix = MatrixNaturalCreate(5, 5);
    //MatrixPrint(matrix, 5, 5);
    //MatrixShaffl(matrix, 5);
    ////MatrixTransp(matrix, 5);
    //std::cout << "\n";
    //MatrixPrint(matrix, 5, 5);

    //BinaryNumber(37);
    //NumberToBase(2684, 16);

    int* array = new int[20];
    for (int i{}; i < 20; i++)
        array[i] = rand() % 100;
    
    for (int i{}; i < 20; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";

    ArraySortMerge(array, 20);

    for (int i{}; i < 20; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

int** MatrixCreate(int rows, int columns)
{
    
    int** matrix = new int*[rows];
    for (int row{}; row < rows; row++)
        matrix[row] = new int[columns];

    for (int row{}; row < rows; row++)
        for (int column{}; column < columns; column++)
            matrix[row][column] = rand() % 100;

    return matrix;
}

int** MatrixNaturalCreate(int rows, int columns)
{
    int** matrix = new int* [rows];
    for (int row{}; row < rows; row++)
        matrix[row] = new int[columns];

    int count{};
    for (int row{}; row < rows; row++)
        for (int column{}; column < columns; column++)
            matrix[row][column] = ++count;

    return matrix;
}

void MatrixPrint(int** matrix, int rows, int columns)
{
    for (int row{}; row < rows; row++)
    {
        for (int column{}; column < columns; column++)
            std::cout << std::setw(2) << matrix[row][column] << " ";
        std::cout << "\n";
    }
}

void MatrixDelete(int** matrix, int rows)
{
    for (int row{}; row < rows; row++)
        delete[] matrix[row];
    delete[] matrix;
}

Item MatrixMin(int** matrix, int rows, int columns)
{
    int rowMin{};
    int columnMin{};

    for (int row{}; row < rows; row++)
        for (int column{}; column < columns; column++)
            if (matrix[row][column] < matrix[rowMin][columnMin])
            {
                rowMin = row;
                columnMin = column;
            }
    
    /*
    Item item;
    item.column = columnMin;
    item.row = rowMin;
    */

    return Item{ rowMin, columnMin }; // return item;
}

unsigned long long BigRand(int digits)
{
    unsigned long long numberRand;
    if (digits >= 20)
    {
        digits = 19;
        numberRand = 1;
        numberRand = numberRand * 10 + rand() % 9;
    }
    else
        numberRand = 1 + rand() % 9;
    for (int i{}; i < digits - 1; i++)
        numberRand = numberRand * 10 + rand() % 10;

    return numberRand;
}

void MatrixTransp(int** matrix, int rows)
{
    for (int i{}; i < rows; i++)
        for (int j{ i }; j < rows; j++)
            std::swap(matrix[i][j], matrix[j][i]);
}

void MatrixShaffl(int** matrix, int rows)
{
    int randomShaffl{ (int)(rows * rows / 2) };
    for (int s{}; s < randomShaffl; s++)
    {
        int row1 = rand() % rows;
        int column1 = rand() % rows;

        int row2 = rand() % rows;
        int column2 = rand() % rows;

        std::swap(matrix[row1][column1], matrix[row2][column2]);
    }
}

void BinaryNumber(int number)
{
    if (number >= 2)
        BinaryNumber(number / 2);
    std::cout << number % 2;
}

void NumberToBase(int number, int base)
{
    if (number >= base)
        NumberToBase(number / base, base);
    int mod = number % base;
    if (mod < 10)
        std::cout << mod;
    else
        std::cout << (char)(mod + 55);
}

void ArraySortMerge(int* array, int size)
{
    if (size > 1)
    {
        int left_size = size / 2;
        int right_size = size - left_size;

        ArraySortMerge(array, left_size);
        ArraySortMerge((array + left_size), right_size);

        int left_index = 0;
        int right_index = left_size + 1;

        int merge_index = 0;
        int* merge_array = new int[size];

        while (left_index < left_size && right_index < right_size)
        {
            if (array[left_index] < array[right_index])
            {
                merge_array[merge_index++] = array[left_index++];
                /*merge_array[merge_index] = array[left_index];
                left_index++;
                merge_index++;*/
            }
            else
            {
                merge_array[merge_index++] = array[right_index++];
                /*merge_array[merge_index] = array[right_index];
                right_index++;
                merge_index++;*/
            }
        }
        while (left_index < left_size)
            merge_array[merge_index++] = array[left_index++];
        while (right_index < right_size)
            merge_array[merge_index++] = array[right_index++];

        for (int i{}; i < size; i++)
            array[i] = merge_array[i];
        delete[] merge_array;
    }

    


}
