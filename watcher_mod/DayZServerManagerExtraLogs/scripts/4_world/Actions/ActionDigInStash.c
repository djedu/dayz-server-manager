modded class ActionDigInStash: ActionContinuousBase {
    override void OnExecuteServer(ActionData action_data){
      super.OnExecuteServer(action_data);
      
      if(!action_data.m_Player) return;
      if(m_LogConfig.ServerConfig.ShowBuryStash==0) return;
      if(m_LogConfig.ServerConfig.SimpleLogsStorage==0){
      SendLogsPlace(action_data.m_Player, string.Format("Buried %1 with %2 ",action_data.m_Target.GetObject(), action_data.m_MainItem.GetType()));
      }else{
      SendLogsPlace(action_data.m_Player, string.Format("Buried %1 with %2 ",action_data.m_Target.GetObject().GetType(), action_data.m_MainItem.GetType()));
      }
    }

}