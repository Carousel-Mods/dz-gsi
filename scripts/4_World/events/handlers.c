// handlers.c

// This is a test case for sending requests when the player makes a jump, nothing to do with handlers in any way
modded class PlayerBase
{   
    // Send a POST request to HTTP-server
    override void OnJumpStart()
    {
        super.OnJumpStart();

        // Get username and SteamID
        // TODO: Implement a system for obtaining username and steamID64 from the server (GetIdenty())
        string username = "[LB] hurfy";
        string steamID  = "76561199223994494";

        PrintFormat("Identy: %1", GetIdentity());

        // Get position
        vector vectorPosition = GetPosition();
        string stringPosition = string.Format("%1 %2 %3", vectorPosition[0], vectorPosition[1], vectorPosition[2]);

        // Generate JSON string and send it
        string data = string.Format("{\"player\": {\"username\": \"%1\", \"steam_id\": %2}, \"action\": {\"type\": \"playerJump\", \"position\": \"%3\" }}", username, steamID, stringPosition);
        SendPostRequest(data);
    }
}