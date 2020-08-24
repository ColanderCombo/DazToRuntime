#pragma once

#include "CoreMinimal.h"
#include "DazToUnrealEnums.h"

class UMaterialInstanceConstant;
// struct for holding material override settings
struct FDUFTextureProperty
{
	FString Name;
	FString Type;
	FString Value;
	FString ObjectName;
	FString ShaderName;

	inline bool operator==(const FDUFTextureProperty& rhs) const
	{
		return Name == rhs.Name && Type == rhs.Type && Value == rhs.Value && ObjectName == rhs.ObjectName;
	}
};

class FDazToUnrealMaterials
{
public:
	static FSoftObjectPath GetBaseMaterial(FString MaterialName, TArray<FDUFTextureProperty > MaterialProperties);
	static UMaterialInstanceConstant* CreateMaterial(const FString CharacterMaterialFolder, const FString CharacterTexturesFolder, FString& MaterialName, TMap<FString, TArray<FDUFTextureProperty>> MaterialProperties, const DazCharacterType CharacterType, UMaterialInstanceConstant* ParentMaterial);
	static void SetMaterialProperty(const FString& MaterialName, const FString& PropertyName, const FString& PropertyType, const FString& PropertyValue, TMap<FString, TArray<FDUFTextureProperty>>& MaterialProperties);


	static FSoftObjectPath GetMostCommonBaseMaterial(TArray<FString> MaterialNames, TMap<FString, TArray<FDUFTextureProperty>> MaterialProperties);
	static TArray<FDUFTextureProperty> GetMostCommonProperties(TArray<FString> MaterialNames, TMap<FString, TArray<FDUFTextureProperty>> MaterialProperties);
	static FDUFTextureProperty GetMostCommonProperty(FString PropertyName, TArray<FString> MaterialNames, TMap<FString, TArray<FDUFTextureProperty>> MaterialProperties);

	static FSoftObjectPath GetBaseMaterialForShader(FString ShaderName);
	static FSoftObjectPath GetSkinMaterialForShader(FString ShaderName);
};