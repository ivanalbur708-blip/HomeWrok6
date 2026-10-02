#include <iostream>


using namespace std;

const int matrixSize = 3;

void Initialize(int matrix[][matrixSize], int size)
{
    for (int row = 0; row < size; row++)
        for (int column = 0; column < size; column++)
            matrix[row][column] = rand() % 100;
}

void Initialize(double matrix[][matrixSize], int size)
{
    for (int row = 0; row < size; row++)
        for (int column = 0; column < size; column++)
            matrix[row][column] = (rand() % 1000) / 10.0;
}

void Initialize(char matrix[][matrixSize], int size)
{
    for (int row = 0; row < size; row++)
        for (int column = 0; column < size; column++)
            matrix[row][column] = 'A' + rand() % 26;
}

void Print(const int matrix[][matrixSize], int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++) cout << matrix[row][column] << '\t';
        cout << '\n';
    }
}

void Print(const double matrix[][matrixSize], int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++) cout << matrix[row][column] << '\t';
        cout << '\n';
    }
}

void Print(const char matrix[][matrixSize], int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++) cout << matrix[row][column] << '\t';
        cout << '\n';
    }
}

void DiagonalMinMax(const int matrix[][matrixSize], int size, int& minimum, int& maximum)
{
    minimum = matrix[0][0];
    maximum = matrix[0][0];
    for (int i = 1; i < size; i++)
    {
        if (matrix[i][i] < minimum) minimum = matrix[i][i];
        if (matrix[i][i] > maximum) maximum = matrix[i][i];
    }
}

void DiagonalMinMax(const double matrix[][matrixSize], int size, double& minimum, double& maximum)
{
    minimum = matrix[0][0];
    maximum = matrix[0][0];
    for (int i = 1; i < size; i++)
    {
        if (matrix[i][i] < minimum) minimum = matrix[i][i];
        if (matrix[i][i] > maximum) maximum = matrix[i][i];
    }
}

void DiagonalMinMax(const char matrix[][matrixSize], int size, char& minimum, char& maximum)
{
    minimum = matrix[0][0];
    maximum = matrix[0][0];
    for (int i = 1; i < size; i++)
    {
        if (matrix[i][i] < minimum) minimum = matrix[i][i];
        if (matrix[i][i] > maximum) maximum = matrix[i][i];
    }
}

void SortRows(int matrix[][matrixSize], int size)
{
    for (int row = 0; row < size; row++)
        for (int i = 1; i < size; i++)
        {
            int value = matrix[row][i];
            int j = i - 1;
            while (j >= 0 && matrix[row][j] > value)
            {
                matrix[row][j + 1] = matrix[row][j];
                j--;
            }
            matrix[row][j + 1] = value;
        }
}

void SortRows(double matrix[][matrixSize], int size)
{
    for (int row = 0; row < size; row++)
        for (int i = 1; i < size; i++)
        {
            double value = matrix[row][i];
            int j = i - 1;
            while (j >= 0 && matrix[row][j] > value)
            {
                matrix[row][j + 1] = matrix[row][j];
                j--;
            }
            matrix[row][j + 1] = value;
        }
}

void SortRows(char matrix[][matrixSize], int size)
{
    for (int row = 0; row < size; row++)
        for (int i = 1; i < size; i++)
        {
            char value = matrix[row][i];
            int j = i - 1;
            while (j >= 0 && matrix[row][j] > value)
            {
                matrix[row][j + 1] = matrix[row][j];
                j--;
            }
            matrix[row][j + 1] = value;
        }
}

int GreatestCommonDivisor(int number1, int number2)
{
    if (number2 == 0) return number1;
    return GreatestCommonDivisor(number2, number1 % number2);
}

void CountBullsAndCows(int secret, int guess, int& bulls, int& cows)
{
    int secretDigits[4];
    int guessDigits[4];

    for (int i = 3; i >= 0; i--)
    {
        secretDigits[i] = secret % 10;
        guessDigits[i] = guess % 10;
        secret /= 10;
        guess /= 10;
    }

    bulls = 0;
    cows = 0;
    for (int i = 0; i < 4; i++)
    {
        if (secretDigits[i] == guessDigits[i]) cows++;
        for (int j = 0; j < 4; j++)
        {
            if (guessDigits[i] == secretDigits[j])
            {
                bulls++;
                break;
            }
        }
    }
}

void PlayBullsAndCows(int secret, int attempt)
{
    int guess;
    cout << "Attempt " << attempt << ". Enter a four-digit number: ";
    cin >> guess;

    int bulls;
    int cows;
    CountBullsAndCows(secret, guess, bulls, cows);
    cout << "Bulls: " << bulls << ", cows: " << cows << '\n';

    if (cows == 4)
    {
        cout << "Number guessed in " << attempt << " attempts.\n";
        return;
    }

    PlayBullsAndCows(secret, attempt + 1);
}

int CreateSecretNumber()
{
    int digits[4];
    digits[0] = rand() % 9 + 1;

    for (int i = 1; i < 4; i++)
    {
        bool unique;
        do
        {
            digits[i] = rand() % 10;
            unique = true;
            for (int j = 0; j < i; j++)
            {
                if (digits[i] == digits[j]) unique = false;
            }
        } while (!unique);
    }

    return digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
}

int main()
{
    srand(time(nullptr));

    // Task 1
    int intMatrix[matrixSize][matrixSize];
    double doubleMatrix[matrixSize][matrixSize];
    char charMatrix[matrixSize][matrixSize];
    Initialize(intMatrix, matrixSize);
    Initialize(doubleMatrix, matrixSize);
    Initialize(charMatrix, matrixSize);

    int intMinimum;
    int intMaximum;
    double doubleMinimum;
    double doubleMaximum;
    char charMinimum;
    char charMaximum;

    DiagonalMinMax(intMatrix, matrixSize, intMinimum, intMaximum);
    DiagonalMinMax(doubleMatrix, matrixSize, doubleMinimum, doubleMaximum);
    DiagonalMinMax(charMatrix, matrixSize, charMinimum, charMaximum);

    SortRows(intMatrix, matrixSize);
    SortRows(doubleMatrix, matrixSize);
    SortRows(charMatrix, matrixSize);

    cout << "Integer matrix:\n";
    Print(intMatrix, matrixSize);
    cout << "Diagonal min/max: " << intMinimum << ' ' << intMaximum << '\n';
    cout << "Double matrix:\n";
    Print(doubleMatrix, matrixSize);
    cout << "Diagonal min/max: " << doubleMinimum << ' ' << doubleMaximum << '\n';
    cout << "Character matrix:\n";
    Print(charMatrix, matrixSize);
    cout << "Diagonal min/max: " << charMinimum << ' ' << charMaximum << '\n';

    // Task 2
    int number1;
    int number2;
    cout << "Two integers: ";
    cin >> number1 >> number2;
    if (number1 < 0) number1 = -number1;
    if (number2 < 0) number2 = -number2;
    cout << "GCD: " << GreatestCommonDivisor(number1, number2) << '\n';

    // Task 3
    PlayBullsAndCows(CreateSecretNumber(), 1);

    return 0;
}
