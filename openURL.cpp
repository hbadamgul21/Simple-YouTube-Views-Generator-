#include <iostream>
#include <string>
#include <windows.h>

/*
Wanted to try and make a simple Youtube view generator, by no means is this suppose to bypass the YT algorithm; however, it seems to work just fine so far. 
Just place your url link, and give the amount of times you want it to run. What I noticed is that if I ran it for 50 views, I would pretty much get half of those views.
I choose iexplore, that way I can work on another browser while having this program run in the background. So far, it has not hinderenced my work. 
Finally, like I said it was a simple thing I wanted to make on the spot. Did not expect it to work, but it works...slowly. lol
*/

class URL {
  
    public:
        std::string urlLINK;
        int t;
        
        URL(std::string l, int times)
        {
            urlLINK = l;
            t = times;
        }
        ~URL() {}
        
        void runURL();
    
    
};

void URL::runURL()
{
   //Performing the necessary tasks to open the given url in internet explore, which runs in the background without any disturbance.
   //After the given time "Sleep(...)" we can close the explore and repeat the process once more. 
   //t = amount of views 
   for (int i = 1; i <= t; i++) 
   {
        Sleep(3000);
        ShellExecute(NULL, "open", "iexplore.exe", urlLINK.c_str(), NULL, SW_MINIMIZE);
        std::cout << "Video number: " << i << std::endl; 
        Sleep(165000);
        ShellExecute(NULL, NULL, "taskkill", "/F /IM iexplore.exe /T", NULL, SW_HIDE);

   } 
}


int main() {

    std::cout<<"Running..." << std::endl;
    //std::string link2 = "https://www.youtube.com/watch?v=hs5gjz-g5rc";
    //ShellExecute(NULL, "open", "iexplore.exe", link2.c_str(), NULL, SW_MINIMIZE);
    //std::string link3 = "https://www.youtube.com/watch?v=_eMQ9f0hkTo";
    
    URL link("https://www.youtube.com/watch?v=_eMQ9f0hkTo", 50);
    link.runURL();

    std::cout<<"Completed...";

    return 0;

}