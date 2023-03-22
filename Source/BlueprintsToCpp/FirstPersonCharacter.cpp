// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"

// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AFirstPersonCharacter::Forward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AFirstPersonCharacter::Right);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Grab"), IE_Pressed, this, &AFirstPersonCharacter::Grab);
	PlayerInputComponent->BindAction(TEXT("Grab"), IE_Released, this, &AFirstPersonCharacter::Release);
}

void AFirstPersonCharacter::Forward(float AxisValue)
{
	GetCharacterMovement()->AddInputVector(GetActorForwardVector() * AxisValue);
}

void AFirstPersonCharacter::Right(float AxisValue)
{
	GetCharacterMovement()->AddInputVector(GetActorRightVector() * AxisValue);
}

void AFirstPersonCharacter::Grab()
{
	GetGrabber()->Grab();
}

void AFirstPersonCharacter::Release()
{
	GetGrabber()->Release();
}

