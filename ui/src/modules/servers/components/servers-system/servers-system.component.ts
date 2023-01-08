import { ChangeDetectionStrategy, Component, OnInit } from '@angular/core';
import { AppCommonService } from '@common/services';

@Component({
    selector: 'sb-servers-system',
    changeDetection: ChangeDetectionStrategy.OnPush,
    templateUrl: './servers-system.component.html',
    styleUrls: ['servers-system.component.scss'],
})
export class DashboardSystemComponent implements OnInit {

    public constructor(
        public commonService: AppCommonService,
    ) {}

    public ngOnInit(): void {
        // ignore
    }

}
