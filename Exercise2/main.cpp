#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

double mapValue(double N)
{
    return ( N - 1 ) * ( 3.0 / 4.0 ) - 1;
}

int main()
{
    ifstream inputFile("data.csv");
    ofstream outputFile("result.csv");

    if(inputFile.fail())
    {
        cerr << "Error: File does not exist" << endl;
        return 1;
    }

    if (outputFile.fail())
    {
        cerr << "Error: Impossible to create output file or it already exists" << endl;
        return 1;
    }

    outputFile << "# N Mean" << endl;

    double sum = 0;
    double currentvalue;
    int i = 1;
    while (inputFile >> currentvalue)
    {
        double mappedValue = mapValue(currentvalue);
        sum += mappedValue;
        outputFile << i << " " << scientific << setprecision(17) << sum / i << endl;
        i++;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
