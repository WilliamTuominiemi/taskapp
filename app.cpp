#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
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
        int lineNumber = 1;
        while (getline(infile, line))
        {
            cout << lineNumber << ". " << line << '\n';
            lineNumber++;
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

void removeTask()
{
    vector<string> tasks;
    string line;

    ifstream infile("tasks.txt");
    if (infile.is_open())
    {
        while (getline(infile, line))
        {
            tasks.push_back(line);
        }
        infile.close();
    }
    else
    {
        cout << "Unable to open file for reading\n";
        return;
    }

    readTasks();

    int x;
    cout << "Which task would you like to remove? Enter task number: ";
    cin >> x;

    if (x < 1 || x > tasks.size())
    {
        cout << "Invalid task number!\n";
        return;
    }

    tasks.erase(tasks.begin() + x - 1);

    ofstream outfile("tasks.txt");
    if (outfile.is_open())
    {
        for (const string &task : tasks)
        {
            outfile << task << '\n';
        }
        outfile.close();
        cout << "Task removed successfully.\n";
    }
    else
    {
        cout << "Unable to open file for writing\n";
    }
}

int main()
{
    while (true)
    {
        cout << "(1) Add a new task (2) Read all tasks (3) Remove a task (0) Quit \n";

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
        else if (x == 3)
        {
            removeTask();
        }
    }

    return 0;
}