#include "Nativization.h"
#include "BP_FunctionLibrary_Add__pf907646509.h"
#include "GeneratedCodeHelpers.h"
#include "Runtime/CoreUObject/Public/UObject/NoExportTypes.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"


#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
PRAGMA_DISABLE_OPTIMIZATION
UBP_FunctionLibrary_Add_C__pf907646509::UBP_FunctionLibrary_Add_C__pf907646509(const FObjectInitializer& ObjectInitializer) : Super()
{
	
}
PRAGMA_ENABLE_OPTIMIZATION
void UBP_FunctionLibrary_Add_C__pf907646509::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
}
PRAGMA_DISABLE_OPTIMIZATION
void UBP_FunctionLibrary_Add_C__pf907646509::__CustomDynamicClassInitialization(UDynamicClass* InDynamicClass)
{
	ensure(0 == InDynamicClass->ReferencedConvertedFields.Num());
	ensure(0 == InDynamicClass->MiscConvertedSubobjects.Num());
	ensure(0 == InDynamicClass->DynamicBindingObjects.Num());
	ensure(0 == InDynamicClass->ComponentTemplates.Num());
	ensure(0 == InDynamicClass->Timelines.Num());
	ensure(0 == InDynamicClass->ComponentClassOverrides.Num());
	ensure(nullptr == InDynamicClass->AnimClassImplementation);
	InDynamicClass->AssembleReferenceTokenStream();
	FConvertedBlueprintsDependencies::FillUsedAssetsInDynamicClass(InDynamicClass, &__StaticDependencies_DirectlyUsedAssets);
}
PRAGMA_ENABLE_OPTIMIZATION
void UBP_FunctionLibrary_Add_C__pf907646509::bpf__Add__pf(float bpp__A__pf, float bpp__B__pf, UObject* bpp____WorldContext__pf, /*out*/ float& bpp__result__pf)
{
	float bpfv__CallFunc_Add_FloatFloat_ReturnValue__pf{};
	bpfv__CallFunc_Add_FloatFloat_ReturnValue__pf = UKismetMathLibrary::Add_FloatFloat(bpp__A__pf, bpp__B__pf);
	bpp__result__pf = bpfv__CallFunc_Add_FloatFloat_ReturnValue__pf;
}
PRAGMA_DISABLE_OPTIMIZATION
void UBP_FunctionLibrary_Add_C__pf907646509::__StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
}
PRAGMA_ENABLE_OPTIMIZATION
PRAGMA_DISABLE_OPTIMIZATION
void UBP_FunctionLibrary_Add_C__pf907646509::__StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_DirectlyUsedAssets(AssetsToLoad);
	const FCompactBlueprintDependencyData LocCompactBlueprintDependencyData[] =
	{
		{0, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.BlueprintFunctionLibrary 
		{1, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetMathLibrary 
	};
	for(const FCompactBlueprintDependencyData& CompactData : LocCompactBlueprintDependencyData)
	{
		AssetsToLoad.Add(FBlueprintDependencyData(F__NativeDependencies::Get(CompactData.ObjectRefIndex), CompactData));
	}
}
PRAGMA_ENABLE_OPTIMIZATION
struct FRegisterHelper__UBP_FunctionLibrary_Add_C__pf907646509
{
	FRegisterHelper__UBP_FunctionLibrary_Add_C__pf907646509()
	{
		FConvertedBlueprintsDependencies::Get().RegisterConvertedClass(TEXT("/Game/Functions/BP_FunctionLibrary_Add"), &UBP_FunctionLibrary_Add_C__pf907646509::__StaticDependenciesAssets);
	}
	static FRegisterHelper__UBP_FunctionLibrary_Add_C__pf907646509 Instance;
};
FRegisterHelper__UBP_FunctionLibrary_Add_C__pf907646509 FRegisterHelper__UBP_FunctionLibrary_Add_C__pf907646509::Instance;
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
