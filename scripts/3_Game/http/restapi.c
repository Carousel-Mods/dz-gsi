class CustomRestCallback : RestCallback
{
    override void OnSuccess(string data, int dataSize)
    {
        PrintFormat("Request completed successfully. Data size: %1\nData: %2", dataSize, data);
    }

    override void OnError(int errorCode)
    {
        PrintFormat("Request failed with error code: %1", errorCode);
    }

    override void OnTimeout()
    {
        Print("Request timed out.");
    }
}

void SendPostRequest(string address, string endpoint, string data)
{   
    // Get REST context 
    RestContext context = GetRestApi().GetRestContext(address);

    if (context)
    {
        // Set callback class
        CustomRestCallback callback = new CustomRestCallback();

        // Set headers and send POST request
        context.SetHeader("application/json");
        context.POST(callback, endpoint, data);
    }
}
