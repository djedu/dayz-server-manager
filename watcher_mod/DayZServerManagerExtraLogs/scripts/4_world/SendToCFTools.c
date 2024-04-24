static void SendLogs(PlayerBase player, string item, string target, string action) {
    if (GetGameLabs().IsServer()) {
        ref _LogPlayerEx logObjectPlayer = new _LogPlayerEx(player);
        action = action + " ";
        ref _Payload_ItemInteract payload = new _Payload_ItemInteract(logObjectPlayer, item, target, action);
        GetGameLabs().GetApi().ItemInteract(new _Callback(), payload);
    }
}
static void SendLogsPlace(PlayerBase player, string action){
    if (GetGameLabs().IsServer()) {
        ref _LogPlayerEx logObjectPlayer = new _LogPlayerEx(player);
        action = action + " ";
        ref _Payload_ItemPlace payload = new _Payload_ItemPlace(logObjectPlayer, action);
        GetGameLabs().GetApi().ItemPlace(new _Callback(), payload);
    }
}
static void SendLogsLog(PlayerBase player, string message){
    if (GetGameLabs().IsServer()) {
        ref _LogPlayerEx logObjectPlayer = new _LogPlayerEx(player);
        string channel = "";
        ref _Payload_PlayerChat payload = new _Payload_PlayerChat(logObjectPlayer, channel, message);
        GetGameLabs().GetApi().PlayerChat(new _Callback(), payload);
    }
}