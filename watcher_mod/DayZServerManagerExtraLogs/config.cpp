class CfgPatches
{
	class DayZServerManagerExtraLogs
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "DayZServerManager"};
	};
};
class CfgMods
{
	class DayZServerManagerExtraLogs
	{
		dir = "DayZServerManagerExtraLogs";
		name = "DayZServerManagerExtraLogs";
		author = "EJGames,TRG_SN1P3R";
		version = "0.9";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"DayZServerManagerExtraLogs/Scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"DayZServerManagerExtraLogs/Scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"DayZServerManagerExtraLogs/Scripts/5_Mission"};
			};
		};
	};
};
