#ifdef CARCOVER

modded class ActionAddCarCover: ActionCoverUncoverCar {
    override void OnFinishProgressServer(ActionData action_data) {
        super.OnFinishProgressServer(action_data);
		if (!action_data.m_Player || !action_data.m_Target) return;
        if(m_LogConfig.CarCover.ShowCarCover==0) return;//Do we want to see this?
        SendLogs(action_data.m_Player, "hands", action_data.m_Target.GetObject().GetType(), "added a car cover to");
    }
}

modded class ActionRemoveCarCover : ActionCoverUncoverCar {
    override void OnFinishProgressServer(ActionData action_data) {
        super.OnFinishProgressServer(action_data); 
		if (!action_data.m_Player || !action_data.m_Target) return;
         if(m_LogConfig.CarCover.ShowCarCover==0) return;//Do we want to see this?
        CarCoverBase CarCovered;
        EntityAI CarEntity = EntityAI.Cast(action_data.m_Target.GetObject());
		Class.CastTo(CarCovered, CarEntity);
        SendLogs(action_data.m_Player, "hands", CarCovered.GetCarClass(), "removed a car cover from");
    }
}
#endif