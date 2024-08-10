class CfgPatches
{
    class GSI
    {   
        // Dependencies
        requiredAddons[] =
        {
            "DZ_Data",
        };
    };
};

class CfgMods 
{
    class GSI
    {   
        // Information
        type    = "mod";
        name    = "DayZ Game State Integration";
        author  = "hurfy";
        version = "1.0.0";

        // Dependencies
        dependencies[] =
        {
            "Game",
            "World"
        };

        // Modules config
        class defs
        {   
            // 1_Core
            // class engineScriptModule
            // {
            //     value="";
            //     files[]={"DayzGSI/scripts/1_core"};
            // };

            
            // 2_GameLib
            // class gameLibScriptModule
            // {
            //     value="";
            //     files[]={"DayzGSI/scripts/2_gamelib"};
            // };

            // 3_Game
            class gameScriptModule
            {
                value   = "";
                files[] = {"DayzGSI/scripts/3_game"};
            };

            // 4_World
            class worldScriptModule
            {
                value   = "";
                files[] = {"DayzGSI/scripts/4_world"};
            };

            // 5_Mission
            // class missionScriptModule
            // {
            //     value="";
            //     files[]={"DayzGSI/scripts/5_mission"};
            // };
        };
    };
};