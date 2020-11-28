#pragma once
#include "Blueprint/BlueprintSupport.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/Engine/Classes/Engine/EngineTypes.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
class UButton;
class UImage;
class USpinBox;
class UTextBlock;
#include "BP_UserInterface_Timer__pf907646509.generated.h"
UCLASS(config=Engine, Blueprintable, BlueprintType, meta=(ReplaceConverted="/Game/Functions/BP_UserInterface_Timer.BP_UserInterface_Timer_C", OverrideNativeName="BP_UserInterface_Timer_C"))
class UBP_UserInterface_Timer_C__pf907646509 : public UUserWidget
{
public:
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, Export, meta=(DisplayName="Button_clear", Category="BP_UserInterface_Timer", OverrideNativeName="Button_clear"))
	UButton* bpv__Button_clear__pf;
	UPROPERTY(BlueprintReadWrite, Export, meta=(DisplayName="Button_play", Category="BP_UserInterface_Timer", OverrideNativeName="Button_play"))
	UButton* bpv__Button_play__pf;
	UPROPERTY(BlueprintReadWrite, Export, meta=(DisplayName="Button_stop", Category="BP_UserInterface_Timer", OverrideNativeName="Button_stop"))
	UButton* bpv__Button_stop__pf;
	UPROPERTY(BlueprintReadWrite, Export, meta=(DisplayName="Image", Category="BP_UserInterface_Timer", OverrideNativeName="Image"))
	UImage* bpv__Image__pf;
	UPROPERTY(BlueprintReadWrite, Export, meta=(DisplayName="SpinBox_Multiplay", Category="BP_UserInterface_Timer", OverrideNativeName="SpinBox_Multiplay"))
	USpinBox* bpv__SpinBox_Multiplay__pf;
	UPROPERTY(BlueprintReadWrite, Export, meta=(DisplayName="TextBlock_clear", Category="BP_UserInterface_Timer", OverrideNativeName="TextBlock_clear"))
	UTextBlock* bpv__TextBlock_clear__pf;
	UPROPERTY(BlueprintReadWrite, Export, meta=(DisplayName="TextBlock_hours", Category="BP_UserInterface_Timer", OverrideNativeName="TextBlock_hours"))
	UTextBlock* bpv__TextBlock_hours__pf;
	UPROPERTY(BlueprintReadWrite, Export, meta=(DisplayName="TextBlock_miliseconds", Category="BP_UserInterface_Timer", OverrideNativeName="TextBlock_miliseconds"))
	UTextBlock* bpv__TextBlock_miliseconds__pf;
	UPROPERTY(BlueprintReadWrite, Export, meta=(DisplayName="TextBlock_minutes", Category="BP_UserInterface_Timer", OverrideNativeName="TextBlock_minutes"))
	UTextBlock* bpv__TextBlock_minutes__pf;
	UPROPERTY(BlueprintReadWrite, Export, meta=(DisplayName="TextBlock_play", Category="BP_UserInterface_Timer", OverrideNativeName="TextBlock_play"))
	UTextBlock* bpv__TextBlock_play__pf;
	UPROPERTY(BlueprintReadWrite, Export, meta=(DisplayName="TextBlock_seconds", Category="BP_UserInterface_Timer", OverrideNativeName="TextBlock_seconds"))
	UTextBlock* bpv__TextBlock_seconds__pf;
	UPROPERTY(BlueprintReadWrite, Export, meta=(DisplayName="TextBlock_stop", Category="BP_UserInterface_Timer", OverrideNativeName="TextBlock_stop"))
	UTextBlock* bpv__TextBlock_stop__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Hours", Category="Default", MultiLine="true", OverrideNativeName="hours"))
	int32 bpv__hours__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Minutes", Category="Default", MultiLine="true", OverrideNativeName="minutes"))
	int32 bpv__minutes__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Seconds", Category="Default", MultiLine="true", OverrideNativeName="seconds"))
	int32 bpv__seconds__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Milliseconds", Category="Default", MultiLine="true", OverrideNativeName="milliseconds"))
	int32 bpv__milliseconds__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Timer", Category="Default", MultiLine="true", OverrideNativeName="Timer"))
	FTimerHandle bpv__Timer__pf;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta=(DisplayName="Multiplay", Category="Default", MultiLine="true", OverrideNativeName="multiplay"))
	float bpv__multiplay__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_CustomEvent_Target"))
	UTextBlock* b0l__K2Node_CustomEvent_Target__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_CustomEvent_InText"))
	FText b0l__K2Node_CustomEvent_InText__pf;
	UPROPERTY(Transient, DuplicateTransient, meta=(OverrideNativeName="K2Node_ComponentBoundEvent_InValue"))
	float b0l__K2Node_ComponentBoundEvent_InValue__pf;
	UBP_UserInterface_Timer_C__pf907646509(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;
	static void __CustomDynamicClassInitialization(UDynamicClass* InDynamicClass);
	static void __StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	static void __StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad);
	void bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_0(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_1(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_2(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_3(int32 bpp__EntryPoint__pf);
	void bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_4(int32 bpp__EntryPoint__pf);
	UFUNCTION(meta=(OverrideNativeName="BndEvt__SpinBox_Multiplay_K2Node_ComponentBoundEvent_3_OnSpinBoxValueChangedEvent__DelegateSignature"))
	virtual void bpf__BndEvt__SpinBox_Multiplay_K2Node_ComponentBoundEvent_3_OnSpinBoxValueChangedEvent__DelegateSignature__pf(float bpp__InValue__pf);
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="Tick_Timer"))
	virtual void bpf__Tick_Timer__pf();
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="Set_Text"))
	virtual void bpf__Set_Text__pf(UTextBlock* bpp__Target__pf, const FText& bpp__InText__pf__const);
	UFUNCTION(BlueprintCallable, meta=(Category, OverrideNativeName="Update_Text"))
	virtual void bpf__Update_Text__pf();
	UFUNCTION(meta=(OverrideNativeName="BndEvt__Button_clear_K2Node_ComponentBoundEvent_2_OnButtonClickedEvent__DelegateSignature"))
	virtual void bpf__BndEvt__Button_clear_K2Node_ComponentBoundEvent_2_OnButtonClickedEvent__DelegateSignature__pf();
	UFUNCTION(meta=(OverrideNativeName="BndEvt__Button_stop_K2Node_ComponentBoundEvent_1_OnButtonClickedEvent__DelegateSignature"))
	virtual void bpf__BndEvt__Button_stop_K2Node_ComponentBoundEvent_1_OnButtonClickedEvent__DelegateSignature__pf();
	UFUNCTION(meta=(OverrideNativeName="BndEvt__Button_play_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature"))
	virtual void bpf__BndEvt__Button_play_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature__pf();
public:
	virtual void GetSlotNames(TArray<FName>& SlotNames) const override;
	virtual void PreSave(const class ITargetPlatform* TargetPlatform) override;
	virtual void InitializeNativeClassData() override;
};
