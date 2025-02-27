// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Zuon : ModuleRules
{
	public Zuon(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
