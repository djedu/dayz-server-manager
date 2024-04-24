modded class ActionAttachToConstruction: ActionSingleUseBase {
	
	override void OnStartServer(ActionData action_data) {
		super.OnStartServer(action_data);
			if(!action_data.m_Player || !action_data.m_Target) return;
			if(m_LogConfig.ServerConfig.ShowLockAttach==0) return; //checks to see if we want to see this


			string check=action_data.m_MainItem.GetType(); //Gets item name to gate logic
			string message;
			CombinationLock lock;
			
			message = action_data.m_MainItem.GetType()+" attached to gate";//sting to pass to the place log type
			
			
				if(check=="CombinationLock"){ //3Dial
					if(m_LogConfig.ServerConfig.ShowLockCode==0){
						SendLogsPlace(action_data.m_Player,message);
						return;
					}

					lock = CombinationLock.Cast(action_data.m_MainItem);//Take Item to clas CombinationLock to get COMBO
					if(!lock) return;
					SendLogsPlace(action_data.m_Player,string.Format("%1 with COMBO:%2",message,lock.GetCombination()));
					return;
				}	

				if(check=="CombinationLock4"){ //4Dial
					if(m_LogConfig.ServerConfig.ShowLockCode==0){
						SendLogsPlace(action_data.m_Player,message);
						return;
					}

					lock = CombinationLock.Cast(action_data.m_MainItem);//Take Item to clas CombinationLock to get COMBO
					if(!lock) return;
					SendLogsPlace(action_data.m_Player,string.Format("%1 with COMBO:%2",message,lock.GetCombination()));
					return;
				}
	}
}
