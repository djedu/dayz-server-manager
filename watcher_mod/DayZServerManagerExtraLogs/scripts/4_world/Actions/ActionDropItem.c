modded class ActionDropItem : ActionSingleUseBase{
	
	override void OnExecuteServer(ActionData action_data) {
		super.OnExecuteServer(action_data);

		if(!action_data.m_Player || !action_data.m_Target) return;//Check for NULL
		string item;
		if(m_LogConfig.ServerConfig.ShowDropStorage==0) return;//Checks if we want to see this action
			item = action_data.m_MainItem.GetType(); //Gets item name
			
		foreach(string CheckItem: m_LogConfig.CustomConfig.DropMonitorItems){
			if(CheckItem=="") return;//leaves the loop if there is bad data.
			
			if(item.Contains(CheckItem)){ //checks if array contains item
				SendLogs(action_data.m_Player,"","","Dropped "+item);
				return;
			}
		}
	}
}
