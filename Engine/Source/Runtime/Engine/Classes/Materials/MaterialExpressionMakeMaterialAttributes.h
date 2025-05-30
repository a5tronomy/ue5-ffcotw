// Copyright Epic Games, Inc. All Rights Reserved.


#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "MaterialExpressionIO.h"
#include "Materials/MaterialExpression.h"
#include "MaterialExpressionMakeMaterialAttributes.generated.h"

UCLASS(collapsecategories, hidecategories = Object, MinimalAPI)
class UMaterialExpressionMakeMaterialAttributes : public UMaterialExpression
{
	GENERATED_UCLASS_BODY()

	UPROPERTY()
	FExpressionInput BaseColor;

	UPROPERTY()
	FExpressionInput Metallic;

	UPROPERTY()
	FExpressionInput Specular;

	UPROPERTY()
	FExpressionInput Roughness;

	UPROPERTY()
	FExpressionInput Anisotropy;

	UPROPERTY()
	FExpressionInput EmissiveColor;

	UPROPERTY()
	FExpressionInput Opacity;

	UPROPERTY()
	FExpressionInput OpacityMask;

	UPROPERTY()
	FExpressionInput Normal;

	UPROPERTY()
	FExpressionInput Tangent;

	UPROPERTY()
	FExpressionInput WorldPositionOffset;

	UPROPERTY()
	FExpressionInput SubsurfaceColor;

	UPROPERTY()
	FExpressionInput ClearCoat;

	UPROPERTY()
	FExpressionInput ClearCoatRoughness;

	UPROPERTY()
	FExpressionInput AmbientOcclusion;

	UPROPERTY()
	FExpressionInput Refraction;

	UPROPERTY()
	FExpressionInput CustomizedUVs[8];

	UPROPERTY()
	FExpressionInput PixelDepthOffset;

	UPROPERTY()
	FExpressionInput ShadingModel;

	UPROPERTY()
	FExpressionInput Displacement;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SpecularOffset;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SpecularRange;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput ShadowColor;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput CharaMask;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput EffectMask;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput CustomData4;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput CustomData5;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput CustomData6;


	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput CustomData7;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput CustomData8;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput CustomData9;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SNK_ProjBlendRatioAndZDepthOffset;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SNK_ActorRootPosition;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SNK_TransViewOrthoProjM0;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SNK_TransViewOrthoProjM1;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SNK_TransViewOrthoProjM2;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SNK_TransViewOrthoProjM3;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SNK_ViewOrthoProjM3;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SNK_PrevActorRootPosition;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SNK_PrevTransViewOrthoProjM0;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SNK_PrevTransViewOrthoProjM1;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SNK_PrevTransViewOrthoProjM2;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SNK_PrevTransViewOrthoProjM3;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SNK_PrevViewOrthoProjM3;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput SNK_SpecialFilterFlag;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput OutlineMask;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput InlineParam;

	/** FFCOTW Custom Engine */
	/** Custom property for FFCOTW, changing this will not affect anything */
	UPROPERTY()
	FExpressionInput AAJitterScale;

	/** Get the input for a material property. Returns nullptr if the property isn't supported. */
	FExpressionInput* GetExpressionInput(EMaterialProperty InProperty);

	//~ Begin UObject Interface
	virtual void Serialize(FStructuredArchive::FRecord Record) override;
	//~ End UObject Interface

	//~ Begin UMaterialExpression Interface
#if WITH_EDITOR
	virtual int32 Compile(class FMaterialCompiler* Compiler, int32 OutputIndex) override;
	virtual void GetCaption(TArray<FString>& OutCaptions) const override;
	virtual bool IsResultMaterialAttributes(int32 OutputIndex) override {return true;}
	virtual uint32 GetInputType(int32 InputIndex) override;
	virtual bool GenerateHLSLExpression(FMaterialHLSLGenerator& Generator, UE::HLSLTree::FScope& Scope, int32 OutputIndex, UE::HLSLTree::FExpression const*& OutExpression) const override;
#endif // WITH_EDITOR
	//~ End UMaterialExpression Interface
};



