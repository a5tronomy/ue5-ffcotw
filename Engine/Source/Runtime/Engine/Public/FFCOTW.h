#pragma once
#include "ActorComponent.h"
#include "Runtime/Engine/Classes/Camera/PlayerCameraManager.h"
#include "SceneView.h"
#include "Materials/MaterialExpression.h"
#include "FFCOTW.generated.h"

class FFCOTW;

USTRUCT(BlueprintType)
struct FSnkViewChannels
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Rendering")
	uint8 bChannel0 : 1;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Rendering")
	uint8 bChannel1 : 1;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Rendering")
	uint8 bChannel2 : 1;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Rendering")
	uint8 bChannel3 : 1;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Rendering")
	uint8 bChannel4 : 1;
	
	FSnkViewChannels();
};

USTRUCT()
struct FSnkViewStackingProxy {
	GENERATED_BODY()
public:

	uint8 UnknownData_FSnkViewStackingProxy[0x40] = {};
	
	FSnkViewStackingProxy();
};

UCLASS(ClassGroup = SNK, meta = (BlueprintSpawnableComponent))
class ENGINE_API USnkViewStackingComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    USnkViewStackingComponent();

private:
    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent")
    int32 StackViewID;

    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent")
    int32 LightGridReuseTargetID;

    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent")
    int32 Priority;

    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent")
    FSnkViewChannels SnkViewChannels;

    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent")
    int32 TargetGPUHeadroom;

    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent")
    uint8 bMainCameraProxy : 1;

    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent")
    uint8 bReflectPostureFromActor : 1;

    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent")
    uint8 bDisableOcclusionTest : 1;

    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent")
    uint8 bDisableSkyAtmosphere : 1;

    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent")
    uint8 bOverrideSkyAtmosphereShadingViewChannels : 1;

    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent", meta=(EditCondition="bOverrideSkyAtmosphereShadingViewChannels"))
    FSnkViewChannels OverrideSkyAtmosphereShadingViewChannels;

    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent")
    uint8 bSetFOVWithFixedAspect : 1;

    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent", meta=(EditCondition="bSetFOVWithFixedAspect"))
    float FOVWithFixedAspect;

    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent", meta=(EditCondition="bSetFOVWithFixedAspect"))
    float FixedAspect;
	
    UPROPERTY(VisibleAnywhere, Category = "ViewStackingComponent")
    FVector4f ScreenMADOffset;

    UPROPERTY(EditDefaultsOnly, Category = "ViewStackingComponent")
    TEnumAsByte<ESceneCaptureSource> OverwriteSceneCaptureSource;

    UPROPERTY(Transient)
    FCameraCacheEntry CameraCachePrivate;

	/** FFCOTW Custom Engine */
	/** Insert of unreflected data */
	uint8 UnknownData_SnkViewStackingComponent[0x10] = {};

public:
	UFUNCTION(BlueprintCallable, Category = "ViewStackingComponent")
	void SetScreenMADOffset(FVector4f Offset);

    UFUNCTION(BlueprintCallable, Category = "ViewStackingComponent")
    void SetPriority(int32 InPriority);

	UFUNCTION()
	void OnComponentActivated_Native();

	UFUNCTION()
	void OnComponentDeactivated_Native();

    UFUNCTION(BlueprintPure, Category = "ViewStackingComponent")
    bool IsReflectPostureFromActor() const;

    UFUNCTION(BlueprintPure, Category = "ViewStackingComponent")
    int32 GetPriority() const;

protected:

    virtual void Activate(bool bReset) override;
    virtual void Deactivate() override;
};

UCLASS(ClassGroup = SNK, meta = (BlueprintSpawnableComponent))
class ENGINE_API UMaterialExpressionShellMeshingData : public UMaterialExpression
{
	GENERATED_BODY()
	
};

UENUM()
enum class ESnkMeshAssetUsageCategory : uint8
{
	Uncategorized,
	Stage,
	ESnkMeshAssetUsageCategory_MAX
};

UENUM()
enum class ESnkStreamingAssetCheckOption : uint8
{
	Nothing,
	Texture,
	Mesh,
	All,
	ESnkStreamingAssetCheckOption_MAX
};

