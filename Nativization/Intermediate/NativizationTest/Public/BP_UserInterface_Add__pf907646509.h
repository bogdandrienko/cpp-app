#pragma once
#include "Blueprint/BlueprintSupport.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "BP_UserInterface_Add__pf907646509.generated.h"
UCLASS(config=Engine, Blueprintable, BlueprintType, meta=(ReplaceConverted="/Game/Functions/BP_UserInterface_Add.BP_UserInterface_Add_C", OverrideNativeName="BP_UserInterface_Add_C"))
class UBP_UserInterface_Add_C__pf907646509 : public UUserWidget
{
public:
	GENERATED_BODY()
	UBP_UserInterface_Add_C__pf907646509(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;
	static void __CustomDynamicClassInitialization(UDynamicClass* InDynamicClass);
	static void __StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="FUNCTION"))
	virtual void bpf__FUNCTION__pf(float bpp__A__pf, float bpp__B__pf, /*out*/ float& bpp__RETURN__pf);
public:
	virtual void GetSlotNames(TArray<FName>& SlotNames) const override;
	virtual void PreSave(const class ITargetPlatform* TargetPlatform) override;
	virtual void InitializeNativeClassData() override;
};
