#include "BeachesCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


ABeachesCharacter::ABeachesCharacter() {
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(RootComponent);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	FollowCamera->SetupAttachment(CameraBoom);

	PrimaryActorTick.bCanEverTick = true;

}

void ABeachesCharacter::BeginPlay() {
	Super::BeginPlay();
	
}

void ABeachesCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

void ABeachesCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABeachesCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABeachesCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ABeachesCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookAround", this, &ABeachesCharacter::LookAround);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABeachesCharacter::Jump);

}

void ABeachesCharacter::MoveForward(float value) {
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, value);
}

void ABeachesCharacter::MoveRight(float value) {
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, value);
}

void ABeachesCharacter::LookUp(float value) {
	AddControllerPitchInput(value * MouseSensibility * GetWorld()->GetDeltaSeconds());
}

void ABeachesCharacter::LookAround(float value) {
	AddControllerYawInput(value * MouseSensibility * GetWorld()->GetDeltaSeconds());
}


