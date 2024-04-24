#ifdef EXTRALOGSCODELOCK

modded class ActionAttachCodeLockToFence: ActionSingleUseBase {
    override void OnExecuteServer(ActionData action_data) {
        super.OnExecuteServer(action_data);
        if (!action_data.m_Player || !action_data.m_MainItem) return;
        if(m_LogConfig..ShowLockAttach==0) return;//Do we want to see this?
        SendLogs(action_data.m_Player, "fence", action_data.m_MainItem.GetType(), "attached");
    }
}

modded class ActionAttachCodeLockToTent: ActionSingleUseBase {
    override void OnExecuteServer(ActionData action_data) {
        super.OnExecuteServer(action_data);
        if (!action_data.m_Player || !action_data.m_MainItem) return;
        if(m_LogConfig.CodeLock.ShowLockAttach==0) return;//Do we want to see this?
        SendLogs(action_data.m_Player, "tent", action_data.m_MainItem.GetType(), "attached");
    }
}
#endif