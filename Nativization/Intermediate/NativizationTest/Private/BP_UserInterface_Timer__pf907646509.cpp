#include "Nativization.h"
#include "BP_UserInterface_Timer__pf907646509.h"
#include "GeneratedCodeHelpers.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Runtime/UMG/Public/Components/CanvasPanel.h"
#include "Runtime/UMG/Public/Components/CanvasPanelSlot.h"
#include "Runtime/UMG/Public/Components/Image.h"
#include "Runtime/UMG/Public/Components/HorizontalBox.h"
#include "Runtime/UMG/Public/Components/HorizontalBoxSlot.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/Engine/Classes/Engine/Font.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/ButtonSlot.h"
#include "Runtime/UMG/Public/Components/SpinBox.h"
#include "Runtime/Engine/Classes/Engine/ComponentDelegateBinding.h"
#include "Runtime/UMG/Public/Components/TextWidgetTypes.h"
#include "Runtime/UMG/Public/Components/Widget.h"
#include "Runtime/UMG/Public/Components/Visual.h"
#include "Runtime/CoreUObject/Public/UObject/NoExportTypes.h"
#include "Runtime/UMG/Public/Components/SlateWrapperTypes.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/EngineBaseTypes.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/AssetUserData.h"
#include "Runtime/Engine/Public/ComponentInstanceDataCache.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraphPin.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_AssetUserData.h"
#include "Runtime/Engine/Classes/GameFramework/DamageType.h"
#include "Runtime/Engine/Classes/Engine/NetSerialization.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterial.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsSettingsEnums.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterialPropertyBase.h"
#include "Runtime/Engine/Classes/Vehicles/TireType.h"
#include "Runtime/Engine/Classes/Engine/DataAsset.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/GameFramework/PhysicsVolume.h"
#include "Runtime/Engine/Classes/GameFramework/Volume.h"
#include "Runtime/Engine/Classes/Engine/Brush.h"
#include "Runtime/Engine/Classes/Components/BrushComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetup.h"
#include "Runtime/Engine/Classes/PhysicsEngine/AggregateGeom.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphereElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ShapeElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BoxElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/SphylElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConvexElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/TaperedCapsuleElem.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodySetupEnums.h"
#include "Runtime/Engine/Classes/PhysicsEngine/BodyInstance.h"
#include "Runtime/Engine/Classes/Engine/BrushBuilder.h"
#include "Runtime/Engine/Classes/Materials/MaterialInterface.h"
#include "Runtime/Engine/Classes/PhysicalMaterials/PhysicalMaterialMask.h"
#include "Runtime/Engine/Classes/Engine/Texture.h"
#include "Runtime/Engine/Classes/EditorFramework/AssetImportData.h"
#include "Runtime/Engine/Classes/Engine/StreamableRenderAsset.h"
#include "Runtime/Engine/Classes/Engine/TextureDefines.h"
#include "Runtime/Engine/Classes/Materials/MaterialLayersFunctions.h"
#include "Runtime/Engine/Classes/Materials/MaterialFunctionInterface.h"
#include "Runtime/Engine/Classes/EditorFramework/ThumbnailInfo.h"
#include "Runtime/Engine/Classes/Materials/Material.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpression.h"
#include "Runtime/Engine/Classes/Materials/MaterialFunction.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpressionComment.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpressionMaterialFunctionCall.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpressionFunctionInput.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpressionFunctionOutput.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraphNode.h"
#include "Runtime/Engine/Public/MaterialShared.h"
#include "Runtime/Engine/Classes/Engine/BlendableInterface.h"
#include "Runtime/Engine/Public/MaterialCachedData.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/Engine/Classes/Engine/FontImportOptions.h"
#include "Runtime/SlateCore/Public/Fonts/CompositeFont.h"
#include "Runtime/SlateCore/Public/Fonts/FontBulkData.h"
#include "Runtime/SlateCore/Public/Fonts/FontProviderInterface.h"
#include "Runtime/Engine/Classes/VT/RuntimeVirtualTexture.h"
#include "Runtime/Engine/Public/VT/RuntimeVirtualTextureEnum.h"
#include "Runtime/Engine/Classes/VT/RuntimeVirtualTextureStreamingProxy.h"
#include "Runtime/Engine/Classes/VT/VirtualTextureBuildSettings.h"
#include "Runtime/Engine/Classes/Curves/CurveLinearColor.h"
#include "Runtime/Engine/Classes/Curves/CurveBase.h"
#include "Runtime/Engine/Classes/Curves/RichCurve.h"
#include "Runtime/Engine/Classes/Curves/RealCurve.h"
#include "Runtime/Engine/Classes/Curves/IndexedCurve.h"
#include "Runtime/Engine/Classes/Curves/KeyHandle.h"
#include "Runtime/Engine/Classes/Curves/CurveLinearColorAtlas.h"
#include "Runtime/Engine/Classes/Materials/MaterialParameterCollection.h"
#include "Runtime/Landscape/Classes/LandscapeGrassType.h"
#include "Runtime/Engine/Classes/Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Engine/StaticMeshSocket.h"
#include "Runtime/StaticMeshDescription/Public/StaticMeshDescription.h"
#include "Runtime/MeshDescription/Public/MeshDescriptionBase.h"
#include "Runtime/MeshDescription/Public/MeshTypes.h"
#include "Runtime/Engine/Public/PerPlatformProperties.h"
#include "Runtime/Engine/Public/Components.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavCollisionBase.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_CollisionDataProvider.h"
#include "Runtime/Engine/Classes/Engine/MeshMerging.h"
#include "Runtime/Engine/Classes/Engine/SubsurfaceProfile.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstance.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceBasePropertyOverrides.h"
#include "Runtime/Engine/Public/StaticParameterSet.h"
#include "Runtime/Engine/Classes/GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/GameFramework/PawnMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/NavMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/MovementComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationTypes.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerState.h"
#include "Runtime/Engine/Classes/GameFramework/Info.h"
#include "Runtime/Engine/Classes/Components/BillboardComponent.h"
#include "Runtime/Engine/Classes/GameFramework/LocalMessage.h"
#include "Runtime/Engine/Classes/GameFramework/OnlineReplStructs.h"
#include "Runtime/CoreUObject/Public/UObject/CoreOnline.h"
#include "Runtime/Engine/Classes/GameFramework/EngineMessage.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAgentInterface.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardData.h"
#include "Runtime/AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/BrainComponent.h"
#include "Runtime/AIModule/Classes/AIResourceInterface.h"
#include "Runtime/GameplayTasks/Classes/GameplayTaskResource.h"
#include "Runtime/AIModule/Classes/Navigation/PathFollowingComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationData.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationDataInterface.h"
#include "Runtime/Engine/Classes/AI/Navigation/PathFollowingAgentInterface.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTCompositeNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTNode.h"
#include "Runtime/GameplayTasks/Classes/GameplayTaskOwnerInterface.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTTaskNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTService.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTAuxiliaryNode.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BTDecorator.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeTypes.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardAssetProvider.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraph.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraphSchema.h"
#include "Runtime/Engine/Classes/Engine/Blueprint.h"
#include "Runtime/GameplayTasks/Classes/GameplayTask.h"
#include "Runtime/NavigationSystem/Public/NavFilters/NavigationQueryFilter.h"
#include "Runtime/NavigationSystem/Public/NavAreas/NavArea.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavAreaBase.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "Runtime/AIModule/Classes/Perception/AISense.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionTypes.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionSystem.h"
#include "Runtime/AIModule/Classes/AISubsystem.h"
#include "Runtime/AIModule/Classes/AISystem.h"
#include "Runtime/Engine/Classes/AI/AISystemBase.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeManager.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Runtime/GameplayTags/Classes/GameplayTagContainer.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryManager.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQuery.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryOption.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryGenerator.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryNode.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/Items/EnvQueryItemType.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryTest.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryTypes.h"
#include "Runtime/AIModule/Classes/DataProviders/AIDataProvider.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryInstanceBlueprintWrapper.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EQSQueryResultSourceInterface.h"
#include "Runtime/AIModule/Classes/EnvironmentQuery/EnvQueryContext.h"
#include "Runtime/AIModule/Classes/Blueprint/AIAsyncTaskBlueprintProxy.h"
#include "Runtime/AIModule/Classes/AITypes.h"
#include "Runtime/AIModule/Classes/HotSpots/AIHotSpotManager.h"
#include "Runtime/AIModule/Classes/Navigation/NavLocalGridManager.h"
#include "Runtime/AIModule/Classes/Perception/AISenseEvent.h"
#include "Runtime/AIModule/Classes/Perception/AISenseConfig.h"
#include "Runtime/AIModule/Classes/Actions/PawnActionsComponent.h"
#include "Runtime/AIModule/Classes/Actions/PawnAction.h"
#include "Runtime/GameplayTasks/Classes/GameplayTasksComponent.h"
#include "Runtime/AIModule/Classes/Perception/AIPerceptionListenerInterface.h"
#include "Runtime/AIModule/Classes/GenericTeamAgentInterface.h"
#include "Runtime/Engine/Public/VisualLogger/VisualLoggerDebugSnapshotInterface.h"
#include "Runtime/Engine/Public/SceneTypes.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavRelevantInterface.h"
#include "Runtime/Engine/Public/HitProxies.h"
#include "Runtime/Engine/Classes/Components/ChildActorComponent.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerInput.h"
#include "Runtime/Engine/Classes/Matinee/MatineeActor.h"
#include "Runtime/Engine/Classes/Matinee/InterpData.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroup.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrack.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInst.h"
#include "Runtime/Engine/Classes/Engine/InterpCurveEdSetup.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroupDirector.h"
#include "Runtime/Engine/Classes/Matinee/InterpFilter.h"
#include "Runtime/Engine/Classes/Matinee/InterpGroupInst.h"
#include "Runtime/Engine/Classes/GameFramework/Character.h"
#include "Runtime/Engine/Classes/Animation/AnimMontage.h"
#include "Runtime/Engine/Classes/Animation/AnimCompositeBase.h"
#include "Runtime/Engine/Classes/Animation/AnimSequenceBase.h"
#include "Runtime/Engine/Classes/Animation/AnimationAsset.h"
#include "Runtime/Engine/Classes/Animation/Skeleton.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshSocket.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
#include "Runtime/Engine/Classes/Components/SkinnedMeshComponent.h"
#include "Runtime/Engine/Classes/Components/MeshComponent.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMesh.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshLODSettings.h"
#include "Runtime/Engine/Classes/Animation/AnimSequence.h"
#include "Runtime/Engine/Public/Animation/AnimTypes.h"
#include "Runtime/Engine/Classes/Animation/AnimBoneCompressionSettings.h"
#include "Runtime/Engine/Classes/Animation/AnimBoneCompressionCodec.h"
#include "Runtime/Engine/Classes/Animation/AnimCurveCompressionSettings.h"
#include "Runtime/Engine/Classes/Animation/AnimCurveCompressionCodec.h"
#include "Runtime/Engine/Classes/Animation/AnimCurveCompressionCodec_CompressedRichCurve.h"
#include "Runtime/Engine/Classes/Animation/AnimEnums.h"
#include "Runtime/Engine/Public/SkeletalMeshReductionSettings.h"
#include "Runtime/Engine/Public/BoneContainer.h"
#include "Runtime/Engine/Classes/Engine/BlueprintCore.h"
#include "Runtime/Engine/Classes/Engine/SimpleConstructionScript.h"
#include "Runtime/Engine/Classes/Engine/SCS_Node.h"
#include "Runtime/Engine/Classes/Engine/BlueprintGeneratedClass.h"
#include "Runtime/Engine/Classes/Engine/TimelineTemplate.h"
#include "Runtime/Engine/Classes/Components/TimelineComponent.h"
#include "Runtime/Engine/Classes/Curves/CurveFloat.h"
#include "Runtime/Engine/Classes/Curves/CurveVector.h"
#include "Runtime/Engine/Classes/Engine/InheritableComponentHandler.h"
#include "Runtime/CoreUObject/Public/UObject/CoreNetTypes.h"
#include "Runtime/Engine/Classes/Engine/Breakpoint.h"
#include "Runtime/Engine/Public/Blueprint/BlueprintExtension.h"
#include "Runtime/Engine/Public/Animation/NodeMappingContainer.h"
#include "Runtime/Engine/Public/Animation/NodeMappingProviderInterface.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsAsset.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicalAnimationComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsConstraintTemplate.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConstraintInstance.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConstraintTypes.h"
#include "Runtime/Engine/Classes/PhysicsEngine/ConstraintDrives.h"
#include "Runtime/Engine/Classes/Interfaces/Interface_PreviewMeshProvider.h"
#include "Runtime/Engine/Classes/Animation/MorphTarget.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "Runtime/Engine/Public/Animation/PoseSnapshot.h"
#include "Runtime/Engine/Public/Animation/AnimNotifyQueue.h"
#include "Runtime/Engine/Classes/Animation/AnimLinkableElement.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotify.h"
#include "Runtime/Engine/Classes/Animation/AnimNotifies/AnimNotifyState.h"
#include "Runtime/ClothingSystemRuntimeInterface/Public/ClothingAssetBase.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshSampling.h"
#include "Runtime/Engine/Public/Animation/SkinWeightProfile.h"
#include "Runtime/Engine/Classes/Engine/SkeletalMeshEditorData.h"
#include "Runtime/Engine/Classes/Animation/PreviewAssetAttachComponent.h"
#include "Runtime/ClothingSystemRuntimeInterface/Public/ClothingSimulationInteractor.h"
#include "Runtime/Engine/Classes/Animation/AnimBlueprintGeneratedClass.h"
#include "Runtime/Engine/Classes/Engine/DynamicBlueprintBinding.h"
#include "Runtime/Engine/Classes/Animation/AnimStateMachineTypes.h"
#include "Runtime/Engine/Public/AlphaBlend.h"
#include "Runtime/Engine/Classes/Animation/BlendProfile.h"
#include "Runtime/Engine/Classes/Animation/AnimClassInterface.h"
#include "Runtime/Engine/Classes/Animation/AnimNodeBase.h"
#include "Runtime/Engine/Public/SingleAnimationPlayData.h"
#include "Runtime/ClothingSystemRuntimeInterface/Public/ClothingSimulationFactory.h"
#include "Runtime/Engine/Classes/Animation/AnimBlueprint.h"
#include "Runtime/Engine/Classes/Engine/PoseWatch.h"
#include "Runtime/Engine/Classes/Animation/SmartName.h"
#include "Runtime/Engine/Classes/Animation/Rig.h"
#include "Runtime/Engine/Classes/Animation/AnimMetaData.h"
#include "Runtime/Engine/Classes/Animation/AssetMappingTable.h"
#include "Runtime/Engine/Classes/Animation/PoseAsset.h"
#include "Runtime/Engine/Public/Animation/AnimCurveTypes.h"
#include "Runtime/Engine/Classes/Animation/TimeStretchCurve.h"
#include "Runtime/Engine/Classes/GameFramework/RootMotionSource.h"
#include "Runtime/Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationAvoidanceTypes.h"
#include "Runtime/Engine/Public/AI/RVOAvoidanceInterface.h"
#include "Runtime/Engine/Classes/Interfaces/NetworkPredictionInterface.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/Components/ShapeComponent.h"
#include "Runtime/Engine/Classes/Components/ArrowComponent.h"
#include "Runtime/Engine/Classes/Camera/PlayerCameraManager.h"
#include "Runtime/UMG/Public/Animation/WidgetAnimation.h"
#include "Runtime/MovieScene/Public/MovieSceneSequence.h"
#include "Runtime/MovieScene/Public/MovieSceneSignedObject.h"
#include "Runtime/MovieScene/Public/MovieSceneObjectBindingID.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationTemplate.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneTrackIdentifier.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationTrack.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSegment.h"
#include "Runtime/MovieScene/Public/MovieSceneTrack.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvalTemplate.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneTrackImplementation.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationField.h"
#include "Runtime/MovieScene/Public/MovieSceneFrameMigration.h"
#include "Runtime/MovieScene/Public/MovieSceneSequenceID.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneEvaluationKey.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSequenceHierarchy.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSequenceTransform.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneTimeTransform.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneTimeWarping.h"
#include "Runtime/MovieScene/Public/Evaluation/MovieSceneSequenceInstanceData.h"
#include "Runtime/MovieScene/Public/MovieSceneSection.h"
#include "Runtime/MovieScene/Public/MovieScene.h"
#include "Runtime/MovieScene/Public/MovieSceneSpawnable.h"
#include "Runtime/MovieScene/Public/MovieScenePossessable.h"
#include "Runtime/MovieScene/Public/MovieSceneBinding.h"
#include "Runtime/MovieScene/Public/MovieSceneFwd.h"
#include "Runtime/MovieScene/Public/MovieSceneFolder.h"
#include "Runtime/MovieScene/Public/Evaluation/Blending/MovieSceneBlendType.h"
#include "Runtime/MovieScene/Public/Generators/MovieSceneEasingFunction.h"
#include "Runtime/MovieScene/Public/Generators/MovieSceneEasingCurves.h"
#include "Runtime/UMG/Public/Animation/WidgetAnimationBinding.h"
#include "Runtime/SlateCore/Public/Layout/Geometry.h"
#include "Runtime/SlateCore/Public/Layout/Margin.h"
#include "Runtime/SlateCore/Public/Styling/SlateColor.h"
#include "Runtime/Slate/Public/Widgets/Layout/Anchors.h"
#include "Runtime/Engine/Classes/Sound/SoundBase.h"
#include "Runtime/Engine/Classes/Sound/SoundClass.h"
#include "Runtime/Engine/Classes/Sound/AudioOutputTarget.h"
#include "Runtime/Engine/Classes/Sound/SoundWaveLoadingBehavior.h"
#include "Runtime/Engine/Classes/Sound/SoundSubmix.h"
#include "Runtime/Engine/Classes/Sound/SoundSubmixSend.h"
#include "Runtime/Engine/Classes/Sound/SoundWave.h"
#include "Runtime/AudioPlatformConfiguration/Public/AudioCompressionSettings.h"
#include "Runtime/Engine/Classes/Sound/SoundGroups.h"
#include "Runtime/Engine/Classes/Engine/CurveTable.h"
#include "Runtime/Engine/Classes/Sound/SoundEffectSubmix.h"
#include "Runtime/Engine/Classes/Sound/SoundEffectPreset.h"
#include "Runtime/AudioExtensions/Public/ISoundfieldFormat.h"
#include "Runtime/Engine/Classes/Sound/SoundMix.h"
#include "Runtime/AudioExtensions/Public/IAudioExtensionPlugin.h"
#include "Runtime/Engine/Classes/Sound/SoundConcurrency.h"
#include "Runtime/Engine/Classes/Sound/SoundAttenuation.h"
#include "Runtime/Engine/Classes/Engine/Attenuation.h"
#include "Runtime/Engine/Classes/Sound/SoundEffectSource.h"
#include "Runtime/Engine/Classes/Sound/SoundSourceBusSend.h"
#include "Runtime/Engine/Classes/Sound/SoundSourceBus.h"
#include "Runtime/UMG/Public/Animation/UMGSequencePlayer.h"
#include "Runtime/SlateCore/Public/Input/Events.h"
#include "Runtime/UMG/Public/Blueprint/DragDropOperation.h"
#include "Runtime/UMG/Public/Components/NamedSlotInterface.h"
#include "Runtime/Engine/Classes/Haptics/HapticFeedbackEffect_Base.h"
#include "Runtime/Engine/Classes/Engine/LatentActionManager.h"
#include "Runtime/Engine/Classes/GameFramework/ForceFeedbackEffect.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawn.h"
#include "Runtime/Engine/Classes/GameFramework/DefaultPawn.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/TextureStreamingTypes.h"
#include "Runtime/Engine/Classes/GameFramework/FloatingPawnMovement.h"
#include "Runtime/Engine/Classes/GameFramework/SpectatorPawnMovement.h"
#include "Runtime/Engine/Classes/GameFramework/HUD.h"
#include "Runtime/Engine/Classes/Engine/Canvas.h"
#include "Runtime/Engine/Classes/Debug/ReporterGraph.h"
#include "Runtime/Engine/Classes/Debug/ReporterBase.h"
#include "Runtime/Engine/Classes/GameFramework/DebugTextInfo.h"
#include "Runtime/Engine/Classes/Camera/CameraShakeSourceComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraShake.h"
#include "Runtime/Engine/Classes/Camera/CameraTypes.h"
#include "Runtime/Engine/Classes/Engine/Scene.h"
#include "Runtime/Engine/Classes/Engine/TextureCube.h"
#include "Runtime/Engine/Classes/Camera/CameraAnim.h"
#include "Runtime/Engine/Classes/Camera/CameraAnimInst.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackMove.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInstMove.h"
#include "Runtime/Engine/Classes/Camera/CameraModifier.h"
#include "Runtime/Engine/Classes/Particles/EmitterCameraLensEffectBase.h"
#include "Runtime/Engine/Classes/Particles/Emitter.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystem.h"
#include "Runtime/Engine/Classes/Particles/ParticleEmitter.h"
#include "Runtime/Engine/Public/ParticleHelper.h"
#include "Runtime/Engine/Classes/Particles/ParticleLODLevel.h"
#include "Runtime/Engine/Classes/Particles/ParticleModuleRequired.h"
#include "Runtime/Engine/Classes/Particles/ParticleModule.h"
#include "Runtime/Engine/Classes/Particles/ParticleSpriteEmitter.h"
#include "Runtime/Engine/Classes/Distributions/DistributionFloat.h"
#include "Runtime/Engine/Classes/Distributions/Distribution.h"
#include "Runtime/Engine/Classes/Particles/SubUVAnimation.h"
#include "Runtime/Engine/Classes/Particles/TypeData/ParticleModuleTypeDataBase.h"
#include "Runtime/Engine/Classes/Particles/Spawn/ParticleModuleSpawn.h"
#include "Runtime/Engine/Classes/Particles/Spawn/ParticleModuleSpawnBase.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventGenerator.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventBase.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventSendToGame.h"
#include "Runtime/Engine/Classes/Particles/Orbit/ParticleModuleOrbit.h"
#include "Runtime/Engine/Classes/Particles/Orbit/ParticleModuleOrbitBase.h"
#include "Runtime/Engine/Classes/Distributions/DistributionVector.h"
#include "Runtime/Engine/Classes/Particles/Event/ParticleModuleEventReceiverBase.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemReplay.h"
#include "Runtime/Engine/Classes/Camera/CameraModifier_CameraShake.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/Engine/Classes/GameFramework/TouchInterface.h"
#include "Runtime/Engine/Classes/Engine/Player.h"
#include "Runtime/Engine/Classes/Matinee/InterpTrackInstDirector.h"
#include "Runtime/Engine/Classes/GameFramework/CheatManager.h"
#include "Runtime/Engine/Classes/Engine/DebugCameraController.h"
#include "Runtime/Engine/Classes/Components/DrawFrustumComponent.h"
#include "Runtime/Engine/Classes/Engine/NetConnection.h"
#include "Runtime/Engine/Classes/Engine/ChildConnection.h"
#include "Runtime/Engine/Classes/Engine/PackageMapClient.h"
#include "Runtime/Engine/Classes/Engine/NetDriver.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/WorldSettings.h"
#include "Runtime/Engine/Classes/AI/NavigationSystemConfig.h"
#include "Runtime/Engine/Classes/GameFramework/DefaultPhysicsVolume.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsCollisionHandler.h"
#include "Runtime/Engine/Classes/GameFramework/GameModeBase.h"
#include "Runtime/Engine/Classes/GameFramework/GameSession.h"
#include "Runtime/Engine/Classes/GameFramework/GameStateBase.h"
#include "Runtime/Engine/Classes/Engine/ServerStatReplicator.h"
#include "Runtime/Engine/Classes/GameFramework/GameNetworkManager.h"
#include "Runtime/Engine/Classes/Sound/ReverbSettings.h"
#include "Runtime/Engine/Classes/Sound/ReverbEffect.h"
#include "Runtime/Engine/Classes/Sound/AudioVolume.h"
#include "Runtime/Engine/Classes/Engine/BookmarkBase.h"
#include "DmgTypeBP_Environmental__pf1001828891.h"
#include "Runtime/Engine/Classes/Engine/BookMark.h"
#include "Runtime/Engine/Classes/Engine/MaterialMerging.h"
#include "Runtime/Engine/Classes/Engine/Level.h"
#include "Runtime/Engine/Classes/Components/ModelComponent.h"
#include "Runtime/Engine/Classes/Engine/LevelActorContainer.h"
#include "Runtime/Engine/Classes/Engine/LevelScriptActor.h"
#include "Runtime/Engine/Classes/Engine/NavigationObjectBase.h"
#include "Runtime/Engine/Classes/AI/Navigation/NavigationDataChunk.h"
#include "Runtime/Engine/Classes/Engine/MapBuildDataRegistry.h"
#include "Runtime/Engine/Classes/Engine/LevelScriptBlueprint.h"
#include "Runtime/Engine/Classes/Components/LineBatchComponent.h"
#include "Runtime/Engine/Classes/Engine/LevelStreaming.h"
#include "Runtime/Engine/Classes/Engine/LevelStreamingVolume.h"
#include "Runtime/Engine/Classes/Engine/DemoNetDriver.h"
#include "Runtime/Engine/Classes/Particles/ParticleEventManager.h"
#include "Runtime/Engine/Classes/AI/NavigationSystemBase.h"
#include "Runtime/Engine/Classes/AI/Navigation/AvoidanceManager.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
#include "Runtime/Engine/Classes/Engine/LocalPlayer.h"
#include "Runtime/Engine/Classes/Engine/GameViewportClient.h"
#include "Runtime/Engine/Classes/Engine/ScriptViewportClient.h"
#include "Runtime/Engine/Classes/Engine/Console.h"
#include "Runtime/Engine/Classes/Engine/DebugDisplayProperty.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Engine/Classes/GameFramework/GameUserSettings.h"
#include "Runtime/Engine/Classes/Engine/AssetManager.h"
#include "Runtime/Engine/Classes/Engine/EngineCustomTimeStep.h"
#include "Runtime/Engine/Classes/Engine/TimecodeProvider.h"
#include "Runtime/Engine/Classes/GameFramework/OnlineSession.h"
#include "Runtime/Engine/Classes/Materials/MaterialParameterCollectionInstance.h"
#include "Runtime/Engine/Classes/Engine/WorldComposition.h"
#include "Runtime/Engine/Classes/Particles/WorldPSCPool.h"
#include "Runtime/Engine/Classes/Layers/Layer.h"
#include "Runtime/Engine/Classes/Engine/Channel.h"
#include "Runtime/Engine/Classes/Engine/ReplicationDriver.h"
#include "Runtime/UMG/Public/Slate/WidgetTransform.h"
#include "Runtime/SlateCore/Public/Types/SlateEnums.h"
#include "Runtime/SlateCore/Public/Input/NavigationReply.h"
#include "Runtime/SlateCore/Public/Layout/Clipping.h"
#include "Runtime/SlateCore/Public/Styling/SlateBrush.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"
#include "Runtime/UMG/Public/Components/PanelSlot.h"
#include "Runtime/SlateCore/Public/Styling/SlateTypes.h"
#include "Runtime/UMG/Public/Blueprint/WidgetNavigation.h"
#include "Runtime/SlateCore/Public/Layout/FlowDirection.h"
#include "Runtime/UMG/Public/Binding/PropertyBinding.h"
#include "Runtime/UMG/Public/Binding/DynamicPropertyPath.h"
#include "Runtime/PropertyPath/Public/PropertyPathHelpers.h"
#include "Runtime/Slate/Public/Framework/Text/TextLayout.h"
#include "Runtime/SlateCore/Public/Fonts/FontCache.h"
#include "Runtime/SlateCore/Public/Fonts/SlateFontInfo.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Classes/Kismet/BlueprintFunctionLibrary.h"
#include "Runtime/Engine/Classes/Engine/CollisionProfile.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Runtime/Engine/Classes/Kismet/KismetTextLibrary.h"
#include "Runtime/UMG/Public/Components/ContentWidget.h"
#include "Runtime/SlateCore/Public/Styling/SlateWidgetStyle.h"
#include "Runtime/SlateCore/Public/Sound/SlateSound.h"
#include "Runtime/SlateCore/Public/Styling/SlateWidgetStyleAsset.h"
#include "Runtime/SlateCore/Public/Styling/SlateWidgetStyleContainerBase.h"
#include "Runtime/SlateCore/Public/Styling/SlateWidgetStyleContainerInterface.h"
#include "Runtime/Engine/Classes/Engine/Texture2DDynamic.h"
#include "Runtime/Engine/Public/Slate/SlateTextureAtlasInterface.h"
#include "Runtime/Engine/Classes/Slate/SlateBrushAsset.h"


#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
PRAGMA_DISABLE_OPTIMIZATION
UBP_UserInterface_Timer_C__pf907646509::UBP_UserInterface_Timer_C__pf907646509(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
	bpv__Button_clear__pf = nullptr;
	bpv__Button_play__pf = nullptr;
	bpv__Button_stop__pf = nullptr;
	bpv__Image__pf = nullptr;
	bpv__SpinBox_Multiplay__pf = nullptr;
	bpv__TextBlock_clear__pf = nullptr;
	bpv__TextBlock_hours__pf = nullptr;
	bpv__TextBlock_miliseconds__pf = nullptr;
	bpv__TextBlock_minutes__pf = nullptr;
	bpv__TextBlock_play__pf = nullptr;
	bpv__TextBlock_seconds__pf = nullptr;
	bpv__TextBlock_stop__pf = nullptr;
	bpv__hours__pf = 0;
	bpv__minutes__pf = 0;
	bpv__seconds__pf = 0;
	bpv__milliseconds__pf = 0;
	bpv__multiplay__pf = 0.000000f;
	bHasScriptImplementedTick = false;
	bHasScriptImplementedPaint = false;
}
PRAGMA_ENABLE_OPTIMIZATION
void UBP_UserInterface_Timer_C__pf907646509::PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph)
{
	Super::PostLoadSubobjects(OuterInstanceGraph);
}
PRAGMA_DISABLE_OPTIMIZATION
void UBP_UserInterface_Timer_C__pf907646509::__CustomDynamicClassInitialization(UDynamicClass* InDynamicClass)
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
	auto __Local__0 = NewObject<UComponentDelegateBinding>(InDynamicClass, UComponentDelegateBinding::StaticClass(), TEXT("ComponentDelegateBinding_1"), (EObjectFlags)0x00000000);
	InDynamicClass->DynamicBindingObjects.Add(__Local__0);
	auto __Local__1 = NewObject<UWidgetTree>(InDynamicClass, UWidgetTree::StaticClass(), TEXT("WidgetTree"), (EObjectFlags)0x00000009);
	InDynamicClass->MiscConvertedSubobjects.Add(__Local__1);
	__Local__0->ComponentDelegateBindings = TArray<FBlueprintComponentDelegateBinding> ();
	__Local__0->ComponentDelegateBindings.AddUninitialized(4);
	FBlueprintComponentDelegateBinding::StaticStruct()->InitializeStruct(__Local__0->ComponentDelegateBindings.GetData(), 4);
	auto& __Local__2 = __Local__0->ComponentDelegateBindings[0];
	__Local__2.ComponentPropertyName = FName(TEXT("SpinBox_Multiplay"));
	__Local__2.DelegatePropertyName = FName(TEXT("OnValueChanged"));
	__Local__2.FunctionNameToBind = FName(TEXT("BndEvt__SpinBox_Multiplay_K2Node_ComponentBoundEvent_3_OnSpinBoxValueChangedEvent__DelegateSignature"));
	auto& __Local__3 = __Local__0->ComponentDelegateBindings[1];
	__Local__3.ComponentPropertyName = FName(TEXT("Button_clear"));
	__Local__3.DelegatePropertyName = FName(TEXT("OnClicked"));
	__Local__3.FunctionNameToBind = FName(TEXT("BndEvt__Button_clear_K2Node_ComponentBoundEvent_2_OnButtonClickedEvent__DelegateSignature"));
	auto& __Local__4 = __Local__0->ComponentDelegateBindings[2];
	__Local__4.ComponentPropertyName = FName(TEXT("Button_stop"));
	__Local__4.DelegatePropertyName = FName(TEXT("OnClicked"));
	__Local__4.FunctionNameToBind = FName(TEXT("BndEvt__Button_stop_K2Node_ComponentBoundEvent_1_OnButtonClickedEvent__DelegateSignature"));
	auto& __Local__5 = __Local__0->ComponentDelegateBindings[3];
	__Local__5.ComponentPropertyName = FName(TEXT("Button_play"));
	__Local__5.DelegatePropertyName = FName(TEXT("OnClicked"));
	__Local__5.FunctionNameToBind = FName(TEXT("BndEvt__Button_play_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature"));
	auto __Local__6 = NewObject<UCanvasPanel>(__Local__1, TEXT("CanvasPanel_0"), (EObjectFlags)0x00280008);
	auto& __Local__7 = (*(AccessPrivateProperty<TArray<UPanelSlot*> >((__Local__6), UPanelWidget::__PPO__Slots() )));
	__Local__7 = TArray<UPanelSlot*> ();
	__Local__7.Reserve(4);
	auto __Local__8 = NewObject<UCanvasPanelSlot>(__Local__6, TEXT("CanvasPanelSlot_2"), (EObjectFlags)0x00280008);
	__Local__8->LayoutData.Offsets.Right = 0.000000f;
	__Local__8->LayoutData.Offsets.Bottom = 0.000000f;
	__Local__8->LayoutData.Anchors.Maximum = FVector2D(1.000000, 1.000000);
	__Local__8->Parent = __Local__6;
	auto __Local__9 = NewObject<UImage>(__Local__1, TEXT("Image"), (EObjectFlags)0x00280008);
	__Local__9->ColorAndOpacity = FLinearColor(0.000000, 0.000000, 0.000000, 1.000000);
	__Local__9->Slot = __Local__8;
	__Local__8->Content = __Local__9;
	__Local__7.Add(__Local__8);
	auto __Local__10 = NewObject<UCanvasPanelSlot>(__Local__6, TEXT("CanvasPanelSlot_3"), (EObjectFlags)0x00280008);
	__Local__10->LayoutData.Offsets.Right = 750.000000f;
	__Local__10->LayoutData.Offsets.Bottom = 100.000000f;
	__Local__10->LayoutData.Anchors.Minimum = FVector2D(0.500000, 0.500000);
	__Local__10->LayoutData.Anchors.Maximum = FVector2D(0.500000, 0.500000);
	__Local__10->LayoutData.Alignment = FVector2D(0.500000, 0.500000);
	__Local__10->Parent = __Local__6;
	auto __Local__11 = NewObject<UHorizontalBox>(__Local__1, TEXT("HorizontalBox_54"), (EObjectFlags)0x00280008);
	auto& __Local__12 = (*(AccessPrivateProperty<TArray<UPanelSlot*> >((__Local__11), UPanelWidget::__PPO__Slots() )));
	__Local__12 = TArray<UPanelSlot*> ();
	__Local__12.Reserve(4);
	auto __Local__13 = NewObject<UHorizontalBoxSlot>(__Local__11, TEXT("HorizontalBoxSlot_0"), (EObjectFlags)0x00280008);
	__Local__13->Padding.Left = 10.000000f;
	__Local__13->Padding.Top = 10.000000f;
	__Local__13->Padding.Right = 10.000000f;
	__Local__13->Padding.Bottom = 10.000000f;
	__Local__13->Size.SizeRule = ESlateSizeRule::Type::Fill;
	__Local__13->HorizontalAlignment = EHorizontalAlignment::HAlign_Center;
	__Local__13->VerticalAlignment = EVerticalAlignment::VAlign_Center;
	__Local__13->Parent = __Local__11;
	auto __Local__14 = NewObject<UTextBlock>(__Local__1, TEXT("TextBlock_hours"), (EObjectFlags)0x00280008);
	__Local__14->Text = FTextStringHelper::CreateFromBuffer(
TEXT("NSLOCTEXT(\"[8C907CA04E27B30E2E790D8F6C34ED57]\", \"4535F4CE46939D3236570795FCCFCF3A\", \"hours\")")	);
	__Local__14->Slot = __Local__13;
	__Local__14->bIsVariable = true;
	__Local__13->Content = __Local__14;
	__Local__12.Add(__Local__13);
	auto __Local__15 = NewObject<UHorizontalBoxSlot>(__Local__11, TEXT("HorizontalBoxSlot_1"), (EObjectFlags)0x00280008);
	__Local__15->Padding.Left = 10.000000f;
	__Local__15->Padding.Top = 10.000000f;
	__Local__15->Padding.Right = 10.000000f;
	__Local__15->Padding.Bottom = 10.000000f;
	__Local__15->Size.SizeRule = ESlateSizeRule::Type::Fill;
	__Local__15->HorizontalAlignment = EHorizontalAlignment::HAlign_Center;
	__Local__15->VerticalAlignment = EVerticalAlignment::VAlign_Center;
	__Local__15->Parent = __Local__11;
	auto __Local__16 = NewObject<UTextBlock>(__Local__1, TEXT("TextBlock_minutes"), (EObjectFlags)0x00280008);
	__Local__16->Text = FTextStringHelper::CreateFromBuffer(
TEXT("NSLOCTEXT(\"[8C907CA04E27B30E2E790D8F6C34ED57]\", \"583BA9D447FAC1E12B2D219B998B26C5\", \"minutes\")")	);
	__Local__16->Slot = __Local__15;
	__Local__16->bIsVariable = true;
	__Local__15->Content = __Local__16;
	__Local__12.Add(__Local__15);
	auto __Local__17 = NewObject<UHorizontalBoxSlot>(__Local__11, TEXT("HorizontalBoxSlot_2"), (EObjectFlags)0x00280008);
	__Local__17->Padding.Left = 10.000000f;
	__Local__17->Padding.Top = 10.000000f;
	__Local__17->Padding.Right = 10.000000f;
	__Local__17->Padding.Bottom = 10.000000f;
	__Local__17->Size.SizeRule = ESlateSizeRule::Type::Fill;
	__Local__17->HorizontalAlignment = EHorizontalAlignment::HAlign_Center;
	__Local__17->VerticalAlignment = EVerticalAlignment::VAlign_Center;
	__Local__17->Parent = __Local__11;
	auto __Local__18 = NewObject<UTextBlock>(__Local__1, TEXT("TextBlock_seconds"), (EObjectFlags)0x00280008);
	__Local__18->Text = FTextStringHelper::CreateFromBuffer(
TEXT("NSLOCTEXT(\"[8C907CA04E27B30E2E790D8F6C34ED57]\", \"34AF9A0548D4868ADC07A1B00594C903\", \"seconds\")")	);
	__Local__18->Slot = __Local__17;
	__Local__18->bIsVariable = true;
	__Local__17->Content = __Local__18;
	__Local__12.Add(__Local__17);
	auto __Local__19 = NewObject<UHorizontalBoxSlot>(__Local__11, TEXT("HorizontalBoxSlot_3"), (EObjectFlags)0x00280008);
	__Local__19->Padding.Left = 10.000000f;
	__Local__19->Padding.Top = 10.000000f;
	__Local__19->Padding.Right = 10.000000f;
	__Local__19->Padding.Bottom = 10.000000f;
	__Local__19->Size.SizeRule = ESlateSizeRule::Type::Fill;
	__Local__19->HorizontalAlignment = EHorizontalAlignment::HAlign_Center;
	__Local__19->VerticalAlignment = EVerticalAlignment::VAlign_Center;
	__Local__19->Parent = __Local__11;
	auto __Local__20 = NewObject<UTextBlock>(__Local__1, TEXT("TextBlock_miliseconds"), (EObjectFlags)0x00280008);
	__Local__20->Text = FTextStringHelper::CreateFromBuffer(
TEXT("NSLOCTEXT(\"[8C907CA04E27B30E2E790D8F6C34ED57]\", \"6BB35AA14FC6D5E62799A6B4AF878D0A\", \"miliseconds\")")	);
	__Local__20->Slot = __Local__19;
	__Local__20->bIsVariable = true;
	__Local__19->Content = __Local__20;
	__Local__12.Add(__Local__19);
	__Local__11->Slot = __Local__10;
	__Local__10->Content = __Local__11;
	__Local__7.Add(__Local__10);
	auto __Local__21 = NewObject<UCanvasPanelSlot>(__Local__6, TEXT("CanvasPanelSlot_4"), (EObjectFlags)0x00280008);
	__Local__21->LayoutData.Anchors.Minimum = FVector2D(0.500000, 0.500000);
	__Local__21->LayoutData.Anchors.Maximum = FVector2D(0.500000, 0.500000);
	__Local__21->LayoutData.Alignment = FVector2D(0.500000, 2.000000);
	__Local__21->bAutoSize = true;
	__Local__21->Parent = __Local__6;
	auto __Local__22 = NewObject<UHorizontalBox>(__Local__1, TEXT("HorizontalBox_160"), (EObjectFlags)0x00280008);
	auto& __Local__23 = (*(AccessPrivateProperty<TArray<UPanelSlot*> >((__Local__22), UPanelWidget::__PPO__Slots() )));
	__Local__23 = TArray<UPanelSlot*> ();
	__Local__23.Reserve(3);
	auto __Local__24 = NewObject<UHorizontalBoxSlot>(__Local__22, TEXT("HorizontalBoxSlot_0"), (EObjectFlags)0x00280008);
	__Local__24->Padding.Left = 10.000000f;
	__Local__24->Padding.Top = 10.000000f;
	__Local__24->Padding.Right = 10.000000f;
	__Local__24->Padding.Bottom = 10.000000f;
	__Local__24->Parent = __Local__22;
	auto __Local__25 = NewObject<UButton>(__Local__1, TEXT("Button_play"), (EObjectFlags)0x00280008);
	auto& __Local__26 = (*(AccessPrivateProperty<TArray<UPanelSlot*> >((__Local__25), UPanelWidget::__PPO__Slots() )));
	__Local__26 = TArray<UPanelSlot*> ();
	__Local__26.Reserve(1);
	auto __Local__27 = NewObject<UButtonSlot>(__Local__25, TEXT("ButtonSlot_0"), (EObjectFlags)0x00280008);
	__Local__27->Padding.Left = 10.000000f;
	__Local__27->Padding.Top = 10.000000f;
	__Local__27->Padding.Right = 10.000000f;
	__Local__27->Padding.Bottom = 10.000000f;
	__Local__27->Parent = __Local__25;
	auto __Local__28 = NewObject<UTextBlock>(__Local__1, TEXT("TextBlock_play"), (EObjectFlags)0x00280008);
	__Local__28->Text = FTextStringHelper::CreateFromBuffer(
TEXT("NSLOCTEXT(\"[8C907CA04E27B30E2E790D8F6C34ED57]\", \"92518797476AE406F8E17185C492C8A4\", \"play\")")	);
	auto& __Local__29 = (*(AccessPrivateProperty<FLinearColor >(&(__Local__28->ColorAndOpacity), FSlateColor::__PPO__SpecifiedColor() )));
	__Local__29 = FLinearColor(0.000000, 0.000000, 0.000000, 1.000000);
	__Local__28->Slot = __Local__27;
	__Local__28->bIsVariable = true;
	__Local__27->Content = __Local__28;
	__Local__26.Add(__Local__27);
	__Local__25->Slot = __Local__24;
	__Local__24->Content = __Local__25;
	__Local__23.Add(__Local__24);
	auto __Local__30 = NewObject<UHorizontalBoxSlot>(__Local__22, TEXT("HorizontalBoxSlot_1"), (EObjectFlags)0x00280008);
	__Local__30->Padding.Left = 10.000000f;
	__Local__30->Padding.Top = 10.000000f;
	__Local__30->Padding.Right = 10.000000f;
	__Local__30->Padding.Bottom = 10.000000f;
	__Local__30->Parent = __Local__22;
	auto __Local__31 = NewObject<UButton>(__Local__1, TEXT("Button_stop"), (EObjectFlags)0x00280008);
	auto& __Local__32 = (*(AccessPrivateProperty<TArray<UPanelSlot*> >((__Local__31), UPanelWidget::__PPO__Slots() )));
	__Local__32 = TArray<UPanelSlot*> ();
	__Local__32.Reserve(1);
	auto __Local__33 = NewObject<UButtonSlot>(__Local__31, TEXT("ButtonSlot_0"), (EObjectFlags)0x00280008);
	__Local__33->Padding.Left = 10.000000f;
	__Local__33->Padding.Top = 10.000000f;
	__Local__33->Padding.Right = 10.000000f;
	__Local__33->Padding.Bottom = 10.000000f;
	__Local__33->Parent = __Local__31;
	auto __Local__34 = NewObject<UTextBlock>(__Local__1, TEXT("TextBlock_stop"), (EObjectFlags)0x00280008);
	__Local__34->Text = FTextStringHelper::CreateFromBuffer(
TEXT("NSLOCTEXT(\"[8C907CA04E27B30E2E790D8F6C34ED57]\", \"90826EE64A00E61D386E24B0AA8FFD1A\", \"stop\")")	);
	auto& __Local__35 = (*(AccessPrivateProperty<FLinearColor >(&(__Local__34->ColorAndOpacity), FSlateColor::__PPO__SpecifiedColor() )));
	__Local__35 = FLinearColor(0.000000, 0.000000, 0.000000, 1.000000);
	__Local__34->Slot = __Local__33;
	__Local__34->bIsVariable = true;
	__Local__33->Content = __Local__34;
	__Local__32.Add(__Local__33);
	__Local__31->Slot = __Local__30;
	__Local__30->Content = __Local__31;
	__Local__23.Add(__Local__30);
	auto __Local__36 = NewObject<UHorizontalBoxSlot>(__Local__22, TEXT("HorizontalBoxSlot_2"), (EObjectFlags)0x00280008);
	__Local__36->Padding.Left = 10.000000f;
	__Local__36->Padding.Top = 10.000000f;
	__Local__36->Padding.Right = 10.000000f;
	__Local__36->Padding.Bottom = 10.000000f;
	__Local__36->Parent = __Local__22;
	auto __Local__37 = NewObject<UButton>(__Local__1, TEXT("Button_clear"), (EObjectFlags)0x00280008);
	auto& __Local__38 = (*(AccessPrivateProperty<TArray<UPanelSlot*> >((__Local__37), UPanelWidget::__PPO__Slots() )));
	__Local__38 = TArray<UPanelSlot*> ();
	__Local__38.Reserve(1);
	auto __Local__39 = NewObject<UButtonSlot>(__Local__37, TEXT("ButtonSlot_0"), (EObjectFlags)0x00280008);
	__Local__39->Padding.Left = 10.000000f;
	__Local__39->Padding.Top = 10.000000f;
	__Local__39->Padding.Right = 10.000000f;
	__Local__39->Padding.Bottom = 10.000000f;
	__Local__39->Parent = __Local__37;
	auto __Local__40 = NewObject<UTextBlock>(__Local__1, TEXT("TextBlock_clear"), (EObjectFlags)0x00280008);
	__Local__40->Text = FTextStringHelper::CreateFromBuffer(
TEXT("NSLOCTEXT(\"[8C907CA04E27B30E2E790D8F6C34ED57]\", \"948AB1284D91663344732296716A92B9\", \"clear\")")	);
	auto& __Local__41 = (*(AccessPrivateProperty<FLinearColor >(&(__Local__40->ColorAndOpacity), FSlateColor::__PPO__SpecifiedColor() )));
	__Local__41 = FLinearColor(0.000000, 0.000000, 0.000000, 1.000000);
	__Local__40->Slot = __Local__39;
	__Local__40->bIsVariable = true;
	__Local__39->Content = __Local__40;
	__Local__38.Add(__Local__39);
	__Local__37->Slot = __Local__36;
	__Local__36->Content = __Local__37;
	__Local__23.Add(__Local__36);
	__Local__22->Slot = __Local__21;
	__Local__21->Content = __Local__22;
	__Local__7.Add(__Local__21);
	auto __Local__42 = NewObject<UCanvasPanelSlot>(__Local__6, TEXT("CanvasPanelSlot_6"), (EObjectFlags)0x00280008);
	__Local__42->LayoutData.Offsets.Bottom = 40.000000f;
	__Local__42->LayoutData.Anchors.Minimum = FVector2D(0.500000, 0.500000);
	__Local__42->LayoutData.Anchors.Maximum = FVector2D(0.500000, 0.500000);
	__Local__42->LayoutData.Alignment = FVector2D(0.500000, -2.000000);
	__Local__42->Parent = __Local__6;
	auto __Local__43 = NewObject<USpinBox>(__Local__1, TEXT("SpinBox_Multiplay"), (EObjectFlags)0x00280008);
	__Local__43->Value = 1.000000f;
	static TWeakFieldPtr<FProperty> __Local__45{};
	const FProperty* __Local__44 = __Local__45.Get();
	if (nullptr == __Local__44)
	{
		__Local__44 = (USpinBox::StaticClass())->FindPropertyByName(FName(TEXT("bOverride_MinValue")));
		check(__Local__44);
		__Local__45 = __Local__44;
	}
	(((FBoolProperty*)__Local__44)->SetPropertyValue_InContainer((__Local__43), true, 0));
	static TWeakFieldPtr<FProperty> __Local__47{};
	const FProperty* __Local__46 = __Local__47.Get();
	if (nullptr == __Local__46)
	{
		__Local__46 = (USpinBox::StaticClass())->FindPropertyByName(FName(TEXT("bOverride_MaxValue")));
		check(__Local__46);
		__Local__47 = __Local__46;
	}
	(((FBoolProperty*)__Local__46)->SetPropertyValue_InContainer((__Local__43), true, 0));
	static TWeakFieldPtr<FProperty> __Local__49{};
	const FProperty* __Local__48 = __Local__49.Get();
	if (nullptr == __Local__48)
	{
		__Local__48 = (USpinBox::StaticClass())->FindPropertyByName(FName(TEXT("bOverride_MinSliderValue")));
		check(__Local__48);
		__Local__49 = __Local__48;
	}
	(((FBoolProperty*)__Local__48)->SetPropertyValue_InContainer((__Local__43), true, 0));
	static TWeakFieldPtr<FProperty> __Local__51{};
	const FProperty* __Local__50 = __Local__51.Get();
	if (nullptr == __Local__50)
	{
		__Local__50 = (USpinBox::StaticClass())->FindPropertyByName(FName(TEXT("bOverride_MaxSliderValue")));
		check(__Local__50);
		__Local__51 = __Local__50;
	}
	(((FBoolProperty*)__Local__50)->SetPropertyValue_InContainer((__Local__43), true, 0));
	auto& __Local__52 = (*(AccessPrivateProperty<float >((__Local__43), USpinBox::__PPO__MinValue() )));
	__Local__52 = 0.010000f;
	auto& __Local__53 = (*(AccessPrivateProperty<float >((__Local__43), USpinBox::__PPO__MaxValue() )));
	__Local__53 = 1000.000000f;
	auto& __Local__54 = (*(AccessPrivateProperty<float >((__Local__43), USpinBox::__PPO__MinSliderValue() )));
	__Local__54 = 0.010000f;
	auto& __Local__55 = (*(AccessPrivateProperty<float >((__Local__43), USpinBox::__PPO__MaxSliderValue() )));
	__Local__55 = 1000.000000f;
	__Local__43->Slot = __Local__42;
	__Local__42->Content = __Local__43;
	__Local__7.Add(__Local__42);
	__Local__1->RootWidget = __Local__6;
}
PRAGMA_ENABLE_OPTIMIZATION
void UBP_UserInterface_Timer_C__pf907646509::GetSlotNames(TArray<FName>& SlotNames) const
{
	TArray<FName>  __Local__56;
	SlotNames.Append(__Local__56);
}
void UBP_UserInterface_Timer_C__pf907646509::InitializeNativeClassData()
{
	TArray<UWidgetAnimation*>  __Local__57;
	TArray<FDelegateRuntimeBinding>  __Local__58;
	UWidgetBlueprintGeneratedClass::InitializeWidgetStatic(this, GetClass(), false, true, CastChecked<UWidgetTree>(CastChecked<UDynamicClass>(UBP_UserInterface_Timer_C__pf907646509::StaticClass())->MiscConvertedSubobjects[0]), __Local__57, __Local__58);
}
void UBP_UserInterface_Timer_C__pf907646509::PreSave(const class ITargetPlatform* TargetPlatform)
{
	Super::PreSave(TargetPlatform);
	TArray<FName> LocalNamedSlots;
	GetSlotNames(LocalNamedSlots);
	RemoveObsoleteBindings(LocalNamedSlots);
}
void UBP_UserInterface_Timer_C__pf907646509::bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_0(int32 bpp__EntryPoint__pf)
{
	bool bpfv__CallFunc_K2_IsTimerPausedHandle_ReturnValue__pf{};
	bool bpfv__CallFunc_K2_IsValidTimerHandle_ReturnValue__pf{};
	float bpfv__CallFunc_Divide_FloatFloat_ReturnValue__pf{};
	FTimerHandle bpfv__CallFunc_K2_SetTimer_ReturnValue__pf{};
	int32 __CurrentState = bpp__EntryPoint__pf;
	do
	{
		switch( __CurrentState )
		{
		case 1:
			{
				UKismetSystemLibrary::K2_ClearAndInvalidateTimerHandle(this, /*out*/ bpv__Timer__pf);
			}
		case 2:
			{
				UKismetSystemLibrary::K2_PauseTimerHandle(this, bpv__Timer__pf);
				__CurrentState = -1;
				break;
			}
		case 3:
			{
			}
		case 4:
			{
				bpfv__CallFunc_K2_IsValidTimerHandle_ReturnValue__pf = UKismetSystemLibrary::K2_IsValidTimerHandle(bpv__Timer__pf);
				if (!bpfv__CallFunc_K2_IsValidTimerHandle_ReturnValue__pf)
				{
					__CurrentState = 7;
					break;
				}
			}
		case 5:
			{
				bpfv__CallFunc_K2_IsTimerPausedHandle_ReturnValue__pf = UKismetSystemLibrary::K2_IsTimerPausedHandle(this, bpv__Timer__pf);
				if (!bpfv__CallFunc_K2_IsTimerPausedHandle_ReturnValue__pf)
				{
					__CurrentState = 2;
					break;
				}
			}
		case 6:
			{
				UKismetSystemLibrary::K2_UnPauseTimerHandle(this, bpv__Timer__pf);
				__CurrentState = -1;
				break;
			}
		case 7:
			{
				bpfv__CallFunc_Divide_FloatFloat_ReturnValue__pf = FCustomThunkTemplates::Divide_FloatFloat(0.010000, bpv__multiplay__pf);
				bpfv__CallFunc_K2_SetTimer_ReturnValue__pf = UKismetSystemLibrary::K2_SetTimer(this, FString(TEXT("Tick_Timer")), bpfv__CallFunc_Divide_FloatFloat_ReturnValue__pf, true, 0.000000, 0.000000);
			}
		case 8:
			{
				bpv__Timer__pf = bpfv__CallFunc_K2_SetTimer_ReturnValue__pf;
				__CurrentState = -1;
				break;
			}
		case 9:
			{
				__CurrentState = 2;
				break;
			}
		case 10:
			{
			}
		case 11:
			{
				bpv__hours__pf = 0;
			}
		case 12:
			{
				bpv__minutes__pf = 0;
			}
		case 13:
			{
				bpv__seconds__pf = 0;
			}
		case 14:
			{
				bpv__milliseconds__pf = 0;
			}
		case 15:
			{
				bpf__Update_Text__pf();
				__CurrentState = 1;
				break;
			}
		default:
			break;
		}
	} while( __CurrentState != -1 );
}
void UBP_UserInterface_Timer_C__pf907646509::bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_1(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 37);
	bpv__multiplay__pf = b0l__K2Node_ComponentBoundEvent_InValue__pf;
	return; //KCST_EndOfThread
}
void UBP_UserInterface_Timer_C__pf907646509::bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_2(int32 bpp__EntryPoint__pf)
{
	int32 bpfv__CallFunc_Add_IntInt_ReturnValue__pf{};
	bool bpfv__CallFunc_LessEqual_IntInt_ReturnValue__pf{};
	int32 bpfv__CallFunc_Add_IntInt_ReturnValue_1__pf{};
	bool bpfv__CallFunc_LessEqual_IntInt_ReturnValue_1__pf{};
	bool bpfv__CallFunc_LessEqual_IntInt_ReturnValue_2__pf{};
	int32 bpfv__CallFunc_Add_IntInt_ReturnValue_2__pf{};
	int32 bpfv__CallFunc_Add_IntInt_ReturnValue_3__pf{};
	TArray< int32, TInlineAllocator<8> > __StateStack;

	int32 __CurrentState = bpp__EntryPoint__pf;
	do
	{
		switch( __CurrentState )
		{
		case 23:
			{
			}
		case 24:
			{
				__StateStack.Push(25);
				__CurrentState = 27;
				break;
			}
		case 25:
			{
			}
		case 26:
			{
				bpf__Update_Text__pf();
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 27:
			{
				bpfv__CallFunc_LessEqual_IntInt_ReturnValue__pf = UKismetMathLibrary::LessEqual_IntInt(bpv__milliseconds__pf, 99);
				if (!bpfv__CallFunc_LessEqual_IntInt_ReturnValue__pf)
				{
					__CurrentState = 29;
					break;
				}
			}
		case 28:
			{
				bpfv__CallFunc_Add_IntInt_ReturnValue_1__pf = UKismetMathLibrary::Add_IntInt(bpv__milliseconds__pf, 1);
				bpv__milliseconds__pf = bpfv__CallFunc_Add_IntInt_ReturnValue_1__pf;
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 29:
			{
				bpv__milliseconds__pf = 0;
			}
		case 30:
			{
				bpfv__CallFunc_LessEqual_IntInt_ReturnValue_1__pf = UKismetMathLibrary::LessEqual_IntInt(bpv__seconds__pf, 60);
				if (!bpfv__CallFunc_LessEqual_IntInt_ReturnValue_1__pf)
				{
					__CurrentState = 32;
					break;
				}
			}
		case 31:
			{
				bpfv__CallFunc_Add_IntInt_ReturnValue__pf = UKismetMathLibrary::Add_IntInt(bpv__seconds__pf, 1);
				bpv__seconds__pf = bpfv__CallFunc_Add_IntInt_ReturnValue__pf;
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 32:
			{
				bpv__seconds__pf = 0;
			}
		case 33:
			{
				bpfv__CallFunc_LessEqual_IntInt_ReturnValue_2__pf = UKismetMathLibrary::LessEqual_IntInt(bpv__minutes__pf, 60);
				if (!bpfv__CallFunc_LessEqual_IntInt_ReturnValue_2__pf)
				{
					__CurrentState = 35;
					break;
				}
			}
		case 34:
			{
				bpfv__CallFunc_Add_IntInt_ReturnValue_3__pf = UKismetMathLibrary::Add_IntInt(bpv__minutes__pf, 1);
				bpv__minutes__pf = bpfv__CallFunc_Add_IntInt_ReturnValue_3__pf;
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		case 35:
			{
				bpv__minutes__pf = 0;
			}
		case 36:
			{
				bpfv__CallFunc_Add_IntInt_ReturnValue_2__pf = UKismetMathLibrary::Add_IntInt(bpv__hours__pf, 1);
				bpv__hours__pf = bpfv__CallFunc_Add_IntInt_ReturnValue_2__pf;
				__CurrentState = (__StateStack.Num() > 0) ? __StateStack.Pop(/*bAllowShrinking=*/ false) : -1;
				break;
			}
		default:
			check(false); // Invalid state
			break;
		}
	} while( __CurrentState != -1 );
}
void UBP_UserInterface_Timer_C__pf907646509::bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_3(int32 bpp__EntryPoint__pf)
{
	FText bpfv__CallFunc_Conv_IntToText_ReturnValue__pf{};
	FText bpfv__CallFunc_Conv_IntToText_ReturnValue_1__pf{};
	FText bpfv__CallFunc_Conv_IntToText_ReturnValue_2__pf{};
	FText bpfv__CallFunc_Conv_IntToText_ReturnValue_3__pf{};
	check(bpp__EntryPoint__pf == 16);
	bpfv__CallFunc_Conv_IntToText_ReturnValue__pf = UKismetTextLibrary::Conv_IntToText(bpv__hours__pf, false, true, 1, 324);
	bpf__Set_Text__pf(bpv__TextBlock_hours__pf, bpfv__CallFunc_Conv_IntToText_ReturnValue__pf);
	bpfv__CallFunc_Conv_IntToText_ReturnValue_1__pf = UKismetTextLibrary::Conv_IntToText(bpv__minutes__pf, false, true, 1, 324);
	bpf__Set_Text__pf(bpv__TextBlock_minutes__pf, bpfv__CallFunc_Conv_IntToText_ReturnValue_1__pf);
	bpfv__CallFunc_Conv_IntToText_ReturnValue_2__pf = UKismetTextLibrary::Conv_IntToText(bpv__seconds__pf, false, true, 1, 324);
	bpf__Set_Text__pf(bpv__TextBlock_seconds__pf, bpfv__CallFunc_Conv_IntToText_ReturnValue_2__pf);
	bpfv__CallFunc_Conv_IntToText_ReturnValue_3__pf = UKismetTextLibrary::Conv_IntToText(bpv__milliseconds__pf, false, true, 1, 324);
	bpf__Set_Text__pf(bpv__TextBlock_miliseconds__pf, bpfv__CallFunc_Conv_IntToText_ReturnValue_3__pf);
	return; //KCST_EndOfThread
}
void UBP_UserInterface_Timer_C__pf907646509::bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_4(int32 bpp__EntryPoint__pf)
{
	check(bpp__EntryPoint__pf == 21);
	if(::IsValid(b0l__K2Node_CustomEvent_Target__pf))
	{
		b0l__K2Node_CustomEvent_Target__pf->SetText(b0l__K2Node_CustomEvent_InText__pf);
	}
	return; //KCST_EndOfThread
}
void UBP_UserInterface_Timer_C__pf907646509::bpf__BndEvt__SpinBox_Multiplay_K2Node_ComponentBoundEvent_3_OnSpinBoxValueChangedEvent__DelegateSignature__pf(float bpp__InValue__pf)
{
	b0l__K2Node_ComponentBoundEvent_InValue__pf = bpp__InValue__pf;
	bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_1(37);
}
void UBP_UserInterface_Timer_C__pf907646509::bpf__Tick_Timer__pf()
{
	bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_2(23);
}
void UBP_UserInterface_Timer_C__pf907646509::bpf__Set_Text__pf(UTextBlock* bpp__Target__pf, const FText& bpp__InText__pf__const)
{
	typedef FText  T__Local__59;
	T__Local__59& bpp__InText__pf = *const_cast<T__Local__59 *>(&bpp__InText__pf__const);
	b0l__K2Node_CustomEvent_Target__pf = bpp__Target__pf;
	b0l__K2Node_CustomEvent_InText__pf = bpp__InText__pf;
	bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_4(21);
}
void UBP_UserInterface_Timer_C__pf907646509::bpf__Update_Text__pf()
{
	bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_3(16);
}
void UBP_UserInterface_Timer_C__pf907646509::bpf__BndEvt__Button_clear_K2Node_ComponentBoundEvent_2_OnButtonClickedEvent__DelegateSignature__pf()
{
	bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_0(10);
}
void UBP_UserInterface_Timer_C__pf907646509::bpf__BndEvt__Button_stop_K2Node_ComponentBoundEvent_1_OnButtonClickedEvent__DelegateSignature__pf()
{
	bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_0(9);
}
void UBP_UserInterface_Timer_C__pf907646509::bpf__BndEvt__Button_play_K2Node_ComponentBoundEvent_0_OnButtonClickedEvent__DelegateSignature__pf()
{
	bpf__ExecuteUbergraph_BP_UserInterface_Timer__pf_0(3);
}
PRAGMA_DISABLE_OPTIMIZATION
void UBP_UserInterface_Timer_C__pf907646509::__StaticDependencies_DirectlyUsedAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
}
PRAGMA_ENABLE_OPTIMIZATION
PRAGMA_DISABLE_OPTIMIZATION
void UBP_UserInterface_Timer_C__pf907646509::__StaticDependenciesAssets(TArray<FBlueprintDependencyData>& AssetsToLoad)
{
	__StaticDependencies_DirectlyUsedAssets(AssetsToLoad);
	const FCompactBlueprintDependencyData LocCompactBlueprintDependencyData[] =
	{
		{0, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Font /Engine/EngineFonts/Roboto.Roboto 
		{1, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/UMG.TextBlock 
		{2, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.TimerHandle 
		{3, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetSystemLibrary 
		{4, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetMathLibrary 
		{5, FBlueprintDependencyType(false, true, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/Engine.KismetTextLibrary 
		{6, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/UMG.UserWidget 
		{7, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  ScriptStruct /Script/Engine.PointerToUberGraphFrame 
		{8, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/UMG.Button 
		{9, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/UMG.Image 
		{10, FBlueprintDependencyType(true, false, false, false), FBlueprintDependencyType(false, false, false, false)},  //  Class /Script/UMG.SpinBox 
	};
	for(const FCompactBlueprintDependencyData& CompactData : LocCompactBlueprintDependencyData)
	{
		AssetsToLoad.Add(FBlueprintDependencyData(F__NativeDependencies::Get(CompactData.ObjectRefIndex), CompactData));
	}
}
PRAGMA_ENABLE_OPTIMIZATION
struct FRegisterHelper__UBP_UserInterface_Timer_C__pf907646509
{
	FRegisterHelper__UBP_UserInterface_Timer_C__pf907646509()
	{
		FConvertedBlueprintsDependencies::Get().RegisterConvertedClass(TEXT("/Game/Functions/BP_UserInterface_Timer"), &UBP_UserInterface_Timer_C__pf907646509::__StaticDependenciesAssets);
	}
	static FRegisterHelper__UBP_UserInterface_Timer_C__pf907646509 Instance;
};
FRegisterHelper__UBP_UserInterface_Timer_C__pf907646509 FRegisterHelper__UBP_UserInterface_Timer_C__pf907646509::Instance;
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
