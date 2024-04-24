modded class ActionTakeItemToHands: ActionInteractBase{
	override void OnExecuteServer( ActionData action_data ){
		super.OnExecuteServer(action_data);

		if(!action_data.m_Player) return;
		if(m_LogConfig.ServerConfig.ShowTakeStorage==0) return; //Checks if we want to show this
		
		string item=string.ToString(action_data.m_Target.GetObject()); //Gets Item name

		if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){ //If we want full item details
				foreach(string CheckItem: m_LogConfig.CustomConfig.TakeMonitorItems){
					if(CheckItem=="") return;

					if(item.Contains(CheckItem)){
						SendLogs(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject()),"Grabbed");
						return;
					}
				}
		}
		else{ //if we want basic info
			foreach(string CheckItem2: m_LogConfig.CustomConfig.TakeMonitorItems){
				if(CheckItem2=="") return;

				if(item.Contains(CheckItem2)){
					SendLogs(action_data.m_Player,"",string.Format("%1",action_data.m_Target.GetObject().GetType()),"Grabbed");
					return;
				}
			 }
		 }
	}
}