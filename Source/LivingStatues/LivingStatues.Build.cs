// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LivingStatues : ModuleRules
{
	public LivingStatues(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        //PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "AIModule",
            "Niagara",
            "EnhancedInput",
            "UMG",
            "FMODStudio",
            "OnlineSubsystem",
            "OnlineSubsystemUtils",
            "Networking",
            "Sockets",
            "AdvancedSessions",
            "AdvancedSteamSessions",
            "OnlineSubsystemSteam"
        });
        PrivateDependencyModuleNames.AddRange(new string[] {
            "Slate",
            "SlateCore",
            "OnlineSubsystem",
            "OnlineSubsystemUtils" // Add this here
        });
    }
}
