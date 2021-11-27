#pragma once

//namespace Debugger
//{
    class debug
    {
        public:
        bool fpsCon()
        {
            return false;
        }
        debug(bool FpsConsole);
        void TerminalBox();
        void SkeletBox();

        private:
        bool isSkeleton;
        bool isMaterial;
        bool isTerminal; 

    };
//}