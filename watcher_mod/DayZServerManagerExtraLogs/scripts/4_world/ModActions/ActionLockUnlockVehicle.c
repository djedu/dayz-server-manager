#ifdef TRADER
modded class ActionUnlockVehicle: ActionLockUnlockVehicle {
	override void OnFinishProgressServer(ActionData action_data) {	
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_Target) return;
        if (m_LogConfig.ServerConfig.ShowCarActions==0) return; //Do we want to see this?
		if (m_LogConfig.ServerConfig.SimpleLogs==1){//Show only name
        SendLogs(action_data.m_Player, action_data.m_MainItem.GetType(), action_data.m_Target.GetObject().GetType(), "unlocked");
        }
        else{
        SendLogs(action_data.m_Player, action_data.m_MainItem.GetType(), string.Format("%1",action_data.m_Target.GetObject()), "unlocked");            
        }
    }
}

modded class ActionUnlockVehicleInside: ActionLockUnlockVehicle {
	override void OnFinishProgressServer(ActionData action_data) {	
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_Target) return;
        if (m_LogConfig.ServerConfig.ShowCarActions==0) return; //Do we want to see this?
		if (m_LogConfig.ServerConfig.SimpleLogs==1){//Show only name
        SendLogs(action_data.m_Player, action_data.m_MainItem.GetType(), action_data.m_Target.GetObject().GetType(), "unlocked from inside");
        }
        else{
        SendLogs(action_data.m_Player, action_data.m_MainItem.GetType(), string.Format("%1",action_data.m_Target.GetObject()), "unlocked from inside");            
        }

    }
}
modded class ActionLockVehicle: ActionLockUnlockVehicle {
	override void OnFinishProgressServer(ActionData action_data) {	
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_Target) return;
        if (m_LogConfig.ServerConfig.ShowCarActions==0) return; //Do we want to see this?
		if (m_LogConfig.ServerConfig.SimpleLogs==1){//Show only name
        SendLogs(action_data.m_Player, action_data.m_MainItem.GetType(), action_data.m_Target.GetObject().GetType(), "locked");
        }
        else{
        SendLogs(action_data.m_Player, action_data.m_MainItem.GetType(), string.Format("%1",action_data.m_Target.GetObject()), "locked");            
        }
    }
}

modded class ActionLockVehicleInside: ActionLockUnlockVehicle {
	override void OnFinishProgressServer(ActionData action_data) {	
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_Target) return;
        CarScript carScript = CarScript.Cast(action_data.m_Target.GetParent());
        SendLogs(action_data.m_Player, action_data.m_MainItem.GetType(), carScript.GetType(), "locked from inside");
    }
}
#endif