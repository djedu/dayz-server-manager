/* tslint:disable: ordered-imports*/
import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { SBRouteData } from '@modules/navigation/models';

/* Module */
import { ServersModule } from './servers.module';

/* Containers */
import * as serversContainers from './containers';

/* Routes */
// eslint-disable-next-line @typescript-eslint/naming-convention
export const ROUTES: Routes = [
    {
        path: '',
        data: {
            title: 'Servers',
            breadcrumbs: [
                {
                    text: 'Servers',
                    active: true,
                },
            ],
        } as SBRouteData,
        canActivate: [],
        component: serversContainers.ServersComponent,
    },
    // {
    //     path: 'static',
    //     data: {
    //         title: 'Servers',
    //         breadcrumbs: [
    //             {
    //                 text: 'Servers',
    //                 link: '/servers',
    //             },
    //             {
    //                 text: 'Static',
    //                 active: true,
    //             },
    //         ],
    //     } as SBRouteData,
    //     canActivate: [],
    //     component: serversContainers.StaticComponent,
    // },
    // {
    //     path: 'light',
    //     data: {
    //         title: 'Servers Light - SB Admin Angular',
    //         breadcrumbs: [
    //             {
    //                 text: 'Servers',
    //                 link: '/servers',
    //             },
    //             {
    //                 text: 'Light',
    //                 active: true,
    //             },
    //         ],
    //     } as SBRouteData,
    //     canActivate: [],
    //     component: serversContainers.LightComponent,
    // },
];

@NgModule({
    imports: [ServersModule, RouterModule.forChild(ROUTES)],
    exports: [RouterModule],
})
export class ServersRoutingModule {}
