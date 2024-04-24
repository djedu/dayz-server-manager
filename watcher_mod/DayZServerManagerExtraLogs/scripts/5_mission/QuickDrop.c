modded class Inventory: LayoutHolder{
    override void UpdateInterval(){
        super.UpdateInterval();

        if (GetUApi().GetInputByID(UAUIFastTransferToVicinity)){
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		    InventoryItem item;
            if (m_HandsArea.IsActive()){
                item = InventoryItem.Cast(m_HandsArea.GetFocusedItem());
                 SendLogs(player,"","","Dropped with CTRL "+string.Format("%1",item.GetType()));
                return;
            }
        }
            else{
                if (m_RightArea.IsActive()){
                item = InventoryItem.Cast(m_RightArea.GetFocusedItem());
                SendLogs(player,"","","Dropped with CTRL "+string.Format("%1",item.GetType()));
                return;
            }

        }
    }
}
