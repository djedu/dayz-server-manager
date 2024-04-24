modded class ActionOpenFence: ActionSingleUseBase {
	override void OnStartServer(ActionData action_data) {
		super.OnStartServer(action_data);
		if (!action_data.m_Player) return;
		if (m_LogConfig.ServerConfig.ShowFenceOpen==0) return;
		if (m_LogConfig.ServerConfig.SimpleLogs==0){
        SendLogs(action_data.m_Player, "", "",string.Format("opened %1",action_data.m_Target.GetObject()));
		}else{
		SendLogs(action_data.m_Player, "", "",string.Format("opened %1",action_data.m_Target.GetObject().GetType()));
		}
	}
}
