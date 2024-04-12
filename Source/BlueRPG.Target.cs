// Copyright NEXONGames

using UnrealBuildTool;
using System.Collections.Generic;

public class BlueRPGTarget : TargetRules
{
	public BlueRPGTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "BlueRPG" } );
	}
}
