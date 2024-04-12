// Copyright NEXONGames

using UnrealBuildTool;
using System.Collections.Generic;

public class BlueRPGEditorTarget : TargetRules
{
	public BlueRPGEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "BlueRPG" } );
	}
}
