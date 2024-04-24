
modded class Fence:BaseBuildingBase{
	override void OnPartDestroyedServer(Man player, string part_name, int action_id, bool destroyed_by_connected_part = false ){
	super.OnPartDestroyedServer(player, part_name, action_id );
		if(m_LogConfig.ServerConfig.ShowBaseDamage==0)return;
		string AdminLog=""; //Allow us to modify our item name to more normal lingo.
		string message = "Destroyed Base Object "; //preface of the message.
		PlayerBase _player = PlayerBase.Cast(player);
		switch(part_name){
			case "wall_metal_up":
				AdminLog="Lower Metal Wall";
				break;
			case "wall_metal_down":
				AdminLog="Lower Metal Wall";
				break;
			case "wall_wood_down":
				AdminLog = "Lower Wooden Wall";
				break;
			case "wall_wood_up":
				AdminLog = "Upper Wooden Wall";
				break;
			case "wall_base_up":
				AdminLog = "Upper Frame";
				break;
			case "wall_base_down":
				AdminLog = "Lower Frame";
				break;
			default:
				AdminLog=part_name;
				break;
			}
	  message = message+AdminLog;
	  SendLogs(_player,"","",message);
	}

}