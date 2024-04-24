// Send to custom API / Log file

private RestApi m_RestApi;
private RestContext m_RestContext;

m_RestApi = CreateRestApi();
m_RestContext = m_RestApi.GetRestContext(GetDZSMApiOptions().host);
// m_RestKey = m_RestApi.GetRestContext(GetDZSMApiOptions().key);
m_RestContext.SetHeader("application/json");
m_RestApi.EnableDebug(false);

DZSMApiOptions apiOptions = GetDZSMApiOptions();


static void SendLogs(PlayerBase player, string item, string target, string action) {
    if (GetGame().IsServer()) {
        ref _LogPlayerEx logObjectPlayer = new _LogPlayerEx(player);
        action = action + " ";
        ref _Payload_ItemInteract payload = new _Payload_ItemInteract(logObjectPlayer, item, target, action);
        if (m_LogConfig.ServerConfig.SendToAPI==1) {
            // Send to API
            // GetGameLabs().GetApi().ItemInteract(new _Callback(), payload);
            m_RestContext.POST(new ServerManagerCallback(), string.Format("/extralogs?key=%1", apiOptions.key), payload);
        }
        if (m_LogConfig.ServerConfig.SendToLogFile==1) {
            // Send to log file
            Print("[DayZServerManagerExtraLogs]", payload);
        }

    }
}
static void SendLogsPlace(PlayerBase player, string action){
    if (GetGame().IsServer()) {
        ref _LogPlayerEx logObjectPlayer = new _LogPlayerEx(player);
        action = action + " ";
        ref _Payload_ItemPlace payload = new _Payload_ItemPlace(logObjectPlayer, action);
        if (m_LogConfig.ServerConfig.SendToAPI==1) {
            // Send to API
            // GetGameLabs().GetApi().ItemPlace(new _Callback(), payload);
            m_RestContext.POST(new ServerManagerCallback(), string.Format("/extralogs?key=%1", apiOptions.key), payload);
        }
        if (m_LogConfig.ServerConfig.SendToLogFile==1) {
            // Send to log file
            Print("[DayZServerManagerExtraLogs]", payload);
        }
    }
}
static void SendLogsLog(PlayerBase player, string message){
    if (GetGame().IsServer()) {
        ref _LogPlayerEx logObjectPlayer = new _LogPlayerEx(player);
        string channel = "";
        ref _Payload_PlayerChat payload = new _Payload_PlayerChat(logObjectPlayer, channel, message);
        if (m_LogConfig.ServerConfig.SendToAPI==1) {
            // Send to API
            // GetGameLabs().GetApi().PlayerChat(new _Callback(), payload);
            m_RestContext.POST(new ServerManagerCallback(), string.Format("/extralogs?key=%1", apiOptions.key), payload);
        }
        if (m_LogConfig.ServerConfig.SendToLogFile==1) {
            // Send to log file
            Print("[DayZServerManagerExtraLogs]", payload);
        }
    }
}