// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NetworkStudy : ModuleRules
{
	public NetworkStudy(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"NetworkStudy",
			"NetworkStudy/Variant_Platforming",
			"NetworkStudy/Variant_Platforming/Animation",
			"NetworkStudy/Variant_Combat",
			"NetworkStudy/Variant_Combat/AI",
			"NetworkStudy/Variant_Combat/Animation",
			"NetworkStudy/Variant_Combat/Gameplay",
			"NetworkStudy/Variant_Combat/Interfaces",
			"NetworkStudy/Variant_Combat/UI",
			"NetworkStudy/Variant_SideScrolling",
			"NetworkStudy/Variant_SideScrolling/AI",
			"NetworkStudy/Variant_SideScrolling/Gameplay",
			"NetworkStudy/Variant_SideScrolling/Interfaces",
			"NetworkStudy/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
