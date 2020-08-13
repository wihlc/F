/**
    WihlC, Aug 13 2020
    This in an excersize for me to learn threads, and I guess you could use it or make it better if you want
    I tried to recreate the way the captions work in pokemon, in case you're wondering

    I'd imagine you could include different captions by making the 'text' variable into an array of strings;
**/

#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <string>

static bool s;

int counter = 0;
bool do_count = false;
int y = 0;
int strPos = 0;

void stuff(char x)
{
    using namespace std::literals::chrono_literals;
    while(!s)
    {
        std::string text = "hey cool I got this program to work and I did it all by myself\n"; //text
            int length = text.length();

            std::cout << text[strPos];
            strPos++;
            if(do_count) //this is set to true if someone presses a key
            {
                std::this_thread::sleep_for(0.02s);
                counter++;
                if(counter % 8 == 0) //after 8 characters are typed fast, uh, dont do that anymore
                {
                    do_count = false;
                    s = true;
                }

            }
            else
            {
                std::this_thread::sleep_for(0.15s);
            }
        strPos %= length;
    }
}


int main()
{
    using namespace std;
    char x;

    while(x != 'q')
    {
        s = false;
        thread worker(stuff, x);
        x = getch();
        do_count = true;
        worker.join();
    }

    cout << "\nProgram Finished" << endl;

    return 0;
}
