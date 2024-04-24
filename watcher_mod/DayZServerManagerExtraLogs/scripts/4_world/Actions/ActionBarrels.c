modded class ActionCloseBarrel: ActionInteractBase{
    	override void OnExecuteServer( ActionData action_data ){
            super.OnExecuteServer(action_data);
            if (!action_data.m_Player) return;
            if(m_LogConfig.ServerConfig.ShowBarrelActions==0) return;//Check if log is enabled
            if(m_LogConfig.ServerConfig.SimpleLogsStorage==1){//Show only name
            SendLogs(action_data.m_Player, "", action_data.m_Target.GetObject().GetType(), "Closed");
            }else
            SendLogs(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject()), "Closed");
            }
        
}


modded class ActionOpenBarrel: ActionInteractBase{
    	override void OnExecuteServer( ActionData action_data ){
            super.OnExecuteServer(action_data);
            if (!action_data.m_Player) return;
            if(m_LogConfig.ServerConfig.ShowBarrelActions==0) return; //Check if log is enabled
            if(m_LogConfig.ServerConfig.SimpleLogsStorage==1){ //Show only name
            SendLogs(action_data.m_Player, "", action_data.m_Target.GetObject().GetType(), "Opened");
            }else
            SendLogs(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject()), "Opened");
            }        
        
}

modded class ActionCloseBarrelHoles: ActionInteractBase{
        override void OnExecuteServer( ActionData action_data ){
            super.OnExecuteServer(action_data);
            if (!action_data.m_Player) return;
            if(m_LogConfig.ServerConfig.ShowBarrelActions==0) return;//Check if log is enabled
            if(m_LogConfig.ServerConfig.SimpleLogsStorage==1){//Show only name
            SendLogs(action_data.m_Player, "", action_data.m_Target.GetObject().GetType(), "Closed");
            }else
            SendLogs(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject()), "Closed");
            }
        
}

modded class ActionOpenBarrelHoles: ActionInteractBase{
            override void OnExecuteServer( ActionData action_data ){
            super.OnExecuteServer(action_data);
            if (!action_data.m_Player) return;
            if(m_LogConfig.ServerConfig.ShowBarrelActions==0) return;//Check if log is enabled
            if(m_LogConfig.ServerConfig.SimpleLogsStorage==1){//Show only name
            SendLogs(action_data.m_Player, "", action_data.m_Target.GetObject().GetType(), "Opened");
            }else
            SendLogs(action_data.m_Player, "", string.Format("%1", action_data.m_Target.GetObject()), "Opened");
            }        
        
}