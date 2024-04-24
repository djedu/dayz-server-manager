modded class PluginAdminLog extends PluginBase{

override void UnconStart( PlayerBase player){
        super.UnconStart(player);
        if(m_LogConfig.ServerConfig.ShowShock==0) return;
        SendLogs(player,"","","is unconscious");
    }

override void UnconStop( PlayerBase player ){	
        super.UnconStop(player);
        if(m_LogConfig.ServerConfig.ShowShock==0) return;
		if ( player.IsAlive() ) 	// Do not log uncon stop for dead players
		{   
            if(m_LogConfig.ServerConfig.LifeTimeFilter>0){
                float life = player.StatGet("playtime");//get lifetime of character
                if(!life) return;
                if(life>=m_LogConfig.ServerConfig.LifeTimeFilter){ //Gates life time at based on value in logs
		            SendLogs(player,"","","regained consciousness" );
                }
                return;
            }
            SendLogs(player,"","","regained consciousness" );
		}
	}
}

//Log NVGs
modded class ActionToggleNVG: ActionBase{
    override void Start( ActionData action_data ){
		super.Start( action_data ); 

        if (!action_data.m_Player) return;
        if (m_LogConfig.ServerConfig.ShowNVGActions==0) return;
        NVGoggles gogglesTemp;
		Clothing NVmountTemp;
		NVmountTemp = Clothing.Cast(action_data.m_Target.GetObject());
		gogglesTemp = NVGoggles.Cast(NVmountTemp.FindAttachmentBySlotName("NVG"));
        
        if (gogglesTemp.m_IsLowered==false){
            SendLogs(action_data.m_Player,"","","turned off NVGs");
        }
        if (gogglesTemp.m_IsLowered==true){
            SendLogs(action_data.m_Player,"","","turned on NVGs");
        }
        
    }
}

//log injectors
modded class ActionInjectSelf: ActionSingleUseBase{
    override void OnExecuteServer( ActionData action_data ){
        super.OnExecuteServer(action_data);
        if(!action_data.m_Player) return;
        if(m_LogConfig.ServerConfig.ShowInjectorActions==0) return;
         SendLogs(action_data.m_Player,"","","used an "+action_data.m_MainItem.GetType()+" injector");
    }	
}

//log breaking legs
modded class BrokenLegsMdfr: ModifierBase{
    override void OnActivate(PlayerBase player){
        super.OnActivate(player);
        if(!player) return;
        if(m_LogConfig.ServerConfig.ShowBrokenLegs==0) return;
        if(m_LogConfig.ServerConfig.LifeTimeFilter>0){
        float life = player.StatGet("playtime");//get lifetime of character
        if(!life) return;
        if(life>=m_LogConfig.ServerConfig.LifeTimeFilter){  //Gates life time at based on value in logs
        SendLogs(player,"","","has broken legs");
            }
            return;
        }
        SendLogs(player,"","","has broken legs");
    }
}

//log splints to yourself
modded class ActionSplintSelf: ActionContinuousBase{
    override void OnFinishProgressServer(ActionData action_data){
        super.OnFinishProgressServer(action_data);
        if(!action_data.m_Player) return;
        if(m_LogConfig.ServerConfig.ShowSplintAction==0) return;
        SendLogs(action_data.m_Player,"","","applied a Splint");
    }
}
//log splints to others
/*modded class ActionSplintTarget: ActionContinuousBase{
    override void OnFinishProgressServer(ActionData action_data){
        super.OnFinishProgressServer(action_data);
        PlayerBase ntarget = PlayerBase.Cast( action_data.m_Target.GetObject());
        if(!action_data.m_Player || !ntarget)  return;
        SendLogs(action_data.m_Player,string.Format("%1",action_data.m_Target.GetObject()),"","applied a Splint to");
    }
}*/

//log stage 1
modded class ContaminationStage1Mdfr: ModifierBase{
    override protected void OnActivate(PlayerBase player){
        super.OnActivate(player);
         if(m_LogConfig.ServerConfig.ShowGasPoison==0) return; //do we want to see this?
        if(!player) return;
        SendLogs(player,"","","has Stage 1 Gas Poisoning");
    }
}

//log stage 2
modded class ContaminationStage2Mdfr: ModifierBase{
    override protected void OnActivate(PlayerBase player){
        super.OnActivate(player);
         if(m_LogConfig.ServerConfig.ShowGasPoison==0) return; //do we want to see this?
        if(!player) return;
        SendLogs(player,"","","has Stage 2 Gas Poisoning");
    }
}

//log stage 3
modded class ContaminationStage3Mdfr: ModifierBase{
     override protected void OnActivate(PlayerBase player){
        super.OnActivate(player);
         if(m_LogConfig.ServerConfig.ShowGasPoison==0) return; //do we want to see this?
        if(!player) return;
        SendLogs(player,"","","has Stage 3 Gas Poisoning");
    }
}

//logs nade actions
modded class ActionPin: ActionSingleUseBase {
	override void OnStartServer(ActionData action_data) {
		super.OnStartServer(action_data);
        if(m_LogConfig.ServerConfig.ShowGrenadeActions==0) return;//do we want to see this?
        SendLogs(action_data.m_Player, "hands", action_data.m_MainItem.GetType(), "pinned");
	}
}

//logs nade actions
modded class ActionUnpin: ActionSingleUseBase {
	override void OnStartServer(ActionData action_data) {
		super.OnStartServer(action_data);
        if(m_LogConfig.ServerConfig.ShowGrenadeActions==0) return;//do we want to see this?
        SendLogs(action_data.m_Player, "hands", action_data.m_MainItem.GetType(), "unpinned");
	}
}

modded class ActionGiveBloodSelf: ActionContinuousBase{
     override void OnEndServer(ActionData action_data){
        super.OnEndServer(action_data);
        if(m_LogConfig.ServerConfig.ShowUseBloodBag==0) return;
        if(!action_data.m_Player) return;

        SendLogs(action_data.m_Player,"","","used a blood bag");
     }
}

modded class ActionGiveBloodTarget: ActionContinuousBase{
     override void OnEndServer(ActionData action_data){
        super.OnEndServer(action_data);
        if(m_LogConfig.ServerConfig.ShowUseBloodBag==0) return;
        if(!action_data.m_Player) return;
        PlayerBase player_target = PlayerBase.Cast(action_data.m_Target.GetObject());
        if(!player_target) return;

        SendLogs(action_data.m_Player,"","","gave a blood transfusion");
        SendLogs(player_target,"","","had received a blood transfusion");
     }
}

modded class ActionCollectBloodTarget: ActionContinuousBase{
    override void OnEndServer(ActionData action_data){
        super.OnEndServer(action_data);
        if(m_LogConfig.ServerConfig.ShowTakeBloodBag==0) return;
        if(!action_data.m_Player) return;
        PlayerBase player_target = PlayerBase.Cast(action_data.m_Target.GetObject());
        if(!player_target) return;
        SendLogs(action_data.m_Player,"","","collected blood");
        SendLogs(player_target,"","","had blood taken");
     }
}

modded class ActionCollectBloodSelf: ActionContinuousBase{
    override void OnEndServer(ActionData action_data){
        super.OnEndServer(action_data);
        if(m_LogConfig.ServerConfig.ShowTakeBloodBag==0) return;
        if(!action_data.m_Player) return;
        SendLogs(action_data.m_Player,"","","collected their blood");
     }
}
