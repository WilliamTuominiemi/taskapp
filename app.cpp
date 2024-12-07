#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void write(string entry)
{
    ofstream outfile("tasks.txt", ios::app);
    if (outfile.is_open())
    {
        outfile << entry << endl;
        outfile.close();
    }
    else
        cout << "Unable to open file for writing";
}

void readTasks()
{
    system("clear");
    cout << "Your tasks: \n";

    string line;
    ifstream infile("tasks.txt");
    if (infile.is_open())
    {
        while (getline(infile, line))
        {
            cout << line << '\n';
        }
        infile.close();
    }
    else
        cout << "Unable to open file for reading";
}

void addTask()
{
    system("clear");
    string x;
    cout << "Enter a task: ";
    cin >> x;
    cout << "Your task is: " << x << "\n";
    write(x);
}

int main()
{
    while (true)
    {
        cout << "(1) Add a new task (2) Read all tasks (0) Quit \n";

        int x;
        cout << "Enter you option: ";
        cin >> x;

        if (x == 0)
        {
            break;
        }
        else if (x == 1)
        {
            addTask();
        }
        else if (x == 2)
        {
            readTasks();
        }
    }

    return 0;
}