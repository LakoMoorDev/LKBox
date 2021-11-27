#include "../../include/LKBox/Debug.h"


//namespace Debugger
//{
    debug::debug(bool FpsConsole)
    {
        fpsCon() = false;
        if(FpsConsole == true)
            fpsCon() = true;
        else
            fpsCon() = false;
    }

    void debug::SkeletBox()
    {

    }

    void debug::TerminalBox()
    {
        
    }
//}