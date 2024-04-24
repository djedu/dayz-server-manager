modded class MissionServer {
    override void OnInit() {
		super.OnInit();
        if (GetGame().IsServer()) {
			// GetGameLabs().AddMonitoredAction("ActionLockDoors");       
            // GetGameLabs().AddMonitoredAction("ActionUnlockDoors");
			// GetGameLabs().AddMonitoredAction("ActionTriggerRemotely");
			// GetGameLabs().AddMonitoredAction("ActionAttachExplosivesTrigger");
            
            Print("[ExtraLogs] Init Logging!");

            #ifdef EXTRALOGSMMG
                Print("[ExtraLogs] MMG Storage found! Logs are Active.");
            #endif

            #ifdef EXTRALOGSCROCO
                Print("[ExtraLogs] Croco Storage found! Logs are Active.");
            #endif

            #ifdef Trader
                Print("[ExtraLogs] Trader found! Logs are Active.");
            #endif

            #ifdef MuchCarKey
                Print("[ExtraLogs] MuchCarKey found! Logs are Active.");
            #endif
                

            GetLogConfig();
    }
}

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
        super.InvokeOnConnect(player, identity);
        if(m_LogConfig.ServerConfig.ShowConnectionInfo==0) return;
        SendLogs(player, "", "", "has connected");
	}

	override void OnClientDisconnectedEvent(PlayerIdentity identity, PlayerBase player, int logoutTime, bool authFailed) {
        super.OnClientDisconnectedEvent(identity, player, logoutTime, authFailed);
        if(m_LogConfig.ServerConfig.ShowConnectionInfo==0) return;
		SendLogs(player, "", "", "is disconnecting");
    }

	override void InvokeOnDisconnect(PlayerBase player) {
        super.InvokeOnDisconnect(player);
        if(m_LogConfig.ServerConfig.ShowConnectionInfo==0) return;
        SendLogs(player, "", "", "has disconnected");
    }		


}
