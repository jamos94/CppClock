
// Week 3 Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
// #include <windows.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

void Clock(int sec, int min, int hour12, int hour24);
// // void userInput(int sec, int min, int hour12, int hour24);
void Menu(int sec, int min, int hour12, int hour24);

void Menu(int sec, int min, int hour12, int hour24)
{
    //int sec{}, min{}, hour24{}, hour12{};
    //create entry menu
    cout << setfill('*') << std::setw(23) << "   " << setfill('*') << setw(20);
    cout << '*' << endl;
    cout << "*   1 - Add One Hour     *" << endl; //option #1
    cout << "*   2 - Add One Minute   *" << endl; //option #2
    cout << "*   3 - Add One Second   *" << endl; //option #3
    cout << "*   4 - Exit Program     *" << endl; //option #4
    cout << setfill('*') << std::setw(23) << "   " << setfill('*') << setw(20);
    cout << '*' << endl;
    // userInput(sec, min, hour12, hour24);
    int option;
    //get user input
    cin >> option;

    //enter menu
    if (option == 5)
    {
        Menu(sec, min, hour12, hour24);
    }

    //option #1
    if (option == 1)
    {
        hour12++; //adds hour
        hour24++; //add hour
    }

    //option #2
    if (option == 2)
    {
        min++;
    }

    //option #3
    if (option == 3)
    {
        sec++;
    }

    //option #4
    if (option == 4)
    {
        return;
    }
    Clock(sec, min, hour12, hour24);
}

//CLOCK FUNCTION
void Clock(int sec, int min, int hour12, int hour24)
{
    int option;
    // cout << "Press 5 to enter menu at any time.\n"; //FIX ME!! USE ESCAPE KEY TO VIEW MENU
    // cin >> option;

    while (!GetAsyncKeyState(0x1B))
    {

        //{

        //if secs are less than 60 add one sec
        if (sec < 60)
        {
            sec++;
        }

        //if secs are equal to 60, add one minute and reset seconds
        if (sec == 60)
        {
            sec = 0;
            min++;
        }

        //when mins reach 60, rest minutes and add an hour
        if (min == 60)
        {
            min = 0;
            hour12++;
            hour24++;
        }

        //when hour passes twelve, rest min & hour while setting hour to 1
        if (hour12 == 12 && min == 60 && sec == 60)
        {
            hour12 = 1;
            min = 0;
            sec = 0;
        }

        //when hour passes 24, reset min & sec for 24 hour clock
        if (hour24 == 24 && min == 60 && sec == 60)
        {
            hour24 = 0;
            min = 0;
            sec = 0;
        }

        Sleep(1000);
        //CLOCKS 24 & 12 HOUR DISPLAY				//FIX ME: CLOCKS WON'T TICK
        cout << setfill('*') << std::setw(23) << "   " << setfill('*') << setw(20);
        cout << '*' << endl;
        cout << "*  12-Hour Clock   *   *  24-Hour Clock   *" << endl;
        cout << "*   " << hour12 << " : " << min << " : " << sec << "     *   *    " << hour24 << " : " << min << " : " << sec << "     * " << endl;
        cout << setfill('*') << setw(23) << "   " << setfill('*') << setw(20);
        cout << '*' << endl;

            // cin >> option;
            // if (option == 5)
            // {
            //   break;
            // }
        //}
        
    }
    Menu(sec, min, hour12, hour24);
}

int main()
{

    int sec = 0;
    int min = 0;
    int hour24 = 0;
    int hour12 = 12;
    // int userInput;

    Clock(sec, min, hour12, hour24);
    // Menu();
    // userInput(hour12, hour24, min, sec);

    //CLOCKS 24 & 12 HOUR DISPLAY				//FIX ME: CLOCKS WON'T TICK
    // cout << setfill('*') << std::setw(23) << "   " << setfill('*') << setw(20);
    // cout << '*' << endl;
    // cout << "*  12-Hour Clock   *   *  24-Hour Clock   *" << endl;
    // cout << "*   " << hour12 << " : " << min << " : " << sec << "     *   *    " << hour24 << " : " << min << " : " << sec << "     * " << endl;
    // cout << setfill('*') << setw(23) << "   " << setfill('*') << setw(20);
    // cout << '*' << endl;
}
