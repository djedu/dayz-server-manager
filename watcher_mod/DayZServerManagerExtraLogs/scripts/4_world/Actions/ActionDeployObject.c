
/*modded class ActionDeployObject: ActionContinuousBase {
	override void OnFinishProgressServer(ActionData action_data) {
        super.OnFinishProgressServer(action_data);

		if (!action_data.m_Player || !action_data.m_MainItem) return;
        SendLogs(action_data.m_Player, "hands", action_data.m_MainItem.GetType(), "deployed");
    }
}
*/