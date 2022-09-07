// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class StormLink : ModuleRules
{
	public StormLink(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
