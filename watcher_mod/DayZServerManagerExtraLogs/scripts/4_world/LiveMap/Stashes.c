modded class UndergroundStash extends ItemBase {

        void UndergroundStash() { //when the stash is created
            if(m_LogConfig.LiveMap.ShowStashs==1){ //Checks to see if we want to see this
                GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Call(this._InitGameLabs);
            }
        }

        ref _Event _registeredInstance;

        private void _InitGameLabs() { //create the map icon and track this item
            this._registeredInstance = new _Event("Stash", "treasure-chest", this);

            // if(GetGameLabs().IsServer()) {
            //      GetGameLabs().RegisterEvent(this._registeredInstance);
            // } 
        }

        void ~UndergroundStash() {
            // if(GetGameLabs().IsServer()) {
            //     if(this._registeredInstance) GetGameLabs().RemoveEvent(this._registeredInstance);
            // }
        }

        // Public API
        _Event _GetEventInstance() {
            return this._registeredInstance;
        }

        void _SetEventInstance(_Event _registeredInstance) {
            this._registeredInstance = _registeredInstance;
        }
}