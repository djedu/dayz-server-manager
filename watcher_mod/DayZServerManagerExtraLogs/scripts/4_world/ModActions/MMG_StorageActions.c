#ifdef EXTRALOGSMMG

modded class ActionOpenCloseCrate_noLock: ActionInteractBase{
     override void OnStartServer( ActionData action_data ){
        super.OnStartServer(action_data);
        if(m_LogConfig.MMGStorage.ShowMMGStorageActions==0) return;
        if(!action_data.m_Player || !action_data.m_Target) return;
        ItemBase building = ItemBase.Cast(action_data.m_Target.GetObject());
        bool State = building.IsOpen();
        string StateAction;
        if(State==true){
            StateAction="Opened ";
        }else{
             StateAction="Closed ";
        }
        if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
            SendLogs(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data),StateAction);
        }else{
            SendLogs(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName(),StateAction);
        }
    }
}

modded class ActionOpenCloseCrate: ActionInteractBase{
    override void OnStartServer( ActionData action_data ){
        super.OnStartServer(action_data);
        if(m_LogConfig.MMGStorage.ShowMMGStorageActions==0) return;
        if(!action_data.m_Player || !action_data.m_Target) return;
        ItemBase building = ItemBase.Cast(action_data.m_Target.GetObject());
        bool State = building.IsOpen();
        string StateAction;
        if(State==true){
            StateAction="Opened ";
        }else{
             StateAction="Closed ";
        }
        if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
            SendLogs(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data),StateAction);
        }else{
            SendLogs(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName(),StateAction);
        }
    }
}

modded class ActionMMGOpen : ActionInteractBase{
    override void OnStartServer( ActionData action_data ){
        super.OnStartServer(action_data);
        if(m_LogConfig.MMGStorage.ShowMMGStorageActions==0) return;
        if(!action_data.m_Player || !action_data.m_Target) return;
        if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
            SendLogs(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data),"Opened ");
        }else{
            SendLogs(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName(),"Opened ");
        }
    }
}

modded class ActionMMGClose: ActionInteractBase{
     override void OnStartServer( ActionData action_data ){
        super.OnStartServer(action_data);
        if(m_LogConfig.MMGStorage.ShowMMGStorageActions==0) return;
        if(!action_data.m_Player || !action_data.m_Target) return;
        if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
            SendLogs(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName()+GetEnitiyIDFromObject(action_data),"Closed ");
        }else{
            SendLogs(action_data.m_Player,"",action_data.m_Target.GetObject().GetDisplayName(),"Closed ");
        }
    }
}

#endif