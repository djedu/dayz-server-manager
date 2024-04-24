import { Manager } from '../control/manager';
import { ExtraLogsContainer } from '../types/extra-logs';
import { MetricTypeEnum } from '../types/metrics';
import * as path from 'path';
import { Paths } from '../services/paths';
import { LogLevel } from '../util/logger';
import { IStatefulService } from '../types/service';
import { inject, injectable, singleton } from 'tsyringe';
import { LoggerFactory } from './loggerfactory';
import { Metrics } from './metrics';
import { FSAPI, InjectionTokens } from '../util/apis';
import { EventBus } from '../control/event-bus';
import { InternalEventTypes } from '../types/events';

@singleton()
@injectable()
export class ExtraLogs extends IStatefulService {

    public readonly MOD_NAME = '@DayZServerManagerExtraLogs';

    public intervalTimeout: number = 1000;
    public readTimeout: number = 1000;
    private lastTickTimestamp: number = 0;
    private tickFilePath: string;

    public constructor(
        loggerFactory: LoggerFactory,
        private manager: Manager,
        private metrics: Metrics,
        private paths: Paths,
        private eventBus: EventBus,
        @inject(InjectionTokens.fs) private fs: FSAPI,
    ) {
        super(loggerFactory.createLogger('ExtraLogs'));

        this.eventBus.on(
            InternalEventTypes.INTERNAL_MOD_INSTALL,
            /* istanbul ignore next */ () => this.installMod(),
        );
        this.eventBus.on(
            InternalEventTypes.GET_INTERNAL_MODS,
            /* istanbul ignore next */ async () => this.getServerMods(),
        );
    }

    public async start(): Promise<void> {
        // ignore
    }

    public async stop(): Promise<void> {
        // ignore
    }

    private async scanTick(): Promise<void> {
        // ignore
    }

    public async processExtraLogs(report: ExtraLogsContainer): Promise<void> {
        const timestamp = new Date().valueOf();

        this.log.log(LogLevel.INFO, `Server sent extra logs: ${report?.players?.length ?? 0} players, ${report?.vehicles?.length ?? 0} vehicles`);

        // void this.metrics.pushMetricValue(
        //     MetricTypeEnum.INGAME_PLAYERS,
        //     {
        //         timestamp,
        //         value: report?.players ?? [],
        //     },
        // );

        // void this.metrics.pushMetricValue(
        //     MetricTypeEnum.INGAME_VEHICLES,
        //     {
        //         timestamp,
        //         value: report?.vehicles ?? [],
        //     },
        // );
    }

    public async installMod(): Promise<void> {

        if (this.manager.config.extraLogsEnabled === false) {
            return;
        }

        const serverPath = this.manager.getServerPath();

        const modsPath = path.join(__dirname, '../mods');
        const mods = this.fs.readdirSync(modsPath);

        for (const mod of mods) {
            const serverModPath = path.join(serverPath, mod);
            if (this.fs.existsSync(serverModPath)) {
                if (!this.paths.removeLink(serverModPath)) {
                    this.log.log(LogLevel.ERROR, `Could not remove mod ${mod} before copying new files`);
                    return;
                }
            }
        }

        this.paths.copyFromPkg(modsPath, serverPath);

    }

    public getServerMods(): string[] {

        if (this.manager.config.extraLogsEnabled === false) {
            return [];
        }

        const mods = [];
        mods.push(this.MOD_NAME);

        return mods;
    }

}
