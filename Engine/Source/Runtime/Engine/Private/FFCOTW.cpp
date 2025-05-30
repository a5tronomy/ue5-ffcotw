#include "FFCOTW.h"

FSnkViewChannels::FSnkViewChannels()
{
	
}

FSnkViewStackingProxy::FSnkViewStackingProxy()
{
	
}

USnkViewStackingComponent::USnkViewStackingComponent()
    : StackViewID(0)
    , LightGridReuseTargetID(0)
    , Priority(0)
    , TargetGPUHeadroom(0)
    , bMainCameraProxy(false)
    , bReflectPostureFromActor(false)
    , bDisableOcclusionTest(false)
    , bDisableSkyAtmosphere(false)
    , bOverrideSkyAtmosphereShadingViewChannels(false)
    , bSetFOVWithFixedAspect(false)
    , FOVWithFixedAspect(90.0f)
    , FixedAspect(1.777778f)
    , ScreenMADOffset(FVector4f(1.0f, 1.0f, 0.0f, 0.0f))
    , OverwriteSceneCaptureSource(ESceneCaptureSource::SCS_SceneColorHDR)
{
    PrimaryComponentTick.bCanEverTick = false;
    bWantsInitializeComponent = true;
}

void USnkViewStackingComponent::SetScreenMADOffset(FVector4f Offset)
{
    ScreenMADOffset = Offset;
}

void USnkViewStackingComponent::SetPriority(int32 InPriority)
{
    Priority = InPriority;
}

bool USnkViewStackingComponent::IsReflectPostureFromActor() const
{
    return bReflectPostureFromActor;
}

int32 USnkViewStackingComponent::GetPriority() const
{
    return Priority;
}

void USnkViewStackingComponent::Activate(bool bReset)
{
    Super::Activate(bReset);
    OnComponentActivated_Native();
}

void USnkViewStackingComponent::Deactivate()
{
    OnComponentDeactivated_Native();
    Super::Deactivate();
}

void USnkViewStackingComponent::OnComponentActivated_Native()
{

}

void USnkViewStackingComponent::OnComponentDeactivated_Native()
{

}