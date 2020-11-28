#pragma once
#include "Blueprint/BlueprintSupport.h"
#include "Runtime/Engine/Classes/Kismet/BlueprintFunctionLibrary.h"
class UObject;
#include "BP_FunctionLibrary_Add__pf907646509.generated.h"
UCLASS(config=Engine, meta=(ReplaceConverted="/Game/Functions/BP_FunctionLibrary_Add.BP_FunctionLibrary_Add_C", OverrideNativeName="BP_FunctionLibrary_Add_C"))
class UBP_FunctionLibrary_Add_C__pf907646509 : public UBlueprintFunctionLibrary
{
public:
	GENERATED_BODY()
	UBP_FunctionLibrary_Add_C__pf907646509(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;
	static void __CustomDynamicClassInitialization(UDynamicClass* InDynamicClass);
	static void __StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	UFUNCTION(BlueprintCallable, meta=(WorldContext="__WorldContext", Category, OverrideNativeName="Add"))
	static void bpf__Add__pf(float bpp__A__pf, float bpp__B__pf, UObject* bpp____WorldContext__pf, /*out*/ float& bpp__result__pf);
public:
};
