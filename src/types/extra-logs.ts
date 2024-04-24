
export interface ExtraLogsEntry {
    entryType: 'VEHICLE' | 'PLAYER';
    type: string;
    name: string;
    id2?: string;
    id: number;
    position: string;
    speed: string;
    damage: number;
    category: 'GROUND' | 'AIR' | 'SEA' | 'MAN';
}

export interface ExtraLogsContainer {
    players: ExtraLogsEntry[];
    vehicles: ExtraLogsEntry[];
}
