// api.c

class CustomRestCallback : RestCallback
{
    void OnSuccess(int errorCode, string data)
    {
        PrintFormat("Request completed successfully with status code: %1", errorCode);
        PrintFormat("Response: %1", data);
    }

    void OnError(int errorCode, string errorMessage)
    {
        PrintFormat("Request failed with error code: %1", errorCode);
        PrintFormat("Error message: %1", errorMessage);
    }

    override void OnTimeout()
    {
        Print("Request timed out.");
    }
}

void SendPostRequest(string data)
{   
    // Get context
    RestContext context = GetRestApi().GetRestContext("http://localhost:8080");
    
    if (context)
    {
        // Set callback class
        CustomRestCallback callback = new CustomRestCallback();

        // Set headers and send POST request
        context.SetHeader("application/json");
        context.POST(callback, "/", data);
    } else 
    {
        Print("Failed to get context");
    }
}