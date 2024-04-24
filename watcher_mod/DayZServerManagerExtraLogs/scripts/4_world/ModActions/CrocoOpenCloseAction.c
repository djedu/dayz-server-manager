#ifdef EXTRALOGSCROCO
modded class ActionOpenOpenableCroco: ActionInteractBase{
    override void OnStartServer( ActionData action_data ){
        super.OnStartServer(action_data);
        if(!action_data.m_Player || !action_data.m_Target) return;
        if(m_LogConfig.CrocoStorage.ShowCrocoStorageActions==0) return; //do we want to see this?
        if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){ //show item ID
            SendLogs(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject()), "Opened");
            return;
        }else{//Show only name
         SendLogs(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject().GetType()), "Opened");
        }
    }
}
modded class ActionCloseOpenableCroco: ActionInteractBase{
    override void OnStartServer( ActionData action_data ){
        super.OnStartServer(action_data);
        if(!action_data.m_Player || !action_data.m_Target) return;
        if(m_LogConfig.CrocoStorage.ShowCrocoStorageActions==0) return;//do we want to see this?
        if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){ //show item ID
            SendLogs(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject()), "Closed");
            return;
        }else{ //Show only name
         SendLogs(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject().GetType()), "Closed");
        }
    }
}
#endif