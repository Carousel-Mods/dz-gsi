class CfgPatches
{
    class EventsAPI
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
    class EventsAPI
    {   
        // Information
        type    = "mod";
        name    = "EventsAPI";
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
            //     files[]={"scripts/1_Core"};
            // };

            
            // 2_GameLib
            // class gameLibScriptModule
            // {
            //     value="";
            //     files[]={"scripts/2_GameLib"};
            // };

            // 3_Game
            class gameScriptModule
            {
                value   = "";
                files[] = {"EventsAPI/scripts/3_Game"};
            };

            // 4_World
            class worldScriptModule
            {
                value   = "";
                files[] = {"EventsAPI/scripts/4_World"};
            };

            // 5_Mission
            // class missionScriptModule
            // {
            //     value="";
            //     files[]={"scripts/5_Mission"};
            // };
        };
    };
};