/* tslint:disable: ordered-imports*/
import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { RouterModule } from '@angular/router';
import { ReactiveFormsModule, FormsModule } from '@angular/forms';

/* Modules */
import { AppCommonModule } from '@common/app-common.module';
import { NavigationModule } from '@modules/navigation/navigation.module';
import { SystemModule } from '@modules/system/system.module';
import { PlayersModule } from '@modules/players/players.module';

/* Components */
import * as serversComponents from './components';

/* Containers */
import * as serversContainers from './containers';
import { NgxGaugeModule } from 'ngx-gauge';


@NgModule({
    imports: [
        CommonModule,
        RouterModule,
        ReactiveFormsModule,
        FormsModule,
        AppCommonModule,
        NavigationModule,
        SystemModule,
        PlayersModule,
        NgxGaugeModule,
    ],
    declarations: [...serversContainers.containers, ...serversComponents.components],
    exports: [...serversContainers.containers, ...serversComponents.components],
})
export class ServersModule {}
