#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BeachesCharacter.generated.h"

UCLASS()
class BEACHES_API ABeachesCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABeachesCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attribute")
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attribute")
	class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	float MouseSensibility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
	float MoveSpeed;

	void MoveForward(float value);
	void MoveRight(float value);
	void LookUp(float value);
	void LookAround(float value);

};
